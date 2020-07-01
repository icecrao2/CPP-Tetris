#pragma once
#ifndef __BLOCK_H_
#define __BLOCK_H_



#include <vector>

using namespace std;

class Block
{
protected:

	const int NumberOfMod = 4;

	vector<int> PosX;
	vector<int> PosY;

	int RotationMod;

	vector<vector<int>> RotationModPosX;
	vector<vector<int>> RotationModPosY;


//	int PosX;
//	int PosY;

public:
	friend class OperatingBlock;
};

#endif // !__BLOCK_H_
