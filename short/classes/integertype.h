#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/binarystream.h"
#include "short/classes/datatype.h"
using namespace std;
class IntegerType : public StandardDataType
  {protected:
     bool isSigned;
     bool isLittleEndianBitOrder;
     bool isLittleEndianByteOrder;
     unsigned long long value;
   public:
     friend ostream& operator << (ostream& os, const IntegerType& type)
       {os << to_string(type.getValue());
        return os;          
       }
     unsigned long long getValue() const
       {return value;          
       }
     void setValue(unsigned long long value)
       {this->value = value;          
       }     
     friend bool operator == (const IntegerType &value1, const IntegerType &value2)
       {return value1.getValue() == value2.getValue();          
       }
     IntegerType(unsigned long long value)
       {this->isLittleEndianBitOrder = true;           
        this->isLittleEndianByteOrder = true;
        this->bitsCount = 64;
        this->isAllocated = false;
        this->value = value;
       }
     virtual unsigned long long getSizeInBits()
       {return 64;
       }
     virtual unsigned long long toBinary(unsigned char* &target)
       {target = new unsigned char[8];
        memcpy(target, &this->value, 8);
        return BinaryStream::getBitsCountInABytes(8);
       }
     virtual void readFromBinary(unsigned char *target)
       {memcpy(&this->value, target, 8);
       }
  };