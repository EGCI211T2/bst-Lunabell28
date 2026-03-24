#include <iostream>
#include <iomanip>
#include <cstdlib> 
using namespace std;
#include "BST.h"

int main(int argc, char **argv) {
  unsigned int i; 
  BST b;
  
  // Start loop at 1 to skip the program name in argv[0]
  for (i = 1; i < argc; ++i) {
       b.insert_node(atoi(argv[i]));
  } 

  // Option 3 prints InOrder, PreOrder, PostOrder, and the Tree
  b.print(3); 
  
  return 0;
}