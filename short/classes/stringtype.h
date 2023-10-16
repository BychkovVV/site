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
class StringType : public DataType<string>
  {public:
   friend bool operator == (const StringType &value1, const StringType &value2)
     {cout << endl << "Comparing equality, value1 (\"" << value1.get() << "\", length: " << to_string(value1.get().size()) << ") and value2 (\"" << value2.get() << "\", length: " << to_string(value2.get().size()) << ")";
      return value1.get() == value2.get();          
     }
     
   friend ostream& operator << (ostream& os, const StringType& type)
     {os << type.get();
      return os;          
     }
   StringType(string value): DataType<string>(value)
     {        
     }
   virtual unsigned long long getSizeInBits() const
     {return BinaryStream::getBitsCountInABytes(this->theValue.size());
     }
   
   virtual void readOptionsFromBinaryStream(BinaryStream &theStream)
     {const unsigned long long theCountInBits = BinaryStream::getBitsCountInABytes(sizeof(unsigned long long));
      unsigned long long theCount;
      theStream.getBits((unsigned char *) &theCount, theCountInBits);
      cout << endl << "Reading string options from binary stream, the length of the string: " << to_string(theCount);
      this->theValue.resize(theCount);
      cout << endl << "The size was set: " << to_string(this->theValue.size()) << ", length: " << to_string(this->theValue.length());
     }
   virtual void readFromBinary(unsigned char *target)
     {const unsigned long long theSize = this->getSizeInBytes();
      char *values;
      values = (char *) target;
      this->theValue.resize(theSize);
      this->theValue.replace(0, theSize, values);
      cout << endl << "After reading object (StringType) from binary representation, size of string: " << to_string(theSize) << ", in bits: " << BinaryStream::getBitsAsString(target, BinaryStream::getBitsCountInABytes(sizeof(unsigned long long))) << ", the string: \"" << this->theValue << "\", in bits: " << BinaryStream::getBitsAsString(target + sizeof(unsigned long long), BinaryStream::getBitsCountInABytes(theSize));
     }
   virtual unsigned long long toBinary(unsigned char* &target) const
     {const unsigned long long sizeOfSize = sizeof(unsigned long long), size = this->theValue.size();  
      target = new unsigned char[sizeOfSize + size];
      memcpy(target, &size, sizeOfSize);
      memcpy(target + sizeOfSize, this->theValue.data(), size);
      cout << endl << "After compying object (StringType) to binary representation, size of string: " << to_string(size) << ", in bits: " << BinaryStream::getBitsAsString(target, BinaryStream::getBitsCountInABytes(sizeOfSize)) << ", the string: \"" << this->theValue << "\", in bits: " << BinaryStream::getBitsAsString(target + sizeOfSize, BinaryStream::getBitsCountInABytes(size));
      return BinaryStream::getBitsCountInABytes(sizeOfSize + size);          
     }
  };