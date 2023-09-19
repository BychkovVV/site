#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
#include "../core/standard.h"
#include "../core/compareoperation.h"
using namespace std;
using CompareOperation = BychkovVV::main::classes::basic::core::CompareOperation;
namespace BychkovVV::main::classes::basic
  {namespace helpers
     {class Calculations : public BychkovVV::main::classes::basic::core::Standard
        {public:
           static bool compare (string operation, double value1, double value2);
           static bool compare (CompareOperation &operation, double value1, double value2);
           static bool compare (CompareOperation &operation, vector<double> value1, vector<double> value2);
           static bool compare (double value1, double value2, CompareOperation operation);
           static bool compare (vector<double> value1, vector<double> value2, CompareOperation operation);
           static bool compare (double value1, double value2, string operation);
           static bool compare (vector<double> value1, vector<double> value2, string operation);
           template <typename TYPE1, typename TYPE2> static map<TYPE2, TYPE1> inverse(map<TYPE1, TYPE2> container);
           static double getLength(vector<double> element);
        };
     }
  }