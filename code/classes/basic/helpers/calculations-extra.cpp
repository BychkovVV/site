#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
#include "standard.cpp"
#include "../types/basic/standard.cpp"
using namespace std;
using namespace BychkovVV::main::classes;
using namespace BychkovVV::main::classes::types;
using namespace BychkovVV::main::types;
namespace BychkovVV::main::classes
  {class Standard;
   class CompareOperation;
   namespace helpers
     {bool Calculations::compare(CompareOperation &operation, double value1, double value2)            
        {bool result;
         switch(operation.getValue())
           {case CompareOperation::LESS:
              result = (value1 < value2);
              break;                   
            case CompareOperation::LESS_OR_EQUAL:
              result = (value1 <= value2);
              break;
            case CompareOperation::EQUAL:
              result = (value1 == value2);
              break;
            case CompareOperation::NOT_EQUAL:
              result = (value1 != value2);
              break;
            case CompareOperation::MORE_OR_EQUAL:
              result = (value1 >= value2);
              break;
            case CompareOperation::MORE:
              result = (value1 > value2);
              break;
           }
         return result;
        }
      bool Calculations::compare(CompareOperation &operation, vector<double> value1, vector<double> value2)
        {const vector<double>::size_type size1 = value1.size(), size2 = value2.size(), minSize = ;
         const bool sizeIsEqual = (size1 == size2);
         if(!sizeIsEqual && (operation.isAnyOf(CompareOperation::EQUAL, CompareOperation::NOT_EQUAL)))
           {Container::              
           }
        }
     }
  }