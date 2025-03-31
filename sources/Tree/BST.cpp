#include "Tree/BST.hpp"
#include <OMLogger/Logger.hpp>

using namespace Tree;

BST::BST()
	: _root(nullptr)
{
}

void BST::InsertNode(int data)
{
	Node* newNode = new Node(data);

	if (!_root)
	{
		_root = newNode;
		LOG_DEBUG("Insert root " + std::to_string(data));
		return;
	}

	Node* parent = nullptr;
	Node* root = _root;

	while (root)
	{
		parent = root;
		if (data < root->_data)
			root = root->_left;
		else
			root = root->_right;
	}

	newNode->_parent = parent;
	if (data < parent->_data)
		parent->_left = newNode;
	else
		parent->_right = newNode;

	LOG_DEBUG("Insert node " + std::to_string(data));
} 

void BST::SearchNode(int data)
{
	Node* result = Search(_root, data);

	if (result)
	{
		LOG_VALIDATION("Node " + std::to_string(data) + " found in tree");
	}
	else
	{
		LOG_WARNING("Node " + std::to_string(data) + " not found in tree");
	}
}

void BST::DeleteNode(int data)
{
	Node* node = Search(_root, data);
	if (node)
	{
		DeleteNode(node);
		LOG_DEBUG("Delete node: " + std::to_string(data));
	}
	else
	{
		LOG_WARNING("Node " + std::to_string(data) + " not found, can't delete");
	}
}

void BST::PrintInorder()
{
	LOG_DEBUG("-- Print Inorder --");
	Inorder(_root);
}

Node* BST::Search(Node* root, int data)
{
	if (!root || root->_data == data)
		return root;

	if (data < root->_data)
		return Search(root->_left, data);
	return Search(root->_right, data);
}

void BST::DeleteNode(Node* deletedNode)
{
	if (!deletedNode)
		return;

	if (!deletedNode->_left)
		Transplante(deletedNode, deletedNode->_right);
	else if (!deletedNode->_right)
		Transplante(deletedNode, deletedNode->_left);
	else
	{
		Node* minNode = MinNode(deletedNode->_right);
		if (minNode->_parent != deletedNode)
		{
			Transplante(minNode, minNode->_right);
			minNode->_right = deletedNode->_right;
			minNode->_right->_parent = minNode;
		}

		Transplante(deletedNode, minNode);
		minNode->_left = deletedNode->_left;
		minNode->_left->_parent = minNode;
	}

	delete deletedNode;
}

void BST::Transplante(Node* u, Node* v)
{
	if (!u->_parent)
		_root = v;
	else if (u == u->_parent->_left)
		u->_parent->_left = v;
	else
		u->_parent->_right = v;

	if (v)
		v->_parent = u->_parent;
}

Node* BST::MinNode(Node* node)
{
	if (!node)
		return node;

	while (node->_left)
		node = node->_left;

	return node;
}

void BST::Inorder(Node* root)
{
	if (!root)
		return;

	Inorder(root->_left);
	LOG_DEBUG(std::to_string(root->_data));
	Inorder(root->_right);
}