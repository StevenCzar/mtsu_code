/*Author: Steven Czarnecki
  Course: CSCI 3180

  Lab number: Lab 2
  Purpose: Eulers/
  Due date: /2019
  */

//dependencies
#include <iostream>
#include <cmath>
using namespace std;

//function prototypes
/*menu - basically does everything
  from print statements to calling the right ODE's*/
bool menu();
{
	double h, t, x, temp, interval, y, soln;
	int n, lower, upper;
	char choice;
	cout << "Which ODE would you like to use?\n";
	cout << "1. x' = x / (1+t)\n";
	cout << "2. x' = t + x\n";
	cout << "3. x' = t - x\n";
	cout << "4. x' = (t - x) / (t + x)\n";
	cout << "Enter any other value to end\n";
	cout << "Choice: ";
	cin >> choice;

	if!(choice = "1"||choice == "2"||choice=="3"||choice =="4")
		return false;

	cout << "Enter the lower bound: ";
	cin >> lower;
	cout << "Enter the upper bound: ";
	cin >> upper;
	cout << "Enter the starting value: ";
	cin >> x;
	cout << "Enter the number of sub intervals: ";
	cin >> n;


	h = (upper-lower)/(n);
	t = lower;
	if(choice == "1")
	{
		cout << "Analytical Solution: " << soln << endl;
		for(int i = 1; i <= n; i++)
		{
			temp = t + (h*first(x,t));
			if((i <= 9)||(i == n))
			{
				cout << t << "\t\t" << temp << endl;
			}
			t = temp;
			x+=h;
		}
	}
	else if(choice == "2")
	{
		cout << "Analytical Solution: " << soln << endl;
		for(int i = 1; i <= n; i++)
		{
			temp = t + (h*second(x,t));
			if((i <= 9)||(i == n))
			{
				cout << t << "\t\t" << temp << endl;
			}
			t = temp;
			x+=h;
		}
	}
	else if(choice == "3")
	{
		cout << "Analytical Solution: " << soln << endl;
		for(int i = 1; i <= n; i++)
		{
			temp = t + (h*third(x,t));
			if((i <= 9)||(i == n))
			{
				cout << t << "\t\t" << temp << endl;
			}
			t = temp;
			x+=h;
		}
	}
	else(choice == "4")
	{
		cout << "Analytical Solution: " << soln << endl;
		for(int i = 1; i <= n; i++)
		{
			eulers = t + (h*fourth(x,t));
			if((i <= 9)||(i == n))
			{
				cout << t << "\t\t" << eulers << endl;
			}
			t = eulers;
			x+=h;
		}
	}
	return true;
}

double eulers(Function
{

}

double heuns()
{

}

double runge_kutta()
{

}

double first(double x, double t);
{
	double est;
	est = (x/(1+t));
	return est;
}
double second(double x, double t);
{
	double est;
	est = t+x;
	return est;
}
double third(double x, double t);
{
	double est;
	est = t-x;
	return est;
}
double fourth(double x, double t);
{
	double est;
	est = (t-x)/(t+x);
	return est;
}

//main
int main()
{
	bool validation;
	validation = true;
	do
	{
		validation = menu();
	}while(validation);	
	return 0;
}

//functions
