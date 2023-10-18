/*#include "headers/standard.h"
*/
#include <iostream>
using namespace std;
void theTestNoLink(char *value)
  {value = new char[3];   
  };
void theTest(char *&value)
  {cout << endl << value;     
   value = new char[3];   
  };
int main()
  {char *value = new char[3];
   theTestNoLink(value);
   cout << endl << value;
   theTest(value);
   cout << endl << value;
   /*BychkovVV::main::classes::basic::wrappers::Standard<bool> index(false), index2(false), index3(true);
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
   */
   return 0;     
  }