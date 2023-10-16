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
     enum class ELEMENTS : unsigned char {DATA = 1, OPTIONS = 2, TYPE = 4};
  };