/*
*Rock Paper Scissors Console application
*Copyright (C) 2023  Jesper Andersson <ajesper00@gmail.com>
*
*This program is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*This program is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*GNU General Public License for more details.

*You should have received a copy of the GNU General Public License
*along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

bool is_playing = true;

int player_score = 0;
int opponent_score = 0;

int max_score;

short player_input;

std::string moves[] = { "Scissors", "Rock", "Paper" };

void GameRound() {
	std::cout << "Best of: " << max_score << "." << "\n" << "------------------" << "\n";
	std::cout << "Player: " << player_score << "\n" << "Opponent: " << opponent_score << "\n";

	short selection = std::rand() % 3;

	std::cout << "0. Scissors\n1. Rock\n2. Paper\n";
	
	std::cout << "You choose: ";

	std::cin >> player_input;  //TODO: SANITISE INPUT
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	std::cout << "\n";

	//	0. Scissors, 1. Rock, 2. Paper	

	if (player_input + 1 == selection || player_input - 2 == selection) {
		opponent_score += 1;
		std::cout << "Opponent Won Turn!" << "\n\n";
	}
	else if (player_input - 1 == selection || player_input + 2 == selection) {
		player_score += 1;
		std::cout << "You Won the Turn!" << "\n\n";
	} 
	else{
		std::cout << "Round Draw." << "\n\n";
	}

	std::cout << "You: " << moves[player_input] << " vs Opponent: " << moves[selection] << "\n"; 

	return;
}

int main() {
	//Sets the seed
	std::srand(std::time(nullptr));

	std::cout << "Best of... ? (Max Score): ";

	std::cin >> max_score; //TODO: SANITISE INPUT
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	std::cout << "\n";
	
	while (is_playing)
	{
		if (player_score < max_score && opponent_score < max_score) {
			GameRound();
		}
		else {
			is_playing = false;
		}
	}

	if (player_score > opponent_score) {
		std::cout << "\n" << "You Won the Game" << "\n";
	}
	else {
		std::cout << "\n" << "You Lost the Game" << "\n";
	}

	std::cout << "Game Over.";

	std::cin.get();

	//std::cout << "Play Again?: [Y/N]"
}