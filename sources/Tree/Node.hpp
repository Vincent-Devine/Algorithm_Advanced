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
}
