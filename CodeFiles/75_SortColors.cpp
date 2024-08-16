#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(NlogN), S: O(N)
 *
 * @def 	Using C++'s STL of Sorting the array. Merge Sort !!
 *
 * @details 	We use the STL & sort the array. Then, we retuen the sorted array as soln.
 */

/**
 * @brief 	Approach-2: T: O(2N), S: O(1)
 *
 * @def 	Optimized Brute Force Solution.
 *
 * @details 	We will keep 3 variables to store the count of 0s, 1s & 2s in the given array. Now, we traverse the array & increase the count respectively. Now, we
 * 		traverse the array again & this time we replace the elements in the array as 1st, we fill the 0s as per the count, then 1s & 2s respectively.
 */

/**
 * @brief 	Approach-3: T: O(N), S: O(1)
 *
 * @def 	Optimal Solution. DUTCH NATIONAL FLAG ALGO !!
 *
 * @details	The algo state to take 3 pointers (low, mid & high). We keep the low & mid pointers at start of array & high at the end. We follow 3 rules of the algo:
 * 			At any point in the array while traversal
 * 			--> Array b/w indexes 0 to (mid - 1) is sorted
 * 			--> Array b/w indexes mid to high is unsorted.
 * 			--> Array b/w indexes 0 to (low - 1) has all 0s.
 * 			--> Array b/w indexes low to (mid - 1) has all 1s.
 * 			--> Array b/w indexes (high + 1) to (N - 1) has all 2s.
 * 		We follow these rules and perform the swapping as we go untill mid pointer crocesses high.
 */
class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		if (nums.size() <= 1)	
			return;
		
		int low = 0, mid = 0, high = (nums.size() - 1);
		while (mid <= high)
		{
			if (nums[mid] == 0)
			{
				swap(nums[mid], nums[low]);
				low++, mid++;
			}
			else if (nums[mid] == 1)
				mid++;
			else if (nums[mid] == 2)
			{
				swap(nums[mid], nums[high]);
				high--;
			}
		}
		return;
	}
};