#include<vector>
#include<stack>

//Depth first search
//Input:
//	1. neighbours - list of neighbours for all nodes of the graph
//	2. start - starting possition of the search
//Output:
//	vector that represents the order of the elements of all elements connected to the start

std::vector<int> DFS(std::vector<std::vector<int>>& neighbours, int start)
{
	std::vector<bool> passed(neighbours.size(), false);
	std::vector<int> order;

	std::stack<int> dfsStack;
	dfsStack.push(start);

	while (! dfsStack.empty())
	{
		bool flag = true;

		int current = dfsStack.top();
		
		if (!passed[current]) {
			order.push_back(current);
			passed[current] = true;
		}

		for (int i = 0; i < neighbours[current].size(); i++)
		{
			if (!passed[neighbours[current][i]])
			{
				dfsStack.push(neighbours[current][i]);
				flag = false;
				break;
			}
		}

		if (flag) {
			dfsStack.pop();
		}
	}

	return order;
}