#pragma once
#include "headers/classes/basic/core/standard.h"
namespace BychkovVV::main::classes::basic::wrappers
  {template <typename TYPE> class Standard : public BychkovVV::main::classes::basic::core::Standard
     {protected:
        TYPE value;        
      public:
        Standard(TYPE value)
          {this->value = value;
          }
        ValueSimpleWrapper(TYPE value)
          {this->setValue(value);
          }
        ValueSimpleWrapper(const ValueSimpleWrapper<TYPE> &value):ValueSimpleWrapper(value.getValue()) 
          {          
          }
        virtual TYPE getValue() const
          {return value;          
          }
        void setValue(TYPE value)
          {//cout << "Setting value << " << value[0] << endl;
           this->value = value;
          }
        void operator = (TYPE value)
          {this->setValue(value);          
          }
        void operator = (ValueSimpleWrapper<TYPE> &value)
          {*this = value.getValue();          
          }
        void operator = (ValueSimpleWrapper<TYPE> &&value)
          {*this = value.getValue();          
          }
     };
  }