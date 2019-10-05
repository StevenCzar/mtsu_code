/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 2
  Purpose: Matrix Math
  Due date: 10/04/2019
  */

//dependencies
#include <iostream>
#include <iomanip>
using namespace std;

//main
int main()
{
	//initialize variables
	int rowA, rowB, colA, colB;
	int matA[10][10], matB[10][10];
	char choice;
	//use for check on validation for operations
	bool valid = true;

	//initial input
	cout << "Input the row size of A: ";
	cin >> rowA;
	cout << "Input the column size of A: ";
	cin >> colA;
	for(int i = 0; i < rowA; i++)
	{
		for(int j = 0; j < colA; j++)
		{
			//prompt for each individual element of the matrix
			cout << "Input matrix A (element [" << i+1 << "][" << j+1 << "]): ";
			cin >> matA[i][j];
		}
	}

	//still inputing
	cout << "Input the row size of B: ";
	cin >> rowB;
	cout << "Input the column size of B: ";
	cin >> colB;
	for(int i = 0; i < rowB; i++)
	{
		for(int j = 0; j < colB; j++)
		{
			cout << "Input matrix rowB(element [" << i+1 << "][" << j+1 << "]): ";
			cin >> matB[i][j];
		}
	}	

	//input char for choice
	cout << "Choose your operation: A for add, S for subtract, ";
	cout << "M for multiply, N for AND, O for OR\n";
	cin >> choice;

	//if-else segment for char check
	//if adding....
	if(choice == 'A' || choice == 'a')
	{
		//validation for operation
		if((rowA != rowB)||(colA != colB))
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		//if you can do it, then do math
		if(valid)
		{
			cout << "The answer is: \n";
			//add element by element
			for(int i = 0; i < rowA; i++)
			{
				for(int j = 0; j < colA; j++)
				{
					cout <<  matA[i][j] + matB[i][j];
					cout << " ";
				}
				cout << "\n";
			}
		}
	}
	//subtraction time
	else if(choice == 'S' || choice == 's')
	{
		//validation time
		if((rowA != rowB)||(colA != colB))
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		//if valid, then do thing
		if(valid)
		{
			cout << "The answer is: \n";
			//subtract each element by each element
			for(int i = 0; i < rowA; i++)
			{
				for(int j = 0; j < colA; j++)
				{
					cout <<  matA[i][j] - matB[i][j];
					cout << " ";
				}
				cout << "\n";
			}
		}
	}
	//multiply time
	else if(choice == 'M' || choice == 'm')
	{
		//declare temp array for storage of values
		int temp[10][10];
		//validation time
		if(rowA!=colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		//if it works, then do thing
		if(valid)
		{
			cout << "The answer is: \n";
			//multiply time for real
			for(int i = 0; i < rowA; i++)
			{
				for(int j = 0; j < colA; j++)
				{
					temp[i][j] = 0;
					for(int k = 0; k < colA; k++)
					{
						//keeps track of sum of each multiplication operation
						temp[i][j] += (matA[i][k] * matB[k][j]);
					}
					//print final element
					cout << temp[i][j];
					cout << " ";
				}
				cout << "\n";
			}
		}
	}
	//AND time
	else if(choice == 'N' || choice == 'n')
	{
		//temp array since it's the same as multiplying
		int temp[10][10];
		if(rowA!=colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		//same as multiply
		if(valid)
		{
			cout << "The answer is: \n";
			for(int i = 0; i < rowA; i++)
			{
				for(int j = 0; j < colA; j++)
				{
					temp[i][j] = 0;
					for(int k = 0; k < colA; k++)
					{
						temp[i][j] += (matA[i][k] * matB[k][j]);
					}
					//literally the same thing as multiplying, but if the value is 1 or more, make it a 1
					if(temp[i][j] >= 1)
					{
						temp[i][j] = 1;
					}
					cout << temp[i][j];
					cout << " ";
				}
				cout << "\n";
			}
		}
	}
	//OR time
	else if(choice == 'O' || choice == 'o')
	{
		//validation time
		if((rowA != rowB)||(colA != colB))
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		//last time it does things
		if(valid)
		{
			cout << "The answer is: \n";
			for(int i = 0; i < rowA; i++)
			{
				for(int j = 0; j < colA; j++)
				{
					//doesn't even put into an output array.  if value after adding is 1 or more, makes it 1
					if((matA[i][j] + matB[i][j]) >= 1)
					{
						cout << "1";
					}
					else
					{
						cout << "0";
					}
					cout << " ";
				}
				cout << "\n";
			}
		}
	}
	//if not a valid char selection... tell them they did it wrong
	else
	{
		cout << "Invalid choice\n";
	}
	//the end
	return 0;
}