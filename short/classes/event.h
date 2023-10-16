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
class Event : public Standard
  {protected:
     string id;
     bool defaultIsPrevented;          
   public:  
     void preventDefault()
       {defaultIsPrevented = true;          
       }
  };