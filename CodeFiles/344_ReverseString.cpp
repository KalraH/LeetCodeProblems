#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N/2), S: O(1)
 *
 * @def 	2 Pointer Approach.
 *
 * @details 	Taking 2 pointers one at starting of string & another at end of string. Traversing the string half way through & swapping 1st & last element simultaneously.
 */
class Solution
{
public:
	void reverseString(vector<char> &s)
	{
		int i = 0, j = (s.size() - 1);
		while (i < (s.size() / 2))
			swap(s[i++], s[j--]);
	}
};