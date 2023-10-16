#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standard.h"
#include "short/classes/binarystream.h"
using namespace std;
class BinaryStreamInformationExchangeMode;
class StandardDataType : public Standard
  {protected:
     unsigned char *data;
     unsigned long long bitsCount;
     bool isAllocated;
     BinaryStreamInformationExchangeMode *exchangeMode;
     virtual unsigned long long getSizeInBytes() const
       {return BinaryStream::getBytesCountInABits(this->getSizeInBits());          
       }
     virtual void allocate()
       {
       }
   public:   
  };