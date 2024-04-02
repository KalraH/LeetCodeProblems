#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(2N)
 *
 * @def		Using Hashmaps.
 *
 * @details	Use 2 hashmaps to store each character's replacement from 1st string in 2nd one. If at any iteration, the pairs are mismatched in either of the HashMaps, 
 * 		return false, else if we reach the end of both string, return true.
 */
class Solution
{
public:
	bool isIsomorphic(string s, string t)
	{
		unordered_map<char, char> aMap, aMap1;

		for (int i = 0; i < s.size(); i++)
		{
			if (aMap.find(s[i]) != aMap.end())
			{
				if (aMap[s[i]] != t[i])
					return false;
			}
			else
			{
				if (aMap1.find(t[i]) != aMap1.end())
					return false;

				aMap[s[i]] = t[i];
				aMap1[t[i]] = s[i];
			}
		}
		return true;
	}
};