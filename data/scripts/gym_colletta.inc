RustboroCity_Gym_EventScript_RoxanneColletta::
	msgbox gText_RoxanneCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROXANNE_5, gText_RoxanneCollettaDefeat
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
	release
	end

DewfordTown_Gym_EventScript_BrawlyColletta::
	msgbox gText_BrawlyCollettaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRAWLY_5, gText_BrawlyCollettaDefeat
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
	trainerbattle_no_intro TRAINER_WATTSON_5, gText_WattsonCollettaDefeat
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
	trainerbattle_no_intro TRAINER_FLANNERY_5, gText_FlanneryCollettaDefeat
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
	trainerbattle_no_intro TRAINER_NORMAN_5, gText_NormanCollettaDefeat
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
	trainerbattle_no_intro TRAINER_WINONA_5, gText_WinonaCollettaDefeat
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
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_5, gText_TateAndLizaCollettaDefeat
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
	trainerbattle_no_intro TRAINER_JUAN_5, gText_JuanCollettaDefeat
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
	.string "{PLAYER} ha ricevuto 100.000 ¥ per la colletta!$"

gText_RoxanneCollettaIntro:
	.string "ROXANNE: Campione! Abbiamo saputo del vile\n"
	.string "rapimento di tua madre da parte del TEAM IDRO!\p"
	.string "La nostra palestra dona 100.000 ¥ per il riscatto,\n"
	.string "ma prima mostrami la solidità del tuo stile!$"

gText_RoxanneCollettaDefeat:
	.string "Una forza incrollabile come la roccia!$"

gText_RoxanneCollettaPost:
	.string "ROXANNE: Splendido! Ecco le 100.000 monete\n"
	.string "e l'antico FLAUTO GHIACCIO per risvegliare ARTICUNO!$"

gText_BrawlyCollettaIntro:
	.string "BRAWLY: Campione! La notizia del rapimento ha\n"
	.string "scosso anche le onde di Bluruvia!\p"
	.string "Contribuiamo con 100.000 ¥, ma prima cavalchiamo\n"
	.string "questa tempesta insieme in battaglia!$"

gText_BrawlyCollettaDefeat:
	.string "Sono stato travolto da un'onda gigantesca!$"

gText_BrawlyCollettaPost:
	.string "BRAWLY: Sei incredibile! Ecco le 100.000 monete\n"
	.string "e il BIGLIETTO ARGENTO per invocare LUGIA!$"

gText_WattsonCollettaIntro:
	.string "WATTSON: Wahahaha! Campione! Il TEAM IDRO\n"
	.string "ha osato oltrepassare ogni limite morale!\p"
	.string "Ciclamipoli dona 100.000 ¥ alla colletta!\n"
	.string "Fammi vedere se il tuo spirito è ad alta tensione!$"

gText_WattsonCollettaDefeat:
	.string "Wahahaha! Una scarica ad altissimo voltaggio!$"

gText_WattsonCollettaPost:
	.string "WATTSON: Elettrizzante! Ecco le 100.000 monete\n"
	.string "e il leggendario FLAUTO TUONO per ZAPDOS!$"

gText_FlanneryCollettaIntro:
	.string "FIAMMETTA: Campione! Il mio cuore brucia di sdegno\n"
	.string "per il vile ricatto del TEAM IDRO!\p"
	.string "La palestra dona 100.000 ¥, ma prima scaldiamo\n"
	.string "il campo con tutta la nostra passione!$"

gText_FlanneryCollettaDefeat:
	.string "Il tuo fuoco arde più luminoso del mio!$"

gText_FlanneryCollettaPost:
	.string "FIAMMETTA: Sei una fiamma inarrestabile!\n"
	.string "Ecco le 100.000 monete e il FLAUTO FUOCO per MOLTRES!$"

gText_NormanBusySearching:
	.string "NORMAN: {PLAYER}! Sono sconvolto per tua madre...\n"
	.string "Sto coordinando le ricerche giorno e notte con\l"
	.string "le pattuglie di tutta la regione di Hoenn!\p"
	.string "So che stai raccogliendo la colletta per pagare\n"
	.string "il riscatto, ma ora sono troppo forte per te e non\l"
	.string "posso fermarmi proprio adesso.\p"
	.string "Dimostrami la tua determinazione battendo prima\n"
	.string "gli altri 7 Capipalestra di Hoenn!\p"
	.string "Solo allora potrai sfidarmi: sarò io l'ultimo\n"
	.string "Capopalestra da affrontare per completare la somma\l"
	.string "e darti il mio contributo!\p"
	.string "Nel frattempo, ho parlato con il PROF. BIRCH:\n"
	.string "ti aiuterà con gli investimenti azionari della\l"
	.string "DEVON SpA al suo laboratorio per far fruttare\l"
	.string "i tuoi risparmi!$"

gText_NormanCollettaIntro:
	.string "NORMAN: {PLAYER}! Hai raccolto il sostegno di\n"
	.string "tutti gli altri 7 Capipalestra di Hoenn!\p"
	.string "Vedo la determinazione e la maturità nei tuoi occhi.\n"
	.string "Ora tocca a noi: sarò l'ultimo ostacolo da superare\l"
	.string "prima di salvare tua madre!\p"
	.string "Mostrami tutto ciò che hai imparato!$"

gText_NormanCollettaDefeat:
	.string "Incredibile... Sei diventato persino più forte\n"
	.string "di me, figlio mio!$"

gText_NormanCollettaPost:
	.string "NORMAN: Non ho più alcun dubbio. Sei pronto per\n"
	.string "affrontare il TEAM IDRO e salvare la mamma!\p"
	.string "Ecco il mio contributo di 100.000 ¥ per la colletta,\n"
	.string "e prendi questo antico cimelio di Kanto: la SFERA\l"
	.string "PSICHICA, capace di risvegliare MEWTWO!$"

gText_WinonaCollettaIntro:
	.string "ALICE: Campione! Il vento ha portato la triste\n"
	.string "notizia fino alle vette di Forestopoli...\p"
	.string "Ci libreremo al tuo fianco: ecco 100.000 ¥!\n"
	.string "Ma prima, danza nell'aria contro i miei Pokémon!$"

gText_WinonaCollettaDefeat:
	.string "Le tue ali solcano i cieli più alti!$"

gText_WinonaCollettaPost:
	.string "ALICE: Splendida grazia! Ecco le 100.000 monete\n"
	.string "e il BIGLIETTO IRIDE per far discendere HO-OH!$"

gText_TateAndLizaCollettaIntro:
	.string "TELL & PAT: Campione! I nostri poteri hanno sentito\n"
	.string "il dolore della tua famiglia rapita in mare...\p"
	.string "Doniamo 100.000 ¥, ma prima sincronizziamo\n"
	.string "le nostre menti in un combattimento d'élite!$"

gText_TateAndLizaCollettaDefeat:
	.string "Una sintonia e una potenza mai viste prima!$"

gText_TateAndLizaCollettaPost:
	.string "TELL & PAT: Meraviglioso! Ecco le 100.000 monete\n"
	.string "e la SFERA MIRAGGIO per far apparire MEW!$"

gText_JuanCollettaIntro:
	.string "RODILFO: Ah, Campione! Un'eleganza ferita da\n"
	.string "un affronto così barbaro del TEAM IDRO!\p"
	.string "Contribuisco con 100.000 ¥ alla colletta!\n"
	.string "Ma deliziami prima con l'arte sublime della lotta!$"

gText_JuanCollettaDefeat:
	.string "Magnifique! Un'esecuzione magistrale!$"

gText_JuanCollettaPost:
	.string "RODILFO: Un trionfo d'arte e coraggio!\n"
	.string "Ecco le 100.000 monete e l'AMBRA DEL TEMPO per CELEBI!$"

gText_CollettaUnlockPokenav:
	.string "Congratulazioni! Hai già ottenuto il supporto\n"
	.string "di ben 4 palestre!\p"
	.string "Per aiutarti a coordinare le ricerche di tua\n"
	.string "madre e rintracciare gli altri Capipalestra,\l"
	.string "ti dono questo dispositivo speciale!$"

gText_CollettaExplainPokenav:
	.string "Il POKéNAV ti permetterà di orientarti lungo\n"
	.string "tutta la regione di HOENN!\p"
	.string "Forza Campione, non mollare!\n"
	.string "Tua madre conta su di te!$"

