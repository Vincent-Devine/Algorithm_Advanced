#include "Pathfinding/BellmanFord.hpp"

using namespace Pathfinding;

std::vector<int> Pathfinding::BellmanFordIterative(int nbEdges, std::vector<Edge> edges, int source, int target)
{
	std::vector<int> distances(nbEdges, INT_MAX);
	distances[source] = 0;

	for (int i = 0; i < nbEdges - 1; ++i)
	{
		for (const Edge& edge : edges)
		{
			if (distances[edge.source] != INT_MAX && distances[edge.source] + edge.weight < distances[edge.destination])
			{
				distances[edge.destination] = distances[edge.source] + edge.weight;
			}
		}
	}

	return distances;
}

void BellmanFordRecursiveHelper(std::vector<int>& distances, const std::vector<Edge>& edges, int iteration, int maxIteration)
{
	if (iteration == maxIteration)
		return;

	std::vector<int> newDistances = distances;

	for (const Edge& edge : edges)
	{
		if (distances[edge.source] != INT_MAX && distances[edge.source] + edge.weight < distances[edge.destination])
		{
			newDistances[edge.destination] = distances[edge.source] + edge.weight;
		}
	}

	distances = newDistances;
	BellmanFordRecursiveHelper(distances, edges, iteration + 1, maxIteration);
}

std::vector<int> Pathfinding::BellmanFordRecursive(int nbEdges, std::vector<Edge> edges, int source, int target)
{
	std::vector<int> distances(nbEdges, INT_MAX);
	distances[source] = 0;
	BellmanFordRecursiveHelper(distances, edges, 0, nbEdges - 1);
	return distances;
}