/* Similar to Question 2244 !! */
#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(2N), S: O(N)
 *
 * @def		Simple Brute-Force with basic Intution of looking at the remainders when any number is divided by 3.
 *
 * @details	We count the number of occurances of each different element of the array. Then we check if the occurances of each different element is divisible by 3. 
 * 		Then we add the result as per the cases:
 * 			-> If the count is completely divisible by 3, we add the Quotient value to the soln.
 * 			-> If the count leaves remainder as 2, we add the Quotient value to the soln as well as we add 1 to the soln for the remainder. 
 * 			-> If the count leaves remainder as 1, we add the (Quotient value - 2) to the soln as well as we add 2 to the soln for the remainder (4).
 */
class Solution
{
private:
	int minOpWithCnt(int currCnt)
	{
		int cnt = 0;

		// If the count is divisible by 3, add the Quotient to the Soln.
		if (currCnt % 3 == 0)
			cnt += (currCnt / 3);

		// If the count divided by 3 leaves remainder 1, add the (Quotient - 1) to the Soln & add 2 for the (remainder + 3) value.
		else if (currCnt % 3 == 1)
		{
			cnt += (currCnt / 3) - 1; 
			cnt += 2;
		}

		// If the count divided by 3 leaves remainder 2, add the Quotient to the Soln as well as add 1 to soln for remainder.
		else if (currCnt % 3 == 2)
		{
			cnt += (currCnt / 3); 
			cnt++;
		}
		return cnt;
	}

public:
	int minOperations(vector<int> &nums)
	{
		int soln = 0;

		// Using Unordered Map to count the occurances of each distinct element.
		unordered_map<int, int> uMap;
		for (auto i: nums)
			uMap[i]++;
		
		for (auto i: uMap)
		{
			// If the count is 1, it can't be divided by 2 or 3. So, return -1.
			if (i.second == 1)
				return -1;

			soln += minOpWithCnt(i.second);
		}
		
		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N + NlogN), S: O(1)
 *
 * @def		Optimizing space by removing map DS.
 *
 * @details	We sort the array initially. Then, we iterate throughout array & count the occurance of each unique element & use the same logic as of previous approach to determine which value is to-be added to soln.
 */
class Solution
{
private:
	int minOpWithCnt(int currCnt)
	{
		int cnt = 0;	

		// If the count is divisible by 3, add the Quotient to the Soln.
		if (currCnt % 3 == 0)
			cnt += (currCnt / 3);

		// If the count divided by 3 leaves remainder 1, add the (Quotient - 1) to the Soln & add 2 for the (remainder + 3) value.
		else if (currCnt % 3 == 1)
		{
			cnt += (currCnt / 3) - 1; 
			cnt += 2;
		}

		// If the count divided by 3 leaves remainder 2, add the Quotient to the Soln as well as add 1 to soln for remainder.
		else if (currCnt % 3 == 2)
		{
			cnt += (currCnt / 3); 
			cnt++;
		}
		return cnt;
	}

public:
	int minOperations(vector<int> &nums)
	{
		// Sorting the array to make it easy to iterate.
		sort(nums.begin(), nums.end());
		int soln = 0, currVal = nums[0], currCnt = 0;

		// Iterating the whole array, counting the occurances of each different element of the array. 
		for (int i = 0; i < nums.size(); i++)
		{
			// When reaching a new element, make it currVal.
			if (currCnt == 0)
				currVal = nums[i];
			
			// Counting the occurance of each element.
			if (nums[i] == currVal)
				currCnt++;
			
			// When reached any different element after counting the occurances.
			else
			{
				// If the count is 1, it can't be divided by 2 or 3. So, return -1.
				if (currCnt == 1)
					return -1;

				soln += minOpWithCnt(currCnt);

				// Resetting currCnt & reducing i by 1 to count the current occurance of new element on which we are as of now.
				currCnt = 0, i--; 
			}
		}

		// Considering the last distinct element's count also for soln.
		if (currCnt == 1)
			return -1;
		else
			soln += minOpWithCnt(currCnt);

		return soln;
	}
};

/**
 * @brief 	Approach-3: T: O(N + NlogN), S: O(1)
 *
 * @def		Just using better mathematics.
 *
 * @details	Just replacing fn calculating Quotient with a better Maths equation.
 */
class Solution
{
public:
	int minOperations(vector<int> &nums)
	{
		// Sorting the array to make it easy to iterate.
		sort(nums.begin(), nums.end());
		int soln = 0, currVal = nums[0], currCnt = 0;

		// Iterating the whole array, counting the occurances of each different element of the array. 
		for (int i = 0; i < nums.size(); i++)
		{
			// When reaching a new element, make it currVal.
			if (currCnt == 0)
				currVal = nums[i];
			
			// Counting the occurance of each element.
			if (nums[i] == currVal)
				currCnt++;
			
			// When reached any different element after counting the occurances.
			else
			{
				// If the count is 1, it can't be divided by 2 or 3. So, return -1.
				if (currCnt == 1)
					return -1;

				soln += (currCnt + 2) / 3;

				// Resetting currCnt & reducing i by 1 to count the current occurance of new element on which we are as of now.
				currCnt = 0, i--; 
			}
		}

		// Considering the last distinct element's count also for soln.
		if (currCnt == 1)
			return -1;
		else
			soln += (currCnt + 2) / 3;

		return soln;
	}
};