#pragma once
#include <vector>
using namespace std;
namespace BychkovVV::main::functions::forCompiler
  {template <typename TYPE> constexpr vector<TYPE> getVector(TYPE value)
     {vector<TYPE> result(value);       
      return result;
     }  
  }