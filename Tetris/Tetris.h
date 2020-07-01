#pragma once

#ifndef __TETRIS_H
#define __TETRIS_H


class Tetris {
private:
	static int Score;

public:
	static const int MAP_WIDTH = 20;
	static const int MAP_HEIGHT = 35; 
	static const int TotalBlockTypeNumber = 5;

	static void PlusScore(const int PlusScore)
	{
		Score += PlusScore;
	}

	static int GetScore()
	{
		return Score;
	}
};

#endif