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
     {class Calculations : public Standard
        {public:
           static bool compare (string operation, double value1, double value2)
             {return compare(CompareOperation(operation), value1, value2);               
             }
           bool Calculations::compare(CompareOperation &operation, double value1, double value2)            
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
           static bool compare (double value1, double value2, CompareOperation operation)
             {return compare(operation, value1, value2);                
             }
           static bool compare (vector<double> value1, vector<double> value2, CompareOperation operation)
             {return compare(operation, value1, value2);                
             }
           static bool compare (double value1, double value2, string operation)
             {return compare(operation, value1, value2);                
             }
           static bool compare (vector<double> value1, vector<double> value2, string operation)
             {return compare(operation, value1, value2);                
             }
           template <typename TYPE1, typename TYPE2> static map<TYPE2, TYPE1> inverse(map<TYPE1, TYPE12> container)
             {map<TYPE2, TYPE1> result;
              for(pair<TYPE1, TYPE2> value: container)
                {result[value.second] = value.first;        
                }
              return result;
             }
           static double getLength(vector<double> element)
             {double result = 0;
              for(double thisElement : element)
                {result += pow(thisElement, 2);                   
                }
              return sqrt(result); 
             }
        };
     }
  }