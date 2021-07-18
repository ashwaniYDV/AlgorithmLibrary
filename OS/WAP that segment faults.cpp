// https://www.geeksforgeeks.org/core-dump-segmentation-fault-c-cpp/

int main() {
  char *str;

  /* Stored in read only part of data segment */
  str = "GfG";

  /* Problem: trying to modify read only memory */
  *(str + 1) = 'n';
  return 0;
}



// C++ program to illustrate Core Dump/Segmentation fault
#include <iostream>
using namespace std;

int main(void) {
  // allocating memory to p
  int* p = (int*) malloc(8 * sizeof(int));

  *p = 100;

  // deallocated the space allocated to p
  free(p);

  // core dump/segmentation fault
  // as now this statement is illegal
  *p = 110;

  return 0;
}
