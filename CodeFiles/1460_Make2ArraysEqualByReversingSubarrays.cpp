#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(Nlog), S: O(1)
 *
 * @def 	Just making sure both arrays have same element.
 *
 * @details 	Sorting both arrays & compairing if both have same elements. If the arrays have same elements, we cam perform n number 
 * 		of swaps to make arr same as target.
 */
class Solution
{
public:
	bool canBeEqual(vector<int> &target, vector<int> &arr)
	{
		sort(arr.begin(), arr.end());
		sort(target.begin(), target.end());

		for (int i = 0; i < target.size(); i++)
			if (arr[i] != target[i])
				return false;
		return true;
	}
};