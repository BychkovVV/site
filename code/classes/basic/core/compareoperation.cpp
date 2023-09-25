#pragma once
#include "../../../../headers/classes/basic/core/compareoperation.h"
namespace BychkovVV::main::classes::basic::core
  {double CompareOperation::toDoubleValue()
     {return value;
     }
   CompareOperation::CompareOperation(unsigned long value)
     {this->value = value;             
     }
   CompareOperation::CompareOperation(string value): CompareOperation(ELEMENTS.at(value))
     {           
     }
   string CompareOperation::toString()
     {return ELEMENTS_REVERSED.at(value);             
     }
   unsigned long CompareOperation::getValue() const
     {return value;
     }
   template <typename TYPE = unsigned long>bool CompareOperation::isAnyOf(TYPE... elements)
     {bool result = false;
      TYPE key;
      for (key : {...elements})
        {if(value == key)
           {result = true;
           }                
         if(result)
           {break;                   
           }
        }
      return result;
     }
   bool Standard::operator ==(unsigned long value) const
     {return (getValue() == value);            
     }
  }