#pragma once
#include <iostream>
#include "standard.h"
namespace BychkovVV::main::classes
  {class Standard
     {protected:
        static const bool compareByVector = false;
      public: 
        void Standard::out()
          {std::cout << "ss";      
          }
        virtual string toString()
          {return "This type 1";          
          }
        static bool isInInterval(unsigned long value, unsigned long min, unsigned long max)
          {return (value >= min) && (value <= max);          
          }
       double toDoubleValue()
         {return helpers::Calculations::getLength(toDoubleVectorValue());            
         }
       vector<double> toDoubleVectorValue()
         {return vector<double>{toDoubleValue()};            
         }
       bool compare(Standard &value, string operation)
         {return compare(operation, value);            
         }
       bool compare(string operation, Standard &value)
         {return compareByVector ? helpers::Calculations::compare(toDoubleVectorValue(), value.toDoubleVectorValue(), operation) : helpers::Calculations::compare(toDoubleValue(), value.toDoubleValue(), operation);            
         }
       bool operator ==(Standard &value)
         {return compare("=", value);            
         }
       bool operator !=(Standard &value)
         {return compare("!=", value);            
         }
       bool operator >=(Standard &value)
         {return compare(">=", value);            
         }
       bool operator >(Standard &value)
         {return compare(">", value);            
         }
       bool operator <=(Standard &value)
         {return compare("<=", value);            
         }
       bool operator <(Standard &value)
         {return compare("<", value);            
         }
      };
   class Matches;
  }