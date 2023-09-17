#include <string>
using namespace std;
namespace BychkovVV::main::classes
  {/*
     Стандартный, базовый класс для всех остальных классов.
     compareByVector - правила для сравнения его, compareByVector - true - сравнивать по векору
     toString - преобразование в строку.
     toDoubleValue - в численный вид ( возможно, дробный).
     toDoubleVectorValue - в векторно-численный вид
   */
   class Standard
     {protected:
        static const bool compareByVector = false;
      public:
        void Standard::out();
        virtual string toString();
        static bool isInInterval(unsigned long value, unsigned long min, unsigned long max);
        double toDoubleValue();
        vector<double> toDoubleVectorValue();
        bool compare(Standard &value, string operation);
        bool compare(string operation, Standard &value);
        bool operator ==(Standard &value);
        bool operator !=(Standard &value);
        bool operator >=(Standard &value);
        bool operator >(Standard &value);
        bool operator <=(Standard &value);
        bool operator <(Standard &value);
      };
   class Matches;
  }