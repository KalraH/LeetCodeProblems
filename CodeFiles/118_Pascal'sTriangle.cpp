#include "../HeaderFiles/incLibs.h"

/*
	For questions related to Pascal's triangle, we have 3 possible scenarios:
	1. To find the element at (row, col) index inside triangle.
		-> For this, we have a mathematical formula to give element at any (r, c) index:
		-> (r - 1) C (c - 1) {r -> Row No. / c -> Column No. All indexed to 1
	2. Print any particular row of the triangle.
		-> We observe that for any row x, there are x elements.
		-> So, we can run the loop for each row & find each element in that row. {Brute Force}
	3. Print the entire triangle.
		-> Brute force would be to calculate each element for each row leading to Approach-1 below.
		-> Optimized will be to calculate each row & append it to soln structure leading to Approach-2 below.
 */

/**
 * @brief 	Approach-1: T: O(N * (N * r)), S: O(N^2)
 *
 * @def		Mathematical Formula with Brute Force. {Ques types 1 & 2}
 *
 * @details	To find any element of Pascal's triangle, there's a formula i.e., (r-1) C (c - 1) {r -> Row No. / c -> Column No. All indexed to 1}.
 * 		To find the soln, we can just calculate the element at each index, then add it into a row array & inturn add it to the soln structure.
 */
class Solution
{
private:
	int elementnCr(int n, int r)
	{
		long long val = 1;
		for (int i = 0; i < r; i++)
		{
			val *= (n - i);
			val /= (i + 1);
		}
		return (int)val;
	}

public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> soln;
		for (int i = 1; i <= numRows; i++)
		{
			vector<int> row;
			for (int j = 1; j <= i; j++)
				row.push_back(elementnCr(i, j));
			
			soln.push_back(row);
		}
		return soln;		
	}
};

/**
 * @brief 	Approach-2: T: O(N^2), S: O(N^2)
 *
 * @def		New Mathematical Formula Optimized. {Ques types 2 & 3}
 *
 * @details	After analysis, the formula to calculate all elements for any row is (val * (row - col)) / col. To find the soln, we can just calculate 
 * 		each row, then add it into the soln structure.
 */
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> soln;
		for (int i = 1; i <= numRows; i++)
		{
			int val = 1;
			vector<int> row;
			row.push_back(val);

			for (int j = 1; j < i; j++)
			{
				val *= (i - j);
				val /= j;
				row.push_back(val);
			}
			soln.push_back(row);
		}
		return soln;		
	}
};