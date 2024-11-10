#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(NlogN), S: O(N)
 *
 * @def 	Merge Sort Algo.
 *
 * @details	We split the array into parts untill the left & right halfs are left with 1 element each & then, we merge the divided arrays with compairing the eles
 * 		in a way to merge them in sorted order. We go on untill we get the entire array sorted.
 */
class Solution
{
private:
	void merge(vector<int> &nums, int low, int mid, int high)
	{
		int left = low, right = (mid + 1);
		vector<int> temp;

		while ((left <= mid) && (right <= high))
		{
			if (nums[left] <= nums[right])
				temp.push_back(nums[left++]);
			else
				temp.push_back(nums[right++]);
		}

		while (left <= mid)
		temp.push_back(nums[left++]);

		while (right <= high)
		temp.push_back(nums[right++]);
		
		for (int  i = low; i <= high; i++)
			nums[i] = temp[i - low];

		return;
	}

	void mergeSort(vector<int> &nums, int low, int high)
	{
		if (low == high)
			return;
		
		int mid = (low + high) / 2;

		mergeSort(nums, low, mid);
		mergeSort(nums, mid + 1, high);

		merge(nums, low, mid, high);

		return;
	}

public:
	vector<int> sortArray(vector<int> &nums)
	{
		vector<int> soln;

		mergeSort(nums, 0, (nums.size() - 1));
		for (int i = 0; i < nums.size(); i++)
			soln.push_back((nums[i]));

		return soln;
	}
};