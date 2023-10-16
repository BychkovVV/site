#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standard.h"
#include "short/classes/event.h"
using namespace std;
template <typename THE_CLASS> class Behavior : public Standard
  {protected:
     THE_CLASS element;
   public:
     Behavior(THE_CLASS &element)
       {this->element = element;          
       }
     void set(THE_CLASS value)
       {Event theEvent("set", value);        
        if(passedTriggers(theEvent, false))
          {element.set(value);
           passedTriggers(theEvent, true);             
          }
        element = value;
       }
     THE_CLASS &get()
       {return element;
       }
  };