#pragma once

#include <string>
#include <vector>

#include "DataStructure/ListNode.hpp"

namespace DataStructure
{
	void Exercice();

	int FindIndex(std::vector<int>& nums, int value);
	int RemoveDuplicates(std::vector<int>& tab);
	std::vector<int> TwoSum(std::vector<int>& nums, int target);
	bool IsValid(std::string s);
	ListNode* MergeTwoLists(ListNode* list1, ListNode* list2);
	int LengthOfLongestSubstring(std::string s);
}