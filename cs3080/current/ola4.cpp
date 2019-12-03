/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 6
  Purpose: Encoding Scheme stuff
  Due date: 12/04/2019
  */

#include <iostream>
#include <iomanip>
using namespace std;


//Start main
int main()
{
	//initial declaration
	int i, error, sum;
	int current[12], parity[4], final[8];
	char entry[12];

	//while getting things...
	while(cin)
	{
		//read in next 12 bits as ints into array
		for(i=0; i<12; i++)
		{
			//get next char
			cin.get(entry[i]);
			//if it's a newline, get the next char instead
			if(entry[i] == '\n')
			{
				cin.get(entry[i]);
			}
			//if it's a 0, make it an int 0
			if(entry[i] == '0')
			{
				current[i] = 0;
			}
			else
			{
				current[i] = 1;
			}
		}

		/*convert hamming code to gray code
		p1 in array location 7 - checks locations: 7-11
		p2 in array location 3 - checks locations: 3-6 and 11
		p3 in array location 1 - checks locations: 1,2,5,6,9,10
		p4 in array location 0 - checks locations: 0,2,4,6,8,10
		
		parity bits placed in order backwards in order to only have to use 1 for loop
		when converting over from binary (really gray code) to decimal value for bit flip

		check #1 (if the sum of all the checked bits is not even, put 1 into parity bit spot)
		skip 8 bits, check next bits till EoS
		*/
		if(!((current[7] + current[8] + current[9] + current[10] + current[11])%2))
		{
			parity[3] = 1;
		}
		else
		{
			parity[3] = 0;
		}
		//check #2 (same as above, but different checked bits)
		//skip 4 bits, check next 4 bits till EoS
		if(!((current[3] + current[4] + current[5] + current[6] + current[11])%2))
		{
			parity[2] = 1;
		}
		else
		{
			parity[2] = 0;
		}
		//check #3 (same again)
		//skip 2 bits, check next 2 bits till EoS
		if(!((current[1] + current[2] + current[5] + current[6] + current[9] + current[10])%2))
		{
			parity[1] = 1;
		}
		else
		{
			parity[1] = 0;
		}
		//check #4
		//every other bit
		if(!((current[0] + current[2] + current[4] + current[6] + current[8] + current[10])%2))
		{
			parity[0] = 1;
		}
		else
		{
			parity[0] = 0;
		}

		//get binary from parity bit, determine error, and flip corresponding bit
		//reset sum to 0 before starting
		sum = 0;
		for(i=0; i<4; i++)
		{
			//gets position - if bit is 0, will always equal 0, if bit is 1, multiplies by 2^n
			sum += parity[i] * (2^i);
		}

		//if sum has a value
		if(sum)
		{
			//index is sum-1, if value is 0, swap to 1, otherwise swap to 0
			if(current[sum-1] == 0)
			{
				current[sum-1] = 1;
			}
			else
			{
				current[sum-1] = 0;
			}
		}
		//hamming code should be done now...
		//time to start gray code conversion to excess-3
		//do gray code to binary (really excess-3)
		//first element is same as previous first element
		//elements 0,1,3,and7 are parity bits to be removed
		final[0] = current[2];
		//set sum to 1 for checking
		sum=1;
		//other elements are: 1 if sum of current + previous elements is odd and 0 if even

		//for loop to go through elements of final array
		for(i=1; i<8; i++)
		{
			//for loop to go through elements of current array
			//start at 4 because 2 is accounted for and 0,1,and 3 need to be removed
			for(int j=4; j<12; j++)
			{
				//leave out element 7 cause it's a parity bit as well
				if(j!=7)
				{
					sum+=current[j];
					//if sum is even, put a 0
					if(sum%2 == 0)
					{
						final[i] = 0;
					}
					//if sum is odd, put a 1
					else
					{
						final[i] = 1;
					}
				}
			}

			//if excess-3 is just binary + 3, then I can convert to decimal now and subtract 3
			//final array should have excess-3 code stored in it

			//reset sum to 0 again
			sum=0;
			for(i=0; i<8; i++)
			{
				//same logic as before to get position
				sum += (final[i] * 2^i);
			}
			//output the result as a char
			cout << static_cast<char>(sum-3);
		}
	}
	return 0;
}

