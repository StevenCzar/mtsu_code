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
	int i, sum, error;
	int current[12], parity[4], final[8];
	char entry[i];

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
			cout << current[i];
		}

		//convert hamming code to gray code
		//p1 in array location 7 - checks locations: 7-11
		//p2 in array location 3 - checks locations: 3-6 and 11
		//p3 in array location 1 - checks locations: 1,2,5,6,9,10
		//p4 in array location 0 - checks locations: 0,2,4,6,8,10
		
		//check #1 (if the sum of all the checked bits is not even, put 1 into parity bit spot)
		//skip 8 bits, check next bits till EoS
		if(!((current[7] + current[8] + current[9] + current[10] + current[11])%2))
		{
			parity[0] = 1;
		}
		else
		{
			parity[0] = 0;
		}
		//check #2 (same as above, but different checked bits)
		//skip 4 bits, check next 4 bits till EoS
		if(!((current[3] + current[4] + current[5] + current[6] + current[11])%2))
		{
			parity[1] = 1;
		}
		else
		{
			parity[1] = 0;
		}
		//check #3 (same again)
		//skip 2 bits, check next 2 bits till EoS
		if(!((current[1] + current[2] + current[5] + current[6] + current[9] + current[10])%2))
		{
			parity[2] = 1;
		}
		else
		{
			parity[2] = 0;
		}
		//check #4
		//every other bit
		if(!((current[0] + current[2] + current[4] + current[6] + current[8] + current[10])%2))
		{
			parity[3] = 1;
		}
		else
		{
			parity[3] = 0;
		}
	}

	return 0;
}

