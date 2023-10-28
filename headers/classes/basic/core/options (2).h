#pragma once
#include "headers/common.h"
#include "headers/classes/basic/core/standard.h"
#include <string>
#include <map>
using namespace std;
namespace BychkovVV::main::classes::basic::core
  {/*
     Стандартный, базовый класс для всех остальных классов.
     compareByVector - правила для сравнения его, compareByVector - true - сравнивать по векору
     toString - преобразование в строку.
     toDoubleValue - в численный вид ( возможно, дробный).
     toDoubleVectorValue - в векторно-численный вид
   */
   template <typename TYPE = string> class Options : public Standard
     {protected:
        map<TYPE, char> elements;
      public:
        Options()
          {             
          }
        map<TYPE, char> getData() const
          {return elements;             
          }
        const TYPE& get(const size_t index) const
          {return this->value.at(index);             
          }
        char operator[](string index) const
          {return get(index);            
          }
        char& operator[](string index)
          {return this->elements[index];            
          }
        friend ostream& operator << (ostream &theStream, const Options<TYPE> &element)
          {theStream << "{";
           bool isBegging = false;
           map<TYPE, char> data = element.getData();
           for(const auto &[key, value] : data)
             {if(isBegging)
                {theStream << ", ";                   
                }
              else
                {isBegging = true;                   
                }
              theStream << key << ": " << ((value == 0) ? "undefined" : ((value == 1) ? "on" : "off"));                            
             }
           theStream << "}";
           return theStream;             
          }
        friend ostream& operator >> (istream &theStream, const Options<TYPE> &c)
          {theStream >> c.value;
           return theStream;             
          }
        Standard<TYPE>& operator += (const Standard<TYPE> &otherElement)
          {this += otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator + (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result += otherElement;
           return result;
          }
        Standard<TYPE> operator + (const Standard<TYPE> &otherElement) const
          {return *this + otherElement.getValue();
          }
     };
  }