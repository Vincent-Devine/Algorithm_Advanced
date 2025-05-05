#pragma once

#include <vector>

namespace Pathfinding
{
	struct Edge
	{
		int source;
		int destination;
		int weight;

		Edge(int source, int destination, int weight)
		{
			this->source = source;
			this->destination = destination;
			this->weight = weight;
		}
	};

	std::vector<int> BellmanFordIterative(int nbEdges, std::vector<Edge> edges, int source, int target);
	std::vector<int> BellmanFordRecursive(int nbEdges, std::vector<Edge> edges, int source, int target);
}