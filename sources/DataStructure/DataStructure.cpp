#include <unordered_map>
#include <unordered_set>
#include <stack>

#include "OMLogger/Logger.hpp"
#include "Utils/Utils.hpp"
#include "DataStructure/DataStructure.hpp"

namespace DataStructure
{
	void Exercice()
	{
		std::vector<int> dataVectorInt = std::vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };
		int resultInt = DataStructure::FindIndex(dataVectorInt, 43);
		Utils::CheckResult("DataStructure: FindIndex", resultInt, 43);

		dataVectorInt = std::vector<int>{ 0, 0, 1, 2, 2, 3 };
		resultInt = DataStructure::RemoveDuplicates(dataVectorInt);
		Utils::CheckResult("DataStructure: RemoveDuplicates", resultInt, 4);

		dataVectorInt = std::vector<int>{ 2, 7, 11, 15 };
		std::vector<int> resultVector = DataStructure::TwoSum(dataVectorInt, 9);
		Utils::CheckResult("DataStructure: TwoSum", resultVector, { 0, 1 });

		std::string dataString = "([]{})";
		bool resultBool = DataStructure::IsValid(dataString);
		Utils::CheckResult("DataStructure: IsValid", resultBool, true);

		dataVectorInt = std::vector<int>{ 0, 1, 2 };
		ListNode* dataListNode1 = Utils::GenerateList(dataVectorInt);
		dataVectorInt = std::vector<int>{ 3, 4, 5 };
		ListNode* dataListNode2 = Utils::GenerateList(dataVectorInt);
		ListNode* resultListNode = DataStructure::MergeTwoLists(dataListNode1, dataListNode2);
		dataVectorInt = std::vector<int>{ 0, 1, 2, 3, 4, 5 };
		Utils::CheckResult("DataStructure: MergeTwoLists", resultListNode, Utils::GenerateList(dataVectorInt));

		dataString = "abcabcbb";
		resultInt = DataStructure::LengthOfLongestSubstring(dataString);
		Utils::CheckResult("DataStructure: LengthOfLongestSubstring", 3, resultInt);
	}

	int FindIndex(std::vector<int>& nums, int value)
	{
		int iteration = 0;
		int begin = 0;
		int last = nums.size() - 1;
		int middle = last / 2;

		while (begin <= last)
		{
			iteration++;

			if (nums[middle] == value)
			{
				LOG_INFO("Number of iteration: " + std::to_string(iteration));
				return middle;
			}

			if (nums[middle] < value)
				begin = middle + 1;
			else
				last = middle - 1;

			middle = (begin + last) / 2;
		}

		LOG_INFO("Number of iteration: " + std::to_string(iteration));
		return -1;
	}
	
	int RemoveDuplicates(std::vector<int>& tab)
	{
		int j = 1;

		for (int i = 1; i < tab.size(); i++)
		{
			if (tab[i] != tab[i - 1])
			{
				tab[j] = tab[i];
				j++;
			}
		}
		return j;
	}

	std::vector<int> TwoSum(std::vector<int>& nums, int target)
	{
		std::unordered_map<int, int> mapComplement;
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i];
			if (mapComplement.count(complement))
			{
				return{ mapComplement[complement], i };
			}

			mapComplement[nums[i]] = i;
		}

		return { -1, -1 };
	}

	bool IsValid(std::string s)
	{
		std::stack<char> element;
		for (char c : s)
		{
			if ( c == '(' || c == '{' || c == '[')
			{
				element.push(c);
			}
			else
			{
				if ((c == ')' && element.top() != '(') ||
					(c == '}' && element.top() != '{') ||
					(c == ']' && element.top() != '[') ||
					element.empty())
				{
					return false;
				}

				element.pop();
			}
		}
		return element.empty();
	}

	ListNode* MergeTwoLists(ListNode* list1, ListNode* list2)
	{
		if (!list1)
			return list2;

		if (!list2)
			return list1;

		
		if (list1->val < list2->val)
		{
			list1->next = MergeTwoLists(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = MergeTwoLists(list2->next, list1);
			return list2;
		}
	}

	int LengthOfLongestSubstring(std::string s)
	{
		int length = 0;
		int left = 0;

		std::unordered_set<char> subString;

		for (int i = 0; i < s.length(); i++)
		{
			if (subString.count(s[i]) == 0)
			{
				subString.insert(s[i]);
				length = max(length, i - left + 1);
			}
			else
			{
				while (subString.count(s[i]))
				{
					subString.erase(s[left]);
					left++;
				}
				subString.insert(s[i]);
			}
		}
		return length;
	}
}