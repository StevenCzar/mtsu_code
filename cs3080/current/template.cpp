/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 2
  Purpose: Matrix Math
  Due date: idk/2019
  */

//dependencies
#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes

//main
int main()
{
	int rowA[10][10], rowB[10][10], colA, colB;
	char choice;
	bool valid = true;

	cout << "Input the row size of A: ";
	cin >> rowA;
	cout << "Input the column size of A: ";
	cin >> colA;
	for(int i = 0; i < rowA; i++)
	{
		for(int j = 0; j < colA; j++)
		{
			cout << "Input matrix A (element [" << i << "][" << j << "]): "
			cin >> matA[i][j];
		}
	}

	cout << "Input the row size of B: ";
	cin >> rowB;
	cout << "Input the column size of B: ";
	cin >> colB;
	for(int i = 0; i < rowB; i++)
	{
		for(int j = 0; j < colB; j++)
		{
			cout << "Input matrix rowB(element [" << i << "][" << j << "]): "
			cin >> matB[i][j];
		}
	}	

	cout << "Choose your operation: A for add, S for subtract, ";
	cout << "M for multiply, N for AND, O for OR\n";
	cin >> choice

	if(choice == "A" || "a")
	{
		if((rowA != rowB)||(colA != colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		if(valid)
		{
			cout << "The answer is: \n";
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
	else if(choice == "S" || "s")
	{
		if((rowA != rowB)||(colA != colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		if(valid)
		{
			cout << "The answer is: \n";
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
	else if(choice == "M" || "m")
	{
		int temp[10][10];
		if(rowA!=colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
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
					cout << temp[i][j];
					cout << " ";
				}
				cout << "\n";
			}
		}
	}
	else if(choice == "N" || "n")
	{
		int temp[10][10];
		if(rowA!=colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
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
					if(temp[i][j] > 1)
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
	else if(choice == "O" || "o")
	{
		if((rowA != rowB)||(colA != colB)
		{
			cout << "Invalid dimensions for operation" << endl;
			valid = false;
		}
		if(valid)
		{
			cout << "The answer is: \n";
			for(int i = 0; i < rowA; i++)
			{
				for(int j = 0; j < colA; j++)
				{
					if((matA[i][j] + matB[i][j]) > 1)
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
	else
	{
		cout << "Invalid choice\n"
	}
	return 0;
}

//functions
