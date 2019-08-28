/*Author: Steven Czarnecki
  Course: CSCI 3180

  Lab number: Lab 1
  Purpose: Create algorithm to use horner's method
  Due date: 08/29/2019
  */

//dependencies
#include <iostream>
using namespace std;

//function prototypes
void horner(int coeff[], int num);
void load_array(int coeff[], int num);
int get_num();
int ask_for_x();
//main
int main()
{
	int num = get_num();
	int coeff[num];
	load_array(coeff, num);
	horner(coeff, num);

	return 0;
}

//functions
//Function that prompts user to enter the value of X
int ask_for_x()
{
	int x;
	cout << "(Enter -1000 to quit)\nEnter the value of x: ";
	cin >> x;
	return x;
}
//Function that prompts user to enter the degree of largest polynomial
int get_num()
{
	int num;
	cout << "Enter the degree of your polynomial: ";
	cin >> num;
	return num;
}
//Function that loads the array with user input for horner
void load_array(int coeff[], int num)
{
	for(int i = num; i >= 0; i--)
	{
		if(i!=0)
		{
			cout << "Enter coefficent for x^"<< i << ": ";
		}
		else
		{
			cout << "Constant term? ";
		}
		cin >> coeff[i];
	}
	return;
}
//Function that applies horner's algorithm
void horner(int coeff[], int num)
{
	//final check for loop
	bool check = true;
	do{
		//gets value of x
		int x = ask_for_x();
		cout << "Value of x: " << x << endl;
		if(x != -1000)
		{
			//initialize answer
			float answer = coeff[num];
			cout << answer << endl;
			for(int i=num-1; i>=0; i--)
			{
				//do multiplication and addition
				answer = (answer*x + coeff[i]);
				cout << "Coefficent: " << coeff[i] << endl;
				cout << "Answer: " << answer << endl;
			}
			cout << "The result is: " << answer << endl;
		}
		else
		{
			//if x = -1000, will flag for quit
			check = false;
		}
	}while(check);
	return;
}
