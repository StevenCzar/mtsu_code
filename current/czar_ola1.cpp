/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 
  Purpose: 
  Due date: /2019
  */

//dependencies
#include <string>
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
	bool is_valid;
	cout << "Please enter your name: ";
	cin >> name;
	cout << "\n Hello " + name + "!";
	return;
}