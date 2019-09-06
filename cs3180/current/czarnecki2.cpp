/*Author: Steven Czarnecki
  Course: CSCI 3180

  Lab number: Open Lab 1 
  Purpose: Taylor Series numerical differentiation stuff
  Due date: 09/05/2019
  */

//dependencies
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//function prototypes
void forward_taylor(double x, int n, double h);
void backward_taylor(double x, int n, double h);
void centered_taylor(double x, int n, double h);
double get_x();
int get_n();

//main
int main()
{
	double h = 1;
	double x = get_x();
	int n = get_n();
	forward_taylor(x, n, h);
	backward_taylor(x, n, h);
	centered_taylor(x, n, h);

	return 0;
}

//functions
double get_x()
{
	int x;
	cout << "Enter x in radians: ";
	cin >> x;
	return x;
}
int get_n()
{
	int n;
	cout << "Enter the value for n: ";
	cin >> n;
	return n;
}
void forward_taylor(double x, int n, double h)
{
	double approx, error;
	double ans = sin(x);
	cout << "i\t\t h\t\t value\t\t error\n";
	for(int i = 0; i < n; i++)
	{
		h = h*.25;
		approx = (sin(x+h) - sin(x))/h;
		error = fabs(ans - approx);
		cout << i << "\t\t" << h << "\t\t" << 
		approx << "\t\t" << error << endl;
	}
	return;
}
void backward_taylor(double x, int n, double h)
{
	cout << "i\t\t value\t\t error\n";
	for(int i = 0; i < n; i++)
	{
		
	}
}
void centered_taylor(double x, int n, double h)
{
	cout << "i\t\t value\t\t error\n";
	for(int i = 0; i < n; i++)
	{
		
	}
}