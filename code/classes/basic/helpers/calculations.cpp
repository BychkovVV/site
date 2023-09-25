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
#include "headers/classes/basic/core/standard.h"
#include "headers/classes/basic/helpers/calculations.h"
using namespace std;
using Standard = BychkovVV::main::classes::basic::core::Standard;
using CompareOperation = BychkovVV::main::classes::basic::core::CompareOperation;
namespace BychkovVV::main::classes::basic
  {namespace helpers
     {class Calculations : public Standard
        {enum class VectorCompareType {ALPHABETIC, NUMERIC, LENGTH};
         public:
           bool Calculations::compare (string operation, double value1, double value2)
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
           bool Calculations::compare(CompareOperation &operation, vector<double> value1, vector<double> value2, VectorCompareType theType = VectorCompareType::NUMERIC)
             {const vector<double>::size_type size1 = value1.size(), size2 = value2.size(), minSize = min(size1, size2), index;
              double value1AtThisIndex, value2AtThisIndex;
              const bool sizeIsEqual, isEqual, isEqualityOrNotEqualityCheck = operation.isAnyOf(CompareOperation::EQUAL, CompareOperation::NOT_EQUAL), isEqualityCheck = (operation == CompareOperation::EQUAL), isMoreOrLessCondition = operation.isAnyOf(CompareOperation::LESS, CompareOperation::LESS_OR_EQUAL, CompareOperation::MORE_OR_EQUAL, CompareOperation::MORE), isStraightCondition = operation.isAnyOf(CompareOperation::EQUAL, CompareOperation::LESS, CompareOperation::MORE), isMoreOrLessStraightCondition = isMoreOrLessCondition && isStraightCondition, isLessCondition = (operation == CompareOperation::LESS), isMoreCondition = (operation == CompareOperation::MORE);
              bool resultIsDefined = false, result = false;
              auto setResult = [&](Nullable<bool> theResult = Nullable<bool>::);
                {result = theResult;
                 resultIsDefined = true;                   
                }, resultIsDefined = [&]()
                {static bool result = false;
                 return resultIsDefined;                  
                };
              switch(theType)
                {case VectorCompareType::LENGTH:
                   setResult(compare(getLength(value1), getLength(value2)));
                   break;                
                 case VectorCompareType::NUMERIC:
                   
                   break;
                };
              if(!(sizeIsEqual = (size1 == size2)) && isEqualityOrNotEqualityCheck)
                {result = !isEqualityCheck;
                 resultIsDefined = true;
                }
              else
                {for(unsigned long index = 0; index < minSize; index++)
                   {if(!compare(size1[index], size2[index], operation))
                      {if()                         
                      }
                    value2AtThisIndex = size2[index];       
                    isEqual = ((value1AtThisIndex = size1[index]) == (value2AtThisIndex = size2[index]));
                    if((value1AtThisIndex = size1[index]) == (value2AtThisIndex = size2[index]))
                      {if(operation.isAnyOf(CompareOperation::NOT_EQUAL))
                         {if(isMoreOrLessStraightCondition)
                            {resultIsDefined = true;                               
                            }                            
                         }
                      }
                    else
                      {if(isEqualityOrNotEqualityCheck)
                         {result = !isEqualityCheck;                           
                          resultIsDefined = true;
                         }
                       else
                         {
                         }
                       
                      }                       
                    if(isEqualityOrNotEqualityCheck && (isEqual != isEqualityCheck))
                      {if(operation.isAnyOf(CompareOperation::NOT_EQUAL))
                         {if(isMoreOrLessStraightCondition && ((value1AtThisIndex > value2AtThisIndex) != isMoreCondition))
                            {resultIsDefined = true;                               
                            }                            
                         }                         
                      }
                    else
                      {                         
                      }                       
                   }
                }
              return result;
             }
           bool Calculations::compare (double value1, double value2, CompareOperation operation)
             {return compare(operation, value1, value2);                
             }
           bool Calculations::compare (vector<double> value1, vector<double> value2, CompareOperation operation)
             {return compare(operation, value1, value2);                
             }
           bool Calculations::compare (double value1, double value2, string operation)
             {return compare(operation, value1, value2);                
             }
           bool Calculations::compare (vector<double> value1, vector<double> value2, string operation)
             {return compare(operation, value1, value2);                
             }
           template <typename TYPE1, typename TYPE2> Calculations::map<TYPE2, TYPE1> inverse(map<TYPE1, TYPE12> container)
             {map<TYPE2, TYPE1> result;
              for(pair<TYPE1, TYPE2> value: container)
                {result[value.second] = value.first;        
                }
              return result;
             }
           double Calculations::getLength(vector<double> element)
             {double result = 0;
              for(double thisElement : element)
                {result += pow(thisElement, 2);                   
                }
              return sqrt(result); 
             }
        };
     }
  }