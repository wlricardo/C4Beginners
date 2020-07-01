#include <stdio.h>

int main(void) {
  
  int *iPtr;
  char *cPtr;
  float *fPtr;

  int iNumber;
  float fNumber;
  char cChar;

  iPtr = &iNumber;
  cPtr = &cChar;
  fPtr = &fNumber;

  // Prints the value of each non-pointer variable.
  printf("\n The value of iNumber is %d", iNumber);
  printf("\n The value of fNumber is %.2f", fNumber);
  printf("\n The value of cChar is %c", cChar);

  // Prints the value of each pointer variable.
  printf("\n\n The value of iPtr is %p", iPtr);
  printf("\n The value of fPtr is %p", fPtr);
  printf("\n The value of cPtr is %p", cPtr);
  
  // Prints the address of each non-pointer variable.
  printf("\n\n The address of iNumber is %p", &iNumber);
  printf("\n The address of fNumber is %p", &fNumber);
  printf("\n The address of cChar is %p", &cChar);
  
  // Prints the address of each pointer variable.
  printf("\n\n The address of iPtr is %p", &iPtr);
  printf("\n The address of fPtr is %p", &fPtr);
  printf("\n The address of cPtr is %p", &cPtr);

  return 0;
}