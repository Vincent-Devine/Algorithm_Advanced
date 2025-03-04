#include "Utils/Utils.hpp"

#include "OMLogger/Logger.hpp"

namespace Utils
{
	void CheckResult(std::string exerciceName, int expectedResult, int obtainedResult)
	{
		if (expectedResult == obtainedResult)
		{
			LOG_VALIDATION(exerciceName + " - Done");
		}
		else
		{
			LOG_ERROR(exerciceName + " - Failed");
		}
	}

	void CheckResult(std::string exerciceName, std::vector<int> expectedResult, std::vector<int> obtainedResult)
	{
		if (expectedResult == obtainedResult)
		{
			LOG_VALIDATION(exerciceName + " - Done");
		}
		else
		{
			LOG_ERROR(exerciceName + " - Failed");
		}
	}

	void CheckResult(std::string exerciceName, bool expectedResult, bool obtainedResult)
	{
		if (expectedResult == obtainedResult)
		{
			LOG_VALIDATION(exerciceName + " - Done");
		}
		else
		{
			LOG_ERROR(exerciceName + " - Failed");
		}
	}

	bool CheckResult(ListNode* expectedResult, ListNode* obtainedResult)
	{
		if (expectedResult->val != obtainedResult->val)
			return false;

		if (expectedResult->next)
		{
			if (obtainedResult->next)
				return CheckResult(expectedResult->next, obtainedResult->next);
			else
				return false;
		}
		else if (obtainedResult->next)
			return false;

		return true;
	}

	void CheckResult(std::string exerciceName, ListNode* expectedResult, ListNode* obtainedResult)
	{
		if (CheckResult(expectedResult, obtainedResult))
		{
			LOG_VALIDATION(exerciceName + " - Done");
		}
		else
		{
			LOG_ERROR(exerciceName + " - Failed");
		}
	}

	ListNode* GenerateList(const std::vector<int>& nums)
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
