/*Author: Steven Czarnecki
  Course: CSCI 3180

  Lab number: Closed Lab 4 
  Purpose: Remove loss of significance from function
  		   With single and double precision
  Due date: 09/12/2019
  */

//dependencies
#include <cmath>
#include <iostream>

using namespace std;

//function prototypes
void single_f1(float x);
void single_f2(float x);
void double_f1(double x);
void double_f2(double x);

//main
int main()
{
	float x, n;
	double y;
	cout << "Enter the number for x: ";
	cin >> x;
	cout << "Enter the number of iterations: ";
	cin >> n;
	//set for 2nd loop
	y = x;

	//print header
	cout << "single precision\nx\t\t f(x)\t\t f2(x)\n";
	for(int i = 0; i < n; i++)
	{
		//prints subtraction and then addition version of formula
		//single precision
		single_f1(x);
		single_f2(x);
		//increments by power of 10 per run
		x = x*10;
	}

	//2nd print header
	cout << "\ndouble precision\nx\t\t f(x)\t\t f2(x)\n";
	for(int i = 0; i < n; i++)
	{
		//print same as above but with double precission
		double_f1(y);
		double_f2(y);
		y = y*10;
	}
	return 0;
}

//functions
//all single and double versions
void single_f1(float x)
{
	cout << x << "\t\t" << (x * (sqrt(x+1) - sqrt(x)));
}

void single_f2(float x)
{
	cout << "\t\t" << (x/(sqrt(x+1) + sqrt(x)));
}
void double_f1(double x)
{
	cout << x << "\t\t" << (x * (sqrt(x+1) - sqrt(x)));
}

void double_f2(double x)
{
	cout << "\t\t" << (x/(sqrt(x+1) + sqrt(x)));
}