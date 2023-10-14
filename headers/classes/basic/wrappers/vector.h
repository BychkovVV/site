#pragma once
#include "headers/common.h"
#include <algorithm>
#include <string>
#include <ostream>
#include <iostream>
#include "headers/classes/basic/core/standard.h"
#include "headers/classes/basic/wrappers/standard.h"
using namespace std;
namespace BychkovVV::main::classes::basic::wrappers
  {template <typename TYPE> class Vector : public Standard<vector<TYPE>>
     {public:
        Vector()
          {           
          }
        Vector(const TYPE value)
          {push(value);
          }
        Vector(TYPE& value)
          {cout << "s2";
           return;
           push(value);           
          }
        Vector(vector<TYPE> value) : Standard(value)
          {
          }
        Vector(vector<TYPE> &value) : Standard(value)
          {
          }
        Vector(vector<TYPE> *value) : Standard(value)
          {            
          }
        Vector(const Standard<vector<TYPE>> &value) : Standard(value) 
          {             
          }
        void operator = (TYPE value)
          {this->set(value);             
          }
        void set(TYPE value, size_t index)
          {this->value[index] = value;            
          }
        size_t getSize() const
          {return this->value.size();             
          }
        void set(TYPE value, size_t indexOfTheElement, TYPE defaultValue)
          {size_t theMin = min(getSize(), indexOfTheElement);
           TYPE& thisValue = defaultValue;
           for(size_t index = theMin; index <= indexOfTheElement; index++)
             {if(index <= indexOfTheElement)
                {this->value.push_back(defaultValue);                   
                }
              else
                {thisValue = value;                   
                }
              set(thisValue, index);
             }
          }
        const TYPE& get(const size_t index) const
          {return this->value.at(index);             
          }
        void set(TYPE value)
          {const size_t SIZE = value.size();
           for(size_t index = 0; index < SIZE; index++)
             {set(value, index);                
             }
          }
        void operator = (Standard<TYPE> &value)
          {*this = value.getValue();             
          }
        void push(TYPE value)
          {set(value, getSize(), value);            
          }
        string join(string separator) const
          {const size_t SIZE = this->value.size();
           bool havetoAddedSeparator = false;
           string result = "";
           for(size_t index = 0; index < SIZE; index++)
             {if(havetoAddedSeparator)
                {result += separator;                  
                }
              else
                {havetoAddedSeparator = true;                   
                }
              result += to_string((*this)[index]);               
             }              
           return result;
          }
        const TYPE& operator[](size_t index) const
          {return get(index);            
          }
        TYPE& operator[](size_t index)
          {return this->value[index];            
          }
        friend ostream& operator << (ostream &theStream, const Vector<TYPE> &element)
          {theStream << "[" << element.join(", ") << "]";
           return theStream;             
          }
        friend ostream& operator >> (istream &theStream, const Vector<TYPE> &c)
          {theStream >> c.value;
           return theStream;             
          }
     };
  }