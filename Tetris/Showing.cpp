#include "Showing.h"
#include "Tetris.h"


#include <vector>
#include <iostream>
#include <conio.h>
#include <Windows.h>

void Showing::ShowMap(const vector<vector<int>>& Map) 
{
	vector<int>::const_iterator iter;

	for (int a = 0; a < Map.size(); a = a + 1)
	{
		for (int b = 0; b < Map[a].size(); b = b + 1)
		{
			if (Map[a][b] == 0)
				std::cout << "бр";
			else if (Map[a][b] == 1 || Map[a][b] == 2)
				std::cout << "бс";
			else if (Map[a][b] == 3)
				std::cout << "в├";
		}
		std::cout << std::endl;
	}

	ShowScore();
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