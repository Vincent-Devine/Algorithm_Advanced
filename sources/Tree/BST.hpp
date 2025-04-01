#pragma once

#include "Tree/Node.hpp"

namespace Tree
{
	class BST
	{
		// Attributes
	private:
		Node* _root;

		// Methods
	public:
		BST();

		void InsertNode(int data);
		void SearchNode(int data);
		void DeleteNode(int data);
		void PrintInorder();
		bool IsBST(Node* root);
		void CheckIsBST();
		Node* BSTToDLL(); // DLL (Double Linked List)
		void PrintDLL(Node* root);

		Node* GetRoot() { return _root; }

	private:
		Node* Search(Node* root, int data);
		void DeleteNode(Node* deletedNode);
		void Transplante(Node* u, Node* v);
		Node* MinNode(Node* node);
		void Inorder(Node* root);
		void ConvertBSTToDLL(Node* root, Node*& head, Node* tail);
	};
}