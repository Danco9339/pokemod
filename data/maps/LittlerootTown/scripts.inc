LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_MoveMomToMaysDoor
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTwinPos
	call_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent
	call_if_eq VAR_OLDALE_RIVAL_STATE, 1, LittlerootTown_EventScript_MoveRivalFromOldale
	call_if_eq VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_EventScript_SetRivalLeftForRoute103
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_EventScript_LeftLabAfterDexUpgrade
	call_if_set FLAG_LEAGUE_BEATEN_AGAIN, LittlerootTown_EventScript_CheckShowMomCaptive
	end

LittlerootTown_EventScript_CheckShowMomCaptive::
	goto_if_set FLAG_MOM_RESCUED, LittlerootTown_EventScript_HideMomCaptive
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_ShowMomCaptiveMale
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_ShowMomCaptiveMale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_HideMomCaptive::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	return

LittlerootTown_EventScript_LeftLabAfterDexUpgrade::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	return

LittlerootTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_EventScript_SetRivalLeftForRoute103::
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_MoveRivalFromOldale::
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_SetExitedHouseAfterLatiSSTicketEvent::
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	return

LittlerootTown_EventScript_MoveMomToMaysDoor::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 8
	return

LittlerootTown_EventScript_SetTwinPos::
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTwinGuardingRoutePos
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 10, 1
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_SetTwinGuardingRoutePos::
	setobjectxyperm LOCALID_LITTLEROOT_TWIN, 7, 2
	setobjectmovementtype LOCALID_LITTLEROOT_TWIN, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetMomInFrontOfDoorMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_SetMomInFrontOfDoorFemale
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorMale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 5, 9
	return

LittlerootTown_EventScript_SetMomInFrontOfDoorFemale::
	setobjectxyperm LOCALID_LITTLEROOT_MOM, 14, 9
	return

LittlerootTown_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruckMale
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_StepOffTruckFemale
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

LittlerootTown_EventScript_StepOffTruckMale::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_NewStoryIntro
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	releaseall
	end

LittlerootTown_EventScript_StepOffTruckFemale::
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_NewStoryIntro
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	releaseall
	end

LittlerootTown_EventScript_NewStoryIntro::
	delay 15
	playse SE_LEDGE
	applywaitmovement LOCALID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	addobject 3
	setobjectxy 3, 5, 9
	turnobject 3, DIR_NORTH
	delay 20
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Common_Movement_FacePlayer
	waitmovement 0
	delay 15
	applywaitmovement 3, LittlerootTown_Movement_BoyRunToPlayer
	msgbox LittlerootTown_Text_ChampionMomKidnapped, MSGBOX_DEFAULT
	closemessage
	applywaitmovement 3, LittlerootTown_Movement_BoyReturnToCrowd
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	setvar VAR_RANSOM_MOM_STATE, 1
	return

LittlerootTown_Movement_BoyRunToPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_Movement_BoyReturnToCrowd:
	walk_up
	walk_in_place_faster_down
	step_end

LittlerootTown_Text_ChampionMomKidnapped:
	.string "CAMPIONE! Oh cielo, sei tornato!\p"
	.string "Mentre eri alla LEGA POKéMON\n"
	.string "a conquistare il titolo,\l"
	.string "è successa una tragedia immane!\p"
	.string "TUA MADRE… È STATA RAPITA!\p"
	.string "Una flotta del TEAM IDRO ha\n"
	.string "circondato la nostra città\l"
	.string "e l'ha trascinata via in mare!\p"
	.string "Hanno lasciato un ricatto:\n"
	.string "pretendono 1.000.000 di monete!\p"
	.string "Tratteranno solo se sconfiggerai\n"
	.string "di nuovo la LEGA POKéMON per\l"
	.string "dimostrare di essere Campione!\p"
	.string "Il PROF. BIRCH ti sta cercando\n"
	.string "disperato nel suo LABORATORIO!\p"
	.string "Presto, corri subito da lui!$"

LittlerootTown_Movement_MomExitHouse:
	walk_down
	step_end

LittlerootTown_Movement_MomApproachPlayerAtTruck:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_Movement_MomApproachDoor:
	delay_16
	delay_8
	walk_up
	step_end

LittlerootTown_Movement_MomEnterHouse:
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_PlayerApproachDoor:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_PlayerEnterHouse:
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_EventScript_BeginDexUpgradeScene::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
	delay 80
	msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	releaseall
	end

LittlerootTown_OnWarp:
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
	addobject LOCALID_LITTLEROOT_BIRCH
	addobject LOCALID_LITTLEROOT_RIVAL
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
	goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
	end

LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
	setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
	setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
	end

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_CanUsePCToStoreItems, MSGBOX_NPC
	end

LittlerootTown_EventScript_Boy::
	msgbox LittlerootTown_Text_BirchSpendsDaysInLab, MSGBOX_NPC
	end

LittlerootTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BEAST_STARTER, LittlerootTown_EventScript_GoodLuck
	msgbox LittlerootTown_Text_TwinGoToBirch, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoSaveBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_LITTLEROOT_TWIN, Common_Movement_FaceOriginalDirection
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	release
	end

LittlerootTown_EventScript_YouSavedBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_NeedPokemonTriggerLeft::
	lockall
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerLeft
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnLeft
	releaseall
	end

LittlerootTown_EventScript_DangerousWithoutPokemon::
	msgbox LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinPushPlayerFromRoute
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_Movement_TwinApproachPlayerLeft:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_TwinPushPlayerFromRoute:
	walk_down
	step_end

LittlerootTown_Movement_TwinReturnLeft:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_faster_down
	step_end

LittlerootTown_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_NeedPokemonTriggerRight::
	lockall
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinApproachPlayerRight
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applywaitmovement LOCALID_LITTLEROOT_TWIN, LittlerootTown_Movement_TwinReturnRight
	releaseall
	end

LittlerootTown_Movement_TwinApproachPlayerRight:
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end

LittlerootTown_Movement_TwinReturnRight:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_EventScript_GoSaveBirchTrigger::
	lockall
	goto_if_set FLAG_RECEIVED_BEAST_STARTER, LittlerootTown_EventScript_GoSaveBirchTriggerDone
	applywaitmovement LOCALID_LITTLEROOT_TWIN, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox LittlerootTown_Text_TwinGoToBirch, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_GoSaveBirchTriggerDone::
	releaseall
	end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_GiveRunningShoesTrigger0::
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 10, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_LITTLEROOT_MOM, 11, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger3::
	lockall
	setvar VAR_0x8008, 3
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger4::
	lockall
	setvar VAR_0x8008, 4
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger5::
	lockall
	setvar VAR_0x8008, 5
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger::
	releaseall
	end

LittlerootTown_EventScript_GiveRunningShoes::
	return

LittlerootTown_EventScript_SetReceivedRunningShoes::
	releaseall
	end

LittlerootTown_EventScript_SetHomeDoorCoordsMale::
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_SetHomeDoorCoordsFemale::
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_MomNoticePlayerMale::
	applywaitmovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterRight
	return

LittlerootTown_EventScript_MomNoticePlayerFemale::
	applywaitmovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterLeft
	return

LittlerootTown_EventScript_MomApproachPlayerMale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerMale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerMale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerMale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerMale5
	return

LittlerootTown_EventScript_MomApproachPlayerFemale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayerFemale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomApproachPlayerFemale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomApproachPlayerFemale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomApproachPlayerFemale5
	return

LittlerootTown_EventScript_MomApproachPlayer0::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
	return

LittlerootTown_EventScript_MomApproachPlayer1::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
	return

LittlerootTown_EventScript_MomApproachPlayerMale2::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale2
	return

LittlerootTown_EventScript_MomApproachPlayerMale3::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale3
	return

LittlerootTown_EventScript_MomApproachPlayerMale4::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale4
	return

LittlerootTown_EventScript_MomApproachPlayerMale5::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerMale5
	return

LittlerootTown_EventScript_MomApproachPlayerFemale2::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale2
	return

LittlerootTown_EventScript_MomApproachPlayerFemale3::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale3
	return

LittlerootTown_EventScript_MomApproachPlayerFemale4::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale4
	return

LittlerootTown_EventScript_MomApproachPlayerFemale5::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayerFemale5
	return

LittlerootTown_EventScript_MomReturnHomeMale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeMale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeMale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeMale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeMale5
	return

LittlerootTown_EventScript_MomReturnHomeFemale::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHomeFemale2
	call_if_eq VAR_0x8008, 3, LittlerootTown_EventScript_MomReturnHomeFemale3
	call_if_eq VAR_0x8008, 4, LittlerootTown_EventScript_MomReturnHomeFemale4
	call_if_eq VAR_0x8008, 5, LittlerootTown_EventScript_MomReturnHomeFemale5
	return

LittlerootTown_EventScript_MomReturnHome0::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
	return

LittlerootTown_EventScript_MomReturnHome1::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
	return

LittlerootTown_EventScript_MomReturnHomeMale2::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale2
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale3::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale3
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale4::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale4
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeMale5::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeMale5
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale2::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale2
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale3::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale3
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale4::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale4
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_MomReturnHomeFemale5::
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHomeFemale5
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_Movement_MomApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_MomApproachPlayerMale2:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale4:
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerMale5:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale2:
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale3:
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomApproachPlayerFemale5:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_MomReturnHome0:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHome1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_MomReturnHomeMale2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale4:
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeMale5:
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale2:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale3:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomReturnHomeFemale5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_MomExitThroughDoor:
	walk_up
	step_end

LittlerootTown_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_MOM_RESCUED, LittlerootTown_EventScript_MomRescued
	goto_if_set FLAG_LEAGUE_BEATEN_AGAIN, LittlerootTown_EventScript_MomRansomExchange
	msgbox LittlerootTown_Text_AquaCaptorDemands, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_MomRansomExchange::
	msgbox LittlerootTown_Text_AquaCaptorLeagueBeaten, MSGBOX_DEFAULT
	callnative CheckRansomMoney
	goto_if_eq VAR_RESULT, FALSE, LittlerootTown_EventScript_RansomNotEnoughMoney
	msgbox LittlerootTown_Text_AquaCaptorAskPay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_EventScript_RansomRefused
	callnative PayRansom
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_PaidRansom1Million
	waitmessage
	waitfanfare
	msgbox LittlerootTown_Text_AquaCaptorGivesMomBack, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_MOM_RESCUED
	setvar VAR_RANSOM_MOM_STATE, 3
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	applywaitmovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_AquaGruntFlee
	removeobject LOCALID_LITTLEROOT_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	release
	end

LittlerootTown_Movement_AquaGruntFlee:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

LittlerootTown_EventScript_RansomNotEnoughMoney::
	msgbox LittlerootTown_Text_AquaCaptorNeedMoreMoney, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_RansomRefused::
	msgbox LittlerootTown_Text_AquaCaptorRefused, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_MomRescued::
	msgbox LittlerootTown_Text_MomRescuedSafe, MSGBOX_DEFAULT
	release
	end

LittlerootTown_Text_TwinGoToBirch:
	.string "CAMPIONE {PLAYER}!\n"
	.string "Il PROF. BIRCH ti aspetta\l"
	.string "con urgenza al LABORATORIO!\p"
	.string "Ha qualcosa per aiutarti\n"
	.string "a salvare tua madre!$"

LittlerootTown_Text_AquaCaptorDemands:
	.string "TEAM IDRO: Ehi tu, ragazzino!\n"
	.string "Abbiamo noi tua madre!\p"
	.string "Se vuoi rivederla sana e salva,\n"
	.string "porta 1.000.000 ¥ e sconfiggi\l"
	.string "di nuovo la LEGA POKéMON!\p"
	.string "Altrimenti scordatela!$"

LittlerootTown_Text_AquaCaptorLeagueBeaten:
	.string "TEAM IDRO: E così hai battuto\n"
	.string "di nuovo la LEGA POKéMON!\p"
	.string "Impressionante, Campione!\p"
	.string "Ma i patti erano due: il titolo\n"
	.string "e 1.000.000 ¥ per il riscatto!\p"
	.string "Hai portato il milione di monete?$"

LittlerootTown_Text_AquaCaptorNeedMoreMoney:
	.string "TEAM IDRO: Cosa?! Non hai con te\n"
	.string "1.000.000 ¥!\p"
	.string "Niente soldi, niente mamma!\n"
	.string "Torna quando avrai la somma!$"

LittlerootTown_Text_AquaCaptorAskPay:
	.string "TEAM IDRO: Ottimo!\n"
	.string "Hai con te 1.000.000 ¥!\p"
	.string "Vuoi pagare il riscatto\n"
	.string "per liberare tua madre?$"

LittlerootTown_Text_AquaCaptorRefused:
	.string "TEAM IDRO: Fai lo spavaldo?!\n"
	.string "Tua madre resta con noi finché\l"
	.string "non paghi il riscatto!$"

LittlerootTown_Text_PaidRansom1Million:
	.string "{PLAYER} ha pagato 1.000.000 ¥\n"
	.string "di riscatto al TEAM IDRO!$"

LittlerootTown_Text_AquaCaptorGivesMomBack:
	.string "TEAM IDRO: Affare fatto!\n"
	.string "Un milione tondo tondo!\p"
	.string "Il TEAM IDRO rispetta i patti.\n"
	.string "Tua madre è stata liberata,\l"
	.string "la troverai dentro casa!\p"
	.string "Ci si vede, Campione!$"

LittlerootTown_Text_MomThankYouChampion:
	.string "MAMMA: Oh, {PLAYER}, tesoro mio!\n"
	.string "Sapevo che saresti arrivato!\p"
	.string "Sei il miglior CAMPIONE che una\n"
	.string "madre potesse mai desiderare!\p"
	.string "Torniamo finalmente a casa nostra!$"

LittlerootTown_Text_MomRescuedSafe:
	.string "MAMMA: Grazie ancora per avermi\n"
	.string "salvata, tesoro mio!\p"
	.string "Riposati pure qui a casa quando\n"
	.string "vuoi!$"

LittlerootTown_Text_OurNewHomeLetsGoInside:
	.string "MOM: {PLAYER}, we're here, honey!\p"
	.string "It must be tiring riding with our things\n"
	.string "in the moving truck.\p"
	.string "Well, this is LITTLEROOT TOWN.\p"
	.string "How do you like it?\n"
	.string "This is our new home!\p"
	.string "It has a quaint feel, but it seems to be\n"
	.string "an easy place to live, don't you think?\p"
	.string "And, you get your own room, {PLAYER}!\n"
	.string "Let's go inside.$"

LittlerootTown_Text_WaitPlayer:
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_WearTheseRunningShoes:
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to PROF. BIRCH?\p"
	.string "Oh! What an adorable POKéMON!\n"
	.string "You got it from PROF. BIRCH. How nice!\p"
	.string "You're your father's child, all right.\n"
	.string "You look good together with POKéMON!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_CanUsePCToStoreItems:
	.string "Quei malviventi del TEAM IDRO…\n"
	.string "Come hanno osato rapire tua madre?!\p"
	.string "Sei il nostro CAMPIONE!\n"
	.string "Fagli vedere di cosa sei capace,\l"
	.string "siamo tutti con te!$"

LittlerootTown_Text_BirchSpendsDaysInLab:
	.string "Ho visto quando l'hanno portata\n"
	.string "via… che paura!\p"
	.string "Ma so che tu la salverai!\n"
	.string "Nessuno può battere il nostro\l"
	.string "grandissimo CAMPIONE!$"

LittlerootTown_Text_IfYouGoInGrassPokemonWillJumpOut:
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild POKéMON will jump out!$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon:
	.string "It's dangerous if you don't have\n"
	.string "your own POKéMON.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
	.string "Um, hi!\p"
	.string "There are scary POKéMON outside!\n"
	.string "I can hear their cries!\p"
	.string "I want to go see what's going on,\n"
	.string "but I don't have any POKéMON…\p"
	.string "Can you go see what's happening\n"
	.string "for me?$"

LittlerootTown_Text_YouSavedBirch:
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
	.string "Forza CAMPIONE {PLAYER}!\n"
	.string "Sconfiggi il TEAM IDRO e\l"
	.string "riporta la mamma a casa!\p"
	.string "Tutto il paese crede in te!$"

LittlerootTown_Text_TownSign:
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s HOUSE$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "PROF. BIRCH'S HOUSE$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"

