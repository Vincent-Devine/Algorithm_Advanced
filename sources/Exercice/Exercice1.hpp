#include <vector>
#include "Utils/ListNode.hpp"

namespace Exercice1
{
	// Algo 1 : Recherche de l�index d�un nombre dans un tableau
	// 
	// Avec un tableau de nombre entiers uniques tri�s dans l�ordre croissant
	// Retournez l�indice du nombre recherch� dans le tableau en faisant le moins d�it�ration possible.

	int FindIndex(std::vector<int>& nums, int value);

	// Algo 2 : Retirer les doublons
	// 
	// Avec un tableau de nombre entiers tri�s dans l�ordre croissant.
	// Supprimez les doublons pour avoir un tableau avec des entiers uniques et dans le m�me ordre. Renvoyez le nombre d��l�ments uniques.
	// Attention : Le nombre d'�l�ments uniques du tableau est k(valeur retourn�e).
	// Modifiez le tableau de telle sorte que les k premiers �l�ments du tableau contiennent les �l�ments uniques dans l'ordre
	// dans lequel ils �taient pr�sents initialement dans le tableau.

	int RemoveDuplicates(std::vector<int>& tab);

	// Algo 3 : Somme de nombre(HashSet or Map)
	// 
	// Avec un tableau d�entier et un entier k, retournez les index des 2 nombres � additionner pour avoir le r�sultat k.
	// Le tableau contient obligatoirement une et unique solution.Le m�me nombre ne peut pas �tre utilis� 2 fois.

	std::vector<int> TwoSum(std::vector<int>& nums, int target);

	// Algo 4 : V�rification des parenth�ses
	// 
	// Avec une cha�ne de caract�res contenant uniquement des(, ), { , }, [et].
	// D�terminez si la cha�ne de caract�res est valide.Elle est valide si :
	// - Les parenth�ses ouverte doivent �tre ferm� avec le m�me type de parenth�se
	// - Les parenth�ses doivent �tre ferm� dans le bon ordre
	// - les parenth�ses ferm�es doivent avoir le m�me type de parenth�se ouverte
	
	bool IsValid(std::string s);

	// Algo 5 : Fusionner 2 listes ordonn�es
	//
	// Fusionner 2 listes ordonn�es.
	// La liste doit �tre faite en r�unissant les n�uds des deux premi�res listes.
	// Retournez le premier �l�ment de la liste fusionn�e.

	ListNode* MergeTwoLists(ListNode* list1, ListNode* list2);

	// Algo 6 : Recherche de la plus longue suite de caract�res sans doublon
	//
	// A partir du cha�ne de caract�res s, trouvez la longueur de la plus longue sous - cha�ne(substring) de caract�re sans doublon
	int LengthOfLongestSubstring(std::string s);
}