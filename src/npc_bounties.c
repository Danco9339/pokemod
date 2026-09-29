#include "global.h"
#include "npc_bounties.h"
#include "event_data.h"
#include "money.h"
#include "item.h"
#include "pokemon.h"
#include "data.h"
#include "pokemon_storage_system.h"
#include "string_util.h"
#include "text.h"
#include "party_menu.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/party_menu.h"
#include "constants/species.h"
#include "constants/vars.h"

extern const u8 EventScript_NpcBounty[];

extern const u8 OldaleTown_EventScript_Girl[];
extern const u8 Route102_EventScript_LittleBoy[];
extern const u8 PetalburgCity_EventScript_Gentleman[];
extern const u8 Route104_EventScript_BugCatcher[];
extern const u8 RustboroCity_EventScript_FatMan[];
extern const u8 DewfordTown_EventScript_Woman[];
extern const u8 Route109_EventScript_Woman[];
extern const u8 SlateportCity_EventScript_FatMan[];
extern const u8 Route110_EventScript_Boy1[];
extern const u8 MauvilleCity_EventScript_Boy[];
extern const u8 Route117_EventScript_LittleBoy[];
extern const u8 VerdanturfTown_EventScript_Boy[];
extern const u8 Route114_EventScript_Man[];
extern const u8 FallarborTown_EventScript_Gentleman[];
extern const u8 LavaridgeTown_EventScript_OldMan[];
extern const u8 FortreeCity_EventScript_Woman[];
extern const u8 LilycoveCity_EventScript_RichBoy[];
extern const u8 MossdeepCity_EventScript_Sailor[];
extern const u8 SootopolisCity_EventScript_Boy1[];
extern const u8 PacifidlogTown_EventScript_NinjaBoy[];
extern const u8 EverGrandeCity_PokemonCenter_1F_EventScript_Woman[];

extern void UpdateFollowerPokemon(void);

static const struct NpcBounty sNpcBounties[] = {
    // 1. Oldale Town (Town 1 / Start game: 1000 coins)
    { OldaleTown_EventScript_Girl, SPECIES_POOCHYENA, 1000, FLAG_NPC_BOUNTY_1 },
    // 2. Route 102 (Early route: 2000 coins)
    { Route102_EventScript_LittleBoy, SPECIES_ZIGZAGOON, 2000, FLAG_NPC_BOUNTY_2 },
    // 3. Petalburg City (Town 2 / Start game: 3000 coins)
    { PetalburgCity_EventScript_Gentleman, SPECIES_RALTS, 3000, FLAG_NPC_BOUNTY_3 },
    // 4. Route 104 (Early route: 4500 coins)
    { Route104_EventScript_BugCatcher, SPECIES_WINGULL, 4500, FLAG_NPC_BOUNTY_4 },
    // 5. Rustboro City (Town 3: 6500 coins)
    { RustboroCity_EventScript_FatMan, SPECIES_NINCADA, 6500, FLAG_NPC_BOUNTY_5 },
    // 6. Dewford Town (Town 4: 9000 coins)
    { DewfordTown_EventScript_Woman, SPECIES_MAKUHITA, 9000, FLAG_NPC_BOUNTY_6 },
    // 7. Route 109 (Beach / Sea: 11000 coins)
    { Route109_EventScript_Woman, SPECIES_TENTACOOL, 11000, FLAG_NPC_BOUNTY_7 },
    // 8. Slateport City (Town 5: 13000 coins)
    { SlateportCity_EventScript_FatMan, SPECIES_ELECTRIKE, 13000, FLAG_NPC_BOUNTY_8 },
    // 9. Route 110 (Cycling road route: 15000 coins)
    { Route110_EventScript_Boy1, SPECIES_PLUSLE, 15000, FLAG_NPC_BOUNTY_9 },
    // 10. Mauville City (Town 6: 18000 coins)
    { MauvilleCity_EventScript_Boy, SPECIES_VOLTORB, 18000, FLAG_NPC_BOUNTY_10 },
    // 11. Route 117 (Daycare route: 20500 coins)
    { Route117_EventScript_LittleBoy, SPECIES_ROSELIA, 20500, FLAG_NPC_BOUNTY_11 },
    // 12. Verdanturf Town (Town 7: 23000 coins)
    { VerdanturfTown_EventScript_Boy, SPECIES_TRAPINCH, 23000, FLAG_NPC_BOUNTY_12 },
    // 13. Route 114 (Meteor Falls route: 26000 coins)
    { Route114_EventScript_Man, SPECIES_SWABLU, 26000, FLAG_NPC_BOUNTY_13 },
    // 14. Fallarbor Town (Town 8: 28000 coins)
    { FallarborTown_EventScript_Gentleman, SPECIES_SPINDA, 28000, FLAG_NPC_BOUNTY_14 },
    // 15. Lavaridge Town (Town 9: 33000 coins)
    { LavaridgeTown_EventScript_OldMan, SPECIES_TORKOAL, 33000, FLAG_NPC_BOUNTY_15 },
    // 16. Fortree City (Town 10: 38000 coins)
    { FortreeCity_EventScript_Woman, SPECIES_TROPIUS, 38000, FLAG_NPC_BOUNTY_16 },
    // 17. Lilycove City (Town 11: 43000 coins)
    { LilycoveCity_EventScript_RichBoy, SPECIES_ABSOL, 43000, FLAG_NPC_BOUNTY_17 },
    // 18. Mossdeep City (Town 12: 48000 coins)
    { MossdeepCity_EventScript_Sailor, SPECIES_SPHEAL, 48000, FLAG_NPC_BOUNTY_18 },
    // 19. Sootopolis City (Town 13: 53000 coins)
    { SootopolisCity_EventScript_Boy1, SPECIES_RELICANTH, 53000, FLAG_NPC_BOUNTY_19 },
    // 20. Pacifidlog Town (Town 14: 58000 coins)
    { PacifidlogTown_EventScript_NinjaBoy, SPECIES_CORSOLA, 58000, FLAG_NPC_BOUNTY_20 },
    // 21. Ever Grande City (Town 15 / End game: 65000 coins)
    { EverGrandeCity_PokemonCenter_1F_EventScript_Woman, SPECIES_BAGON, 65000, FLAG_NPC_BOUNTY_21 },
};

static EWRAM_DATA u8 sCurrentBountyId = 0;

const u8 *TryGetBountyNpcScript(const u8 *origScript)
{
    u32 i;

    if (origScript == NULL)
        return NULL;

    if (VarGet(VAR_RANSOM_MOM_STATE) < 1)
        return origScript;

    for (i = 0; i < ARRAY_COUNT(sNpcBounties); i++)
    {
        if (sNpcBounties[i].origScript == origScript)
        {
            sCurrentBountyId = i + 1;
            return EventScript_NpcBounty;
        }
    }

    return origScript;
}

void NpcBounty_CheckStatus(void)
{
    u32 i;
    u8 index;
    u16 wantedSpecies;

    if (sCurrentBountyId == 0 || sCurrentBountyId > ARRAY_COUNT(sNpcBounties))
    {
        gSpecialVar_Result = 0;
        return;
    }

    index = sCurrentBountyId - 1;

    if (FlagGet(sNpcBounties[index].flagId))
    {
        gSpecialVar_Result = 1; // Already completed
        return;
    }

    wantedSpecies = sNpcBounties[index].species;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];
        if (!GetMonData(mon, MON_DATA_IS_EGG) && GetMonData(mon, MON_DATA_SPECIES) == wantedSpecies)
        {
            gSpecialVar_Result = 2; // Has requested mon in party
            return;
        }
    }

    gSpecialVar_Result = 0; // New offer / still looking
}

void NpcBounty_BufferStrings(void)
{
    u8 index;

    if (sCurrentBountyId == 0 || sCurrentBountyId > ARRAY_COUNT(sNpcBounties))
        return;

    index = sCurrentBountyId - 1;

    StringCopy(gStringVar1, gSpeciesNames[sNpcBounties[index].species]);
    ConvertIntToDecimalStringN(gStringVar2, sNpcBounties[index].reward, STR_CONV_MODE_LEFT_ALIGN, 6);
}

void NpcBounty_ValidateAndDeliverMon(void)
{
    u8 slot;
    u8 index;
    struct Pokemon *mon;
    u32 i;
    u8 aliveMons;
    u16 heldItem;
    u16 emptyItem = ITEM_NONE;

    if (sCurrentBountyId == 0 || sCurrentBountyId > ARRAY_COUNT(sNpcBounties))
    {
        gSpecialVar_Result = 2;
        return;
    }

    index = sCurrentBountyId - 1;

    slot = gSpecialVar_0x8004;
    if (slot >= gPlayerPartyCount)
    {
        gSpecialVar_Result = 2;
        return;
    }

    mon = &gPlayerParty[slot];

    if (GetMonData(mon, MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = 1; // Is egg
        return;
    }

    if (GetMonData(mon, MON_DATA_SPECIES) != sNpcBounties[index].species)
    {
        StringCopy(gStringVar3, gSpeciesNames[GetMonData(mon, MON_DATA_SPECIES)]);
        gSpecialVar_Result = 2; // Wrong species
        return;
    }

    if (gPlayerPartyCount <= 1)
    {
        gSpecialVar_Result = 3; // Only mon in party
        return;
    }

    aliveMons = 0;
    for (i = 0; i < gPlayerPartyCount; i++)
    {
        if (i != slot && !GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG) && GetMonData(&gPlayerParty[i], MON_DATA_HP) > 0)
            aliveMons++;
    }

    if (aliveMons == 0)
    {
        gSpecialVar_Result = 3; // Cannot give away last conscious mon
        return;
    }

    // Safe return of held item
    heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    if (heldItem != ITEM_NONE)
    {
        AddBagItem(heldItem, 1);
        SetMonData(mon, MON_DATA_HELD_ITEM, &emptyItem);
    }

    // Deliver mon
    ZeroMonData(mon);
    CompactPartySlots();
    CalculatePlayerPartyCount();
    UpdateFollowerPokemon();

    // Reward player
    AddMoney(&gSaveBlock1Ptr->money, sNpcBounties[index].reward);
    FlagSet(sNpcBounties[index].flagId);

    gSpecialVar_Result = 0; // Success!
}
