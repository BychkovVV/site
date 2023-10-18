#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/longlongoptions.h"
using namespace std;
class BinaryStreamInformationExchangeMode: public LongLongOptions
  {public:
     static inline unsigned long long DEFAULT_VALUE = 0;
     enum class ELEMENTS : unsigned char {DATA = 1, OPTIONS = 2, TYPE = 4};
     BinaryStreamInformationExchangeMode()
       {if(DEFAULT_VALUE == 0)
          {DEFAULT_VALUE = ((unsigned long long) BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS) | ((unsigned long long) BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA);            
          }          
        BinaryStreamInformationExchangeMode(DEFAULT_VALUE);
       }
     BinaryStreamInformationExchangeMode(unsigned long long value) : LongLongOptions(value)
       {          
       }
  };