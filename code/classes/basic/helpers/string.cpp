#pragma once
#include "string.h"
using namespace std;
using namespace BychkovVV::main::classes;
using namespace BychkovVV::main::classes::types;
using namespace BychkovVV::main::types;
namespace BychkovVV::main::classes::basic::helpers
  {class String : public Standard
     {protected:
        static string getMatchPrefix()
          {const char * result = "%";
           return result;        
          }
        static string getMatchPostfix()
          {const char * result = "";
           return result;        
          }
        static string getMatchBySymbol(char value)
          {return wrapBy(string(&value, 1), getMatchPrefix(), getMatchPostfix());
          }
        static string getMatchBySymbol(char *value)
          {return wrapBy(string(value), getMatchPrefix(), getMatchPostfix());
          }
        static string getMatchBySymbol(string value)
          {return wrapBy(value, getMatchPrefix(), getMatchPostfix());
          }
          
        /*static constexpr const string_view getMatchBySymbol(const  *value)
          {string_view prefix = getMatchPrefix(), postfix = getMatchPostfix();
           const size_t prefixSize = prefix.size(), postfixSize = postfix.size(), valueSize = strlen(value), thisIndex = 0;
           const size_t theSize = prefixSize + valueSize + postfixSize;
           const int valueSizeAsInt = 3;
           std::array<char, value.size()> dest;
           prefix.copy(dest.data(), prefixSize, thisIndex);
           thisIndex += prefixSize;
           valueSize.copy(value.data(), valueSize, thisIndex);
           thisIndex += valueSize;
           valueSize.copy(postfix.data(), 
           return string_view(dest.data());
           /*const char *prefix = getMatchPrefix(), *postfix = getMatchPostfix();
           char *result = new char[strlen(prefix) + strlen(value) + strlen(postfix)];          
           strcpy(result, prefix);
           strcat(result, value);
           strcat(result, postfix);
           return result;
           */
          /*
          }
          */
      public:
        static string wrapBy(string value, string before)
          {return wrapBy(value, before, before);             
          }
        static string wrapBy(string value, SameTypePair<string> wrapper)
          {return get<0>(wrapper) + value + get<1>(wrapper);             
          }
        static string wrapBy(string value, string before, string after)
          {return wrapBy(value, SameTypePair<string>(before, after));             
          }
        static string convert(bool value)
          {return string(value ? "<TRUE>" : "<FALSE>");
          }
        static string convert(int value)
          {return to_string(value);
          }
        static string convert(unsigned int value)
          {return to_string(value);
          }
        static string convert(long value)
          {return to_string(value);
          }
        static string convert(unsigned long value)
          {return to_string(value);
          }
        static string convert(double value)
          {return to_string(value);
          }
        static string convert(string value)
          {return value;
          }
        static string convert(long long unsigned int &value)
          {return to_string(value);
          }          
        static string convert(std::filesystem::path value)
          {return value.string();
          }
        static string convert(char value)
          {return string(&value, 1);
          }
        static string convert(unsigned char value)
          {return string(((char *) & value), 1);
          }
        static string convert(char *value)
          {return string(value);
          }
        static string convert(const char *value)
          {return string(value);
          }
        static string convert(::BychkovVV::main::classes::Standard &value)
          {return value.toString();
          }        
        template<typename TYPE> static string convert(vector<TYPE> value)
          {string result = "";
           bool isNext = false;
           typename vector<TYPE>::size_type THIS_SIZE_TYPE;
           vector<int>::size_type index;
           for(index = 0; index < value.size(); index++)
             {if(isNext)
                {result += ", ";                   
                }
              else
                {isNext += true;                   
                }              
              result += convert(value[index]);                
             }
           return result;
          }
        template< typename... TYPES > string static byTemplate(string theTemplate, TYPES... matches)
          {size_t offset = 0, newOffset = 0;
           const string MATCH = getMatchBySymbol('s');
           const size_t LENGTH_OF_THE_MATCH = MATCH.length();
           bool haveToCheck = true;
           string result = "";           
           ([&]
           {if(haveToCheck)
              {if((newOffset = theTemplate.find(MATCH, offset)) == string::npos)
                 {haveToCheck = false;
                 }
               else
                 {result += theTemplate.substr(offset, newOffset - offset) + convert(matches);        
                  offset = newOffset + LENGTH_OF_THE_MATCH;
                 }
              }
           }(), ...);
           result += theTemplate.substr(offset);
           return result;
          }
        static Matches findAll(std::string value, char symbol)
          {unsigned long count = 0;
           std::string::size_type maxSize = value.length() - 1, thisIndex;
           IntervalElement<std::string::size_type> theInterval(0, value.length(), true, false);
           for(thisIndex = 0; theInterval.has(thisIndex = value.find_first_of(symbol, thisIndex)); thisIndex++)
             {count++;   
             }
           Matches result(count);
           for(thisIndex = 0; theInterval.has(thisIndex = value.find_first_of(symbol, thisIndex)); thisIndex++)
             {result.push(symbol, thisIndex, thisIndex + 1);             
             }
           return result;
          }
     };
  }