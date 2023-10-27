#pragma once
#include <cstring>
#include <utility>
#include "standard.cpp"
#include "../types/basic/standard.cpp"
using namespace std;
using namespace BychkovVV::main::classes;
using namespace BychkovVV::main::classes::types;
using namespace BychkovVV::main::types;
namespace BychkovVV::main::classes::basic::helpers
  {class String : public Standard
     {protected:
        static string getMatchPrefix();
        static string getMatchPostfix();
        static string getMatchBySymbol(char value);
        static string getMatchBySymbol(char *value);
        static string getMatchBySymbol(string value);
      public:
        static string wrapBy(string value, string before);
        static string wrapBy(string value, SameTypePair<string> wrapper);
        static string wrapBy(string value, string before, string after);
        static string convert(bool value);
        static string convert(int value);
        static string convert(unsigned int value);
        static string convert(long value);
        static string convert(unsigned long value);
        static string convert(double value);
        static string convert(string value);
        static string convert(long long unsigned int &value);
        static string convert(std::filesystem::path value);
        static string convert(char value);
        static string convert(unsigned char value);
        static string convert(char *value);
        static string convert(const char *value);
        static string convert(::BychkovVV::main::classes::Standard &value);
        template<typename TYPE> static string convert(vector<TYPE> value);
        template< typename... TYPES > string static byTemplate(string theTemplate, TYPES... matches);
        static Matches findAll(std::string value, char symbol);
     };
  }