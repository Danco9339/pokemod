EventScript_TV::
	lockall
	incrementgamestat GAME_STAT_WATCHED_TV
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForPlayersHouseNews
	goto_if_eq VAR_RESULT, PLAYERS_HOUSE_TV_NONE, EventScript_TV_NotPlayersHouse
	goto_if_set FLAG_MOM_RESCUED, EventScript_PlayersHouseMomRescuedNews
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_TV_MomKidnappedNewsFlash, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_PlayersHouseMomRescuedNews::
	msgbox gText_TV_MomRescuedNewsFlash, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_TV_NotPlayersHouse::
	goto_if_unset FLAG_SYS_TV_START, EventScript_MomDadMightLikeThis1
	goto_if_set FLAG_SYS_TV_WATCH, EventScript_MomDadMightLikeThis1
	specialvar VAR_RESULT, IsGabbyAndTyShowOnTheAir
	goto_if_eq VAR_RESULT, TRUE, EventScript_DoInSearchOfTrainers
	goto EventScript_TryDoPokeNews
	end

EventScript_TryDoTVShow::
	specialvar VAR_0x8004, GetRandomActiveShowIdx
	goto_if_eq VAR_0x8004, 255, EventScript_MomDadMightLikeThis2
	specialvar VAR_RESULT, GetNextActiveShowIfMassOutbreak
	goto_if_eq VAR_RESULT, 255, EventScript_MomDadMightLikeThis2
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, GetSelectedTVShow
	goto_if_ne VAR_RESULT, 0, EventScript_DoTVShow
	end

EventScript_MomDadMightLikeThis1::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	special TurnOffTVScreen
	releaseall
	end

EventScript_PlayersHouseMovie::
	msgbox PlayersHouse_1F_Text_TheresAMovieOnTV, MSGBOX_DEFAULT
	releaseall
	end

@ special InitRoamer is a junk call. Its input var (VAR_0x8004) hasn't been set, and
@ It's called again when Mom actually asks for the color, overwriting
@ whatever it does here.
EventScript_PlayersHouseLatiNewsFlash::
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	special InitRoamer
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	releaseall
	end

@ The following is a loop for the TV show messages
@ VAR_RESULT is set to TRUE when the show has printed its final message
EventScript_DoTVShow::
	special DoTVShow
	waitmessage
	waitbuttonpress
	goto_if_ne VAR_RESULT, TRUE, EventScript_DoTVShow
	goto EventScript_TurnOffTV
	end

EventScript_TurnOffTV::
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_MomDadMightLikeThis2::
	special GetMomOrDadStringForTVMessage
	msgbox gText_MomOrDadMightLikeThisProgram, MSGBOX_DEFAULT
	goto EventScript_TurnOffTV
	end

EventScript_TryDoPokeNews::
	special DoPokeNews
	goto_if_eq VAR_RESULT, FALSE, EventScript_TryDoTVShow
	waitmessage
	waitbuttonpress
	goto EventScript_TurnOffTV
	end

EventScript_DoInSearchOfTrainers::
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	goto_if_eq VAR_RESULT, 0, EventScript_DoInSearchOfTrainers
	goto EventScript_TurnOffTV
	end

gText_TV_MomKidnappedNewsFlash:
	.string "EDIZIONE STRAORDINARIA DEL TELEGIORNALE!\p"
	.string "“Interrompiamo i programmi per una notizia\n"
	.string "sconvolgente da ALDANOVA.\p"
	.string "La signora di casa, madre del nuovo Campione\n"
	.string "della Lega Pokémon, è stata RAPITA!\p"
	.string "I testimoni riferiscono di una violenta incursione\n"
	.string "da parte di criminali con divise del TEAM IDRO.\p"
	.string "Le autorità invitano chiunque abbia informazioni\n"
	.string "a farsi avanti immediatamente.”$"

gText_TV_MomRescuedNewsFlash:
	.string "EDIZIONE DEL TELEGIORNALE:\p"
	.string "“Notizia dell'ultima ora: la madre del\n"
	.string "Campione è stata tratta in salvo!\p"
	.string "Tutta Hoenn esulta per il coraggio del nostro\n"
	.string "straordinario Campione!”$"
