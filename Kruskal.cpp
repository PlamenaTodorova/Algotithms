#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct Node
{
	int sorce;
	int destination;
	int path;

	bool operator<(const Node& n) const
	{
		return path < n.path;
	}
};

vector<Node> Kruskal(vector<Node>& edges, int numberOfVertexes)
{
	vector<Node> tree;
	vector<set<int>> unions(numberOfVertexes);

	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].sorce << " " << edges[i].destination << " " << edges[i].path << endl;
	}

	int taken = 0, index = 0;
	
	while (taken < numberOfVertexes - 1)
	{
		Node currentEdge = edges[index++];

		vector<int> result;
		vector<int>::iterator it;

		it = set_intersection(unions[currentEdge.sorce].begin(), unions[currentEdge.sorce].end(),
			unions[currentEdge.destination].begin(), unions[currentEdge.destination].end(),
			result.begin());

		if (it - result.begin() == 0)
		{
			tree.push_back(currentEdge);
			unions[currentEdge.sorce].insert(currentEdge.destination);
			unions[currentEdge.destination].insert(currentEdge.sorce);
		}
	}

	return tree;
}

int main()
{
	vector<Node> edges(11);
	
	for (int i = 0; i < 11; i++)
	{
		cin >> edges[i].sorce >> edges[i].destination >> edges[i].path;
	}

	cout << endl;

	for (int i = 0; i < edges.size(); i++)
	{
		cout << edges[i].sorce << " " << edges[i].destination << " " << edges[i].path << endl;
	}

	cout << endl;

	vector<Node> result = Kruskal(edges, 7);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i].sorce << " " << result[i].destination << " " << result[i].path << endl;
	}

	system("pause");
}