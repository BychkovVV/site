#pragma once
#include "headers/common.h"
#include <algorithm>
#include <string>
#include <map>
#include <ostream>
#include <iostream>
#include "headers/classes/basic/core/standard.h"
#include "headers/classes/basic/wrappers/standard.h"
using namespace std;
namespace BychkovVV::main::classes::basic::wrappers
  {template <typename TYPE> class CustomValues : public Standard<TYPE>
     {protected:
        static map<string, CustomValues<TYPE>> theCustomValues;
        string theValue = "";
      public:
        CustomValues<TYPE>& getSpecial(const string type)
          {if(!theCustomValues.contains(type))
             {CustomValues<TYPE> *result = new CustomValues<TYPE>();
              result->setCustomValue(type);          
              theCustomValues[type] = *result;
             }
           return theCustomValues[type];
          }
        string getCustomValue(string type)
          {return theValue;             
          }
        void setCustomValue(string type)
          {theValue = type;             
          }
        void unsetCustomValue(string type)
          {theValue = "";             
          }
        bool isInCustomValue()
          {return theValue.length() > 0;             
          }
        bool isInCustomValue(string type)
          {return theValue == type;             
          }
     };
  }