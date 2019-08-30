/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 
  Purpose: 
  Due date: /2019
  */

//dependencies
#include <string>
#include <iostream>
using namespace std;

//function prototypes
void hello();

//main
int main()
{
	hello();
	return 0;
}

//functions
void hello()
{
	string name;
	cout << "Please enter your name: ";
	getline(cin,name);
	cout << "Hello " + name + "!\n";
	return;
}
