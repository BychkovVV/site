#include "headers/standard.h"
#include <iostream>
using namespace std;
int main()
  {BychkovVV::main::classes::basic::wrappers::Standard<bool> index(false), index2(false), index3(true);
   BychkovVV::main::classes::basic::wrappers::Vector<bool> index4(false);
   BychkovVV::main::classes::basic::wrappers::CustomValues<bool> index5;
   BychkovVV::main::classes::basic::core::Options theOptions;
   theOptions["ss"] = true;
   cout << theOptions << endl;
   cout << (index || index2);
   cout << (index || index2 || index3);
   index4.push(true);
   
   cout << index4;
   cout << "s";
   return 0;     
  }