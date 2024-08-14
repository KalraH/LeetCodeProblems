#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^3), S: O(1)
 *
 * @def		Brute Force.
 *
 * @details	We traverse via the given array & we take every sub-array & calculate the sum of all elements in it & return the max calculated sum as soln.
 */
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		if (nums.size() <= 1)
			return nums[0];

		int soln = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i; j < nums.size(); j++)
			{
				int sum = 0;
				for (int k = i; k <= j; k++)
					sum += nums[k];

				soln = max(soln, sum);
			}
		}
		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N^2), S: O(1)
 *
 * @def		Optimized Brute Force.
 *
 * @details	We traverse via the given array & calculate the sum of all possible sub-arrays while traversing in the second loop & return the max calculated sum as soln.
 */
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		if (nums.size() <= 1)
			return nums[0];

		int soln = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0;
			for (int j = i; j < nums.size(); j++)
			{
				sum += nums[j];
				soln = max(soln, sum);
			}
		}
		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N), S: O(1)
 *
 * @def		Optimal Solution. KADANE's ALGO !!
 *
 * @details	We are going to traverse the array & keep a maxSum variable storing the max sum value encountered till this index, we also keep a temporary sum variable to
 * 		store the current sum. While traversing the array, if at any moment, the sum is -ve, we reset it to 0, else we continue to traverse checking for the max
 * 		sum till now. At the end, we have the final solution. 
 * 		This above approach to keep 2 variables (maxSum till now & temp Sum), traverse the array & reset the temp sum whenever the sum is -ve, else continue with
 * 		finding the maxSum till the end of traversal is known as KADANE's ALGO.
 */
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		if (nums.size() <= 1)
			return nums[0];

		int maxSum = INT_MIN, sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			maxSum = max(maxSum, sum);

			if (sum < 0)
				sum = 0;
		}
		return maxSum;
	}
};