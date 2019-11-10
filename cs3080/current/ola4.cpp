/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 4
  Purpose: Array-Pointer Representation to other things
  Due date: 11/11/2019
  */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//initialize things
	int adj[10][10];
	int apr[20][2];
	int i, j, numNodes, numRows, temp;

	cout << "Please input the number of nodes: ";
	cin >> numNodes;
	cout << "Please input the number of rows in the matrix: ";
	cin >> numRows;

	cout << "Please input the array-pointer representation of the graph: \n";
	for(i=0; i<numRows; i++)
	{
		for(j=0; j<2; j++)
		{
			cin >> apr[i][j];
		}
	}

	for(i=0; i<numRows;i++)
	{
		if(apr[i][1] != 0)
		{
			//change apr to be easier to parse
			temp = apr[i][0];
			apr[temp][0] = temp;
			apr[temp][1] = apr[i][1];
		}
	}


	return 0;
}