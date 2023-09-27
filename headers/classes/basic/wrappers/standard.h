#pragma once
#include "headers/common.h"
#include <ostream>
#include <iostream>
#include "headers/classes/basic/core/standard.h"
namespace BychkovVV::main::classes::basic::wrappers
  {template <typename TYPE> class Standard : public BychkovVV::main::classes::basic::core::Standard
     {protected:
        TYPE value;        
      public:
        Standard(TYPE value)
          {this->setValue(value);
          }
        Standard(TYPE &value)
          {this->setValue(value);
          }
        Standard(TYPE *value)
          {return this->setValue(*value);             
          }
        Standard(const Standard<TYPE> &value) : Standard(value.getValue()) 
          {             
          }
        virtual ~Standard<TYPE>()
          {             
          }
        virtual TYPE getValue() const
          {return value;             
          }
        void setValue(TYPE value)
          {this->value = value;          
          }
        void operator = (TYPE value)
          {this->setValue(value);             
          }
        void operator = (Standard<TYPE> &value)
          {*this = value.getValue();             
          }
        Standard<TYPE>& operator += (const TYPE otherElement)
          {value += otherElement;             
           return *this;
          }
        Standard<TYPE>& operator +() const
          {Standard<TYPE> *linkToTheResult = new Standard<TYPE>(*this);          
           linkToTheResult->setValue(( + 1) * value);
           return *linkToTheResult;
          }
        Standard<TYPE>& operator -() const
          {Standard<TYPE> *linkToTheResult = new Standard<TYPE>(*this);          
           linkToTheResult->setValue(( - 1) * value);
           return *linkToTheResult;
          }
        Standard<TYPE>& operator ~() const
          {Standard<TYPE> *linkToTheResult = new Standard<TYPE>(*this);          
           linkToTheResult->setValue(~ value);
           return *linkToTheResult;
          }
        Standard<TYPE>& operator ++()
          {++value;
           return *this;          
          }
        Standard<TYPE>& operator ++(int)
          {Standard<TYPE> *old = new Standard<TYPE>(*this);
           operator++();
           return *old;          
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
        Standard<TYPE>& operator -= (const TYPE otherElement)
          {value -= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator --()
          {--value;
           return *this;          
          }
        Standard<TYPE>& operator --(int)
          {Standard<TYPE> *old = new Standard<TYPE>(*this);
           operator--();
           return *old;          
          }
        Standard<TYPE>& operator -= (const Standard<TYPE> &otherElement)
          {this -= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator - (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result -= otherElement;
           return result;
          }
        Standard<TYPE> operator - (const Standard<TYPE> &otherElement) const
          {return *this - otherElement.getValue();
          }
        Standard<TYPE>& operator *= (const TYPE otherElement)
          {value *= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator *= (const Standard<TYPE> &otherElement)
          {this *= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator * (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result *= otherElement;
           return result;
          }
        Standard<TYPE> operator * (const Standard<TYPE> &otherElement) const
          {return *this * otherElement.getValue();
          }
        Standard<TYPE>& operator /= (const TYPE otherElement)
          {value /= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator /= (const Standard<TYPE> &otherElement)
          {this /= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator / (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result /= otherElement;
           return result;
          }
        Standard<TYPE> operator / (const Standard<TYPE> &otherElement) const
          {return *this / otherElement.getValue();
          }
        Standard<TYPE>& operator %= (const TYPE otherElement)
          {value %= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator %= (const Standard<TYPE> &otherElement)
          {this %= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator % (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result %= otherElement;
           return result;
          }
        Standard<TYPE> operator % (const Standard<TYPE> &otherElement) const
          {return *this % otherElement.getValue();
          }
        Standard<TYPE>& operator &= (const TYPE otherElement)
          {value &= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator &= (const Standard<TYPE> &otherElement)
          {this &= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator & (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result &= otherElement;
           return result;
          }
        Standard<TYPE> operator & (const Standard<TYPE> &otherElement) const
          {return *this & otherElement.getValue();
          }
        Standard<TYPE>& operator |= (const TYPE otherElement)
          {value |= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator |= (const Standard<TYPE> &otherElement)
          {this |= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator | (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result |= otherElement;
           return result;
          }
        Standard<TYPE> operator | (const Standard<TYPE> &otherElement) const
          {return *this | otherElement.getValue();
          }
        Standard<TYPE>& operator ^= (const TYPE otherElement)
          {value ^= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator ^= (const Standard<TYPE> &otherElement)
          {this ^= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator ^ (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result ^= otherElement;
           return result;
          }
        Standard<TYPE> operator ^ (const Standard<TYPE> &otherElement) const
          {return *this ^ otherElement.getValue();
          }
        Standard<TYPE>& operator <<= (const TYPE otherElement)
          {value <<= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator <<= (const long long otherElement)
          {value <<= otherElement;             
           return *this;
          }  
        Standard<TYPE>& operator <<= (const Standard<TYPE> &otherElement)
          {this <<= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator << (const long long otherElement) const
          {Standard<TYPE> result(this);            
           result <<= otherElement;
           return result;
          }
        Standard<TYPE> operator << (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result <<= otherElement;
           return result;
          }
        Standard<TYPE> operator << (const Standard<TYPE> &otherElement) const
          {return *this << otherElement.getValue();
          }
        Standard<TYPE>& operator >>= (const long long otherElement)
          {value >>= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator >>= (const TYPE otherElement)
          {value >>= otherElement;             
           return *this;
          }
        Standard<TYPE>& operator >>= (const Standard<TYPE> &otherElement)
          {this >>= otherElement.getValue();             
           return *this;
          }
        Standard<TYPE> operator >> (const long long otherElement) const
          {Standard<TYPE> result(this);            
           result >>= otherElement;
           return result;
          }
        Standard<TYPE> operator >> (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result >>= otherElement;
           return result;
          }
        Standard<TYPE> operator >> (const Standard<TYPE> &otherElement) const
          {return *this >> otherElement.getValue();
          }
        friend ostream& operator << (ostream &theStream, const Standard<TYPE> &c)
          {theStream << c.getValue();
           return theStream;             
          }
        friend ostream& operator >> (istream &theStream, const Standard<TYPE> &c)
          {theStream >> c.value;
           return theStream;             
          }
        Standard<TYPE>& operator !() const
          {Standard<TYPE> *linkToTheResult = new Standard<TYPE>(*this);          
           linkToTheResult->setValue(! value);
           return *linkToTheResult;
          }
        Standard<TYPE> operator && (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result = value && otherElement;
           return result;
          }
        Standard<TYPE> operator && (const Standard<TYPE> &otherElement) const
          {return operator &&(otherElement.getValue());
          }
        Standard<TYPE> operator || (const TYPE &otherElement) const
          {Standard<TYPE> result(this);            
           result = value || otherElement;
           return result;
          }
        Standard<TYPE> operator || (const Standard<TYPE> &otherElement) const
          {return operator ||(otherElement.getValue());
          }
          
          
          
          
          
          
          
          
          
          

     };
  }