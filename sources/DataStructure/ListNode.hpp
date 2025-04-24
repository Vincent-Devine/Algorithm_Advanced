#pragma once

namespace DataStructure
{
	struct ListNode
	{
		int val;
		ListNode* next = nullptr;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	inline ListNode* GenerateList(const std::vector<int>& nums)
	{
		if (nums.size() == 0)
			return nullptr;

		ListNode* tmp = new ListNode(nums[0]);
		ListNode* head = tmp;

		for (int i = 1; i < nums.size(); i++)
		{
			tmp->next = new ListNode(nums[i]);
			tmp = tmp->next;
		}
		return head;
	}
}