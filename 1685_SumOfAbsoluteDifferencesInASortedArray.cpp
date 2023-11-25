#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Approach-1: T: O(N^2), S: O(1)
 * 
 * @details Simple Brute-Force. 
 * 
 * Just traverse over the entire array & at each index, calculate the diff of the value on current index with all array elements.
*/
class Solution 
{
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
	{
		int N = nums.size();
		vector<int> result(N, 0);

		int k = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				result[k] += abs( nums[i] - nums[j] );
			k++;
		}
		return result;
	}
};

/**
 * @brief Approach-2: T: O(2N), S: O(2N)
 * 
 * @details Using Suffix & Prefix Sum Arrays with the formula derived after few twikes.
 * 
 * The way to derive below formula is to consier the value which we need to get at any index i, which is:
 * 	result[i] = (nums[i] - nums[0]) + (nums[i] - nums[1]) + ....... + (nums[i] - nums[i-1]) + (nums[i+1] - nums[i]) + (nums[i+2] - nums[i]) + ....... + (nums[N-1] - nums[i])
 * Simplifying the above formula we get:
 * 	result[i] = (nums[i] * i) - {nums[0] + nums[1] + .... + nums[i-1]} + {nums[i+1] + nums[i+2] + .... + nums[N-1]} - {nums[i] * (N - i - 1)}
 * 	result[i] = (nums[i] * i) - {		Prefix Sum 		 } + {		    Suffix Sum		      } - {nums[i] * (N - i - 1)}
 * 
 * Further Simplification gives: 	result[i] === {nums[i] * (2i + 1 - N)} - {Prefix Sum} + {Suffix Sum}
*/
class Solution 
{
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
	{
		int N = nums.size();

		int i = 0, j = N - 1;
		int preSum = 0, sufSum = 0;
		vector<int> prefixSum(N, 0), suffixSum(N, 0);
		
		// Creating Prefix-Sum & Suffix-Sum Arrays
		while (i < N && j >= 0)
		{
			prefixSum[i] = preSum;
			preSum += nums[i++];

			suffixSum[j] = sufSum;
			sufSum += nums[j--];
		}
		
		vector<int> result(N, 0);
		for (int i = 0; i < N; i++)
			result[i] = ( (nums[i] * (2*i + 1 - N) ) + suffixSum[i] - prefixSum[i] );

		return result;
	}
};