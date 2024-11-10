#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def		Brute Force.
 *
 * @details	Loop from 1 to N, and keep a track of solution in a variable being multiplied by x.
 */

/**
 * @brief 	Approach-2: T: O(logN), S: O(1)
 *
 * @def		Optimal Solution.
 *
 * @details	We use basic maths. If we have (N)^4 we break it as (NxN)^2 & so on If the power is even, for odd power, we do (N)^3 === N x (N)^2.
 */
class Solution
{
public:
	double myPow(double x, int n)
	{
		double soln = 1.0;
		long long pow = n;

		if (pow < 0)
			pow = (-1 * pow);
		
		while (pow)
		{
			if ( !(pow % 2) )
				x *= x, pow /= 2;
			else
				soln *= x, pow--;
		}
		
		if (n < 0)
			soln = (double)(1.0) / (double)(soln);

		return soln;
	}
};