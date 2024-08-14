#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N! * N), S: O(1)
 *
 * @def 	Brute Force.
 *
 * @details 	Firstly, we generate all the unique possible permutations of the given array in sorted order. Now, we will perform a linear search in the generated list to
 * 		locate our given array & return the next element of the list. If there is no such element, we will return the 1st element of the generated list.
 */

/**
 * @brief 	Approach-2: T: O(), S: O(1)
 *
 * @def 	Using C++ STL.
 *
 * @details 	Will use the Cpp's standard STL next_permutation() to find the soln. This STL will return the answer to our question directly.
 */
class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		next_permutation(nums.begin(), nums.end());
	}
};

/**
 * @brief 	Approach-3: T: O(N), S: O(1)
 *
 * @def 	Optimal Solution.
 *
 * @details 	First we find the biggest Prefix array by reverse traversing the array & finding the first element bigger than the others at the back, we mark this index
 * 		as breakPointIdx. Now, we re-traverse the array & find the element which is just greater than the element fount at breakPointIdx & swap both elements.
 * 		Now, we reverse the left-over array to the right-hand-side of breakPointIdx. If, we have the array as the last element of all possible next premutations,
 * 		we reverse the input array & return as soln.
 */
class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		if (nums.size() == 1)
			return;

		int breakPointIdx = -1;
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				breakPointIdx = i;
				break;
			}
		}
		
		if (breakPointIdx == -1)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		for (int i = nums.size() - 1; i > breakPointIdx; i--)
		{
			if (nums[i] > nums[breakPointIdx])
			{
				swap(nums[i], nums[breakPointIdx]);
				break;
			}
		}
		reverse(nums.begin() + breakPointIdx + 1, nums.end());
	}
};