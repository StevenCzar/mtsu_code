/*Steven Czarnecki
 * CSCI 3130
 * OLA1
 * 1/30/20
 */
#include <string.h>

//prototype for function
void myfunction2(const char *message);

int main() {

	//bad persona joke here
	const char *message = "The Dorm Theme is bad\nDo you know how long you waste\nTo die and hear it?\n-me\n\0";
	//calls asm function
	myfunction2(message);

  return 0;
}
