RustboroCity_Gym_EventScript_RoxanneColletta::
	msgbox gText_RoxanneCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROXANNE_1, gText_RoxanneCollettaDefeat
	msgbox gText_RoxanneCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_FLUTE_ICE
	setflag FLAG_COLLETTA_ROXANNE
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	giveitem ITEM_TM_ROCK_TOMB
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyColletta::
	msgbox gText_BrawlyCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRAWLY_1, gText_BrawlyCollettaDefeat
	msgbox gText_BrawlyCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_BELL_SILVER
	setflag FLAG_COLLETTA_BRAWLY
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

MauvilleCity_Gym_EventScript_WattsonColletta::
	msgbox gText_WattsonCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WATTSON_1, gText_WattsonCollettaDefeat
	msgbox gText_WattsonCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_FLUTE_THUNDER
	setflag FLAG_COLLETTA_WATTSON
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

LavaridgeTown_Gym_EventScript_FlanneryColletta::
	msgbox gText_FlanneryCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FLANNERY_1, gText_FlanneryCollettaDefeat
	msgbox gText_FlanneryCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_FLUTE_FIRE
	setflag FLAG_COLLETTA_FLANNERY
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

PetalburgCity_Gym_EventScript_NormanColletta::
	goto_if_lt VAR_COLLETTA_GYMS_COUNT, 7, PetalburgCity_Gym_EventScript_NormanBusySearching
	msgbox gText_NormanCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, gText_NormanCollettaDefeat
	msgbox gText_NormanCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_ORB_PSYCHIC
	setflag FLAG_COLLETTA_NORMAN
	setflag FLAG_DEVON_INVESTMENT_UNLOCKED
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

PetalburgCity_Gym_EventScript_NormanBusySearching::
	msgbox gText_NormanBusySearching, MSGBOX_DEFAULT
	setflag FLAG_DEVON_INVESTMENT_UNLOCKED
	release
	end

FortreeCity_Gym_EventScript_WinonaColletta::
	msgbox gText_WinonaCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WINONA_1, gText_WinonaCollettaDefeat
	msgbox gText_WinonaCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_BELL_RAINBOW
	setflag FLAG_COLLETTA_WINONA
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaColletta::
	msgbox gText_TateAndLizaCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, gText_TateAndLizaCollettaDefeat
	msgbox gText_TateAndLizaCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_MIRAGE_ORB
	setflag FLAG_COLLETTA_TATE_AND_LIZA
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanColletta::
	msgbox gText_JuanCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JUAN_1, gText_JuanCollettaDefeat
	msgbox gText_JuanCollettaPost, MSGBOX_DEFAULT
	addmoney 100000
	playfanfare MUS_OBTAIN_ITEM
	message gText_Received100kColletta
	waitmessage
	waitfanfare
	giveitem ITEM_LEGEND_TIME_AMBER
	setflag FLAG_COLLETTA_JUAN
	addvar VAR_COLLETTA_GYMS_COUNT, 1
	call Common_EventScript_CheckCollettaPokenav
	release
	end

Common_EventScript_CheckCollettaPokenav::
	goto_if_set FLAG_SYS_POKENAV_GET, Common_EventScript_CheckCollettaPokenavReturn
	goto_if_lt VAR_COLLETTA_GYMS_COUNT, 4, Common_EventScript_CheckCollettaPokenavReturn
	msgbox gText_CollettaUnlockPokenav, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	msgbox gText_CollettaExplainPokenav, MSGBOX_DEFAULT
Common_EventScript_CheckCollettaPokenavReturn::
	return

gText_Received100kColletta:
	.string "{PLAYER} ha ricevuto 100.000 ¥\n"
	.string "per la colletta!$"

gText_RoxanneCollettaIntro:
	.string "PETRA: CAMPIONE!\n"
	.string "Ho saputo del vile rapimento\l"
	.string "di tua madre dal TEAM IDRO!\p"
	.string "Doniamo 100.000 ¥ alla colletta,\n"
	.string "ma prima mostrami la solidità\l"
	.string "della tua squadra!$"

gText_RoxanneCollettaDefeat:
	.string "Una forza solida come la roccia!$"

gText_RoxanneCollettaPost:
	.string "PETRA: Splendido!\n"
	.string "Ecco le 100.000 monete e il sacro\l"
	.string "FLAUTO GHIACCIO per ARTICUNO!$"

gText_BrawlyCollettaIntro:
	.string "RUDI: CAMPIONE!\n"
	.string "La notizia del rapimento ha\l"
	.string "scosso le onde di BLURUVIA!\p"
	.string "Contribuiamo con 100.000 ¥,\n"
	.string "ma prima affrontiamo la tempesta\l"
	.string "in una grande sfida!$"

gText_BrawlyCollettaDefeat:
	.string "Travolto da un'onda gigantesca!$"

gText_BrawlyCollettaPost:
	.string "RUDI: Sei incredibile!\n"
	.string "Ecco le 100.000 monete e il sacro\l"
	.string "ALANARGENTO per LUGIA!$"

gText_WattsonCollettaIntro:
	.string "WALTER: Wahahaha! CAMPIONE!\n"
	.string "Il TEAM IDRO ha esagerato!\p"
	.string "CICLAMIPOLI dona 100.000 ¥!\n"
	.string "Mostrami se il tuo spirito\l"
	.string "è ancora ad alta tensione!$"

gText_WattsonCollettaDefeat:
	.string "Una scossa ad alto voltaggio!$"

gText_WattsonCollettaPost:
	.string "WALTER: Elettrizzante!\n"
	.string "Ecco le 100.000 monete e il sacro\l"
	.string "FLAUTO TUONO per ZAPDOS!$"

gText_FlanneryCollettaIntro:
	.string "FIAMMETTA: CAMPIONE!\n"
	.string "Il mio cuore brucia di sdegno\l"
	.string "per il vile ricatto subito!\p"
	.string "Doniamo 100.000 ¥ alla colletta,\n"
	.string "ma prima lottiamo con passione!$"

gText_FlanneryCollettaDefeat:
	.string "Il tuo fuoco arde più del mio!$"

gText_FlanneryCollettaPost:
	.string "FIAMMETTA: Sei inarrestabile!\n"
	.string "Ecco le 100.000 monete e il sacro\l"
	.string "FLAUTO FUOCO per MOLTRES!$"

gText_NormanBusySearching:
	.string "NORMAN: {PLAYER}!\n"
	.string "Sono sconvolto per tua madre…\p"
	.string "Sto coordinando le ricerche\n"
	.string "con le pattuglie di tutta HOENN!\p"
	.string "Raccogli la colletta dalle altre\n"
	.string "7 palestre prima di sfidarmi.\p"
	.string "Sarò la tua prova finale prima\n"
	.string "dello scontro con il TEAM IDRO!\p"
	.string "Nel frattempo, il PROF. BIRCH\n"
	.string "ti aiuterà con le azioni DEVON\l"
	.string "per far fruttare i tuoi risparmi!$"

gText_NormanCollettaIntro:
	.string "NORMAN: {PLAYER}! Hai ottenuto il\n"
	.string "sostegno delle altre 7 palestre!\p"
	.string "Vedo la determinazione nei tuoi\n"
	.string "occhi: è il momento di lottare!\p"
	.string "Mostrami tutta la tua forza!$"

gText_NormanCollettaDefeat:
	.string "Incredibile… Sei più forte di me,\n"
	.string "figlio mio!$"

gText_NormanCollettaPost:
	.string "NORMAN: Sei pronto per salvare\n"
	.string "tua madre dal TEAM IDRO!\p"
	.string "Ecco il mio contributo di\n"
	.string "100.000 ¥ per il riscatto,\l"
	.string "e la mistica SFERA PSICHICA\l"
	.string "per risvegliare MEWTWO!$"

gText_WinonaCollettaIntro:
	.string "ALICE: CAMPIONE!\n"
	.string "Il vento ha portato la notizia\l"
	.string "fino alle vette di FORESTOPOLI…\p"
	.string "Ci libreremo al tuo fianco: ecco\n"
	.string "100.000 ¥! Ma ora lotta in volo\l"
	.string "contro i miei POKéMON!$"

gText_WinonaCollettaDefeat:
	.string "Le tue ali solcano i cieli!$"

gText_WinonaCollettaPost:
	.string "ALICE: Splendida grazia!\n"
	.string "Ecco le 100.000 monete e la sacra\l"
	.string "IRIDOCELLA per HO-OH!$"

gText_TateAndLizaCollettaIntro:
	.string "TELL & PAT: CAMPIONE!\n"
	.string "Abbiamo avvertito il dolore\l"
	.string "della tua povera famiglia!\p"
	.string "Doniamo 100.000 ¥ per il riscatto,\n"
	.string "ma prima sincronizziamo le menti\l"
	.string "in una grande battaglia!$"

gText_TateAndLizaCollettaDefeat:
	.string "Una sintonia mai vista prima!$"

gText_TateAndLizaCollettaPost:
	.string "TELL & PAT: Meraviglioso!\n"
	.string "Ecco le 100.000 monete e la sacra\l"
	.string "SFERA MIRAGGIO per MEW!$"

gText_JuanCollettaIntro:
	.string "RODOLFO: Ah, CAMPIONE!\n"
	.string "Un vile e barbaro affronto da\l"
	.string "parte del TEAM IDRO!\p"
	.string "Contribuisco con 100.000 ¥,\n"
	.string "ma deliziami con una bella lotta!$"

gText_JuanCollettaDefeat:
	.string "Magnifique! Esecuzione sublime!$"

gText_JuanCollettaPost:
	.string "RODOLFO: Trionfo di grazia!\n"
	.string "Ecco le 100.000 monete e la sacra\l"
	.string "AMBRA TEMPO per CELEBI!$"

gText_CollettaUnlockPokenav:
	.string "Congratulazioni!\n"
	.string "Hai il sostegno di 4 palestre!\p"
	.string "Per coordinare le ricerche di tua\n"
	.string "madre e rintracciare i leader,\l"
	.string "ti dono questo strumento utile!$"

gText_CollettaExplainPokenav:
	.string "Il POKéNAV ti aiuterà lungo\n"
	.string "tutta la regione di HOENN!\p"
	.string "Forza CAMPIONE, non mollare!\n"
	.string "Tua madre conta su di te!$"

