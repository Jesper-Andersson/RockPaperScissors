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