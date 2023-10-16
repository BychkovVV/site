#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standard.h"
using namespace std;
class EventTriggerTime : public Standard
  {public:
     bool isAfter;
     EventTriggerTime(bool isAfter)
       {this->isAfter = isAfter;          
       }
  };