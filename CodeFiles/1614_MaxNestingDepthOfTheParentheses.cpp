#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def 	Simple Brute-Force.
 *
 * @details 	Just traverse over the entire string, keep a max Depth Count & Current Depth count variables. Check at every index if the element is,
 * 			-> "(": Increase the Current Depth Count by 1, also, check if in any case the count increases the max count, update the max Depth Count
 * 			-> ")": Decrease the Current Depth Count by 1.
 */
class Solution
{
public:
	int maxDepth(string s)
	{
		int soln = 0, currDepth = 0;
		for (char i : s)
		{
			if (i == '(')
			{
				currDepth++;
				soln = max(soln, currDepth);
			}
			else if (i == ')')
				currDepth--;
		}
		return soln;
	}
};