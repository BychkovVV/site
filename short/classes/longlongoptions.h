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
class LongLongOptions: public DataType<unsigned long long>
  {public:
     LongLongOptions(unsigned long long value) : DataType(value)
       {          
       }     
     LongLongOptions& operator += (const unsigned long long type)
       {theValue |= type;         
        return *this;
       }
     LongLongOptions& operator += (const LongLongOptions& type)
       {return *this += type.get();        
       }
     bool has(unsigned long long value)
       {return (value & ~theValue) == 0;          
       }
  };