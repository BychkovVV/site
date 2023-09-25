#include <iostream>
using namespace std;
namespace BychkovVV::main::classes::basic::wrappers
  {template <typename TYPE> class Standard
     {protected:
      public:
        TYPE value;
        ValueSimpleWrapper()
          {          
          }
        ValueSimpleWrapper(TYPE value)
          {this->setValue(value);
          }
        ValueSimpleWrapper(const ValueSimpleWrapper<TYPE> &value):ValueSimpleWrapper(value.getValue()) 
          {          
          }
        virtual TYPE getValue() const
          {return value;          
          }
        void setValue(TYPE value)
          {//cout << "Setting value << " << value[0] << endl;
           this->value = value;
          }
        void operator = (TYPE value)
          {this->setValue(value);          
          }
        void operator = (ValueSimpleWrapper<TYPE> &value)
          {*this = value.getValue();          
          }
        void operator = (ValueSimpleWrapper<TYPE> &&value)
          {*this = value.getValue();          
          }
     };
  }
template <typename VALUE> class Nullable
  {
  }
auto theFunc = [&](unsigned int toOut = 4)
  {cout << toOut;     
  };
int main()
  {theFunc();
   return 0;     
  }