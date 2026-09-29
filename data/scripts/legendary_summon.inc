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

@ Subroutine condivisa per gestire la fuga:
@ VAR_0x8004 = species, VAR_0x8005 = livello, VAR_RESULT = esito battaglia
@ Se FLAG_LEGEND_ROAMER_ACTIVE non e' settato: diventa roamer
@ Altrimenti: perso per sempre
EventScript_Summon_Fled_Handler::
	goto_if_set FLAG_LEGEND_ROAMER_ACTIVE, EventScript_Summon_LostForever
	@ Primo leggendario che fugge: diventa errante
	special InitRoamerSpecies
	setflag FLAG_LEGEND_ROAMER_ACTIVE
	return

EventScript_Summon_LostForever::
	@ Gia' esiste un roamer: questo e' perso per sempre
	msgbox gText_Summon_LostForever, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_WhiteOut::
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	end

@ ============================================================
@ ARTICUNO
@ ============================================================
EventScript_Summon_Articuno::
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Articuno, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_ARTICUNO, 50, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Articuno_Caught
	setvar VAR_0x8004, SPECIES_ARTICUNO
	setvar VAR_0x8005, 50
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Articuno_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Articuno_Caught::
	msgbox gText_Summon_Articuno_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ LUGIA
@ ============================================================
EventScript_Summon_Lugia::
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Lugia, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_LUGIA, 60, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Lugia_Caught
	setvar VAR_0x8004, SPECIES_LUGIA
	setvar VAR_0x8005, 60
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Lugia_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Lugia_Caught::
	msgbox gText_Summon_Lugia_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ ZAPDOS
@ ============================================================
EventScript_Summon_Zapdos::
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Zapdos, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Zapdos_Caught
	setvar VAR_0x8004, SPECIES_ZAPDOS
	setvar VAR_0x8005, 50
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Zapdos_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Zapdos_Caught::
	msgbox gText_Summon_Zapdos_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ MOLTRES
@ ============================================================
EventScript_Summon_Moltres::
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Moltres, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_MOLTRES, 50, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Moltres_Caught
	setvar VAR_0x8004, SPECIES_MOLTRES
	setvar VAR_0x8005, 50
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Moltres_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Moltres_Caught::
	msgbox gText_Summon_Moltres_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ MEWTWO
@ ============================================================
EventScript_Summon_Mewtwo::
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Mewtwo, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_MEWTWO, 70, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Mewtwo_Caught
	setvar VAR_0x8004, SPECIES_MEWTWO
	setvar VAR_0x8005, 70
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Mewtwo_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Mewtwo_Caught::
	msgbox gText_Summon_Mewtwo_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ HO-OH
@ ============================================================
EventScript_Summon_HoOh::
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_HoOh, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_HO_OH, 60, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_HoOh_Caught
	setvar VAR_0x8004, SPECIES_HO_OH
	setvar VAR_0x8005, 60
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_HoOh_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_HoOh_Caught::
	msgbox gText_Summon_HoOh_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ MEW
@ ============================================================
EventScript_Summon_Mew::
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Mew, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_MEW, 50, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Mew_Caught
	setvar VAR_0x8004, SPECIES_MEW
	setvar VAR_0x8005, 50
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Mew_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Mew_Caught::
	msgbox gText_Summon_Mew_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ CELEBI
@ ============================================================
EventScript_Summon_Celebi::
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Celebi, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	removeitem VAR_ITEM_ID
	setwildbattle SPECIES_CELEBI, 50, ITEM_NONE
	setflag FLAG_SUMMONING_LEGEND
	dowildbattle
	clearflag FLAG_SUMMONING_LEGEND
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Summon_Celebi_Caught
	setvar VAR_0x8004, SPECIES_CELEBI
	setvar VAR_0x8005, 50
	call EventScript_Summon_Fled_Handler
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	msgbox gText_Summon_Celebi_Fled, MSGBOX_DEFAULT
	closemessage
	waitmoncry
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, EventScript_Summon_WhiteOut
	releaseall
	end

EventScript_Summon_Celebi_Caught::
	msgbox gText_Summon_Celebi_Caught, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ ============================================================
@ TESTI
@ ============================================================

gText_Summon_LostForever:
	.string "È fuggito per sempre...\n"
	.string "Non ritornerà mai più.\p"
	.string "Avevi già un leggendario\n"
	.string "errante: non c'era spazio\l"
	.string "per un altro!$"

gText_Summon_Articuno:
	.string "Il FLAUTO GHIACCIO suona una\n"
	.string "melodia gelida nell'aria...\p"
	.string "L'ambiente si congela...\n"
	.string "ARTICUNO appare maestoso!$"

gText_Summon_Articuno_Fled:
	.string "ARTICUNO ha spiccato il volo\n"
	.string "ed è fuggito via nei cieli!\p"
	.string "Sembra che stia volando per\n"
	.string "tutta la regione di HOENN!$"

gText_Summon_Articuno_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "ARTICUNO!$"

gText_Summon_Lugia:
	.string "Il BIGLIETTO ARGENTO risplende\n"
	.string "come le profondità marine...\p"
	.string "I mari si agitano con furia...\n"
	.string "LUGIA scende dal cielo!$"

gText_Summon_Lugia_Fled:
	.string "LUGIA si è immerso negli abissi\n"
	.string "ed è scomparso nel mare!\p"
	.string "Sembra vagare per i mari\n"
	.string "di tutta HOENN!$"

gText_Summon_Lugia_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "LUGIA!$"

gText_Summon_Zapdos:
	.string "Il FLAUTO TUONO emette potenti\n"
	.string "scintille elettriche!\p"
	.string "I fulmini squarciano le nubi...\n"
	.string "ZAPDOS appare ruggendo!$"

gText_Summon_Zapdos_Fled:
	.string "ZAPDOS ha scatenato un fulmine\n"
	.string "ed è fuggito via veloce!\p"
	.string "Sembra volare per HOENN\n"
	.string "tra le tempeste!$"

gText_Summon_Zapdos_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "ZAPDOS!$"

gText_Summon_Moltres:
	.string "Il FLAUTO FUOCO emana un forte\n"
	.string "calore come lava ardente!\p"
	.string "Un turbine di fuoco divampa...\n"
	.string "MOLTRES appare fiero!$"

gText_Summon_Moltres_Fled:
	.string "MOLTRES si è avvolto nel fuoco\n"
	.string "ed è volato via lontano!\p"
	.string "Sembra vagare per le vette\n"
	.string "vulcaniche di HOENN!$"

gText_Summon_Moltres_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "MOLTRES!$"

gText_Summon_Mewtwo:
	.string "La SFERA PSICHICA irradia una\n"
	.string "forza arcana smisurata!\p"
	.string "Lo spazio attorno si distorce...\n"
	.string "MEWTWO appare dinanzi a te!$"

gText_Summon_Mewtwo_Fled:
	.string "MEWTWO ha usato il teletrasporto\n"
	.string "ed è scomparso nel nulla!\p"
	.string "Sembra vagare per i luoghi\n"
	.string "remoti di HOENN!$"

gText_Summon_Mewtwo_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "MEWTWO!$"

gText_Summon_HoOh:
	.string "Il BIGLIETTO IRIDE risplende\n"
	.string "di mille colori radiosi!\p"
	.string "Un arcobaleno illumina l'aria...\n"
	.string "HO-OH scende maestoso!$"

gText_Summon_HoOh_Fled:
	.string "HO-OH ha spiegato le sue ali\n"
	.string "ed è volato verso il sole!\p"
	.string "Sembra planare per i cieli\n"
	.string "di tutta HOENN!$"

gText_Summon_HoOh_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "HO-OH!$"

gText_Summon_Mew:
	.string "La SFERA MIRAGGIO palpita di\n"
	.string "una luce tenue e gentile...\p"
	.string "Con un battito d'ali lieve...\n"
	.string "MEW si materializza qui!$"

gText_Summon_Mew_Fled:
	.string "MEW ha fatto una piroetta ed è\n"
	.string "svanito in un soffio d'aria!\p"
	.string "Sembra giocare nascosto\n"
	.string "per tutta HOENN!$"

gText_Summon_Mew_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "MEW!$"

gText_Summon_Celebi:
	.string "L'AMBRA DEL TEMPO brilla di\n"
	.string "un verde purissimo e antico!\p"
	.string "Il tempo sembra fermarsi...\n"
	.string "CELEBI appare volando!$"

gText_Summon_Celebi_Fled:
	.string "CELEBI ha attraversato il tempo\n"
	.string "ed è svanito nella foresta!\p"
	.string "Sembra vagare tra i boschi\n"
	.string "di HOENN!$"

gText_Summon_Celebi_Caught:
	.string "Incredibile! Sei riuscito a\n"
	.string "catturare il leggendario\l"
	.string "CELEBI!$"
