#include "Pathfinding/Pathfinding.hpp"

#include <chrono>

#include <OMLogger/Logger.hpp>
#include "Pathfinding/BellmanFord.hpp"

using namespace Pathfinding;

void Pathfinding::Exercice()
{
	std::vector<Edge> edges =
	{
		Edge(0, 1, 5) ,
		Edge(0, 2, 7),
		Edge(1, 2, 3),
		Edge(1, 3, 4),
		Edge(1, 4, 6),
		Edge(3, 4, -1),
		Edge(3, 5, 2),
		Edge(4, 5, -3),
	};

	const int source = 0;
	const int target = 4;

	auto start = std::chrono::high_resolution_clock::now();

	std::vector<int> distancesIterative = BellmanFordIterative(edges.size(), edges, source, target);

	auto end = std::chrono::high_resolution_clock::now();
	double durationIterative = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

	start = std::chrono::high_resolution_clock::now();

	std::vector<int> distancesRecursive = BellmanFordRecursive(edges.size(), edges, source, target);

	end = std::chrono::high_resolution_clock::now();
	double durationRecursive = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();


	OM_LOG_INFO("Iteration: Distance from " + std::to_string(source) + " to " + std::to_string(target) + " = " + std::to_string(distancesIterative[target]));
	OM_LOG_INFO("Recursive: Distance from " + std::to_string(source) + " to " + std::to_string(target) + " = " + std::to_string(distancesRecursive[target]));

	OM_LOG_INFO("Iteration: time =  " + std::to_string(durationIterative) + " ms");
	OM_LOG_INFO("Recursive: time =  " + std::to_string(durationRecursive) + " ms");
}

