#include <queue>
#include <vector>

using namespace std;

//Breadth first search
//Input:
//	1. neighbours - list of neighbours for all nodes of the graph
//	2. start - starting possition of the search
//Output:
//	vector that represents the order of the elements of all elements connected to the start

vector<int> BFS(vector<vector<int>> &neighbours, int start)
{
	vector<bool> passed(neighbours.size(), false);
	vector<int> order;

	queue<int> bfsQueue;
	bfsQueue.push(start);

	while (!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		bfsQueue.pop();

		if (passed[current] == true)
		{
			continue;
		}

		passed[current] = true;
		order.push_back(current);

		for (int i = 0; i < neighbours[current].size(); i++)
		{
			if (!passed[neighbours[current][i]])
			{
				bfsQueue.push(neighbours[current][i]);
			}
		}
	}

	return order;
}