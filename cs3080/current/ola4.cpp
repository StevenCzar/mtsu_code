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
	int final[10];
	int i, j, numNodes, numRows, temp, degree;
	//make matrix 0's
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			adj[i][j] = 0;
		}
	}
	
	//basic i/o stuff
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

	//create adjacency matrix from pseudocode
	for(i=0; i<numRows;i++)
	{
		temp = apr[i][1];
		while(temp!=0)
		{
			adj[i][apr[temp][0]] = 1;
			temp = apr[temp][1];
		}
	}

	//from adjacency matrix, get degree and each adjacent node
	for(i=0; i<numNodes; i++)
	{
		cout << "\n***Node " << i+1 << " information***\n";
		degree = 0;
		for(j=0; j<numNodes; j++)
		{
			if(adj[i][j] == 1)
			{	
				//gets adjacent node and places in array
				final[degree] = j+1;
				degree++;
			}
		}
		//if the degree of the node is 0, print that it is isolated
		if(degree == 0)
		{
			cout << i+1 << " is an isolated node \n";
		}
		//print out the degree of the node
		cout << "Degree of node " << i+1 << " is: " << degree << endl;
		//print the adjacent nodes
		cout << "The nodes adjacent to node " << i+1 << " are: ";
		for(j=0;j<=degree;j++)
		{
			cout << final[j] << " ";
		}
	}
	return 0;
}