#pragma once
#include <string>
#include <vector>
using namespace std;
namespace BychkovVV::main::classes::basic::core
  {/*
     Стандартный, базовый класс для всех остальных классов.
     compareByVector - правила для сравнения его, compareByVector - true - сравнивать по векору
     toString - преобразование в строку.
     toDoubleValue - в численный вид (возможно, дробный).
     toDoubleVectorValue - в векторно-численный вид
   */
   class Standard
     {protected:
        static const bool compareByVector = false;
      public:
        Standard();
        virtual ~Standard();
        virtual string toString() const;
        double toDoubleValue() const;
        vector<double> toDoubleVectorValue() const;
        MAYBE_VIRTUAL_PREFIX
        bool compare(Standard const &value, string operation) const;
        MAYBE_VIRTUAL_PREFIX
        bool compare(string operation, Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator ==(Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator !=(Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator >=(Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator >(Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator <=(Standard const &value) const;
        MAYBE_VIRTUAL_PREFIX
        bool operator <(Standard const &value) const;
      };
  }