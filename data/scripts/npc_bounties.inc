EventScript_NpcBounty::
	lock
	faceplayer
	callnative NpcBounty_CheckStatus
	callnative NpcBounty_BufferStrings
	switch VAR_RESULT
	case 1, EventScript_NpcBounty_AlreadyCompleted
	case 2, EventScript_NpcBounty_HasMonToDeliver
	@ Default (0):
	goto EventScript_NpcBounty_OfferQuest
	end

EventScript_NpcBounty_AlreadyCompleted::
	msgbox gText_NpcBounty_AlreadyCompleted, MSGBOX_DEFAULT
	release
	end

EventScript_NpcBounty_OfferQuest::
	msgbox gText_NpcBounty_OfferIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NpcBounty_Declined
	msgbox gText_NpcBounty_Accepted, MSGBOX_DEFAULT
	release
	end

EventScript_NpcBounty_Declined::
	msgbox gText_NpcBounty_Declined, MSGBOX_DEFAULT
	release
	end

EventScript_NpcBounty_HasMonToDeliver::
	msgbox gText_NpcBounty_AskDeliver, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NpcBounty_Declined
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EventScript_NpcBounty_Declined
	callnative NpcBounty_ValidateAndDeliverMon
	switch VAR_RESULT
	case 1, EventScript_NpcBounty_IsEgg
	case 2, EventScript_NpcBounty_WrongSpecies
	case 3, EventScript_NpcBounty_OnlyMon
	@ Case 0: Success
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_NpcBounty_HandedOverMon, MSGBOX_DEFAULT
	waitfanfare
	playse SE_SHOP
	msgbox gText_NpcBounty_ReceivedMoney, MSGBOX_DEFAULT
	waitse
	msgbox gText_NpcBounty_DeliveredThanks, MSGBOX_DEFAULT
	release
	end

EventScript_NpcBounty_IsEgg::
	msgbox gText_NpcBounty_IsEgg, MSGBOX_DEFAULT
	release
	end

EventScript_NpcBounty_WrongSpecies::
	msgbox gText_NpcBounty_WrongSpecies, MSGBOX_DEFAULT
	release
	end

EventScript_NpcBounty_OnlyMon::
	msgbox gText_NpcBounty_OnlyMon, MSGBOX_DEFAULT
	release
	end

gText_NpcBounty_AlreadyCompleted:
	.string "Grazie ancora per quel\n"
	.string "{STR_VAR_1} che mi hai dato!\p"
	.string "Spero che le mie monete ti\n"
	.string "aiutino a salvare tua madre!\p"
	.string "Forza CAMPIONE, siamo con te!$"

gText_NpcBounty_OfferIntro:
	.string "CAMPIONE! Voglio contribuire\n"
	.string "alla causa per tua madre!\p"
	.string "Sto cercando disperatamente\n"
	.string "un {STR_VAR_1} da catturare!\p"
	.string "Se lo catturi e me lo dai,\n"
	.string "ti ricompenserò con\l"
	.string "{STR_VAR_2} monete!\p"
	.string "Accetti di aiutarmi?$"

gText_NpcBounty_Accepted:
	.string "Fantastico! Conto su di te!\n"
	.string "Appena catturi un {STR_VAR_1},\l"
	.string "portamelo per ricevere\l"
	.string "le {STR_VAR_2} monete!$"

gText_NpcBounty_Declined:
	.string "Capisco, hai mille impegni!\n"
	.string "Se decidi di aiutarmi, sono qui!$"

gText_NpcBounty_AskDeliver:
	.string "CAMPIONE! Hai con te\n"
	.string "il {STR_VAR_1} che cercavo!\p"
	.string "Vuoi darmelo in cambio\n"
	.string "delle {STR_VAR_2} monete?$"

gText_NpcBounty_HandedOverMon:
	.string "{PLAYER} consegna {STR_VAR_1}\n"
	.string "all'abitante del luogo.$"

gText_NpcBounty_ReceivedMoney:
	.string "{PLAYER} riceve {STR_VAR_2} monete\n"
	.string "da aggiungere al riscatto!$"

gText_NpcBounty_DeliveredThanks:
	.string "Grazie di vero cuore!\n"
	.string "Spero che questo denaro ti aiuti\l"
	.string "a salvare tua madre!\p"
	.string "Buona fortuna, Campione!$"

gText_NpcBounty_IsEgg:
	.string "Oh… Quello è solo un UOVO!\n"
	.string "Non posso accettarlo.$"

gText_NpcBounty_WrongSpecies:
	.string "Mmh… Quello è un {STR_VAR_3}!\n"
	.string "Non posso accettarlo.\p"
	.string "Cerco proprio {STR_VAR_1}!$"

gText_NpcBounty_OnlyMon:
	.string "Non posso chiederti di dare via\n"
	.string "il tuo unico POKéMON abile!\p"
	.string "Torna quando avrai un altro\n"
	.string "POKéMON in squadra!$"
