#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^3), S: O(1)
 *
 * @def		BruteForce.
 *
 * @details	We traverse the entite Matrix, whenever we find a 0, we set its entire Row & Column to -1 (excepts the 0s). Later we traverse the entire Matrix again &
 * 		replace all -1s with 0s. {Constraint: If the matrix has any element as -1, we might end up setting it to 0 even though its not needed}
 */
class Solution
{
private:
	void setRowZero(int k, vector<vector<int>> &matrix)
	{
		for (int i = 0; i < matrix[0].size(); i++)
			matrix[k][i] = (matrix[k][i] == 0) ? 0 : -1;
	}

	void setColumnZero(int k, vector<vector<int>> &matrix)
	{
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][k] = (matrix[i][k] == 0) ? 0 : -1;
	}

public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] != 0)
					continue;

				if (matrix[i][j] == 0)
				{
					setRowZero(i, matrix);
					setColumnZero(j, matrix);
				}
			}
		}

		for (auto &i : matrix)
			for (auto &j : i)
				if (j == -1)
					j = 0;
	}
};

/**
 * @brief 	Approach-2: T: O(N^2), S: O(N + M)
 *
 * @def		Optimized by reducing iterating each column/row whenever we encounter a 0 in matrix.
 *
 * @details	We traverse the entite Matrix, we keep 2 arrays row/column of sizes n & m respectively initialized to 0. Whenever we find a 0 in matrix, we set row/column
 * 		array's locations as 1. Then we traverse the matrix again & for each index, if we have 0 in either of the 2 arrays row/column, we replace the element to 0.
 */
class Solution
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int n = matrix.size(), m = matrix[0].size();
		vector<int> row(n, 0), column(m, 0);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!matrix[i][j])
					row[i] = 1, column[j] = 1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (row[i] || column[j])
					matrix[i][j] = 0;
	}
};

/**
 * @brief 	Approach-3: T: O(N^2), S: O(1)
 *
 * @def		Optimized by removing the additional arrays for Row/Column.
 *
 * @details	This time we are going to assume the 1st row/column as the additional arrays to keep the track of 0s in each row/column. We keep an additional variable for
 * 		the overlapping cell's data matrix[0][0]. We, traverse the entire matrix & mark the 0s in rows/columns by marking 0s in the 1st row/column. For the case of
 * 		1st column, we mark 0 in it by marking the additional variable to 0. At end, we traverse the matrix again & while checking the 1st row/column, we set the 
 * 		matrix elements to 0s. At end, we check the additional variable's value &set the 1st column to 0 accordingly.
 */
class Solution
{
public:
	void setZeroes(vector<vector<int>> &matrix)
	{
		int n = matrix.size(), m = matrix[0].size();

		int col0 = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j])
					continue;
				
				matrix[i][0] = 0;
				if (j)
					matrix[0][j] = 0;
				else
					col0 = 0;
			}
		}

		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				if (matrix[i][j] && (!matrix[i][0] || !matrix[0][j]))
					matrix[i][j] = 0;

		if (!matrix[0][0])
			for (int j = 0; j < m; j++)
				matrix[0][j] = 0;

		if (!col0)
			for (int i = 0; i < n; i++)
				matrix[i][0] = 0;
	}
};