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
        unsigned long getValue() const;
        double toDoubleValue();
        template <typename TYPE = unsigned long>bool isAnyOf(TYPE... elements);
        CompareOperation(unsigned long value);
        CompareOperation(string value);
        virtual string toString() const;
        bool operator ==(unsigned long &value) const;
     };
  }