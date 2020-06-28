#pragma once
#include "Block.h"

#include <iostream>
#include <vector>

/*
	**
	**
	���
*/


class TwoBlock : public Block
{

private:
	const int NumberOfBlock = 4;

	/*
	vector<ik,.nt> PosX;
	vector<int> PosY;

	int RotationMod;

	vector<vector<int>> RotationModPosX;
	vector<vector<int>> RotationModPosY;
	*/

public:

	TwoBlock() : Block()
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

		RotationModPosX[0][0] = 9;
		RotationModPosX[0][1] = 9;
		RotationModPosX[0][2] = 10;
		RotationModPosX[0][3] = 10;

		RotationModPosY[0][0] = 0;
		RotationModPosY[0][1] = 1;
		RotationModPosY[0][2] = 0;
		RotationModPosY[0][3] = 1;

		RotationModPosX[1][0] = 9;
		RotationModPosX[1][1] = 9;
		RotationModPosX[1][2] = 10;
		RotationModPosX[1][3] = 10;

		RotationModPosY[1][0] = 0;
		RotationModPosY[1][1] = 1;
		RotationModPosY[1][2] = 0;
		RotationModPosY[1][3] = 1;

		RotationModPosX[2][0] = 9;
		RotationModPosX[2][1] = 9;
		RotationModPosX[2][2] = 10;
		RotationModPosX[2][3] = 10;

		RotationModPosY[2][0] = 0;
		RotationModPosY[2][1] = 1;
		RotationModPosY[2][2] = 0;
		RotationModPosY[2][3] = 1;

		RotationModPosX[3][0] = 9;
		RotationModPosX[3][1] = 9;
		RotationModPosX[3][2] = 10;
		RotationModPosX[3][3] = 10;

		RotationModPosY[3][0] = 0;
		RotationModPosY[3][1] = 1;
		RotationModPosY[3][2] = 0;
		RotationModPosY[3][3] = 1;


		PosX = RotationModPosX[RotationMod];
		PosY = RotationModPosY[RotationMod];
	}

};
