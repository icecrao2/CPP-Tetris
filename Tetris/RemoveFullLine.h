#pragma once
#include <Windows.h>
#include <queue>

using namespace std;

class RemoveFullLine
{
private:
	queue<int> SearchForTheFullLine(vector<vector<int>>& Map);
	void ExplodeTheLine(queue<int> Element, const int QueueSize, vector<vector<int>>& Map);
	void DestroyTheLine(queue<int> Element, const int QueueSize, vector<vector<int>>& Map);

public:
	void FindAndRemoveFullLine(vector<vector<int>>& Map);
};

