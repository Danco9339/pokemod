EventScript_UseLegendarySummonItem::
	lockall
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_FLUTE_ICE, EventScript_Summon_Articuno
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_BELL_SILVER, EventScript_Summon_Lugia
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_FLUTE_THUNDER, EventScript_Summon_Zapdos
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_FLUTE_FIRE, EventScript_Summon_Moltres
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_ORB_PSYCHIC, EventScript_Summon_Mewtwo
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_BELL_RAINBOW, EventScript_Summon_HoOh
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_MIRAGE_ORB, EventScript_Summon_Mew
	goto_if_eq VAR_ITEM_ID, ITEM_LEGEND_TIME_AMBER, EventScript_Summon_Celebi
	releaseall
	end

EventScript_Summon_Articuno::
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Articuno, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_ARTICUNO, 50, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_Lugia::
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Lugia, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_LUGIA, 60, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_Zapdos::
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Zapdos, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_Moltres::
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Moltres, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_Mewtwo::
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Mewtwo, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_MEWTWO, 70, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_HoOh::
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_HoOh, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_HO_OH, 60, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_Mew::
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Mew, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_MEW, 50, ITEM_NONE
	dowildbattle
	releaseall
	end

EventScript_Summon_Celebi::
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Celebi, MSGBOX_DEFAULT
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_CELEBI, 50, ITEM_NONE
	dowildbattle
	releaseall
	end

gText_Summon_Articuno:
	.string "Il FLAUTO GHIACCIO suona una melodia gelida!\nL'aria si congela... ARTICUNO appare!$"

gText_Summon_Lugia:
	.string "Il BIGLIETTO ARGENTO risplende come il mare!\nI mari si agitano... LUGIA scende dal cielo!$"

gText_Summon_Zapdos:
	.string "Il FLAUTO TUONO scatena scintille elettriche!\nI fulmini squarciano le nubi... ZAPDOS appare!$"

gText_Summon_Moltres:
	.string "Il FLAUTO FUOCO si scalda come magma ardente!\nUn turbine di fiamme divampa... MOLTRES appare!$"

gText_Summon_Mewtwo:
	.string "La SFERA PSICHICA irradia una forza smisurata!\nLo spazio attorno si distorce... MEWTWO appare!$"

gText_Summon_HoOh:
	.string "Il BIGLIETTO IRIDE risplende di mille colori!\nUn arcobaleno illumina il cielo... HO-OH appare!$"

gText_Summon_Mew:
	.string "La SFERA MIRAGGIO palpita di una luce gentile!\nCon un battito d'ali... MEW si materializza!$"

gText_Summon_Celebi:
	.string "L'AMBRA DEL TEMPO brilla di un verde purissimo!\nIl tempo sembra fermarsi... CELEBI appare!$"
