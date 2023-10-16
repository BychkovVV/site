#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standarddatatype.h"
using namespace std;
class BinaryStreamInformationExchangeMode;
template <typename TYPE> class DataType : public StandardDataType
  {protected:
     TYPE theValue;
   public:
     friend ostream& operator << (ostream& os, const DataType<TYPE>& type)
       {os << to_string(type.get());
        return os;          
       }
     friend bool operator == (const DataType<TYPE> &value1, const DataType<TYPE> &value2)
       {cout << endl << "Comparing equality, value1 and value2";
        return value1 == value2.get();          
       }
     friend bool operator == (const TYPE value1, const DataType<TYPE> &value2)
       {cout << endl << "Comparing equality, value1 and value2";
        return value1 == value2.get();          
       }
     friend bool operator == (const DataType<TYPE> &value1, const TYPE value2)
       {cout << endl << "Comparing equality, value1 and value2";
        return value1.get() == value2;          
       }
     virtual unsigned long long getSizeInBits() const
       {cout << endl << "Size of this type: " << to_string(sizeof(TYPE));
        return BinaryStream::getBitsCountInABytes(sizeof(TYPE));
       }
     virtual unsigned long long toBinary(unsigned char* &target) const
       {const unsigned long long theSizeInBits = this->getSizeInBits(), theSizeInBytes = BinaryStream::getBytesCountInABits(theSizeInBits);
        target = new unsigned char[theSizeInBytes];
        memcpy(target, &this->theValue, theSizeInBytes);
        return theSizeInBits;
       }
     virtual void readFromBinary(unsigned char *target)
       {memcpy(&this->theValue, target, BinaryStream::getBytesCountInABits(this->getSizeInBits()));
       }
     virtual void readFromBinaryStream(BinaryStream &theStream)
       {this->readOptionsFromBinaryStream(theStream);          
        this->readDataFromBinaryStream(theStream);
       }
     virtual void readOptionsFromBinaryStream(BinaryStream &theStream)
       {
       }
     virtual void readDataFromBinaryStream(BinaryStream &theStream)
       {const unsigned long long theCountInBits = this->getSizeInBits(), theCountInBytes = BinaryStream::getBytesCountInABits(theCountInBits);
        unsigned char *elements = new unsigned char[theCountInBytes];
        theStream.getBits(elements, theCountInBits);
        this->readFromBinary(elements);
       }
     DataType(TYPE value)
       {set(value);        
       }
     void set(TYPE value)
       {theValue = value;
       }
     TYPE get() const
       {return theValue;
       }
  };