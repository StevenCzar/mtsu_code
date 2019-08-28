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
int ask_for_x()
{
	int x;
	cout << "(Enter -1000 to quit)\nEnter the value of x: ";
	cin >> x;
	return x;
}
int get_num()
{
	int num;
	cout << "Enter the degree of your polynomial: ";
	cin >> num;
	return num;
}

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

void horner(int coeff[], int num)
{
	bool check = true;
	do{
		int x = ask_for_x();
		cout << "Value of x: " << x << endl;
		if(x != -1000)
		{
			float answer = coeff[num];
			cout << answer << endl;
			for(int i=num-1; i>=0; i--)
			{
				answer = (answer*x + coeff[i]);
				cout << "Coefficent: " << coeff[i] << endl;
				cout << "Answer: " << answer << endl;
			}
			cout << "The result is: " << answer << endl;
		}
		else
		{
			check = false;
		}
	}while(check);
	return;
}
