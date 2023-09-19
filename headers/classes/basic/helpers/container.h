#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include "standard.cpp"
#include "../types/basic/standard.cpp"
using namespace std;
using namespace BychkovVV::main::classes;
using namespace BychkovVV::main::classes::types;
using namespace BychkovVV::main::types;
namespace BychkovVV::main::classes::helpers
  {class Container : public Standard
     {public:
        template <typename VALUE_TYPE> static vector<SearchResultItem<string::size_type, VALUE_TYPE>> getSearchItems(vector<VALUE_TYPE> container)
          {SearchResultItem<string::size_type, VALUE_TYPE> element;
           vector<SearchResultItem<string::size_type, VALUE_TYPE>> result;
           for(element: container)
             {result.push_back(element);                
             }
           return result;
          }
        template <typename KEY_TYPE, typename VALUE_TYPE> static vector<SearchResultItem<KEY_TYPE, VALUE_TYPE>> getMostValues(vector<SearchResultItem<KEY_TYPE, VALUE_TYPE>> object, const *comparer, string::size_type maxElements = string::npos, string::size_type maxValuesCount = string::npos)
          {SearchResultItem<KEY_TYPE, VALUE_TYPE> otherElement, otherElement2;
           vector<SearchResultItem<KEY_TYPE, VALUE_TYPE>> buffer, result;
           copy(object.begin(), object.end(), back_inserter(buffer));
           string::size_type SIZE = object.size(), resultLength = 0, differentValuesCount = 0;
           BychkovVV::main::enums::CompareResult compareResult;
           double compareResult;
           if(((maxElements == string::npos) || (maxElements > 0)) && ((maxValuesCount == string::npos) || (maxValuesCount > 0)))
             {string::size_type index1 = 0;
              bool haveToContinueLoop = index1 < SIZE;
              while(haveToContinueLoop)
                {mostElement = buffer[index1];
                 for(string::size_type index2 = index1 + 1; index2 < SIZE; index2++)
                   {otherElement = buffer[index2];
                    compareResult = comparer(mostElement, otherElement);
                    switch(compareResult)
                      {case BychkovVV::main::enums::CompareResult::WORSE:
                         otherElement2 = otherElement;
                         otherElement = buffer[index1];
                         buffer[index1] = otherElement2;
                         break;                   
                      }                 
                   }
                 result.push_back(buffer[index1]);
                 if((maxValuesCount != string::npos) && ((resultLength == 0) || (comparer(result[resultLength], buffer[index1]) != BychkovVV::main::enums::CompareResult::SAME)) && (++differentValuesCount >= maxValuesCount))
                   {haveToContinueLoop = false;                 
                   }
                 else
                   {if((++index1 >= SIZE) || ((maxElements != string::npos) && (index1 >= maxElements)))
                      {haveToContinueLoop = false;                         
                      }
                   }
                }
             }
           return result;
          }
        const *getSearchResultCompareFunction(bool byValue, bool isMore = false)
          {return []()
             {                 
             }          
          }
        template<typename VALUE_TYPE> VALUE_TYPE static max(vector<VALUE_TYPE> container)
          {vector<SearchResultItem<string::size_type, VALUE_TYPE>> searchItems = getSearchItems(container);                       
           vector<SearchResultItem<string::size_type, VALUE_TYPE>> result = getMostValues<string::size_type, VALUE_TYPE>(searchItems, BychkovVV::main::enums::CompareResult [](SearchResultItem<string::size_type, VALUE_TYPE> element1, SearchResultItem<string::size_type, VALUE_TYPE> element2)
             {if(element1.value == element2.value)                
             });
          }
     };
  }