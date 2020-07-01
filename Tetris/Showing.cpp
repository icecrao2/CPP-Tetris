#include "Showing.h"
#include "Tetris.h"


#include <vector>
#include <iostream>
#include <conio.h>
#include <Windows.h>

void Showing::ShowMap(const vector<vector<int>>& Map) 
{
	/*
	for (int a = 0; a < Map.size(); a = a + 1)
	{
		MapElement = const_cast<vector<int>*>(&Map[a]);
		for (int b = 0; b < Map[a].size(); b = b + 1)
		{
			if (Map[a][b] == 0)
				std::cout << "бр";
			else if (Map[a][b] == 1 || Map[a][b] == 2)
				std::cout << "бс";
			else if (Map[a][b] == 3)
				std::cout << "в├";
			MapElement++;
		}
		std::cout << std::endl;
	}
	*/

	int* MapElement = const_cast<int*>(&Map[0][0]);
	vector<int>* MapVectorElement = const_cast<vector<int>*>(&Map[0]);

	for (size_t a = 0 ; a < Map.size(); a = a + 1)
	{
	//	MapElement = const_cast<int*>(&Map[a][0]);
		MapElement = &(*MapVectorElement)[0] ;
		for (size_t b = 0 ; b < Map[a].size() ; ++b)
		{
			if (*MapElement == 0)
				std::cout << "бр";
			else if (*MapElement == 1 || *MapElement == 2)
				std::cout << "бс";
			else if (*MapElement == 3)
				std::cout << "в├";

			++MapElement;
		}
		++MapVectorElement;
		std::cout << std::endl;
	}
	ShowScore();
	MapElement = nullptr;
	delete MapElement;
}


void Showing::ShowScore()
{
	GoToXY(43,0);
	std::cout << "SCORE : " <<Tetris::GetScore() << std::endl;
}

void Showing::GoToXY(const int x, const int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}