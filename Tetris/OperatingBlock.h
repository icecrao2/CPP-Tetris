#pragma once
#include "Block.h"
#include <iostream>
#include <vector>

class OperatingBlock
{
private:
	
	Block* block;


	//로테이션이 가능한지 확인한다.
	bool CheckCanRotate(const vector<vector<int>>& Map);
	bool CheckCanMoveRight(const vector<vector<int>>& Map);
	bool CheckCanMoveLeft(const vector<vector<int>>& Map);
	bool CheckCanDown(const vector<vector<int>>& Map);
	void EraseBlockInMap(vector<vector<int>>& Map);
	bool CancelRotation(); 
	void ApplyToMap(vector<vector<int>>& Map);
	void MoveRotationModPos(void(*Apply)(int& RotationModPos), vector<vector<int>>& RotationModPos);
	
public:

	OperatingBlock(Block* block)
	{
		this->block = block;
	}
	/*
	OneBlock()
	{
		//show = new Showing();
		RotationMod = 0;

		PosX.reserve(5);
		PosY.reserve(5);
		PosX.resize(5);
		PosY.resize(5);
		RotationModPosX.reserve(4);
		RotationModPosX.resize(4);
		RotationModPosY.reserve(4);
		RotationModPosY.resize(4);

		for (int a = 0; a < RotationModPosX.size(); a = a + 1)
		{
			RotationModPosX[a].reserve(4);
			RotationModPosY[a].reserve(4);
			RotationModPosX[a].resize(4);
			RotationModPosY[a].resize(4);
		}

		RotationModPosX[0][0] = 9;
		RotationModPosX[0][1] = 10;
		RotationModPosX[0][2] = 11;
		RotationModPosX[0][3] = 11;

		RotationModPosY[0][0] = 0;
		RotationModPosY[0][1] = 0;
		RotationModPosY[0][2] = 0;
		RotationModPosY[0][3] = 1;
		
		RotationModPosX[1][0] = 11;
		RotationModPosX[1][1] = 11;
		RotationModPosX[1][2] = 11;
		RotationModPosX[1][3] = 10;

		RotationModPosY[1][0] = 1;
		RotationModPosY[1][1] = 2;
		RotationModPosY[1][2] = 3;
		RotationModPosY[1][3] = 3;

		RotationModPosX[2][0] = 10;
		RotationModPosX[2][1] = 9;
		RotationModPosX[2][2] = 8;
		RotationModPosX[2][3] = 8;

		RotationModPosY[2][0] = 3;
		RotationModPosY[2][1] = 3;
		RotationModPosY[2][2] = 3;
		RotationModPosY[2][3] = 2;

		RotationModPosX[3][0] = 8;
		RotationModPosX[3][1] = 8;
		RotationModPosX[3][2] = 8;
		RotationModPosX[3][3] = 9;

		RotationModPosY[3][0] = 2;
		RotationModPosY[3][1] = 1;
		RotationModPosY[3][2] = 0;
		RotationModPosY[3][3] = 0;
		
		PosX = RotationModPosX[0];
		PosY = RotationModPosY[0];

	}
	*/
	
	void Falling(vector<vector<int>>& Map);
	void PushLeftButton(vector<vector<int>>& Map);
	void PushRightButton(vector<vector<int>>& Map);
	void PushUpButton(vector<vector<int>>& Map);
	void PushDownButton(vector<vector<int>>& Map);
	void FixBlock(vector<vector<int>>& Map);

	~OperatingBlock()
	{
		//delete show;
	}
};

