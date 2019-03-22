/*
	- Main code -

	Here you can see the start and end of the main game loop.
	For the gameplay code, please, go to PkmnGameMode.cpp or
	For the gamplay header, go to PkmnGameMode.h files.
*/

#pragma once

#include <iostream>
#include <string>
#include <windows.h>

#include "PkmnGameMode.h"


// Functions Declarations
void ConsoleWindowAjustment();
void PrintGoodBye();

// Instantiate a New Game
FPkmnGameMode PkmnGM;

int main()
{
	ConsoleWindowAjustment();

	do
	{
		PkmnGM.PrintIntro();
		PkmnGM.PlayGame();
		PkmnGM.AskGameOver();
	}
	while(!PkmnGM.GetIsGameOver());

	PrintGoodBye();

	return 0;
}



void PrintGoodBye()
{
	std::cout << std::endl;
	std::cout << " Thanks for playing!\n";
}

void ConsoleWindowAjustment()
{
	HWND Console = GetConsoleWindow();
	RECT R;
	GetWindowRect(Console, &R);

	MoveWindow(Console, R.left, R.top, 645, 940, TRUE);
	SetWindowPos(Console, 0, 500, 75, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}