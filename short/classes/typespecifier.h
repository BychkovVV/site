#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/datatype.h"
using namespace std;
class TypeSpecifier: public DataType<unsigned char>
  {public:
     TypeSpecifier(unsigned char value) : DataType<unsigned char>(value)
       {          
       }
     virtual void readFromBinaryStream(BinaryStream &theStream)
       {this->readDataFromBinaryStream(theStream);          
       }
     virtual unsigned long long toBinaryStream(unsigned char* &target) const
       {return this->dataToBinaryStream(target);          
       }
     static TypeSpecifier& getById(unsigned char id = 0)
       {TypeSpecifier *result = new TypeSpecifier(id);
        return *result;
       }
     enum class ELEMENTS : unsigned char {BOOLEAN = 0, UINT64 = 1, STRING = 2};
     
  };