#include <iostream>
#include <vector>

#include "OMLogger/Logger.hpp"
#include "Utils/Utils.hpp"
#include "Exercice/Exercice1.hpp"
#include "Tree/Exercice.hpp"

int main()
{
	// Exercice 1 - Algo 1
    std::vector<int> dataVectorInt = std::vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };
	int resultInt = Exercice1::FindIndex(dataVectorInt, 43);
	Utils::CheckResult("Exercice1: FindIndex", resultInt, 43);

	// Exercice 1 - Algo 2
	dataVectorInt = std::vector<int>{ 0, 0, 1, 2, 2, 3 };
	resultInt = Exercice1::RemoveDuplicates(dataVectorInt);
	Utils::CheckResult("Exercice1: RemoveDuplicates", resultInt, 4);

	// Exercice 1 - Algo 3
	dataVectorInt = std::vector<int>{ 2, 7, 11, 15 };
	std::vector<int> resultVector = Exercice1::TwoSum(dataVectorInt, 9);
	Utils::CheckResult("Exercice1: TwoSum", resultVector, {0, 1});

	// Exercice 1 - Algo 4
	std::string dataString = "([]{})";
	bool resultBool = Exercice1::IsValid(dataString);
	Utils::CheckResult("Exercice1: IsValid", resultBool, true);

	// Exercice 1 - Algo 5
	dataVectorInt = std::vector<int>{ 0, 1, 2 };
	ListNode* dataListNode1 = Utils::GenerateList(dataVectorInt);
	dataVectorInt = std::vector<int>{ 3, 4, 5 };
	ListNode* dataListNode2 = Utils::GenerateList(dataVectorInt);
	ListNode* resultListNode = Exercice1::MergeTwoLists(dataListNode1, dataListNode2);
	dataVectorInt = std::vector<int>{ 0, 1, 2, 3, 4, 5 };
	Utils::CheckResult("Exercice1: MergeTwoLists", resultListNode, Utils::GenerateList(dataVectorInt));

	// Exercice 1 - Algo 6
	dataString = "abcabcbb";
	resultInt = Exercice1::LengthOfLongestSubstring(dataString);
	Utils::CheckResult("Exercice1: LengthOfLongestSubstring", 3, resultInt);

	Tree::Exercice();
}