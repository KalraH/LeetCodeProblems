#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N^2 + 2N), S: O(1)
 *
 * @def 	Brute Force.
 *
 * @details 	Traverse the array with compairing each element with others to look for duplicates. Then, calculate the sum of 1 to N, then subtract all the elements from 
 * 		that sum. Add the duplicate element found earlier into the subtracted value to find the missing val.
 */
class Solution
{
public:
	vector<int> findTwoElement(vector<int> arr, int n)
	{
		vector<int> solArr;
		for (int i = 0; i < n; i++)
		{
			for (int j = (i + 1); j < n; j++)
			{
				if (arr[i] == arr[j])
				{
					solArr.push_back(arr[i]);
					break;
				}
			}
		}

		int sumOfnEle = 0;
		for (int i = 1; i <= n; i++)
			sumOfnEle += i;
		
		for (int i = 1; i <= n; i++)
			sumOfnEle -= arr[i - 1];
		
		solArr.push_back(sumOfnEle + solArr.back());
		
		return solArr;
	}
};

/**
 * @brief 	Approach-2: T: O(N^2), S: O(1)
 *
 * @def 	Brute Force.
 *
 * @details 	Traverse the array with compairing each element with 1 to N elements and count their occurance in array. The element occuring twice is the repeating one &
 * 		the element not occuring inside array is missing one.
 */
class Solution
{
public:
	vector<int> findTwoElement(vector<int> arr, int n)
	{
		vector<int> solArr(2, 0);
		for (int i = 1; i <= n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
				if (arr[j] == i)
					cnt++;

			if (cnt == 2)
				solArr[0] = i;
			else if (cnt == 0)
				solArr[1] = i;
		}
		return solArr;
	}
};

/**
 * @brief 	Approach-3: T: O(2N + NlogN), S: O(1)
 *
 * @def 	Optimized Brute Force.
 *
 * @details 	Sort the array & them traverse it looking for any repeated entry. Once found, add it to the soln Array. Then, calculate the sum of 1 to N, simultaneously 
 * 		subtracting each element from that sum. Add the duplicate element found earlier into the sum value to find the missing val.
 */
class Solution
{
public:
	vector<int> findTwoElement(vector<int> arr, int n)
	{
		vector<int> solArr;
		sort(arr.begin(), arr.end());

		for (int i = 0; i < (n - 1); i++)
		{
			if (arr[i] == arr[i + 1])
			{
				solArr.push_back(arr[i]);
				break;
			}
		}

		int sumOfnEle = 0;
		for (int i = 1; i <= n; i++)
		{
			sumOfnEle += i;
			sumOfnEle -= arr[i - 1];
		}
		
		solArr.push_back(sumOfnEle + solArr.back());
		
		return solArr;
	}
};

/**
 * @brief 	Approach-4: T: O(2N), S: O(N)
 *
 * @def 	Better Solution. Using extra space.
 *
 * @details 	We create a frequency array to store the fequency of each element. As soon as we encounter that an element is aready found, add it to the soln Array. Then, 
 * 		calculate the sum of 1 to N, simultaneously subtracting each element from that sum. Add the duplicate element found earlier into the sum value to find the 
 * 		missing val.
 */
class Solution
{
public:
	vector<int> findTwoElement(vector<int> arr, int n)
	{
		vector<int> solArr, temp(n + 1, 0);
		for (auto i: arr)
		{
			if (temp[i] != 0)
			{
				solArr.push_back(i);
				break;
			}
			else
				temp[i]++;
		}

		int sumOfnEle = 0;
		for (int i = 1; i <= n; i++)
		{
			sumOfnEle += i;
			sumOfnEle -= arr[i - 1];
		}
		solArr.push_back(sumOfnEle + solArr.back());
		
		return solArr;
	}
};

/**
 * @brief 	Approach-5: T: O(N), S: O(1)
 *
 * @def 	Optimal Solution-1. MATHEMATICS !!
 *
 * @details 	We will find the sum of array elements (S) & also the sum of squares of all array elements (S2). We will calculate the sum of 1st N natural Nos. (Sn) & 
 * 		also the sum of squares of 1st N natural Nos. (Sn2) using formulas:
 * 			-> Sn  = (n * (n - 1)) / 2
 * 			-> Sn2 = (n * (n + 1) * (2n + 1)) / 6
 * 		Now, we consider X as our Repeating element & Y as our Missing element. We do a littile math as find the values of X by the 2 equations we get as:
 * 			-> X - Y = S - Sn
 * 			-> X^2 - Y^2 = S2 - Sn2
 */
class Solution
{
public:
	vector<int> findTwoElement(vector<int> arr, int n)
	{
		vector<int> solArr(2, 0);
		long long S = 0, S2 = 0;
		long long Sn = ((n * (n + 1)) / 2), Sn2 = ((n * (n + 1) * (2*n + 1)) / 6);

		for (auto i: arr)
		{
		    S += i; 
		    S2 += (i * i);
		}
		
		long long XminusY = (S - Sn), X2minusY2 = (S2 - Sn2);
		long long XplusY = (X2minusY2 / XminusY);

		// Now, we have (X + Y) & (X - Y). Doing (X + Y) + (X - Y) gives 2X === (((X + Y) + (X - Y)) / 2) gives X
		int X = ((XminusY + XplusY) / 2);

		// Now, ((X + Y) - X) gives Y.
		int Y = (X - XminusY);

		solArr[0] = (int)X, solArr[1] = (int)Y;
		
		return solArr;
	}
};

/**
 * @brief 	Approach-6: T: O(3N), S: O(1)
 *
 * @def 	Optimal Solution-2. XOR OPERATION !!
 *
 * @details 	We will find the XOR of all array elements, the XOR of 1st N natural Nos. & then XOR them together. Will calculate the first bit from the right which is 
 * 		set, as its the first bit different b/w our repeating and missing Nos. After this will differentiate all the array elements & the 1st N natural Nos on the
 * 		basis of this bitNo found earlier. If the no's have set bit at the index of bitNo, will XOR them in a variable one else will XOR them in the variable zero.
 * 		Now, will iterate through array to check the occurance of any of the elements one/zero & if the occurance is 2, we get our repeating No. & the other-one is
 * 		the corresponding missing No. Else if the occurance is 0, we get our missing No. & the other-one is the corresponding repeating No. Now, we return the soln
 * 		array accordingly.
 */
class Solution
{
public:
	vector<int> findTwoElement(vector<int> arr, int n)
	{
		vector<int> solArr;

		int xorOfEles = 0;
		for (int i = 0; i < n; i++)
			xorOfEles ^= (arr[i] ^ (i + 1));

		int bitNo = 0;
		while (1)
		{
			if (xorOfEles & (1 << bitNo))
				break;
			bitNo++;
		}

		int zero = 0, one = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] & (1 << bitNo))
				one ^= arr[i];
			else 
				zero ^= arr[i];
			
			if ((i + 1) & (1 << bitNo))
				one ^= (i + 1);
			else 
				zero ^= (i + 1);
		}

		int tempCnt = 0;
		for (auto i: arr)
			if (i == one)
				tempCnt++;
		
		if (tempCnt == 2) 
			return {one, zero};
		
		return {zero, one};
	}
};