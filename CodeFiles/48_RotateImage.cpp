#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^2), S: O(N^2)
 *
 * @def 	Brute Force. Using Extra Space.
 *
 * @details 	We create a new solution matrix. We traverse the given matrix & fill the solution matrix in a way that the solution matrix is 90 degree rotated. For this
 * 		I deduced a formula: 
 * 					tempM[j][N - i - 1] = matrix[i][j]
 * 		Now, we re-write the input matrix.
 */
class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int N = matrix.size();
		vector<vector<int>> tempM(N, vector<int>(N, 0));

		if (N <= 1)
			return;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				tempM[j][N - i - 1] = matrix[i][j];
		
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				matrix[i][j] = tempM[i][j];
	}
};

/**
 * @brief 	Approach-2: T: O(N^2), S: O(1)
 *
 * @def 	Optimal Solution.
 *
 * @details 	First we transpose the given input matrix by swapping every diagonally opposite element going row wise. Now, we can just reverse each row to achieve the 
 * 		expected solution. 
 */
class Solution
{
public:
	void rotate(vector<vector<int>> &matrix)
	{
		int N = matrix.size();
		vector<vector<int>> tempM(N, vector<int>(N, 0));

		if (N <= 1)
			return;

		for (int i = 0; i < (N - 1); i++)
			for (int j = (i + 1); j < N; j++)
				swap(matrix[i][j], matrix[j][i]);
		
		
		for (int i = 0; i < N; i++)
			reverse(matrix[i].begin(), matrix[i].end());
			// We can use below loop in place of STL also to reverse each row.
			// for (int j = 0; j < (N / 2); j++)
				// swap(matrix[i][j], matrix[i][N - j - 1]);
	}
};