#include "headers/standard.h"
#include <iostream>
using namespace std;
int main()
  {BychkovVV::main::classes::basic::wrappers::Standard<bool> index(false), index2(false), index3(true);
   cout << (index || index2);
   cout << (index || index2 || index3);
   return 0;     
  }