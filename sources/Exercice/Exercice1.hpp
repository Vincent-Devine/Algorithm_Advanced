#include <vector>
#include "Utils/ListNode.hpp"

namespace Exercice1
{
	// Algo 1 : Recherche de l’index d’un nombre dans un tableau
	// 
	// Avec un tableau de nombre entiers uniques triés dans l’ordre croissant
	// Retournez l’indice du nombre recherché dans le tableau en faisant le moins d’itération possible.

	int FindIndex(std::vector<int>& nums, int value);

	// Algo 2 : Retirer les doublons
	// 
	// Avec un tableau de nombre entiers triés dans l’ordre croissant.
	// Supprimez les doublons pour avoir un tableau avec des entiers uniques et dans le même ordre. Renvoyez le nombre d’éléments uniques.
	// Attention : Le nombre d'éléments uniques du tableau est k(valeur retournée).
	// Modifiez le tableau de telle sorte que les k premiers éléments du tableau contiennent les éléments uniques dans l'ordre
	// dans lequel ils étaient présents initialement dans le tableau.

	int RemoveDuplicates(std::vector<int>& tab);

	// Algo 3 : Somme de nombre(HashSet or Map)
	// 
	// Avec un tableau d’entier et un entier k, retournez les index des 2 nombres à additionner pour avoir le résultat k.
	// Le tableau contient obligatoirement une et unique solution.Le même nombre ne peut pas être utilisé 2 fois.

	std::vector<int> TwoSum(std::vector<int>& nums, int target);

	// Algo 4 : Vérification des parenthèses
	// 
	// Avec une chaîne de caractères contenant uniquement des(, ), { , }, [et].
	// Déterminez si la chaîne de caractères est valide.Elle est valide si :
	// - Les parenthèses ouverte doivent être fermé avec le même type de parenthèse
	// - Les parenthèses doivent être fermé dans le bon ordre
	// - les parenthèses fermées doivent avoir le même type de parenthèse ouverte
	
	bool IsValid(std::string s);

	// Algo 5 : Fusionner 2 listes ordonnées
	//
	// Fusionner 2 listes ordonnées.
	// La liste doit être faite en réunissant les nœuds des deux premières listes.
	// Retournez le premier élément de la liste fusionnée.

	ListNode* MergeTwoLists(ListNode* list1, ListNode* list2);

	// Algo 6 : Recherche de la plus longue suite de caractères sans doublon
	//
	// A partir du chaîne de caractères s, trouvez la longueur de la plus longue sous - chaîne(substring) de caractère sans doublon
	int LengthOfLongestSubstring(std::string s);
}