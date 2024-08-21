#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(2(N + M) + (N + M)log(N + M)), S: O(N + M)
 *
 * @def 	Brute Force.
 *
 * @details 	Take a 3rd array and copy both the input arrays into it. Now, we sort the 3rd array & then we empty it into the 1st one.
 */

/**
 * @brief 	Approach-2: T: O(M + (N + M)log(N + M)), S: O(1)
 *
 * @def 	Optimal Solution-1.
 *
 * @details 	We empty the 2nd array into the 2nd half of the 1st array. Then, we sort the 1st array.
 */
class Solution
{
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		for (int i = m; i < (m + n); i++)
			nums1[i] = nums2[i - m];

		sort(nums1.begin(), nums1.end());
	}
};

/**
 * @brief 	Approach-3: T: O(M + (N + M)log(N + M)), S: O(1)
 *
 * @def 	Optimal Solution-2. GAP METHOD !!
 *
 * @details	We take a variable gap ( ceil of (n + m / 2)) & 2 pointers left(placed at 0th index) & right(placed at gap distance away from left). Now, we traverse both arrays with the pointers untill
 * 		they cross the (n + m) length boundry. At each step we check & if needed replace the elements in the arrays as per their order of precedence. After end of every traversal, we reduce gap
 * 		by ceil of gap/2 untill gap reaches 1 (then we stop). Then, we copy the 2nd array into the 2nd half of 1st array. 
 */
class Solution
{
private:
	void swapEle(vector<int> &arr1, vector<int> &arr2, int i, int j)
	{
		if (arr1[i] > arr2[j])
			swap(arr1[i], arr2[j]);
	}

public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		if ( !m )
		{
			for (int i = 0; i < n; i++)
				nums1[i] = nums2[i];
			return;
		}
		else if ( !n )
			return;

		int len = (n + m);
		int gap = (len / 2) + (len % 2);
		
		while (gap > 0)
		{
			int left = 0, right = (left + gap);
			while (right < len)
			{
				// Swapping b/w nums1 & nums2
				if ((left < m) && (right >= m))
					swapEle(nums1, nums2, left, right - m);
				// Swapping b/w nums2 & nums2
				else if (left >= m)
					swapEle(nums2, nums2, left - m, right - m);
				// Swapping b/w nums1 & nums1
				else if ((left < m) && (right < m))
					swapEle(nums1, nums1, left, right);

				left++, right++;
			}
			if (gap == 1)
				break;

			gap = (gap / 2) + (gap % 2);
		}

		for (int i = 0; i < n; i++)
			nums1[i + m] = nums2[i];
	}
};