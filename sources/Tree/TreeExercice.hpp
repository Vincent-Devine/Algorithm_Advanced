#pragma once

#include "Tree/RBT.hpp"

namespace Tree
{
	void TreeExercice()
	{
		RBT tree;

		tree.InsertNode(1);
		tree.InsertNode(2);
		tree.InsertNode(3);
		tree.InsertNode(4);
		tree.InsertNode(5);
		tree.InsertNode(8);
		tree.InsertNode(9);
		tree.InsertNode(10);
		tree.InsertNode(15);
		tree.InsertNode(22);
		tree.InsertNode(18);

		tree.PrintInorder();

		tree.SearchNode(9);
		tree.SearchNode(17);

		tree.DeleteNode(3);
		tree.DeleteNode(8);
		tree.DeleteNode(45);
		tree.DeleteNode(22);

		tree.PrintInorder();
	}
}