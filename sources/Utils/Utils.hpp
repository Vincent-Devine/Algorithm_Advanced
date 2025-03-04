#include <string>
#include <vector>

#include "Utils/ListNode.hpp"

namespace Utils
{
	void CheckResult(std::string exerciceName, int expectedResult, int obtainedResult);
	void CheckResult(std::string exerciceName, std::vector<int> expectedResult, std::vector<int> obtainedResult);
	void CheckResult(std::string exerciceName, bool expectedResult, bool obtainedResult);
	void CheckResult(std::string exerciceName, ListNode* expectedResult, ListNode* obtainedResult);

	ListNode* GenerateList(const std::vector<int>& nums);
}