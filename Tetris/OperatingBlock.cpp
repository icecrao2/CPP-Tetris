
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include <algorithm>
#include <Windows.h>
#include <iostream>

#include "OperatingBlock.h"
#include "Showing.h"
#include "Tetris.h"

using namespace std;

mutex m1;


void OperatingBlock::Falling(vector<vector<int>>& Map)
{
	//Showing* show = new Showing();

	while (1)
	{	
		//블럭을 더 내릴 수 있는지 확인한다.
		if (!CheckCanDown(Map))
			return;
		
		m1.lock();

		//기존 블럭을 지운다
		EraseBlockInMap(Map);

		//로테이션모드 포지션을 갱신한다.
		MoveRotationModPos([](int& RotationModPos)->void { ++RotationModPos; }, block->RotationModPosY);

		//갱신한 로테이션모드 포지션을 현재 포지션에 대입한다.
		block->PosY = block->RotationModPosY[block->RotationMod];

		//대입한 포지션을 맵에 적용한다.
		ApplyToMap(Map);
		//system("cls");
		Showing::ShowBlock(Map, block->PosX, block->PosY);

		m1.unlock();

		Sleep(Tetris::FallingSpeed);

	}

	
}

void OperatingBlock::PushLeftButton(vector<vector<int>>& Map)
{
	//블럭을 왼쪽으로 이동할 수 있는지 확인한다..
	if (!CheckCanMoveLeft(Map))
		return;

	m1.lock();

	//기존 블럭을 지운다
	EraseBlockInMap(Map);

	//로테이션모드 포지션을 갱신한다.
	MoveRotationModPos([](int& RotationModPos)->void { --RotationModPos; }, block->RotationModPosX);

	//갱신한 로테이션모드 포지션을 현재 포지션에 대입한다.
	block->PosX = block->RotationModPosX[block->RotationMod];

	//대입한 포지션을 맵에 적용한다.
	ApplyToMap(Map);

	//system("cls");
	Showing::ShowBlock(Map, block->PosX, block->PosY);

	m1.unlock();
}
void OperatingBlock::PushRightButton(vector<vector<int>>& Map)
{
	//블럭을 오른쪽으로 이동할 수 있는지 확인한다..
	if (!CheckCanMoveRight(Map))
		return;
	m1.lock();
	
	//기존 블럭을 지운다
	EraseBlockInMap(Map);

	//로테이션모드 포지션을 갱신한다.
	MoveRotationModPos([](int& RotationModPos)->void { ++RotationModPos; }, block->RotationModPosX);

	//갱신한 로테이션모드 포지션을 현재 포지션에 대입한다.
	block->PosX = block->RotationModPosX[block->RotationMod];

	//대입한 포지션을 맵에 적용한다.
	ApplyToMap(Map);
	//system("cls");
	Showing::ShowBlock(Map, block->PosX, block->PosY);

	m1.unlock();
}
void OperatingBlock::PushUpButton(vector<vector<int>>& Map)
{
	if (block->RotationMod != 3)
		++(block->RotationMod);
	else
		block->RotationMod = 0;

	//회전할 수 없다면
	if ( !CheckCanRotate(Map))
		return;

	m1.lock();

	//기존 블럭을 지운다
	EraseBlockInMap(Map);

	//회전값을 현재 블록에 적용한다.
	block->PosX = block->RotationModPosX[block->RotationMod];
	block->PosY = block->RotationModPosY[block->RotationMod];
	
	//대입한 포지션을 맵에 적용한다.
	ApplyToMap(Map);
	//system("cls");
	Showing::ShowBlock(Map, block->PosX, block->PosY);

	m1.unlock();

}
void OperatingBlock::PushDownButton(vector<vector<int>>& Map)
{
	//블럭을 밑으로 이동할 수 있는지 확인한다..
	if (!CheckCanDown(Map))
		return;
	m1.lock();

	//기존 블럭을 지운다
	EraseBlockInMap(Map);

	//로테이션모드 포지션을 갱신한다.
	MoveRotationModPos([](int& RotationModPos)->void { ++RotationModPos; }, block->RotationModPosY);

	//갱신한 로테이션모드 포지션을 현재 포지션에 대입한다.
	block->PosY = block->RotationModPosY[block->RotationMod];

	//대입한 포지션을 맵에 적용한다.
	ApplyToMap(Map);
	//system("cls");
	Showing::ShowBlock(Map, block->PosX, block->PosY);

	m1.unlock();
}

void OperatingBlock::FixBlock(vector<vector<int>>& Map)
{
	m1.lock();
	for (int a = 0; a < block->PosX.size(); a = a + 1)
	{
		Map[block->PosY[a]][block->PosX[a]] = 2;
	}

	m1.unlock();
}

bool OperatingBlock::CheckCanRotate(const vector<vector<int>>& Map)
{
	for (int a = 0; a < block->RotationModPosY[block->RotationMod].size(); a = a + 1)
	{
		if (block->RotationModPosY[block->RotationMod][a] < 0 || block->RotationModPosY[block->RotationMod][a] >= Tetris::MAP_HEIGHT)
		{
			return CancelRotation();
		}
		else if (block->RotationModPosX[block->RotationMod][a] < 0 || block->RotationModPosX[block->RotationMod][a] >= Tetris::MAP_WIDTH)
		{
			return CancelRotation();
		}
		else if (Map[block->RotationModPosY[block->RotationMod][a]][block->RotationModPosX[block->RotationMod][a]] == 2)
		{
			return CancelRotation();
		}
	}
	return true;
}

bool OperatingBlock::CancelRotation()
{
	if (block->RotationMod != 0)
		--(block->RotationMod);
	else
		block->RotationMod = 3;

	return false;
}

bool OperatingBlock::CheckCanMoveRight(const vector<vector<int>>& Map)
{
	//블럭을 오른쪽으로 이동할 수 있는지 확인한다..
	for (int a = 0; a < block->PosX.size(); a = a + 1)
	{
		//Block이 끝에 다다르면 return한다.
		if (block->PosX[a] == (Tetris::MAP_WIDTH - 1))
			return false;

		//Block이 존재하면 더이상 down 하지 않고 return한다.
		else if ((Map[block->PosY[a]][block->PosX[a] + 1]) == 2)
			return false;
	}
	return true;
}

bool OperatingBlock::CheckCanMoveLeft(const vector<vector<int>>& Map)
{
	//블럭을 오른쪽으로 이동할 수 있는지 확인한다..
	for (int a = 0; a < block->PosX.size(); a = a + 1)
	{
		//Block이 끝에 다다르면 return한다.
		if (block->PosX[a] == 0)
			return false;

		//Block이 존재하면 더이상 down 하지 않고 return한다.
		else if ((Map[block->PosY[a]][block->PosX[a] - 1]) == 2)
			return false;
	}
	return true;
}

bool OperatingBlock::CheckCanDown(const vector<vector<int>>& Map)
{
	for (int a = 0; a < block->PosY.size(); a = a + 1)
	{
		//Block이 끝에 다다르면 return한다.
		if (block->PosY[a] == (Tetris::MAP_HEIGHT - 1))
			return false;

		//Block이 존재하면 더이상 down 하지 않고 return한다.
		else if ((Map[block->PosY[a] + 1][block->PosX[a]]) == 2)
			return false;
	}
	return true;
}

void OperatingBlock::EraseBlockInMap(vector<vector<int>>& Map)
{
	for (int a = 0; a < block->PosY.size(); a = a + 1)
	{
		Map[block->PosY[a]][block->PosX[a]] = 0;
	}
}

void OperatingBlock::ApplyToMap(vector<vector<int>>& Map)
{
	for (int a = 0; a < block->PosY.size(); a = a + 1)
	{
		Map[block->PosY[a]][block->PosX[a]] = 1;
	}
}

void OperatingBlock::MoveRotationModPos(void(*Apply)(int& RotationModPos), vector<vector<int>>& RotationModPos)
{
	//로테이션모드 포지션을 갱신한다.
	for (int a = 0; a < RotationModPos.size(); a = a + 1)
	{
		for (int b = 0; b < RotationModPos[a].size(); b = b + 1)
		{
			Apply(RotationModPos[a][b]);
			//--RotationModPosX[a][b];
		}
	}
}