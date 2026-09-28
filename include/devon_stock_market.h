#ifndef GUARD_DEVON_STOCK_MARKET_H
#define GUARD_DEVON_STOCK_MARKET_H

#include "global.h"

u32 GetDevonStockValue(void);
void SetDevonStockValue(u32 val);
u32 GetDevonStockInvested(void);
void SetDevonStockInvested(u32 val);
void UpdateDevonStockMarket(void);

void DevonStock_GetStatus(void);
void DevonStock_Deposit(void);
void DevonStock_Withdraw(void);
void DevonStock_GetMarketNews(void);
void GiveRandomLegendaryBeast(void);
void CheckRansomMoney(void);
void PayRansom(void);

#endif // GUARD_DEVON_STOCK_MARKET_H
