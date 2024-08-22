#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^2), S: O(1)
 *
 * @def 	Brute Force.
 *
 * @details 	Traverse the array with compairing each element with other to look for duplicates.
 */
class Solution
{
public:
	int findDuplicate(vector<int> &nums)
	{
		int soln = nums[nums.size() - 1];

		for (int i = 0; i < nums.size(); i++)
			for (int j = (i + 1); j < nums.size(); j++)
				if (nums[i] == nums[j])
					return nums[i];

		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N + NlogN), S: O(1)
 *
 * @def 	Optimized Brute Force.
 *
 * @details 	Sort the array & them traverse it looking for any repeated entry. Its our solution.
 */
class Solution
{
public:
	int findDuplicate(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		
		int temp = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == temp)
				return nums[i];
			else
				temp = nums[i];
		}
		return nums[nums.size() - 1];
	}
};

/**
 * @brief 	Approach-3: T: O(N), S: O(N)
 *
 * @def 	Better Solution. Using extra space.
 *
 * @details 	We create a frequency array to store the fequency of each element. As soon as we encounter that an element is aready found, we return it as the duplicate 
 * 		array.
 */
class Solution
{
public:
	int findDuplicate(vector<int> &nums)
	{
		vector<int> temp(nums.size(), 0);
		for (auto i: nums)
		{
			if (temp[i] != 0)
				return i;
			else
				temp[i]++;
		}
		return nums[nums.size() - 1];
	}
};

/**
 * @brief 	Approach-4: T: O(N), S: O(1)
 *
 * @def 	Optimal Solution. LINKED LIST CYCLE METHOD !!
 *
 * @details 	We take 2 pointers slow & fast (Tortoise & Heir Method), we keep both at start of array initially. Now, we move them as follows:
 * 			Slow moves 1 step at a time & Fast moves 2 steps at a time BUT, in way to include the above mentioned method to solve this question, pointers move
 * 			as at index idx, pointers moves to arr[idx] as 1 step movement.
 * 		At the 1st collision point of both pointers, we move fast pointer to arr[0] & then both pointers move 1 step at a time untill they meet again. At the 2nd
 * 		meetup point, we get the duplicate element.
 */
class Solution
{
public:
	int findDuplicate(vector<int> &nums)
	{
		int slow = nums[0], fast = nums[0];
		do
		{
			slow = nums[slow], fast = nums[nums[fast]];
		} while (slow != fast);
		
		fast = nums[0];
		while (slow != fast)
			slow = nums[slow], fast = nums[fast];
			
		return slow;
	}
};