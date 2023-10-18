#pragma once
#include "short/classes/standard.h"
#include "short/classes/binarystream.h"
unsigned long long Standard::getSizeInBits() const
  {return BinaryStream::getBitsCountInABytes(this->getSizeInBytes());          
  }
unsigned long long Standard::getSizeInBytes() const
  {return BinaryStream::getBytesCountInABits(this->getSizeInBits());          
  }