#include "standard.h"
#include <map>
namespace BychkovVV::main::classes::basic::core
  {class CompareOperation : public Standard
     {protected:
        static const map<string, unsigned long> ELEMENTS;
        static const map<unsigned long, string> ELEMENTS_REVERSED;
        unsigned long value;
      public:
        static const unsigned long LESS = 1;
        static const unsigned long LESS_OR_EQUAL = 2;
        static const unsigned long EQUAL = 3;
        static const unsigned long NOT_EQUAL = 4;
        static const unsigned long MORE_OR_EQUAL = 5;
        static const unsigned long MORE = 6;
        double toDoubleValue();
        CompareOperation(unsigned long value);
        CompareOperation(string value): CompareOperation(ELEMENTS.at(value))
          {
          }
        virtual string toString();
     };
  }