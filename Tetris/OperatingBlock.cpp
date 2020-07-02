
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
		//���� �� ���� �� �ִ��� Ȯ���Ѵ�.
		if (!CheckCanDown(Map))
			return;
		
		m1.lock();

		//���� ���� �����
		EraseBlockInMap(Map);

		//�����̼Ǹ�� �������� �����Ѵ�.
		MoveRotationModPos([](int& RotationModPos)->void { ++RotationModPos; }, block->RotationModPosY);

		//������ �����̼Ǹ�� �������� ���� �����ǿ� �����Ѵ�.
		block->PosY = block->RotationModPosY[block->RotationMod];

		//������ �������� �ʿ� �����Ѵ�.
		ApplyToMap(Map);
		//system("cls");
		Showing::ShowBlock(Map, block->PosX, block->PosY);

		m1.unlock();

		Sleep(Tetris::FallingSpeed);

	}

	
}

void OperatingBlock::PushLeftButton(vector<vector<int>>& Map)
{
	//���� �������� �̵��� �� �ִ��� Ȯ���Ѵ�..
	if (!CheckCanMoveLeft(Map))
		return;

	m1.lock();

	//���� ���� �����
	EraseBlockInMap(Map);

	//�����̼Ǹ�� �������� �����Ѵ�.
	MoveRotationModPos([](int& RotationModPos)->void { --RotationModPos; }, block->RotationModPosX);

	//������ �����̼Ǹ�� �������� ���� �����ǿ� �����Ѵ�.
	block->PosX = block->RotationModPosX[block->RotationMod];

	//������ �������� �ʿ� �����Ѵ�.
	ApplyToMap(Map);

	//system("cls");
	Showing::ShowBlock(Map, block->PosX, block->PosY);

	m1.unlock();
}
void OperatingBlock::PushRightButton(vector<vector<int>>& Map)
{
	//���� ���������� �̵��� �� �ִ��� Ȯ���Ѵ�..
	if (!CheckCanMoveRight(Map))
		return;
	m1.lock();
	
	//���� ���� �����
	EraseBlockInMap(Map);

	//�����̼Ǹ�� �������� �����Ѵ�.
	MoveRotationModPos([](int& RotationModPos)->void { ++RotationModPos; }, block->RotationModPosX);

	//������ �����̼Ǹ�� �������� ���� �����ǿ� �����Ѵ�.
	block->PosX = block->RotationModPosX[block->RotationMod];

	//������ �������� �ʿ� �����Ѵ�.
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

	//ȸ���� �� ���ٸ�
	if ( !CheckCanRotate(Map))
		return;

	m1.lock();

	//���� ���� �����
	EraseBlockInMap(Map);

	//ȸ������ ���� ��Ͽ� �����Ѵ�.
	block->PosX = block->RotationModPosX[block->RotationMod];
	block->PosY = block->RotationModPosY[block->RotationMod];
	
	//������ �������� �ʿ� �����Ѵ�.
	ApplyToMap(Map);
	//system("cls");
	Showing::ShowBlock(Map, block->PosX, block->PosY);

	m1.unlock();

}
void OperatingBlock::PushDownButton(vector<vector<int>>& Map)
{
	//���� ������ �̵��� �� �ִ��� Ȯ���Ѵ�..
	if (!CheckCanDown(Map))
		return;
	m1.lock();

	//���� ���� �����
	EraseBlockInMap(Map);

	//�����̼Ǹ�� �������� �����Ѵ�.
	MoveRotationModPos([](int& RotationModPos)->void { ++RotationModPos; }, block->RotationModPosY);

	//������ �����̼Ǹ�� �������� ���� �����ǿ� �����Ѵ�.
	block->PosY = block->RotationModPosY[block->RotationMod];

	//������ �������� �ʿ� �����Ѵ�.
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
	//���� ���������� �̵��� �� �ִ��� Ȯ���Ѵ�..
	for (int a = 0; a < block->PosX.size(); a = a + 1)
	{
		//Block�� ���� �ٴٸ��� return�Ѵ�.
		if (block->PosX[a] == (Tetris::MAP_WIDTH - 1))
			return false;

		//Block�� �����ϸ� ���̻� down ���� �ʰ� return�Ѵ�.
		else if ((Map[block->PosY[a]][block->PosX[a] + 1]) == 2)
			return false;
	}
	return true;
}

bool OperatingBlock::CheckCanMoveLeft(const vector<vector<int>>& Map)
{
	//���� ���������� �̵��� �� �ִ��� Ȯ���Ѵ�..
	for (int a = 0; a < block->PosX.size(); a = a + 1)
	{
		//Block�� ���� �ٴٸ��� return�Ѵ�.
		if (block->PosX[a] == 0)
			return false;

		//Block�� �����ϸ� ���̻� down ���� �ʰ� return�Ѵ�.
		else if ((Map[block->PosY[a]][block->PosX[a] - 1]) == 2)
			return false;
	}
	return true;
}

bool OperatingBlock::CheckCanDown(const vector<vector<int>>& Map)
{
	for (int a = 0; a < block->PosY.size(); a = a + 1)
	{
		//Block�� ���� �ٴٸ��� return�Ѵ�.
		if (block->PosY[a] == (Tetris::MAP_HEIGHT - 1))
			return false;

		//Block�� �����ϸ� ���̻� down ���� �ʰ� return�Ѵ�.
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
	//�����̼Ǹ�� �������� �����Ѵ�.
	for (int a = 0; a < RotationModPos.size(); a = a + 1)
	{
		for (int b = 0; b < RotationModPos[a].size(); b = b + 1)
		{
			Apply(RotationModPos[a][b]);
			//--RotationModPosX[a][b];
		}
	}
}