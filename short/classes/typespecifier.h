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
     enum class ELEMENTS : unsigned char {BOOLEAN = 0, UINT64 = 1, STRING = 2};
     
  };