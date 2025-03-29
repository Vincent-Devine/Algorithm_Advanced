#include "Tree/RBT.hpp"

#include <OMLogger/Logger.hpp>

using namespace Tree;

RBT::RBT()
	: _root(nullptr)
{
}

void RBT::InsertNode(int data)
{
	Node* newNode = new Node(data);
	
	if (!_root)
	{
		_root = newNode;
		_root->_color = Color::BLACK;
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
	FixInsert(newNode);
}

void RBT::SearchNode(int data)
{
	Node* result = Search(_root, data);
	
	if (result)
	{
		LOG_VALIDATION("Node " + std::to_string(data) + " found in tree.");
	}
	else
	{
		LOG_WARNING("Node " + std::to_string(data) + " not found in tree.");
	}
}

void RBT::DeleteNode(int data)
{
	Node* node = Search(_root, data);
	if(node)
	{
		DeleteNode(node);
		LOG_DEBUG("Delete node: " + std::to_string(data));
	}
	else
	{
		LOG_WARNING("Node " + std::to_string(data) + " not found, can't delete");
	}
}

void RBT::PrintInorder()
{
	LOG_DEBUG("-- Print Inorder --");
	Inorder(_root);
}

void RBT::RotateLeft(Node* ptr)
{
	Node* rightChild = ptr->_right;
	ptr->_right = rightChild->_left;

	if (ptr->_right)
		ptr->_right->_parent = ptr;

	rightChild->_parent = ptr->_parent;
	if (!ptr->_parent)
		_root = rightChild;
	else if (ptr == ptr->_parent->_left)
		ptr->_parent->_left = rightChild;
	else
		ptr->_parent->_right = rightChild;

	rightChild->_left = ptr;
	ptr->_parent = rightChild;
}

void RBT::RotateRight(Node* ptr)
{
	Node* leftChild = ptr->_left;
	ptr->_left = leftChild->_right;

	if (ptr->_left)
		ptr->_left->_parent = ptr;

	leftChild->_parent = ptr->_parent;
	if (!ptr->_parent)
		_root = leftChild;
	else if (ptr == ptr->_parent->_left)
		ptr->_parent->_left = leftChild;
	else
		ptr->_parent->_right = leftChild;

	leftChild->_right = ptr;
	ptr->_parent = leftChild;
}

void RBT::FixInsert(Node* newNode)
{
	while (newNode->_parent && newNode->_parent->_color == Color::RED)
	{
		Node* grandparent = newNode->_parent->_parent;
		if (newNode->_parent == grandparent->_left)
		{
			Node* uncle = grandparent->_right;
			if (uncle && uncle->_color == Color::RED)
			{
				newNode->_parent->_color = Color::BLACK;
				uncle->_color = Color::BLACK;
				grandparent->_color = Color::RED;
				newNode = grandparent;
			}
			else
			{
				if (newNode == newNode->_parent->_right)
				{
					newNode = newNode->_parent;
					RotateLeft(newNode);
				}
				newNode->_parent->_color = Color::BLACK;
				grandparent->_color = Color::RED;
				RotateRight(grandparent);
			}
		}
		else
		{
			Node* uncle = grandparent->_left;
			if (uncle && uncle->_color == Color::RED)
			{
				newNode->_parent->_color = Color::BLACK;
				uncle->_color = Color::BLACK;
				grandparent->_color = Color::RED;
				newNode = grandparent;
			}
			else
			{
				if (newNode == newNode->_parent->_left)
				{
					newNode = newNode->_parent;
					RotateRight(newNode);
				}
				newNode->_parent->_color = Color::BLACK;
				grandparent->_color = Color::RED;
				RotateLeft(grandparent);
			}
		}
	}
	_root->_color = Color::BLACK;
}

Node* RBT::Search(Node * root, int data)
{
	if (!root || root->_data == data)
		return root;

	if (data < root->_data)
		return Search(root->_left, data);
	return Search(root->_right, data);
}

void RBT::DeleteNode(Node* deletedNode)
{
	if (!deletedNode)
		return;

	Node* u = deletedNode;
	Color originalColor = u->_color;
	Node* v;

	if (!deletedNode->_left)
	{
		v = deletedNode->_right;
		Transplant(deletedNode, deletedNode->_right);
	}
	else if (!deletedNode->_right)
	{
		v = deletedNode->_left;
		Transplant(deletedNode, deletedNode->_left);
	}
	else
	{
		u = MinNode(deletedNode->_left);
		originalColor = u->_color;
		v = u->_right;
		
		if (u->_parent == deletedNode && v)
		{
			v->_parent = u;
		}
		else
		{
			Transplant(u, u->_right);
			u->_right = deletedNode->_right;
			u->_right->_parent = u;
		}

		Transplant(deletedNode, u);
		if (deletedNode->_left)
		{
			u->_left = deletedNode->_left;
			u->_left->_parent = u;
			u->_color = deletedNode->_color;
		}
	}

	delete deletedNode;
	if (originalColor == Color::BLACK && v)
		FixDelete(v);
}

void RBT::Transplant(Node* u, Node* v)
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

void RBT::FixDelete(Node* node)
{
	while (node != _root && (!node || node->_color == Color::BLACK))
	{
		if (node == node->_parent->_left)
		{
			Node* temp = node->_parent->_right;
			if (temp->_color == Color::RED)
			{
				temp->_color = Color::BLACK;
				node->_parent->_color = Color::RED;
				RotateLeft(node->_parent);
				temp = node->_parent->_right;
			}
			
			if ((!temp->_left || temp->_left->_color == Color::BLACK) && (!temp->_right || temp->_right->_color == Color::BLACK))
			{
				temp->_color = Color::RED;
				node = node->_parent;
			}
			else
			{
				if (!temp->_right || temp->_right->_color == Color::BLACK)
				{
					if (temp->_left)
						temp->_left->_color = Color::BLACK;

					temp->_left->_color = Color::RED;
					RotateRight(temp);
					temp = node->_parent->_right;
				}

				temp->_color = node->_parent->_color;
				node->_parent->_color = Color::BLACK;
				if (temp->_right)
					temp->_right->_color = Color::BLACK;

				RotateLeft(node->_parent);
				node = _root;
			}
		}
		else
		{
			Node* temp = node->_parent->_left;
			if (temp->_color == Color::RED)
			{
				temp->_color = Color::BLACK;
				node->_parent->_color = Color::RED;
				RotateRight(node->_parent);
				temp = node->_parent->_left;
			}

			if ((!temp->_right || temp->_right->_color == Color::BLACK) && (!temp->_left || temp->_left->_color == Color::BLACK))
			{
				temp->_color = Color::RED;
				node = node->_parent;
			}
			else
			{
				if (!temp->_left || temp->_left->_color == Color::BLACK)
				{
					if (temp->_right)
						temp->_right->_color = Color::BLACK;
					temp->_color = Color::RED;
					RotateLeft(temp);
					temp = node->_parent->_left;
				}

				temp->_color = node->_parent->_color;
				node->_parent->_color = Color::BLACK;
				if (temp->_left)
					temp->_left->_color = Color::BLACK;
				RotateRight(node->_parent);
				node = _root;
			}
		}
	}

	if (node)
		node->_color = Color::BLACK;
}

Node* RBT::MinNode(Node* node)
{
	if (!node)
		return node;

	while (node->_left)
		node = node->_left;

	return node;
}

void RBT::Inorder(Node* root)
{
	if (!root)
		return;

	Inorder(root->_left);
	LOG_DEBUG(std::to_string(root->_data) + " - " + ColorToString(root->_color));
	Inorder(root->_right);
}