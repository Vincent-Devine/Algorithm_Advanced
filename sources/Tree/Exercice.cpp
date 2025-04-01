#include "Tree/Exercice.hpp"

#include <chrono>
#include <OMLogger/Logger.hpp>
#include "Tree/RBT.hpp"
#include "Tree/BST.hpp"

using namespace Tree;

std::chrono::duration<double> elapsedRBT;
std::chrono::duration<double> elapsedBST;

void ExerciceRBT()
{
	auto start = std::chrono::high_resolution_clock::now();

	RBT RBTTree;

	RBTTree.InsertNode(1);
	RBTTree.InsertNode(2);
	RBTTree.InsertNode(3);
	RBTTree.InsertNode(4);
	RBTTree.InsertNode(5);
	RBTTree.InsertNode(8);
	RBTTree.InsertNode(9);
	RBTTree.InsertNode(10);
	RBTTree.InsertNode(15);
	RBTTree.InsertNode(22);
	RBTTree.InsertNode(18);

	RBTTree.PrintInorder();

	RBTTree.SearchNode(9);
	RBTTree.SearchNode(17);

	RBTTree.DeleteNode(3);
	RBTTree.DeleteNode(8);
	RBTTree.DeleteNode(45);
	RBTTree.DeleteNode(22);

	RBTTree.PrintInorder();

	auto end = std::chrono::high_resolution_clock::now();
	elapsedRBT = end - start;
}

void ExerciceBST()
{
	auto start = std::chrono::high_resolution_clock::now();

	BST BSTTree;

	BSTTree.InsertNode(1);
	BSTTree.InsertNode(2);
	BSTTree.InsertNode(3);
	BSTTree.InsertNode(4);
	BSTTree.InsertNode(5);
	BSTTree.InsertNode(8);
	BSTTree.InsertNode(9);
	BSTTree.InsertNode(10);
	BSTTree.InsertNode(15);
	BSTTree.InsertNode(22);
	BSTTree.InsertNode(18);

	BSTTree.PrintInorder();

	BSTTree.SearchNode(9);
	BSTTree.SearchNode(17);

	BSTTree.DeleteNode(3);
	BSTTree.DeleteNode(8);
	BSTTree.DeleteNode(45);
	BSTTree.DeleteNode(22);

	BSTTree.PrintInorder();

	auto end = std::chrono::high_resolution_clock::now();
	elapsedBST = end - start;

	BSTTree.CheckIsBST();
	Node* DLLRoot = BSTTree.BSTToDLL();
	BSTTree.PrintDLL(DLLRoot);
}

void Tree::Exercice()
{
	ExerciceRBT();
	ExerciceBST();

	LOG_INFO("Execution time BST (Binary Search Tree): " + std::to_string(elapsedBST.count()) + " seconds");
	LOG_INFO("Execution time RBT (Red Black Tree): " + std::to_string(elapsedRBT.count()) + " seconds");
}