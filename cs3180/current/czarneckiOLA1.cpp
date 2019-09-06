/*Author: Steven Czarnecki
  Course: CSCI 3180

  Lab number: Open Lab 1 
  Purpose: Taylor Series numerical differentiation stuff
  Due date: 09/05/2019
  */

//NOTE: Tested using g++ compiler on Linux and worked correctly
//Well, some poor tabbing but lack of time to fix cosmetic issue
//Code written using SublimeText and pushed via GitHub

//dependencies
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//function prototypes
void forward_taylor(double x, int n, double h, double ans);
void backward_taylor(double x, int n, double h, double ans);
void centered_taylor(double x, int n, double h, double ans);
double get_x();
int get_n();

//main
int main()
{
	//Initialize values
	double h = 1;
	double x = get_x();
	int n = get_n();
	//Analytical solution uses cos as it is derivative of sin
	double ans = cos(x);
	cout << "Analytical solution: " << ans << endl;
	forward_taylor(x, n, h, ans);
	backward_taylor(x, n, h, ans);
	centered_taylor(x, n, h, ans);

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
//function for forward difference taylor series
void forward_taylor(double x, int n, double h, double ans)
{
	//Initilize values
	double approx, error;
	cout << "******FORWARDS******\n";
	cout << "i\t\t h\t\t value\t\t error\n";
	//loops n times and prints info
	for(int i = 0; i < n; i++)
	{
		h = h*.25;
		approx = (sin(x+h) - sin(x))/h;
		error = fabs(ans - approx);
		cout << (i+1) << "\t\t" << h << "\t\t" << 
		approx << "\t\t" << error << endl;
	}
	return;
}
//function for backward difference taylor series
void backward_taylor(double x, int n, double h, double ans)
{
	double approx, error;
	cout << "******BACKWARDS******\n";
	cout << "i\t\t h\t\t value\t\t error\n";
	for(int i = 0; i < n; i++)
	{
		h = h*.25;
		approx = (sin(x) - sin(x-h))/h;
		error = fabs(ans - approx);
		cout << (i+1) << "\t\t" << h << "\t\t" << 
		approx << "\t\t" << error << endl;
	}
	return;
}
//function for center difference taylor series
void centered_taylor(double x, int n, double h, double ans)
{
	double approx, error;
	cout << "******CENTERED******\n";
	cout << "i\t\t h\t\t value\t\t error\n";
	for(int i = 0; i < n; i++)
	{
		h = h*.25;
		approx = (sin(x+h) - sin(x-h))/(2*h);
		error = fabs(ans - approx);
		cout << (i+1) << "\t\t" << h << "\t\t" << 
		approx << "\t\t" << error << endl;
	}
	return;
}