#pragma once

namespace Tree
{
	enum Color
	{
		RED,
		BLACK
	};

	inline const char* ColorToString(Color color)
	{
		return (color == Color::RED) ? "RED" : "BLACK";
	}

	struct Node
	{
		int _data;
		Color _color;
		Node* _left;
		Node* _right;
		Node* _parent;

		Node(int data)
			: _data(data), _color(Color::RED), _left(nullptr), _right(nullptr), _parent(nullptr)
		{
		}
	};

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