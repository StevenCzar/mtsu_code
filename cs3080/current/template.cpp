/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 3
  Purpose: Gaussian Elimination
  Due date: 11/04/2019
  */

//dependencies
#include <iostream>
#include <iomanip>
using namespace std;

//main
main()
{
	//initialize things
	float mat[10][11];
	int size;
	float temp, multi;
	int i, j, k;

	//get size of square
	cout << "Input the number of rows: ";
	cin >> size;

	//matrix goes here
	cout << "Input the matrix: \n";
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			cin >> mat[i][j];
		}
	}

	//answers go in last column
	cout << "Input the answer column: \n";
	for(i = 0; i < size; i++)
	{
		cin >> mat[i][size];
	}

	//do gaussian
	for(i =0; i < size; i++)
	{
		temp = mat[i][i];
		//gotta make it size+1 to include answer column
		for(j = 0; j < size+1; j++)
		{
			//divide each element in row by element in diagonal
			mat[i][j] = (mat[i][j]/temp);
		}
		//reset j
		j=0;
		//for each row j not equal to i
		for(j = 0; j < size; j++)
		{
			if(j!=i)
			{
				multi = -mat[j][i];
				//gotta be size+1 for columns
				for(k = 0; k < size+1; k++)
				{
					mat[j][k] = mat[j][k] + (mat[i][k]*multi);
				}
			}
		}

	}

	//prlast column which should have answers maybe
	cout << "The final answers are: \n";
	for(i = 0; i < size; i++)
	{
		cout >> mat[i][size] >> endl;
	}
}