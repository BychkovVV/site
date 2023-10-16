#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
using namespace std;
class BinaryStream;
class Standard
  {public:
     map<string, stack<bool>> booleanSettings;
     map<string, stack<unsigned long long>> unsignedLongLongSettings;
     void pushSetting(string theSetting, bool theValue)
       {booleanSettings[theSetting].push(theValue);
       }
     void pushSetting(string theSetting, unsigned long long theValue)
       {unsignedLongLongSettings[theSetting].push(theValue);
       }
     bool popBooleanSetting(string theSetting)
       {bool result = getBooleanSetting(theSetting);
        booleanSettings[theSetting].pop();
        return result;
       }
     unsigned long long popUnsignedLongLongSetting(string theSetting)
       {unsigned long long result = getUnsignedLongLongSetting(theSetting);
        unsignedLongLongSettings[theSetting].pop();
        return result;
       }
     bool getBooleanSetting(string theSetting)
       {const stack<bool> STACK = booleanSettings[theSetting];
        return (STACK.size() == 0) ? false : STACK.top();          
       }
     unsigned long long getUnsignedLongLongSetting(string theSetting)
       {const stack<unsigned long long> STACK = unsignedLongLongSettings[theSetting];
        return (STACK.size() == 0) ? 0 : STACK.top();          
       }
     virtual void doAccordingBooleanSetting(string setting, bool isComplete)
       {          
       }
     virtual void doAccordingUnsignedLongLongSetting(string setting, bool isComplete)
       {          
       }
    virtual unsigned long long getSizeInBytes() const
      {return 0;
      }    
    virtual unsigned long long getSizeInBits() const
      {return 0;
      }     
    virtual void readFromBinary(unsigned char *target)
      {
      }
    virtual void readFromBinaryStream(BinaryStream &theStream)
      {
      }
    static void fromBinary(unsigned char *target)
      {
      }
    virtual unsigned long long toBinary(unsigned char* &target) const
      {return 0;          
      }     
  };