#include <Windows.h>
#include <iostream>

#include "RemoveFullLine.h"
#include "Showing.h"
#include "Tetris.h"

void RemoveFullLine::DestroyTheLine(queue<int> Element, const int QueueSize, vector<vector<int>>& Map)
{
	for (int b = 0; b < QueueSize; b = b + 1)
	{
		for (int a = Element.front(); a > 0; a = a - 1)
		{
			Map[a] = Map[a - 1];
		}
		Element.pop();
	}

	system("cls");
	Showing::MakeMap(Map);
}


void RemoveFullLine::ExplodeTheLine(queue<int> Element, const int QueueSize, vector<vector<int>>& Map)
{
	for (int b = 0; b < QueueSize; b = b + 1)
	{
		for (int a = 0; a < Map[Element.front()].size(); a = a + 1)
		{
			Map[Element.front()][a] = 3;
		}
		Element.pop();
	}

	system("cls");
	Showing::MakeMap(Map);
	Sleep(200);

}

queue<int> RemoveFullLine::SearchForTheFullLine(vector<vector<int>>& Map)
{
	bool IsTheLineFull = true;
	queue<int> LineLists;

	for (int a = 0; a < Map.size(); a = a + 1)
	{
		IsTheLineFull = true;
		for (int b = 0; b < Map[a].size(); b = b + 1)
		{
			if (Map[a][b] != 2)
			{
				IsTheLineFull = false;
				break;
			}
		}
		if (IsTheLineFull)
		{
			LineLists.push(a);
		}
	}

	return LineLists;
}


void RemoveFullLine::FindAndRemoveFullLine(vector<vector<int>>& Map)
{
	queue<int> LineLists = SearchForTheFullLine(Map);
	const int SizeOfLineLists = LineLists.size();

	Tetris::PlusScore(SizeOfLineLists * 100);

	ExplodeTheLine(LineLists, SizeOfLineLists, Map);
	DestroyTheLine(LineLists, SizeOfLineLists, Map);

}