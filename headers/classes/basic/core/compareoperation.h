#include "headers/classes/basic/core/standard.h"
#include <map>
#pragma pack(push, 4)
using UNSIGNED_INTEGER = BychkovVV::main::types::basic::core::UNSIGNED_INTEGER;
namespace BychkovVV::main::classes::basic::core
  {class CompareOperation : public Standard
     {protected:
        static const map<string, UNSIGNED_INTEGER> ELEMENTS;
        static const map<unsigned long, string> ELEMENTS_REVERSED;
        BychkovVV::main::types::basic::core::UNSIGNED_INTEGER value;
      public:
        static const unsigned long LESS = 1;
        static const unsigned long LESS_OR_EQUAL = 2;
        static const unsigned long EQUAL = 3;
        static const unsigned long NOT_EQUAL = 4;
        static const unsigned long MORE_OR_EQUAL = 5;
        static const unsigned long MORE = 6;
        unsigned long getValue() const;
        double toDoubleValue();
        template <typename TYPE = unsigned long>bool isAnyOf(TYPE elements...);
        CompareOperation(unsigned long value);
        CompareOperation(string value);
        virtual string toString() const;
        MAYBE_VIRTUAL_PREFIX
        bool operator ==(Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator ==(BychkovVV::main::types::basic::core::UNSIGNED_INTEGER const &value) const;
     };
  }
#pragma pack(pop)