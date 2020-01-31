#include <string.h>

void myfunction2(const char *message, unsigned int size);

int main() {

  const char *message = "Hello World\n\0";

  myfunction2(message,strlen(message));

  return 0;
}
