#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N + log(N)), S: O(N)
 *
 * @def		Using Brute Force.
 *
 * @details	Convert the input decimal into binary array using classic conversion & then traverse through the array to fing the number of 1's in it.
 */
class Solution
{
private:
	vector<int64_t> convertDecToBin(uint32_t n)
	{
		int8_t rem = 0;
		vector<int64_t> decToBin;
		while (n > 0)
		{
			rem = (n % 2);
			n /= 2;
			decToBin.push_back(rem);
		}
		return decToBin;
	}

public:
	int hammingWeight(uint32_t n)
	{
		int32_t soln = 0;

		// Convert input into binary form.
		vector<int64_t> binary = convertDecToBin(n);

		// Finding the number of 1's in the binary string of input.
		for (auto i: binary)
			if (i == 1)
				soln++;
		
		return soln;
	}
};

/**
 * @brief 	Approach-2: T: O(N), S: O(N) 
 *
 * @def		Using bitset STL.
 *
 * @details 	Convert the input decimal into binary string using bitset STL & then traverse through the string to fing the number of 1's in it.
 */
class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int32_t soln = 0;

		// Convert input into binary form & store it inside a string.
		string binary = bitset<64>(n).to_string();

		// Finding the number of 1's in the binary string of input.
		for (auto i: binary)
			if (i == '1')
				soln++;
		
		return soln;
	}
};

/**
 * @brief 	Approach-3: T: O(log(N)), S: O(1)
 *
 * @def		Optimized above approach.
 *
 * @details	While Converting the input decimal into binary just add the remainders (number % 2) as if its 1 it will increase our soln count.
 */
class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int32_t soln = 0, rem = 0;
		while (n > 0)
		{
			rem = (n % 2);
			n /= 2;
			soln += rem;
		}
		return soln;
	}
};