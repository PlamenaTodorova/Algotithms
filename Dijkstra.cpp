#include<vector>
#include<queue>

//Dijkstra - shortest path to all nodes
//Input:
//	1. neighbours - list of neighbours for all nodes of the graph
//	2. start - starting possition of the search
//Output:
//	vector that represents the shortest path to node i from start

struct Node
{
	int destination;
	int path;

	bool operator<(const Node& n) const
	{
		return path > n.path;
	}
};

std::vector<int> Dijkstra(std::vector<std::vector<Node>>& neighbours, int start)
{
	std::vector<bool> passed(neighbours.size(), false);
	std::vector<int> paths(neighbours.size(), INT_MAX);

	std::priority_queue<Node> queue;
	queue.push({ start, 0 });

	while (!queue.empty())
	{
		Node current = queue.top();
		queue.pop();

		if (passed[current.destination] == true)
		{
			continue;
		}

		passed[current.destination] = true;
		paths[current.destination] = current.path;

		for (int i = 0; i < neighbours[current.destination].size(); i++)
		{
			Node neighbour = neighbours[current.destination][i];
			if (!passed[neighbour.destination])
			{
				queue.push({neighbour.destination, neighbour.path + current.path});
			}
		}
	}

	return paths;
}