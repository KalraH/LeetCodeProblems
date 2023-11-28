#include "../HeaderFiles/incLibs.h"

/**
 * @brief 	Approach-1: T: O(N), S: O(1)
 *
 * @def 	Following basic intution.
 *
 * @details 	For a valid partition, each sides should have >= 2 & as there are plants in between seats, after 2 seats are found, each plant leade to a new partition, so as the 3rd seat is found after the discovery of 2 seats, we have (noOfPlantsInBetweenSeats + 1) different partitions.
 * 		So, we just traverse the corridor, count the no of Seats, once it reaches 2, we start counting noOfPlantsInBetweenSeats & at the discovery of 3rd seat, we add the value to soln. 
 * 		Just, need to make sure at the end of traversal, we are left with 2 seats only otherwise we cant perform the partitions as there will always be 1 half with less than 2 seats.
 */
class Solution
{
public:
	int numberOfWays(string corridor)
	{
		int32_t soln = 0, len = corridor.length();
		// No of items in the Corridor are less for the basic condition to-be satisfied.
		if (len <= 1)
			return soln;

		int64_t noOfSeats = 0, noOfPlantsInBetweenSeats = 0;
		for (int32_t i = 0; i < len; i++)
		{
			// Finding no of seats.
			if (corridor[i] == 'S')
				noOfSeats++;
			// Finding no of plants in between 2nd & 3rd seat.
			else if (corridor[i] == 'P' && noOfSeats == 2)
				noOfPlantsInBetweenSeats++;

			// Once we find the 3rd seat, no of possible partitions between the initial 2 seats & the 3rd seat are simply (noOfPlantsInBetweenSeats + 1).
			if (noOfSeats == 3)
			{
				soln = (soln * (noOfPlantsInBetweenSeats + 1)) % int64_t(1e9 + 7);
				noOfSeats = 1;
				noOfPlantsInBetweenSeats = 0;
			}
		}

		// If there is a partition in the end with just 1 seat on either side.
		if (noOfSeats != 2)
			return 0;

		return soln;
	}
};