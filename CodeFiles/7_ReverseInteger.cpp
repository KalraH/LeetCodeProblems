#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(log10(N)), S: O(1)
 *
 * @def		Simply extracting digits of number.
 *
 * @details	We simply extract the digits of input using (x = x % 10), then we add them into soln with a condition that we multiply soln by 10 before adding next digit.
 */
class Solution
{
public:
	int reverse(int x)
	{
		if ((x < 10) && (x > -10))
			return x;

		long inpt = x;
		int isNegFlag = 0;
		if (x < 0)
			isNegFlag = 1, inpt *= (-1);

		long revNo = 0;
		while (inpt > 0)
		{
			revNo = (revNo * 10) + (inpt % 10);
			inpt /= 10;
			
			if (revNo > INT_MAX)
				return 0;
		}
		return (isNegFlag) ? (revNo * (-1)) : revNo;
	}
};