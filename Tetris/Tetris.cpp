﻿#include <iostream>
#include <vector>
#include <thread>
#include <conio.h>
#include <Windows.h>


#include "Showing.h"
#include "OperatingBlock.h"
#include "Block.h"
#include "Tetris.h"
#include "OneBlock.h"
#include "TwoBlock.h"
#include "ThreeBlock.h"
#include "FourBlock.h"
#include "FiveBlock.h"

using namespace std;


vector<vector<int>> Map(Tetris::MAP_HEIGHT, vector<int>(Tetris::MAP_WIDTH));

bool KeyboardCTRLThreadIsRunning = false;


enum BlockTypes
{
	TypeOneBlock = 0,
	TypeTwoBlock = 1,
	TypeThreeBlock = 2,
	TypeFourBlock = 3,
	TypeFiveBlock = 4
};


void StartDownThread(vector<vector<int>>& Map, OperatingBlock* block)
{
	block->Falling(Map);
}

void StartKeyboardCTRLThread(vector<vector<int>>& Map, OperatingBlock* block)
{
	int Key = -1;

	while (KeyboardCTRLThreadIsRunning) {
		Key = -1;
		//std::cout << "Thread" << std::endl;

		if (GetAsyncKeyState(VK_UP) & 0x0001 == TRUE)
		{
			block->PushUpButton(Map);
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 0x0001 == TRUE)
		{
			block->PushRightButton(Map);
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x0001 == TRUE)
		{
			block->PushLeftButton(Map);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001 == TRUE)
		{
			block->PushDownButton(Map);
		}
		/*

		Key = _getch();
		
		if (Key == 72)
		{
			//block->PushUpButton(Map);
		}
		*/
		//std::cout << "Thread" << std::endl;
	}
}

Block* ReadyToFallingBlock()
{
	//포인터는 소멸되지 않는다.
	Block* Blocks;

	srand((unsigned int)time(0));

	int RandomNum = rand() % Tetris::TotalBlockTypeNumber;

	if (RandomNum % Tetris::TotalBlockTypeNumber == TypeOneBlock)
	{
		Blocks = new OneBlock();
	}
	else if (RandomNum % Tetris::TotalBlockTypeNumber == TypeTwoBlock)
	{
		Blocks = new TwoBlock();
	}
	else if (RandomNum % Tetris::TotalBlockTypeNumber == TypeThreeBlock)
	{
		Blocks = new ThreeBlock();
	}
	else if (RandomNum % Tetris::TotalBlockTypeNumber == TypeFourBlock)
	{
		Blocks = new FourBlock();
	}
	else if (RandomNum % Tetris::TotalBlockTypeNumber == TypeFiveBlock)
	{
		Blocks = new FiveBlock();
	}
	else
	{
		Blocks = new FiveBlock();
	}
	return Blocks;
}

int main()
{
	system(" mode  con lines=45   cols=60 ");
	
	int a = 1;
	while (1)
	{
		Block* Blocks = ReadyToFallingBlock();

		OperatingBlock* OperBlock = new OperatingBlock(Blocks);

		//다운시키는 친구
		std::thread t1(StartDownThread, ref(Map), ref(OperBlock));

		//Keyboard쓰레드 실행중 여부
		KeyboardCTRLThreadIsRunning = true;

		//키보드 입력 확인 후 값 입력하는 친구
		std::thread t2(StartKeyboardCTRLThread, ref(Map), ref(OperBlock));

		t1.join();
		KeyboardCTRLThreadIsRunning = false;
		
		t2.join();
		
		OperBlock->FixBlock(Map);

		Sleep(1000);

		delete OperBlock;
		delete Blocks;

		std::cout << "Thread!" << std::endl;

		++a;
	}
}