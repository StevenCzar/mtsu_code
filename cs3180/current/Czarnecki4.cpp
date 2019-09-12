/*Author: Steven Czarnecki
  Course: CSCI 3180

  Lab number: Closed Lab 4 
  Purpose: Remove loss of significance from function
  Due date: 09/12/2019
  */

//dependencies
#include <cmath>
#include <iostream>

using namespace std;

//function prototypes
void function1(double x);
void function2(double x);

//main
int main()
{
	double x, n;
	cout << "Enter the number for x: ";
	cin >> x;
	cout << "Enter the number of iterations: ";
	cin >> n;

	cout << "x\t\t f(x)\t\t f2(x)\n";
	for(int i = 0; i < n; i++)
	{
		function1(x, n, i);
		function2(x, n, i);
		x = x*10;
	}
	return 0;
}

//functions
void function1(double x)
{
	cout << x << "\t\t" << (x * (sqrt(x+1) - sqrt(x)));
}

void function2(double x)
{
	cout << "\t\t" << (x/(sqrt(x+1) + x));
}