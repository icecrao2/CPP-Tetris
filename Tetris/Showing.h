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
	static void GoToXY(const int x, const int y);

	static void ShowScore();

public:
	static void ShowMap(const vector<vector<int>>& Map);
	

};

#endif // !