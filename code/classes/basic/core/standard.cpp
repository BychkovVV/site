#include "headers/common.h"
#include "headers/classes/basic/core/standard.h"
#include "headers/classes/basic/helpers/calculations.h"
using Calculations = BychkovVV::main::classes::basic::helpers::Calculations;
namespace BychkovVV::main::classes::basic::core
  {Standard::Standard()
     {        
     }
   Standard::~Standard()
     {        
     }
   string Standard::toString() const
     {return "This type 1";          
     }
   double Standard::toDoubleValue() const
     {return Calculations::getLength(toDoubleVectorValue());            
     }
   vector<double> Standard::toDoubleVectorValue() const
     {return vector<double>{toDoubleValue()};            
     }
   bool Standard::compare(Standard const &value, string operation) const
     {return compare(operation, value);            
     }
   bool Standard::compare(string operation, Standard const &value) const
     {return compareByVector ? Calculations::compare(toDoubleVectorValue(), value.toDoubleVectorValue(), operation) : Calculations::compare(toDoubleValue(), value.toDoubleValue(), operation);            
     }
   bool Standard::operator ==(Standard const& value) const
     {return this->compare("=", value);            
     }
   bool Standard::operator !=(Standard const& value) const
     {return this->compare("!=", value);            
     }
   bool Standard::operator >=(Standard const& value) const
     {return this->compare(">=", value);            
     }
   bool Standard::operator >(Standard const& value) const
     {return this->compare(">", value);            
     }
   bool Standard::operator <=(Standard const& value) const
     {return this->compare("<=", value);            
     }
   bool Standard::operator <(Standard const& value) const
     {return this->compare("<", value);            
     }   
  };