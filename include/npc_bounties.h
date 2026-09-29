#ifndef GUARD_NPC_BOUNTIES_H
#define GUARD_NPC_BOUNTIES_H

#include "global.h"

struct NpcBounty
{
    const u8 *origScript;
    u16 species;
    u32 reward;
    u16 flagId;
};

const u8 *TryGetBountyNpcScript(const u8 *origScript);
void NpcBounty_CheckStatus(void);
void NpcBounty_BufferStrings(void);
void NpcBounty_ValidateAndDeliverMon(void);

#endif // GUARD_NPC_BOUNTIES_H
