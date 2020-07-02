#pragma once

#ifndef __SHOWING_H_
#define __SHOWING_H_ 




#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;
class Showing
{
private:
	static vector<int> PastXPos;
	static vector<int> PastYPos;


	static void GoToXY(const int x, const int y);
	static void ShowScore();

public:


	static void ShowBlock(const vector<vector<int>>& Map, const vector<int> Xpos, const vector<int> Ypos);
	static void DeleteBlockInMap();
	static void MakeMap(const vector<vector<int>>& Map);

};

#endif // !