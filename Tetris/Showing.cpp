#include "Showing.h"
#include "Tetris.h"


#include <vector>
#include <iostream>
#include <conio.h>
#include <Windows.h>

void Showing::MakeMap(const vector<vector<int>>& Map)
{
	int* MapElement = const_cast<int*>(&Map[0][0]);
	//vector<int>* MapVectorElement = const_cast<vector<int>*>(&Map[0]);

	for (size_t a = 0; a < Map.size(); a = a + 1)
	{
		MapElement = const_cast<int*>(&Map[a][0]);
		//	MapElement = &(*MapVectorElement)[0] ;
		for (size_t b = 0; b < Map[a].size(); ++b)
		{
			if (*MapElement == 0)
				std::cout << "бр";
			else if (*MapElement == 1 || *MapElement == 2)
				std::cout << "бс";
			else if (*MapElement == 3)
				std::cout << "в├";

			++MapElement;
		}
		//	++MapVectorElement;
		std::cout << std::endl;
	}


	ShowScore();
	MapElement = nullptr;
	delete MapElement;

}

vector<int> Showing::PastXPos(10);
vector<int> Showing::PastYPos(10);


void Showing::DeleteBlockInMap()
{
	PastXPos.clear();
	PastYPos.clear();
}

void Showing::ShowBlock(const vector<vector<int>>& Map, const vector<int> Xpos, const vector<int> Ypos)
{
	
	for (int a = 0; a < PastXPos.size(); a = a + 1)
	{
		GoToXY(PastXPos[a]*2, PastYPos[a]);
		std::cout << "бр";
	}
	
	for (int a = 0; a < Xpos.size(); a = a + 1)
	{
		GoToXY(Xpos[a]*2, Ypos[a]);
		std::cout << "бс";
	}
	
	

	PastXPos = Xpos;
	PastYPos = Ypos;

}


void Showing::ShowScore()
{
	GoToXY(43,0);
	std::cout << "SCORE : " <<Tetris::GetScore();

	GoToXY(0, 0);
}

void Showing::GoToXY(const int x, const int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}