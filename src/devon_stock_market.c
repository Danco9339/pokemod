#include "global.h"
#include "devon_stock_market.h"
#include "event_data.h"
#include "money.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "constants/species.h"
#include "constants/vars.h"

static const u8 sText_DevonMarketBullish[] = _("Il mercato DEVON è in forte rialzo!\nI nuovi prototipi high-tech vanno a ruba.$");
static const u8 sText_DevonMarketSteady[] = _("Crescita solida e costante per DEVON SpA.\nGli analisti prevedono ottimi guadagni.$");
static const u8 sText_DevonMarketDip[] = _("Piccola correzione tecnica dei mercati.\nGli esperti consigliano di accumulare quote.$");
static const u8 sText_DevonMarketBearish[] = _("Flessione settimanale temporanea per DEVON.\nLa tendenza a lungo termine resta al rialzo.$");

u32 GetDevonStockValue(void)
{
    u16 low = VarGet(VAR_DEVON_STOCKS_VALUE_LOW);
    u16 high = VarGet(VAR_DEVON_STOCKS_VALUE_HIGH);
    return ((u32)high << 16) | low;
}

void SetDevonStockValue(u32 val)
{
    VarSet(VAR_DEVON_STOCKS_VALUE_LOW, (u16)(val & 0xFFFF));
    VarSet(VAR_DEVON_STOCKS_VALUE_HIGH, (u16)((val >> 16) & 0xFFFF));
}

u32 GetDevonStockInvested(void)
{
    u16 low = VarGet(VAR_DEVON_STOCKS_INVESTED_LOW);
    u16 high = VarGet(VAR_DEVON_STOCKS_INVESTED_HIGH);
    return ((u32)high << 16) | low;
}

void SetDevonStockInvested(u32 val)
{
    VarSet(VAR_DEVON_STOCKS_INVESTED_LOW, (u16)(val & 0xFFFF));
    VarSet(VAR_DEVON_STOCKS_INVESTED_HIGH, (u16)((val >> 16) & 0xFFFF));
}

void UpdateDevonStockMarket(void)
{
    u16 steps = VarGet(VAR_DEVON_STOCKS_STEP_COUNTER);
    steps++;

    if (steps >= 300)
    {
        u32 currentVal;
        VarSet(VAR_DEVON_STOCKS_STEP_COUNTER, 0);

        currentVal = GetDevonStockValue();
        if (currentVal > 0)
        {
            u16 roll = Random() % 100;
            s32 percentChange;
            s64 newVal;

            // Simulated weekly return averaging +4%:
            // 10% chance: -7% (temporary dip)
            // 15% chance: -3% (minor pullback)
            // 45% chance: +4% (steady progress)
            // 30% chance: +11% (bullish surge)
            // Weighted average: 0.10*(-7) + 0.15*(-3) + 0.45*(+4) + 0.30*(+11) = +3.95% (~+4%)
            if (roll < 10)
                percentChange = -7;
            else if (roll < 25)
                percentChange = -3;
            else if (roll < 70)
                percentChange = 4;
            else
                percentChange = 11;

            newVal = ((s64)currentVal * (100 + percentChange)) / 100;
            if (newVal < 1)
                newVal = 1;
            if (newVal > 99999999)
                newVal = 99999999;

            SetDevonStockValue((u32)newVal);
            VarSet(VAR_DEVON_MARKET_TREND, (u16)(percentChange + 50));
        }
    }
    else
    {
        VarSet(VAR_DEVON_STOCKS_STEP_COUNTER, steps);
    }
}

void DevonStock_GetStatus(void)
{
    u32 invested = GetDevonStockInvested();
    u32 curVal = GetDevonStockValue();

    ConvertIntToDecimalStringN(gStringVar1, invested, STR_CONV_MODE_LEFT_ALIGN, 8);
    ConvertIntToDecimalStringN(gStringVar2, curVal, STR_CONV_MODE_LEFT_ALIGN, 8);

    if (curVal >= invested)
    {
        u32 profit = curVal - invested;
        u32 pct = (invested > 0) ? (profit * 100) / invested : 0;
        ConvertIntToDecimalStringN(gStringVar3, profit, STR_CONV_MODE_LEFT_ALIGN, 8);
        gSpecialVar_Result = 1; // In profit or even
    }
    else
    {
        u32 loss = invested - curVal;
        u32 pct = (invested > 0) ? (loss * 100) / invested : 0;
        ConvertIntToDecimalStringN(gStringVar3, loss, STR_CONV_MODE_LEFT_ALIGN, 8);
        gSpecialVar_Result = 2; // In loss
    }
}

void DevonStock_Deposit(void)
{
    u32 depositAmount = 0;
    u32 playerMoney = GetMoney(&gSaveBlock1Ptr->money);

    switch (gSpecialVar_0x8004)
    {
    case 0:
        depositAmount = 10000;
        break;
    case 1:
        depositAmount = 50000;
        break;
    case 2:
        depositAmount = 100000;
        break;
    case 3:
        depositAmount = playerMoney;
        break;
    default:
        depositAmount = 0;
        break;
    }

    if (depositAmount == 0 || playerMoney < depositAmount)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    RemoveMoney(&gSaveBlock1Ptr->money, depositAmount);
    SetDevonStockInvested(GetDevonStockInvested() + depositAmount);
    SetDevonStockValue(GetDevonStockValue() + depositAmount);

    ConvertIntToDecimalStringN(gStringVar1, depositAmount, STR_CONV_MODE_LEFT_ALIGN, 8);
    gSpecialVar_Result = TRUE;
}

void DevonStock_Withdraw(void)
{
    u32 curVal = GetDevonStockValue();
    u32 invested = GetDevonStockInvested();
    u32 withdrawAmount = 0;

    if (curVal == 0)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    if (gSpecialVar_0x8004 == 0) // Withdraw ALL
    {
        withdrawAmount = curVal;
        SetDevonStockValue(0);
        SetDevonStockInvested(0);
    }
    else // Withdraw HALF
    {
        withdrawAmount = curVal / 2;
        SetDevonStockValue(curVal - withdrawAmount);
        SetDevonStockInvested(invested / 2);
    }

    AddMoney(&gSaveBlock1Ptr->money, withdrawAmount);
    ConvertIntToDecimalStringN(gStringVar1, withdrawAmount, STR_CONV_MODE_LEFT_ALIGN, 8);
    gSpecialVar_0x8005 = withdrawAmount;
    gSpecialVar_Result = TRUE;
}

void DevonStock_GetMarketNews(void)
{
    u16 trendRaw = VarGet(VAR_DEVON_MARKET_TREND);
    s32 trend = (s32)trendRaw - 50;

    if (trend >= 8)
        StringCopy(gStringVar4, sText_DevonMarketBullish);
    else if (trend >= 0)
        StringCopy(gStringVar4, sText_DevonMarketSteady);
    else if (trend >= -4)
        StringCopy(gStringVar4, sText_DevonMarketDip);
    else
        StringCopy(gStringVar4, sText_DevonMarketBearish);
}

void GiveRandomLegendaryBeast(void)
{
    u16 roll = Random() % 3;
    u16 species;

    switch (roll)
    {
    case 0:
        species = SPECIES_RAIKOU;
        break;
    case 1:
        species = SPECIES_ENTEI;
        break;
    case 2:
    default:
        species = SPECIES_SUICUNE;
        break;
    }

    VarSet(VAR_RANSOM_MOM_BEAST_CHOSEN, roll);
    gSpecialVar_0x8004 = species;
}

void CheckRansomMoney(void)
{
    if (GetMoney(&gSaveBlock1Ptr->money) >= 1000000)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void PayRansom(void)
{
    if (GetMoney(&gSaveBlock1Ptr->money) >= 1000000)
    {
        RemoveMoney(&gSaveBlock1Ptr->money, 1000000);
        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}
