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
  }