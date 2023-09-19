#pragma once
#include <cstring>
#include <utility>
#include "standard.cpp"
#include "../types/basic/standard.cpp"
#include "../types/basic/intervalelement.cpp"
using namespace std;
using namespace BychkovVV::main::classes;
using namespace BychkovVV::main::classes::types::basic;
using namespace BychkovVV::main::types;
Matches String::findAll(std::string value, char symbol)
  {unsigned long count = 0;
   std::string::size_type maxSize = value.length() - 1, thisIndex;
   IntervalElement<std::string::size_type> theInterval(0, value.length(), true, false);
   for(thisIndex = 0; theInterval.has(thisIndex = value.find_first_of(symbol, thisIndex)); thisIndex++)
     {count++;   
     }
   Matches result(count);
   for(thisIndex = 0; theInterval.has(thisIndex = value.find_first_of(symbol, thisIndex)); thisIndex++)
     {result.push(symbol, thisIndex, thisIndex + 1);             
     }
   return result;
  }