/*
	- Pokémon Game Header -

	Here you can see all the declarations of variables, functions,
	structs, enums etc. used in the gameplay.

	For the definitions, please, go to PkmnGameMode.cpp file.
*/

/*
	Summary:
	- Libraries
	- Names Definitions
	- Struct
		- Variables
		- Mapping
	- Enum
		- Guess Validation Structure
	- Class
		- Public
			- Functions Declarations
		- Private
			- Variables Declarations
			- Booleans Declarations Comprovations
*/

#pragma once

#include <string>
#include <map>

using string = std::string;
#define TMap std::map

struct FPkmnStruct
{
	int Match = 0;
	int Close = 0;

	TMap<string, string> HintMap
	{
		{"ivysaur", "In Super Smash Bros., it is the only Pokemon that Pkmn Trainer uses\n       that does not use an HM move."},
		{"squirtle", "As a species, it has been trained most frequently of all the Kanto\n       starter Pokemon by major anime Trainers, with Ash, May, Gary, and\n       Tierno each owning one."},
		{"metapod", "It is the first Pokemon to evolve in a movie"},
		{"pidgey","It is the only Pokemon with a base stat total of 251 and has the\n       shortest cry of any Pokemon, being only 0.181 of a second long."},
		{"pidgeot", "Its eye markings strongly resemble the Sun/Sky gods of Egyptian\n       mythology; Ra and Horus."},
		{"spearow", "According to the anime episode 'I Choose You!', it cannot see color."},
		{"fearow", "It takes inspiration from many soaring, predatory birds."},
		{"ekans","One of it's favorite food is other Pokemon eggs."},
		{"arbok", "It is the last Pokemon to be featured on the Kanto Pokerap."},
		{"pikachu", "In 2008, Japanese researchers discovered a new protein that helps\n       carry electrical impulses from the eyes to the brain and named it\n       in reference to him."},
		{"raichu", "It originally had an evolution named 'Gorochu', which would have\n       had two horns and fangs."},
		{"clefairy","It was originally going to be the official mascot of Pokemon."},
		{"vulpix", "It is based on a Japanese legend, which have a very singular body\n       aspect and can breathe fire"},
		{"zubat", "It and its evolution are the only Pokemon to appear in the lineup\n       of every villainous team in the main series games."},
		{"golbat", "Its gaping maw seems to be a caricature of mythological vampires."},
		{"dugtrio","It appears to be very similar to the artificial moles used in the\n       Whac-A-Mole arcade games."},
		{"meowth", "It is the first Pokemon in the Pokemon anime to talk."},
		{"persian", "It has a special item that makes it resemble a Carbuncle, a Latin-\n       American mythological beast which had something similar at the\n       same spot."},
		{"psyduck", "It was considered for the role of Pikachu's counterpart in Pokemon:\n       Let's Go, Pikachu! and Let's Go, Eevee! instead of Eevee."},
		{"golduck","It's appearance has aspects of a kappa, a Japanese mythological\n       creature."},
		{"mankey", "It has a singular pig-like nose, a long tail, and a very strong\n       personality."},
		{"growlithe", "It is most likely based on Japanese legend called Komainu."},
		{"poliwag", "Prior to Generation VI, It had the same cry than Ditto."},
		{"poliwrath","It has a singular aspect in its belly."},
		{"machop", "Before the release of the English versions of Pokemon Red and Blue,\n       it was known as 'Kara-Tee'."},
		{"machoke", "In the Pokemon Red and Blue beta, It was originally known as\n       'Kung-Foo'."},
		{"golem", "In Generation I, it is the only Pokemon that cannot ever be seen\n       without trading."},
		{"ponyta","It's Stadium and FireRed Pokedex entries state that it can jump over\n       the Eiffel Tower and Ayers Rock, which exist in the real world."},
		{"muk", "It appears to be a pile of living sludge."},
		{"cloyster", "It is tied with Mega Slowbro for the highest base Defense stat of\n       all Water-type Pokémon."},
		{"gastly", "In the Pokemon Red and Blue beta, It's prototype name was 'Spirit'."},
		{"haunter","In the Pokemon Red and Blue beta, It's prototype name was 'Spectre'."},
		{"onix", "Its name is a corruption of a mineral."},
		{"hypno", "It is based on a tapir and baku, or dream eater spirit, of Japanese\n       mythology."},
		{"kingler", "It's known as the Pincer Pokemon."},
		{"cubone","In the Pokemon Red and Blue beta, it was originally known as\n       'Orphon'."},
		{"rhydon", "It was the first Pokemon ever created."},
		{"chansey", "In the Pokemon Red and Blue beta, it was originally known as\n       'Lucky'."},
		{"horsea", "It's art work from Pokemon Red and Blue depicted it with two fins\n       instead of one."},
		{"seaking","In the Pokemon Red and Blue beta, it's prototype name was 'Neptune'."},
		{"staryu", "It appears to be a pun on a literal star, as it is rumored to be\n       extraterrestrial in nature."},
		{"starmie", "It bears some resemblance to the Star of Ishtar. Ishtar, also\n       called Inanna, is known as Queen of Heaven."},
		{"scyther", "In the Pokemon Red and Blue beta, it's prototype name was 'Stryke'."},
		{"jynx","Its Pokedex entries state that it speaks an incomprehensible\n       language."},
		{"tauros", "It used to be one of the most powerful Pokemon in the metagame of\n       the Generation I core series games, in part because it could\n       learn Blizzard."},
		{"flareon", "Its fluffy mane and tail resemble a Pomeranian dog, as well as a\n       lion's mane."},
		{"omanyte", "In the Pokemon Red and Blue beta, it was originally known as 'Ess'.\n       This is derived from the beginning of the word 'escargot', which is\n       French for snail."},
		{"kabuto","In the Pokemon Red and Blue beta, it was originally known as 'Att',\n       which is derived from the word 'Atlantis'."},
		{"kabutops", "In the Pokemon Red and Blue beta, it was originally known as\n       'Lantis'. This is derived from the word 'Atlantis'."},
		{"snorlax", "It is the heaviest Normal-type Pokemon"},
		{"articuno", "In Red, Blue, and Yellow, there are binoculars in the gate\n       separating Fuchsia City from Route 15, through which it can\n       be seen flying toward the sea."},
		{"zapdos", "Of all Legendary Pokemon with fixed in-game locations, it can be\n       obtained with the fewest number of Badges."},
		{"moltres", "It may also be based on the Japanese mythical bird known as Suzaku,\n       guardian of the South."},
		{"dragonite", "It is able to reach a speed of at least 1500 mph (2500 km/h),\n       which is about twice the speed of sound in the air (Mach 2)."},
		{"mew", "The only way to legitimately obtain a Shiny version of it is via\n       the Old Sea Map on a Japanese copy of Pokemon Emerald."}
	};
};

// struct PkmnAndHint in the end

enum class EGuessStatus
{
	Null,
	Special_Character,
	Not_Lowercase,
	Not_Isogram,
	Wrong_Lenght,
	Ok
};

class FPkmnGameMode
{
public:
	FPkmnGameMode(); // Contructor
	FPkmnStruct PkmnStruct;

	int GetMaxTries() const;
	int GetCurrentTry() const;
	int GetPkmnNameLenght() const; 
	
	string GetPkmnName();
	string GetHint(); 
	string GetValidGuess();
	string GetAnyGuess();

	bool GetIsGameWon() const;
	bool GetIsGameOver();

	string SetPokemon();
	string SetHint(string);
	FPkmnStruct SetCountersToZero();

	void PrintIntro();
	void PrintWhatPkmn();
	void PrintTry();
	void PrintTryResults();
	void PrintHint();
	void PrintGameSummary();
	bool AskGameOver();

	EGuessStatus CheckGuessValidity(string) const;
	FPkmnStruct SubmitValidGuess(string);

	void Reset();

	void PlayGame();

private:
	int PlayerCurrentTry;
	int PlayerMaxTries;
	int PkmnIndex;
	string Pokemon;
	string Guess;
	string Hint;
	bool bIsGameWon;
	bool bIsGameOver;
	bool bCanAskHint;

	bool IsIsogram(std::string) const;
	bool IsLowercase(std::string) const;
	bool IsSpecialCharacter(std::string) const;
};
