#pragma once

#include "Tree/Node.hpp"

namespace Tree
{
	class RBT
	{
		// Attributes
	private:
		Node* _root;

		// Methods
	public:
		RBT();

		void InsertNode(int data);
		void SearchNode(int data);
		void DeleteNode(int data);
		void PrintInorder();

	private:
		void RotateLeft(Node* ptr);
		void RotateRight(Node* ptr);
		void FixInsert(Node* NewNode);
		Node* Search(Node* root, int data);
		void DeleteNode(Node* deletedNode);
		void Transplant(Node* u, Node* v);
		void FixDelete(Node* node);
		Node* MinNode(Node* node);
		void Inorder(Node* root);
	};
}