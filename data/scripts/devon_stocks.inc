LittlerootTown_ProfessorBirchsLab_EventScript_BirchStockMarket::
	msgbox gText_DevonStock_Welcome, MSGBOX_DEFAULT
LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu::
	message gText_DevonStock_WhatToDo
	waitmessage
	multichoice 18, 4, MULTI_DEVON_STOCKS, FALSE
	switch VAR_RESULT
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_StockStatus
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_StockDeposit
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_StockWithdraw
	case 3, LittlerootTown_ProfessorBirchsLab_EventScript_StockNews
	case 4, LittlerootTown_ProfessorBirchsLab_EventScript_StockExit
	case MULTI_B_PRESSED, LittlerootTown_ProfessorBirchsLab_EventScript_StockExit
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StockStatus::
	callnative DevonStock_GetStatus
	goto_if_eq VAR_RESULT, 1, LittlerootTown_ProfessorBirchsLab_EventScript_StockStatusProfit
	msgbox gText_DevonStock_StatusLoss, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StockStatusProfit::
	msgbox gText_DevonStock_StatusProfit, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StockDeposit::
	showmoneybox 0, 0
	message gText_DevonStock_DepositPrompt
	waitmessage
	multichoice 18, 4, MULTI_DEVON_DEPOSIT, FALSE
	switch VAR_RESULT
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_Deposit10k
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_Deposit50k
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_Deposit100k
	case 3, LittlerootTown_ProfessorBirchsLab_EventScript_DepositAll
	case 4, LittlerootTown_ProfessorBirchsLab_EventScript_DepositCancel
	case MULTI_B_PRESSED, LittlerootTown_ProfessorBirchsLab_EventScript_DepositCancel
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Deposit10k::
	setvar VAR_0x8004, 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_DoDeposit

LittlerootTown_ProfessorBirchsLab_EventScript_Deposit50k::
	setvar VAR_0x8004, 1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_DoDeposit

LittlerootTown_ProfessorBirchsLab_EventScript_Deposit100k::
	setvar VAR_0x8004, 2
	goto LittlerootTown_ProfessorBirchsLab_EventScript_DoDeposit

LittlerootTown_ProfessorBirchsLab_EventScript_DepositAll::
	setvar VAR_0x8004, 3
	goto LittlerootTown_ProfessorBirchsLab_EventScript_DoDeposit

LittlerootTown_ProfessorBirchsLab_EventScript_DoDeposit::
	callnative DevonStock_Deposit
	hidemoneybox
	goto_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_DepositFail
	playse SE_SHOP
	msgbox gText_DevonStock_DepositSuccess, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DepositFail::
	msgbox gText_DevonStock_DepositNotEnoughMoney, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DepositCancel::
	hidemoneybox
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StockWithdraw::
	showmoneybox 0, 0
	message gText_DevonStock_WithdrawPrompt
	waitmessage
	multichoice 18, 6, MULTI_DEVON_WITHDRAW, FALSE
	switch VAR_RESULT
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawAll
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawHalf
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawCancel
	case MULTI_B_PRESSED, LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawCancel
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawAll::
	setvar VAR_0x8004, 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_DoWithdraw

LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawHalf::
	setvar VAR_0x8004, 1
	goto LittlerootTown_ProfessorBirchsLab_EventScript_DoWithdraw

LittlerootTown_ProfessorBirchsLab_EventScript_DoWithdraw::
	callnative DevonStock_Withdraw
	hidemoneybox
	goto_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawFail
	playse SE_SHOP
	msgbox gText_DevonStock_WithdrawSuccess, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawFail::
	msgbox gText_DevonStock_NoFundsToWithdraw, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_WithdrawCancel::
	hidemoneybox
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StockNews::
	callnative DevonStock_GetMarketNews
	msgbox gStringVar4, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_StockMarketMenu
	end

LittlerootTown_ProfessorBirchsLab_EventScript_StockExit::
	msgbox gText_DevonStock_Goodbye, MSGBOX_DEFAULT
	release
	end

gText_DevonStock_Welcome:
	.string "PROF. BIRCH: CAMPIONE!\n"
	.string "Ecco le AZIONI DEVON SpA!\p"
	.string "Rendimento medio: +4%.\n"
	.string "Il trend storico è al rialzo!$"

gText_DevonStock_WhatToDo:
	.string "Cosa desideri fare con le azioni?$"

gText_DevonStock_StatusProfit:
	.string "--- AZIONI DEVON SpA ---\n"
	.string "Capitale: {STR_VAR_1} ¥\l"
	.string "Valore:   {STR_VAR_2} ¥\l"
	.string "Profitto: +{STR_VAR_3} ¥ (ATTIVO!)$"

gText_DevonStock_StatusLoss:
	.string "--- AZIONI DEVON SpA ---\n"
	.string "Capitale:  {STR_VAR_1} ¥\l"
	.string "Valore:    {STR_VAR_2} ¥\l"
	.string "Flessione: -{STR_VAR_3} ¥$"

gText_DevonStock_DepositPrompt:
	.string "Quanto denaro vuoi investire?$"

gText_DevonStock_DepositSuccess:
	.string "Operazione completata!\n"
	.string "Acquistate quote per {STR_VAR_1} ¥.$"

gText_DevonStock_DepositNotEnoughMoney:
	.string "Non hai abbastanza denaro liquido\n"
	.string "nel portafoglio.$"

gText_DevonStock_WithdrawPrompt:
	.string "Quanto capitale vuoi ritirare?$"

gText_DevonStock_WithdrawSuccess:
	.string "Liquidazione completata!\n"
	.string "Hai ritirato {STR_VAR_1} ¥.$"

gText_DevonStock_NoFundsToWithdraw:
	.string "Non hai quote azionarie da\n"
	.string "poter ritirare.$"

gText_DevonStock_Goodbye:
	.string "PROF. BIRCH: Ottima gestione!\n"
	.string "Fai fruttare i tuoi fondi per\l"
	.string "salvare tua madre!$"
