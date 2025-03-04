#include <unordered_map>
#include <unordered_set>
#include <stack>

#include "OMLogger/Logger.hpp"
#include "Exercice/Exercice1.hpp"

namespace Exercice1
{
	// Algo 1 : Recherche de l�index d�un nombre dans un tableau
	// 
	// Avec un tableau de nombre entiers uniques tri�s dans l�ordre croissant
	// Retournez l�indice du nombre recherch� dans le tableau en faisant le moins d�it�ration possible.

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

	// Algo 2 : Retirer les doublons
	// 
	// Avec un tableau de nombre entiers tri�s dans l�ordre croissant.
	// Supprimez les doublons pour avoir un tableau avec des entiers uniques et dans le m�me ordre. Renvoyez le nombre d��l�ments uniques.
	// Attention : Le nombre d'�l�ments uniques du tableau est k(valeur retourn�e).
	// Modifiez le tableau de telle sorte que les k premiers �l�ments du tableau contiennent les �l�ments uniques dans l'ordre
	// dans lequel ils �taient pr�sents initialement dans le tableau.
	
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

	// Algo 3 : Somme de nombre(HashSet or Map)
	// 
	// Avec un tableau d�entier et un entier k, retournez les index des 2 nombres � additionner pour avoir le r�sultat k.
	// Le tableau contient obligatoirement une et unique solution.Le m�me nombre ne peut pas �tre utilis� 2 fois.
	
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

	// Algo 4 : V�rification des parenth�ses
	// 
	// Avec une cha�ne de caract�res contenant uniquement des(, ), { , }, [et].D�terminez si la cha�ne de caract�res est valide.Elle est valide si :
	// Les parenth�ses ouverte doivent �tre ferm� avec le m�me type de parenth�se
	// Les parenth�ses doivent �tre ferm� dans le bon ordre
	// les parenth�ses ferm�es doivent avoir le m�me type de parenth�se ouverte
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

	// Algo 5 : Fusionner 2 listes ordonn�es
	//
	// Fusionner 2 listes ordonn�es.
	// La liste doit �tre faite en r�unissant les n�uds des deux premi�res listes.
	// Retournez le premier �l�ment de la liste fusionn�e.

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

	// Algo 6 : Recherche de la plus longue suite de caract�res sans doublon
	//
	// A partir du cha�ne de caract�res s, trouvez la longueur de la plus longue sous - cha�ne(substring) de caract�re sans doublon
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