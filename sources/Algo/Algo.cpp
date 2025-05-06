#include "Algo/Algo.hpp"

#include <vector>
#include <unordered_set>
#include <OMLogger/Logger.hpp>

using namespace Algo;

int MajorityElement(std::vector<int>& nums)
{
	int count = 0;
	int candidate = 0;

	for (int num : nums)
	{
		if (count == 0)
			candidate = num;

		count += (num == candidate) ? 1 : -1;
	}

	return candidate;
}

int ClimbStair(int n)
{
	if(n <= 2)
		return n;

	int first = 1;
	int second = 2;

	for (int i = 3; i <= n; ++i)
	{
		int temp = first + second;
		first = second;
		second = temp;
	}

	return second;
}

std::string LongestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.empty())
		return "";

	std::string prefix = strs[0];

	for (int i = 1; i < strs.size(); ++i)
	{
		while (strs[i].find(prefix) != 0)
		{
			prefix = prefix.substr(0, prefix.size() - 1);
			if (prefix.empty())
				return "";
		}
	}

	return prefix;
}

bool IsValidSudoku(std::vector<std::vector<char>>& board)
{
	std::unordered_set<int> rows[9];
	std::unordered_set<int> cols[9];
	std::unordered_set<int> boxes[9];

	for (int r = 0; r < 9; ++r)
	{
		for (int c = 0; c < 9; ++c)
		{
			if (board[r][c] == '.')
				continue;

			char value = board[r][c];
			int boxeIndex = (r / 3) * 3 + (c / 3);

			if (rows[r].count(value) || cols[c].count(value) || boxes[boxeIndex].count(value))
				return false;

			rows[r].insert(value);
			cols[c].insert(value);
			boxes[boxeIndex].insert(value);
		}
	}

	return true;
}

void Algo::Exercice()
{
	const int RESULT_MAJORITY_ELEMENT = 3;
	std::vector<int> nums = { 3, 2, 3 };
	if (MajorityElement(nums) == RESULT_MAJORITY_ELEMENT)
	{
		OM_LOG_INFO("Majority Element - Done");
	}
	else
	{
		OM_LOG_WARNING("Majority Element - Failed");
	}

	const int RESULT_CLIMB_STAIRS = 3;
	if (ClimbStair(3) == RESULT_CLIMB_STAIRS)
	{
		OM_LOG_INFO("Climb Stais - Done");
	}
	else
	{
		OM_LOG_WARNING("Climb Stais - Failed");
	}

	const std::string RESULT_LONGEST_COMMON_PREFIX = "fl";
	std::vector<std::string> strs = { "flower", "flow", "flight" };
	if (LongestCommonPrefix(strs) == RESULT_LONGEST_COMMON_PREFIX)
	{
		OM_LOG_INFO("Longest Common Prefix - Done");
	}
	else
	{
		OM_LOG_WARNING("Longest Common Prefix - Failed");
	}

	const bool RESULT_IS_VALID_SUDOKU = true;
	std::vector<std::vector<char>> board =
	{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
	 ,{'6', '.', '.', '1', '9', '5', '.', '.', '.'}
	 ,{'.', '9', '8', '.', '.', '.', '.', '6', '.'}
	 ,{'8', '.', '.', '.', '6', '.', '.', '.', '3'}
	 ,{'4', '.', '.', '8', '.', '3', '.', '.', '1'}
	 ,{'7', '.', '.', '.', '2', '.', '.', '.', '6'}
	 ,{'.', '6', '.', '.', '.', '.', '2', '8', '.'}
	 ,{'.', '.', '.', '4', '1', '9', '.', '.', '5'}
	 ,{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	if (IsValidSudoku(board) == RESULT_IS_VALID_SUDOKU)
	{
		OM_LOG_INFO("Is Valid Sudoku - Done");
	}
	else
	{
		OM_LOG_WARNING("Is Valid Sudoku - Failed");
	}
}