Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	call_if_set FLAG_RECEIVED_POKENAV, Route104_MrBrineysHouse_EventScript_HideRustboroRival
	end

Route104_MrBrineysHouse_EventScript_HideRustboroRival::
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	return

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	msgbox Route104_MrBrineysHouse_Text_WaitUpPeeko, MSGBOX_DEFAULT
	msgbox Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_SailToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route104_MrBrineysHouse_Text_WaitUpPeeko:
	.string "SIG. BRINEY: Aspetta, piccola!\n"
	.string "Non correre così, PEEKO!$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Uhm? Ma tu sei {PLAYER}{KUN}!\n"
	.string "Hai salvato la mia adorata PEEKO!\l"
	.string "Ti sarò per sempre grato!\p"
	.string "Cosa mi dici?\n"
	.string "Vuoi salpare con me?\p"
	.string "Uhm-uhm…\p"
	.string "Hai una LETTERA per BLURUVIA e un\n"
	.string "pacco da consegnare a SELCEPOLI?\p"
	.string "E stai anche cercando tua madre…\n"
	.string "Che vita movimentata hai!\p"
	.string "Non temere, salpare con me\n"
	.string "non è affatto un problema.\p"
	.string "Sei venuto dalla persona giusta!\n"
	.string "Mettiamo la prua su BLURUVIA!$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "SIG. BRINEY: A BLURUVIA, dunque!\p"
	.string "Salpate le ancore!\n"
	.string "PEEKO, si salpa, tesoro mio!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "SIG. BRINEY: Ah sì?\n"
	.string "Le tue consegne possono attendere?\p"
	.string "Vieni pure a dirmelo quando\n"
	.string "vorrai salpare!$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "SIG. BRINEY: Ahoy!\n"
	.string "So bene cosa devi fare!\p"
	.string "Devi portare la LETTERA a\n"
	.string "BLURUVIA e il pacco a SELCEPOLI.\p"
	.string "Per me non c'è alcun problema:\n"
	.string "sono l'uomo giusto per la rotta!\p"
	.string "Prima di tutto, rotta su BLURUVIA!$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "SIG. BRINEY: Ahoy!\n"
	.string "So bene cosa devi fare!\p"
	.string "Devi consegnare il pacco al\n"
	.string "CAP. REMO a SELCEPOLI.\p"
	.string "Nessun problema per me!\n"
	.string "Ci penso io!\p"
	.string "Prima di tutto, rotta su BLURUVIA!$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "SIG. BRINEY: Ahoy!\n"
	.string "Per te prenderei il mare sempre!\p"
	.string "E dimmi, amico mio: dove siamo\n"
	.string "diretti questa volta?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "SIG. BRINEY: Capisco.\n"
	.string "PEEKO ti deve la vita.\p"
	.string "Fatti vivo ogni volta che vorrai\n"
	.string "prendere il largo!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "PEEKO: Pii piihyoro!$"

