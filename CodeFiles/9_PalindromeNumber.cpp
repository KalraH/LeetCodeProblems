#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(log10(N)), S: O(1)
 *
 * @def		Simple Brute force.
 *
 * @details	We simply generate -ve of the input, keep a copy of input & compare the reverse no with the input. If they are same, the input is palindrome.
 */
class Solution
{
public:
	bool isPalindrome(int x)
	{
		long revNo = 0, dup = x;
		while (x > 0)
		{
			revNo = (revNo * 10) + (x % 10);
			x /= 10;
		}
		return (revNo == dup) ? true : false;
	}
};