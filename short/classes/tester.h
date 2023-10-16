#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standard.h"
using namespace std;
class Tester : public Standard
  {protected:
     inline static bool OUTPUT_THIS = true;
   public:
     template <typename TYPE> static bool assertEqual(TYPE value1, TYPE value2, string value1Name, string value2Name)
       {bool result = assertEqual(value1, value2, false);
        if(OUTPUT_THIS || !result)
          {cout << endl << "Checking equality: " << value1Name << " (calculated value: \"" << value1 << "\") = " << value2Name << " (calculated value: \"" << value2 << "\") ?";
           if(result)
             {cout << " - ok";               
             }
           else
             {error("Is not equal");                
             }
          }
        return result;
       }
     template <typename TYPE> static bool assertEqual(TYPE value1, TYPE value2, bool outErrors = true)
       {bool result;
        if(!(result = (value1 == value2)) && outErrors)
          {error("Is not equal");             
          }          
        return result;
       }
     static void error(string message)
       {cerr << endl << "Error: " << message;          
       }     
  };