/* Similar to Question 2870 !! */
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
public:
	int minimumRounds(vector<int>& tasks)
	{
		int soln = 0;

		// Using Unordered Map to count the occurances of each distinct element.
		unordered_map<int, int> uMap;
		for (auto i: tasks)
			uMap[i]++;
		
		for (auto i: uMap)
		{
			// If the count is 1, it can't be divided by 2 or 3. So, return -1.
			if (i.second == 1)
				return -1;

			soln += (i.second + 2) / 3;
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
public:
	int minimumRounds(vector<int>& tasks)
	{
		// Sorting the array to make it easy to iterate.
		sort(tasks.begin(), tasks.end());
		int soln = 0, currVal = tasks[0], currCnt = 0;

		// Iterating the whole array, counting the occurances of each different element of the array. 
		for (int i = 0; i < tasks.size(); i++)
		{
			// When reaching a new element, make it currVal.
			if (currCnt == 0)
				currVal = tasks[i];
			
			// Counting the occurance of each element.
			if (tasks[i] == currVal)
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