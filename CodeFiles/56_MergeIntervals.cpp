#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(NlogN + 2N), S: O(N)
 *
 * @def 	Brute Force. Using Extra Space.
 *
 * @details	First we sort the given array then, we create a new array to store solution. Then we traverse the array with few conditions in mind:
 * 			If at any index we encounter soln array is non-empty & current element's end is smaller than the last added into solution, we can skip that element 
 * 			as its already been taken care in the earlier traversals.
 * 		Now, we take a 2nd loop to iterate into the given arrays to find all the overlapping elements. 
 */
class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		int N = intervals.size();
		vector<vector<int>> soln;

		sort(intervals.begin(), intervals.end());
		for (int i = 0; i < N; i++)
		{
			int start = intervals[i][0], end = intervals[i][1];
			if ( !soln.empty() && (end <= soln.back()[1]))
				continue;

			for (int j = (i + 1); j < N; j++)
			{
				if (intervals[j][0] <= end)
					end = max(end, intervals[j][1]);
				else
					break;
			}
			soln.push_back({start, end});
		}
		return soln;
	}
};

/**
 * @brief 	Approach-1: T: O(NlogN + 2N), S: O(N)
 *
 * @def 	Optimal Solution.
 *
 * @details	First we sort the given array then, we create a new array to store solution. Then we traverse the array with few conditions in mind:
 * 			If the soln array is empty OR we encounter start range of a new interval > end range of last element in soln array, we add it as a new interval.
 * 			If we get an overlapping interval, we update the end range of last added element in soln array as per the max of the end range of the interval.
 */
class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		int N = intervals.size();
		vector<vector<int>> soln;
		
		sort(intervals.begin(), intervals.end()); 
		for (int i = 0; i < N; i++)
		{
			if ( soln.empty() || (intervals[i][0] > soln.back()[1]))
				soln.push_back(intervals[i]);
			else
				soln.back()[1] = max(soln.back()[1], intervals[i][1]);
		}
		return soln;
	}
};