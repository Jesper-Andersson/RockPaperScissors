#include <cstdlib>
#include <ctime>
#include <iostream>
/*	
	0. Scissors
	1. Rock	
    2. Paper
*/

bool is_playing = true;

int player_score = 0;
int opponent_score = 0;

int temp_score;

short player_input;

void GameRound() {
	std::cout << "Player: " << player_score << std::endl << "Opponent: " << opponent_score << std::endl;

	short selection = std::rand() % 3;

	std::cout << selection;
	
	std::cin.get();

	return;
}

int main() {
	//Sets the seed
	std::srand(std::time(nullptr));

	short scissors = 0;
	short rock = 1;
	short paper = 2;
	
	while (is_playing)
	{
		GameRound();
	}

	return 0;
}