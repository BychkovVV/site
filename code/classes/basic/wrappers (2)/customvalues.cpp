#pragma once
#include "headers/classes/basic/wrappers/customvalues.h"
namespace BychkovVV::main::classes::basic::wrappers
  {
   /*export template <typename TYPE> Standard<TYPE>::Standard(TYPE value)
     {this->setValue(value);
     };
   export template <typename TYPE> Standard<TYPE>::Standard(TYPE &value)
     {this->setValue(value);
     }
   export template <typename TYPE> virtual Standard<TYPE>::~Standard<TYPE>()
     {
     }
   export template <typename TYPE> Standard<TYPE>::Standard(TYPE *value)
     {this->setValue(*value);
     }
   export template <typename TYPE> Standard<TYPE>::Standard(const Standard<TYPE> &value):Standard<TYPE>(value.getValue()) 
     {          
     }
   export template <typename TYPE> TYPE Standard<TYPE>::getValue() const
     {return value;          
     }
   export template <typename TYPE> void Standard<TYPE>::setValue(TYPE value)
     {//cout << "Setting value << " << value[0] << endl;
      this->value = value;
     }
   export template <typename TYPE> void Standard<TYPE>::operator = (TYPE value)
     {this->setValue(value);          
     }
   export template <typename TYPE> void Standard<TYPE>::operator = (Standard<TYPE> &value)
     {*this = value.getValue();          
     }
   export template <typename TYPE> void Standard<TYPE>::operator = (Standard<TYPE> &&value)
     {*this = value.getValue();          
     }
   */
  }