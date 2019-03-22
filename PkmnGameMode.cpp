/*
	- Pokémon Game C++ File -

	Here you can see all the main game definitions.
*/

/*
	Summary:
	- Game Construct

	- Reset Game Core Structure and Values to Default 
	
	- Getters
		- Max Tryes
		- Current Try
		- Pokémon Name Lenght
		- Pokémon Name
		- Hint
		- Valid Guess
		- Any Guess
		- Is Game Won?
		- Is Game Over?
	
	- Setters
		- Pokémon
		- Hint
		- Try Counters to Zero
	
	- Printers
		- Intro
		- What Pokémon?
		- Player Actual Try
		- Try Results
		- Hint
		- Game Summary
		- Ask Game Over

	- Guess Validation
		- Check Guess Validity
		- Submit Valid Guess
		- Is Isogram?
		- Is Lowercase?
		- Is Special Character?

	- Full Game
		- Gameplay
*/

#pragma once

#include "PkmnGameMode.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>

// Game Construct
FPkmnGameMode::FPkmnGameMode()
{
	Reset();
}

void FPkmnGameMode::Reset()
{
	SetPokemon();
	SetHint(Pokemon);
	SetCountersToZero();
	GetPkmnName();
	GetPkmnNameLenght();

	PlayerMaxTries = 5; //GetMaxTries();
	PlayerCurrentTry = 1;

	bIsGameWon = false;
	bIsGameOver = false;
	bCanAskHint = true;
}

// *********************************************************************************************************************************************************************
// *********************************************************************************************************************************************************************

// Getters
int FPkmnGameMode::GetMaxTries() const
{
	return PlayerMaxTries;
}

int FPkmnGameMode::GetCurrentTry() const
{
	return PlayerCurrentTry;
}

int FPkmnGameMode::GetPkmnNameLenght() const
{
	return Pokemon.length();
}

string FPkmnGameMode::GetPkmnName()
{
	return string(Pokemon);
}

string FPkmnGameMode::GetHint()
{	
	if (bCanAskHint && PlayerCurrentTry == PlayerMaxTries)
	{
		Hint = "You only have one last try, you can't ask for a Hint.";
		return Hint;
	}
	else if (bCanAskHint && PlayerCurrentTry < PlayerMaxTries)
	{
		PlayerCurrentTry++;
		bCanAskHint = false;
		return Hint;
	}
	else if (!bCanAskHint)
	{
		Hint = "You've already asked for your hint before.";
		return Hint;
	}
	else
	{
		Hint = "You can't ask for a Hint right now.";
		return Hint;
	}
}

string FPkmnGameMode::GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Null;

	do
	{
		PrintTry();

		GetAnyGuess();
		if (Guess == "Hint" || Guess == "hint" || Guess == "HINT")
		{
			PrintHint();
		}
		else
		{
			Status = CheckGuessValidity(Guess);
			switch (Status)
			{
			case EGuessStatus::Special_Character:
				std::cout << " Please, do not use any special character or spaces between letters.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << " All letters must be lowercase. Please, try again.\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << " " << Guess << " is not a valid Isogram. Please, enter a name without repeating letters.\n";
				break;
			case EGuessStatus::Wrong_Lenght:
				std::cout << " Please enter a " << GetPkmnNameLenght() << " letter name.\n";
				break;
			case EGuessStatus::Ok:
				return Guess;
				break;
				//default:
					//return Guess;
					//break;
			}
			std::cout << std::endl;
		}
	}
	while (Status != EGuessStatus::Ok);

	return Guess;
}

string FPkmnGameMode::GetAnyGuess()
{
	std::cout << " Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool FPkmnGameMode::GetIsGameWon() const
{
	return bIsGameWon;
}

bool FPkmnGameMode::GetIsGameOver()
{
	return bIsGameOver;
}

// *********************************************************************************************************************************************************************
// *********************************************************************************************************************************************************************

//Setters
string FPkmnGameMode::SetPokemon()
{
	srand(time(NULL));
	
	std::vector <string> PkmnArray = 
	{	"ivysaur", "squirtle", "metapod", "pidgey",
		"pidgeot", "spearow", "fearow", "ekans",
		"arbok", "pikachu", "raichu", "clefairy",
		"vulpix", "zubat", "golbat", "dugtrio",
		"meowth", "persian", "psyduck", "golduck",
		"mankey", "growlithe", "poliwag", "poliwrath",
		"machop", "machoke", "golem", "ponyta",
		"muk", "cloyster", "gastly", "haunter",
		"onix", "hypno", "kingler", "cubone",
		"rhydon", "chansey", "horsea", "seaking",
		"staryu", "starmie", "scyther", "jynx",
		"tauros", "flareon", "omanyte", "kabuto",
		"kabutops", "snorlax", "articuno", "zapdos",
		"moltres", "dragonite", "mew"
	};

	PkmnIndex = PkmnArray.size();

	int RandomPkmn = rand() % PkmnIndex;
	Pokemon = PkmnArray[RandomPkmn];

	return string(Pokemon);
}

string FPkmnGameMode::SetHint(string pPkmn)
{
	Hint = PkmnStruct.HintMap[pPkmn];
	return Hint;
}

FPkmnStruct FPkmnGameMode::SetCountersToZero()
{
	PkmnStruct.Match = 0;
	PkmnStruct.Close = 0;
	return FPkmnStruct();
}

// *********************************************************************************************************************************************************************
// *********************************************************************************************************************************************************************

//Printers
void FPkmnGameMode::PrintIntro()
{
	std::cout << std::endl;
	std::cout << " ************************************************************************* \n";
	std::cout << "                                   ,'\\" << std::endl;
	std::cout << "     _.----.        ____         ,'  _\\   ___    ___     ____" << std::endl;
	std::cout << " _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << std::endl;
	std::cout << " \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << std::endl;
	std::cout << "  \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << std::endl;
	std::cout << "    \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << std::endl;
	std::cout << "     \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << std::endl;
	std::cout << "      \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << std::endl;
	std::cout << "       \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << std::endl;
	std::cout << "        \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << std::endl;
	std::cout << "         \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << std::endl;
	std::cout << "                                 `'                            '-._|" << std::endl;
	std::cout << std::endl;
	std::cout << "               Welcome to 1st Generation Pokemon Isogram" << std::endl;
	std::cout << std::endl;
	std::cout << "                    by Bernardo Garcia Carvalho" << std::endl;
	std::cout << "                 https://www.bernardogamedesign.com/" << std::endl;
	std::cout << std::endl;
}

void FPkmnGameMode::PrintWhatPkmn()
{
	std::cout << " ************************************************************************* \n";
	std::cout << std::endl;
	std::cout << " Isogram:" << std::endl;
	std::cout << " Also known as a 'nonpattern word' is a logological term for a word or\n phrase without a repeating letter." << std::endl;
	std::cout << std::endl;
	std::cout << " Objective:" << std::endl;
	std::cout << " Guess the Pokemon's name before the attempts are exhausted." << std::endl;
	std::cout << std::endl;
	std::cout << " ------------------------------------------------------------------------- \n";
	std::cout << std::endl;
	std::cout << " How to play:" << std::endl;
	std::cout << std::endl;
	std::cout << " - Write down a Pokemon Name and press Enter key." << std::endl;
	std::cout << std::endl;
	std::cout << " - Every valid guess will show a result." << std::endl;
	std::cout << "   - 'Match' is when the letters are at the same position of the\n      correct answer;" << std::endl;
	std::cout << "   - 'Close' is when the correct answer contains the letters of\n      the guess but not at the same position." << std::endl;
	std::cout << std::endl;
	std::cout << " - You can also type 'hint', without quotes, for a helpful hand." << std::endl;
	std::cout << "   - Be careful, as it consumes one try." << std::endl;
	std::cout << std::endl;
	std::cout << "                               Good luck!" << std::endl;
	std::cout << std::endl;
	std::cout << " ------------------------------------------------------------------------- \n";
	std::cout << std::endl;
	std::cout << " Who is this Pokemon? (" << GetPkmnNameLenght() << " letters)\n";
	std::cout << std::endl;
}

void FPkmnGameMode::PrintTry()
{
	std::cout << " Try " << GetCurrentTry() << " of " << GetMaxTries() << std::endl;
}

void FPkmnGameMode::PrintTryResults()
{
	std::cout << " Matches = " << PkmnStruct.Match;
	std::cout << " | Close = " << PkmnStruct.Close << "\n\n";
}

void FPkmnGameMode::PrintHint()
{
	GetHint();
	std::cout << std::endl;
	std::cout << " Hint: " << Hint;
	std::cout << std::endl;
	std::cout << std::endl;
}

void FPkmnGameMode::PrintGameSummary()
{
	if (bIsGameWon)
	{
		std::cout << " Well done!\n You win!\n";
	}
	else
	{
		std::cout << " The Pokemon was: "<< Pokemon << std::endl;
		std::cout << " Better luck next time!\n";
	}
}

bool FPkmnGameMode::AskGameOver()
{
	string Response;

	while ((Response[0] != 'y' || Response[0] != 'Y') || (Response[0] != 'n' || Response[0] != 'N'))
	{
		std::cout << std::endl;
		std::cout << " Do you want to play again (y/n)? ";
		std::getline(std::cin, Response);

		if ((Response[0] == 'y' || Response[0] == 'Y'))
		{
			bIsGameOver = false;
			break;
		}
		else if (Response[0] == 'n' || Response[0] == 'N')
		{
			bIsGameOver = true;
			break;
		}
		else
		{
			std::cout << " This is not a valid answer. Please, say Yes or No.\n";
		}
	}

	return bIsGameOver;
}

// *********************************************************************************************************************************************************************
// *********************************************************************************************************************************************************************

// Guess Validation
EGuessStatus FPkmnGameMode::CheckGuessValidity(string pGuess) const
{
	if (IsSpecialCharacter(pGuess))
	{
		return EGuessStatus::Special_Character;
	}
	else if (!IsIsogram(pGuess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(pGuess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (pGuess.length() != GetPkmnNameLenght())
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

FPkmnStruct FPkmnGameMode::SubmitValidGuess(string pGuess)
{
	PlayerCurrentTry++;

	for (int PkmnNameChar = 0; PkmnNameChar < GetPkmnNameLenght(); PkmnNameChar++)
	{
		for (int GuessChar = 0; GuessChar < GetPkmnNameLenght(); GuessChar++)
		{
			if (pGuess[GuessChar] == Pokemon[PkmnNameChar])
			{
				if (GuessChar == PkmnNameChar)
				{
					PkmnStruct.Match++;
				}
				else
				{
					PkmnStruct.Close++;
				}
			}
		}
	}
	if (PkmnStruct.Match == GetPkmnNameLenght())
	{
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return PkmnStruct;
}

bool FPkmnGameMode::IsIsogram(string pGuess) const
{
	// Treat 0 and 1 letter words as isograms.
	if (pGuess.length() <= 1)
	{
		return true;
	}

	//Setup Local Map
	TMap<char, bool> LetterSeen;

	for (auto Letter : pGuess)
	{
		Letter = tolower(Letter);

		// If the letter is in the map we do not gave an isogram
		if (LetterSeen[Letter])
		{
			return false;
		}
		// Otherwise we add the letter to the map as seen
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

bool FPkmnGameMode::IsLowercase(string pGuess) const
{
	for (auto Letter : pGuess)
	{
		if (isupper(Letter))
		{
			return false;
		}
	}
	return true;
}

bool FPkmnGameMode::IsSpecialCharacter(std::string pGuess) const
{
	if (pGuess.empty())
	{
		return true;
	}
	for (auto Letter : pGuess)
	{
		if (!isalpha(Letter) || isspace(Letter))
		{
			return true;
		}
	}
	return false;
}

// *********************************************************************************************************************************************************************
// *********************************************************************************************************************************************************************

// Full Game
void FPkmnGameMode::PlayGame()
{
	Reset();
	PrintWhatPkmn();
	
	while (!GetIsGameWon() && GetCurrentTry() <= PlayerMaxTries)
	{
		SetCountersToZero();

		GetValidGuess();

		PkmnStruct = SubmitValidGuess(Guess);

		PrintTryResults();

		GetIsGameWon();
	}

	PrintGameSummary();
}