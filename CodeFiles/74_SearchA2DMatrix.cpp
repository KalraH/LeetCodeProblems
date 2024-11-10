#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(NxM), S: O(1)
 *
 * @def 	Brute Force.
 *
 * @details 	Iterate through entire matrix and find the element.
 */
class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target)
	{
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[i].size(); j++)
				if (matrix[i][j] == target)
					return true;

		return false;
	}
};

/**
 * @brief 	Approach-2: T: O(N + M), S: O(1)
 *
 * @def 	Better Approach.
 *
 * @details 	Using the conditions given in question of sored rows & each row's last element is smaller than the next row's 1st element, We check if the target in
 * 		in range for that particular row, if so, we traverse the relevant row and look for it.
 */
class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) 
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			if ((target >= matrix[i][0]) && (target <= matrix[i][matrix[i].size() - 1]))
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					if (matrix[i][j] == target)
						return true;
				}
			}
		}
		return false;
	}
};

/**
 * @brief 	Approach-3: T: O(N + log(M)), S: O(1)
 *
 * @def 	Optimal Approach. USING BINARY SEARCH !!
 *
 * @details 	Using the conditions given in question of sored rows & each row's last element is smaller than the next row's 1st element, We check if the target in
 * 		in range for that particular row, if so, we use binary search to traverse the relevant row and look for it.
 */
class Solution
{
private:
	bool binarySearch(vector<int> arr, int target)
	{
		int low = 0, high = arr.size();
		while (low <= high)
		{
			int mid = (low + high) / 2;

			if (target == arr[mid])
				return true;
			else if (target < arr[mid])
				high = (mid - 1);
			else
				low = (mid + 1);
		}
		return false;
	}
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) 
	{
		for (int i = 0; i < matrix.size(); i++)
			if ((target >= matrix[i][0]) && (target <= matrix[i][matrix[i].size() - 1]))
				return binarySearch(matrix[i], target);

		return false;
	}
};

/**
 * @brief 	Approach-4: T: O(log(N + M)), S: O(1)
 *
 * @def 	Most Optimal Approach. USING SMART BINARY SEARCH !!
 *
 * @details 	Using the conditions given in question of sored rows & each row's last element is smaller than the next row's 1st element. We imagine that the entire 
 * 		matrix is a 1D array & then use binary search in this 1D array to find the target. The hypothetical 1D array starts from idx 0, & goes to idx (n * m).
 * 		At any point, to convert the 1D index into 2D, we use the formula, row = (mid / m) & col = (mid % m).
 */
class Solution
{
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) 
	{
		int n = matrix.size(), m = matrix[0].size();
		int low = 0, high = ((n * m) - 1);

		while (low <= high)
		{
			int mid = (low + high) / 2;
			int row = (mid / m), col = (mid % m);

			if (target == matrix[row][col])
				return true;
			else if (target < matrix[row][col])
				high = (mid - 1);
			else
				low = (mid + 1);
		}
		return false;
	}
};