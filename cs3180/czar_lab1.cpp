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
float horner(int coeff[], int num);
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
}
int get_num()
{
	int num;
	cout << "Enter the number of coefficients: ";
	cin >> num;
	return num;
}

void load_array(int coeff[], int num)
{
	for(int i = 0; i < num; i++)
	{
		cout << "Enter the " << i+1 << " coefficient: ";
		cin >> coeff[i];
	}
	return;
}

float horner(int coeff[], int num)
{
	int x = ask_for_x();
	if(x != -1000)
	{
		answer = coeff[0];
		for(int i=1; i<num; i++)
			answer = answer*x + coeff[i];
		cout << "The result is: " << answer << endl;
	}
	return;
}
