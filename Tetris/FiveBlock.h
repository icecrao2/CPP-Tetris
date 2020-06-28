#pragma once
#include "Block.h"

#include <iostream>
#include <vector>

/*
	*
	****  ¸ð¾ç
*/

class FiveBlock : public Block
{

private:

	const int NumberOfBlock = 4;

	/*
	vector<int> PosX;
	vector<int> PosY;

	int RotationMod;

	vector<vector<int>> RotationModPosX;
	vector<vector<int>> RotationModPosY;
	*/

public:

	FiveBlock() : Block()
	{
		RotationMod = 0;

		PosX.reserve(NumberOfBlock);
		PosY.reserve(NumberOfBlock);
		PosX.resize(NumberOfBlock);
		PosY.resize(NumberOfBlock);
		RotationModPosX.reserve(NumberOfMod);
		RotationModPosX.resize(NumberOfMod);
		RotationModPosY.reserve(NumberOfMod);
		RotationModPosY.resize(NumberOfMod);

		for (int a = 0; a < RotationModPosX.size(); a = a + 1)
		{
			RotationModPosX[a].reserve(NumberOfMod);
			RotationModPosY[a].reserve(NumberOfMod);
			RotationModPosX[a].resize(NumberOfMod);
			RotationModPosY[a].resize(NumberOfMod);
		}

		RotationModPosX[0][0] = 10;
		RotationModPosX[0][1] = 10;
		RotationModPosX[0][2] = 10;
		RotationModPosX[0][3] = 10;

		RotationModPosY[0][0] = 0;
		RotationModPosY[0][1] = 1;
		RotationModPosY[0][2] = 2;
		RotationModPosY[0][3] = 3;

		RotationModPosX[1][0] = 9;
		RotationModPosX[1][1] = 10;
		RotationModPosX[1][2] = 11;
		RotationModPosX[1][3] = 12;

		RotationModPosY[1][0] = 2;
		RotationModPosY[1][1] = 2;
		RotationModPosY[1][2] = 2;
		RotationModPosY[1][3] = 2;

		RotationModPosX[2][0] = 11;
		RotationModPosX[2][1] = 11;
		RotationModPosX[2][2] = 11;
		RotationModPosX[2][3] = 11;

		RotationModPosY[2][0] = 0;
		RotationModPosY[2][1] = 1;
		RotationModPosY[2][2] = 2;
		RotationModPosY[2][3] = 3;

		RotationModPosX[3][0] = 9;
		RotationModPosX[3][1] = 10;
		RotationModPosX[3][2] = 11;
		RotationModPosX[3][3] = 12;

		RotationModPosY[3][0] = 1;
		RotationModPosY[3][1] = 1;
		RotationModPosY[3][2] = 1;
		RotationModPosY[3][3] = 1;


		PosX = RotationModPosX[RotationMod];
		PosY = RotationModPosY[RotationMod];
	}

};

