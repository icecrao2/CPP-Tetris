#include "Showing.h"
#include <vector>
#include <iostream>

void Showing::ShowMap(const vector<vector<int>>& Map) 
{
	vector<int>::const_iterator iter;

	for (int a = 0; a < Map.size(); a = a + 1)
	{
		for (int b = 0; b < Map[a].size(); b = b + 1)
		{
			if (Map[a][b] == 0)
				std::cout << "бр";
			else if (Map[a][b] == 1 || Map[a][b] == 2)
				std::cout << "бс";
		}
		std::cout << std::endl;
	}
	/*
	for(vector<int>::size_type i = 0 ; i < Map.size() ; i = i + 1)
	{
		for (iter = Map[i].begin() ; iter < Map[i].end() ; iter = iter + 1)
		{
			if (*iter == 0)
				std::cout << "бр";
			else if (*iter == 1)
				std::cout << "бс";
		}
		std::cout << std::endl;
	}
	*/
}