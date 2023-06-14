/*
*Rock Paper Scissors Console application
*Copyright (C) 2023 Jesper Andersson <ajesper00@gmail.com>
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

#include <limits>
#include <cstdlib>
#include <ctime>
#include <iostream>

bool is_playing = true;
bool valid_input = false;

short player_score = 0;
short opponent_score = 0;
short max_score;
short player_selection;

std::string moves[] = { "Scissors", "Rock", "Paper" };

void GameRound() {
	std::cout << "Best of: " << max_score << "." << "\n" << "------------------" << "\n";
	std::cout << "Player: " << player_score << "\n" << "Opponent: " << opponent_score << "\n";

	short selection = std::rand() % 3;

	std::cout << "0. Scissors\n1. Rock\n2. Paper\n";
	
	std::cout << "You choose: ";
	std::cin >> player_selection;

	// ! Negative (ex -1) input ends the game.
	valid_input = false;
	
	while (!valid_input) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Invalid Input, Try again:" << "\n";
			std::cin >> max_score;
		}
		if (!std::cin.fail()) {
			valid_input = true;
		}
	}

	std::cout << "\n";

	//	0. Scissors, 1. Rock, 2. Paper	
	if (player_selection + 1 == selection || player_selection - 2 == selection) {
		opponent_score += 1;
		std::cout << "Opponent Won Turn!" << "\n\n";
	}
	else if (player_selection - 1 == selection || player_selection + 2 == selection) {
		player_score += 1;
		std::cout << "You Won the Turn!" << "\n\n";
	} 
	else{
		std::cout << "Round Draw." << "\n\n";
	}

	std::cout << "You: " << moves[player_selection] << " vs Opponent: " << moves[selection] << "\n"; 
}

int main() {
	//Sets the seed
	std::srand(std::time(nullptr));

	std::cout << "Best of...(Max Score, 1-100): ";
	std::cin >> max_score; 

	valid_input = false;

	while (!valid_input) {
		if (std::cin.fail() || max_score > 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Invalid Input, Try again:" << "\n";
			std::cin >> max_score;
		}
		if (!std::cin.fail()){
			valid_input = true;
		}
	}

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