#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(), S: O()
 *
 * @def		Basic Intution to maximize profit at every sell.
 *
 * @details	We keep track of array's minimum element as well as the max profit encountered at selling the element on which we are at that moment. 
 */
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int minimumEle = prices[0], maxProfit = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			int currCost = (prices[i] - minimumEle);
			maxProfit = max(maxProfit, currCost);
			minimumEle = min(minimumEle, prices[i]);
		}
		return maxProfit;
	}
};