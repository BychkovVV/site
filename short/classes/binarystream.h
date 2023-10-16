#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standard.h"
#include "short/classes/datasource.h"
using namespace std;
class BinaryStream : public DataSource
  {protected:
     inline static unsigned long long BITS_COUNT_IN_A_BYTE = 8;
     unsigned long long position; 
     /*
     Данные текущего байта информации
     */
     unsigned char currentByteData;     
   public:
     virtual void assign()
       {this->position = 0;          
       }
     virtual void unassign()
       {this->position = 0;          
       }     
     friend BinaryStream& operator << (BinaryStream &_this, Standard &value)
       {unsigned long long theCount;
        unsigned char *elements;
        theCount = value.toBinary(elements);
        _this.setBits(elements, theCount);
        cout << endl << "Using operator << " << to_string(theCount);
        return _this;
       }
    friend BinaryStream& operator >> (BinaryStream &_this, Standard &value)
       {unsigned long long theCount = value.getSizeInBits();
        unsigned char *elements = new unsigned char[theCount];
        /*_this.getBits(elements, value.getSizeInBits());
        */
        value.readFromBinaryStream(_this);
        cout << endl << "Using operator << " << to_string(theCount);
        return _this;
       }
     static string getBitsAsString(unsigned char value, unsigned long bitsCount, unsigned char theOffset = 0)
       {string result = "";
        const unsigned char endIndex = theOffset + bitsCount;
        unsigned char mask = (1 << ((BITS_COUNT_IN_A_BYTE - 1) - theOffset));
        for(unsigned char index = theOffset; index < endIndex; index++)
          {result += ((value & mask) ? "1" : "0");
           mask >>= 1;             
          }          
        return result;
       }
     static string getBitsAsString(unsigned char value)
       {return getBitsAsString(value, BITS_COUNT_IN_A_BYTE);          
       }
     /*static string getBitsAsString(unsigned char *value, unsigned long bitsCount, unsigned long startOffset)
       {if(startOffset > 0)
          {while(startOffset > BITS_COUNT_IN_A_BYTE)
             {startOffset -= BITS_COUNT_IN_A_BYTE;
              value++;
             }           
          }
        if(startOffset > 0)
          {*value >>= startOffset;             
          }
        return getBitsAsString(*value, bitsCount);
       }
     */
     static unsigned long long getBitsCountInABytes(unsigned long long bytesCount)
       {return bytesCount * BITS_COUNT_IN_A_BYTE;          
       }
     static unsigned long long getBytesCountInABits(unsigned long long bitsCount)
       {return (unsigned long long) ceil(((double) bitsCount) / BITS_COUNT_IN_A_BYTE);          
       }
     static string getBitsAsString(unsigned char *value, unsigned long bitsCount, unsigned long startOffset = 0)
       {while(startOffset >= BITS_COUNT_IN_A_BYTE)
          {startOffset -= BITS_COUNT_IN_A_BYTE;
           value++;
          }        
        string result = "";
        unsigned char thisCount;
        unsigned char bitsLeftCountForFillingThisByte;
        bool haveToContinue;
        while(bitsCount > 0)
          {if(haveToContinue = (bitsCount >= (bitsLeftCountForFillingThisByte = BITS_COUNT_IN_A_BYTE - startOffset)))
             {bitsCount -= (thisCount = bitsLeftCountForFillingThisByte); 
             }
           else
             {thisCount = bitsCount;
              bitsCount = 0;          
             }
           result += getBitsAsString(*(value++), thisCount, startOffset);
           if(haveToContinue && (startOffset > 0))
             {startOffset = 0;
             }
          }
        return result;
       }
     static string getBitsAsString(unsigned char *value)
       {return getBitsAsString(value, BITS_COUNT_IN_A_BYTE);          
       }
     static unsigned char getByteFromString(string byte)
       {unsigned long size = byte.size();
        unsigned char mask = (1 << (BITS_COUNT_IN_A_BYTE - 1)), result = 0;
        for(unsigned long index = 0; index < size; index++)
          {if(byte[index] == '1')
             {result |= mask;                
             }
           mask >>= 1;             
          }
        return result;
       }
     static unsigned char* getBytesFromString(string bytes)
       {unsigned long long thisBitsCount, bitsCount;
        unsigned char *result = new unsigned char[getBytesCountInABits(bitsCount = bytes.size())], *thisPointer = result;
        for(unsigned long long thisBitsCount = 0; thisBitsCount < bitsCount; thisBitsCount += BITS_COUNT_IN_A_BYTE, thisPointer++)
          {*thisPointer = getByteFromString(bytes.substr(thisBitsCount, BITS_COUNT_IN_A_BYTE));
          }
        return result;
       }
     static void outBits(unsigned char value, unsigned long bitsCount, unsigned long startOffset)
       {if(startOffset > 0)
          {value >>= startOffset;
          }
        outBits(value, bitsCount);
       }
     static void outBits(unsigned char value, unsigned long bitsCount)
       {for(unsigned long index = 0; index < bitsCount; index++)
          {cout << (((value & 1) == 1) ? "1" : "0");
           value >>= 1;             
          }
       }
     static void outBits(unsigned char *value, unsigned long bitsCount, unsigned long startOffset)
       {if(startOffset > 0)
          {while(startOffset > BITS_COUNT_IN_A_BYTE)
             {startOffset -= BITS_COUNT_IN_A_BYTE;
              value++;
             }           
          }
        if(startOffset > 0)
          {*value >>= startOffset;             
          }
        cout << *value << endl;
        outBits(*value, bitsCount);
       }
     static void outBits(unsigned char *value, unsigned long bitsCount)
       {unsigned char thisCount;
        while(bitsCount > 0)
          {if(bitsCount >= BITS_COUNT_IN_A_BYTE)
             {bitsCount -= (thisCount = BITS_COUNT_IN_A_BYTE);                
             }
           else
             {thisCount = bitsCount;
              bitsCount = 0;          
             }
           outBits(*value, thisCount);
          }
       }
     static unsigned char setValueOfTheBit(unsigned char value, unsigned long offset, bool thisValue)
       {unsigned char mask = 1;
        if(offset < BITS_COUNT_IN_A_BYTE - 1)
          {mask <<= BITS_COUNT_IN_A_BYTE - 1 - offset;          
          }
        if(thisValue)
          {value |= mask;             
          }
        else
          {value &= ~mask;              
          }
        return value;
       }
     static bool getValueOfTheBit(unsigned char thisData, unsigned char thisOffset)
       {cout << endl << "getValueOfTheBit(" << getBitsAsString(thisData) << ", " << to_string((int) thisOffset) << ")";
        unsigned char mask = 1;
        if(thisOffset < BITS_COUNT_IN_A_BYTE - 1)
          {mask <<= BITS_COUNT_IN_A_BYTE - 1 - thisOffset;          
          }
        cout << endl << "(" << getBitsAsString(thisData) << ") & (" << getBitsAsString(mask) << ")";
        return (thisData & mask) ? true : false;
       }
     static unsigned long long getOffsetInBitsByBytes(unsigned long long theBytesCount)
       {return BITS_COUNT_IN_A_BYTE * theBytesCount;          
       }
     virtual unsigned long long getBitsPoistion()
       {return position;          
       }
     virtual unsigned long long getBitsPoistionAtTheStartOfTheByte()
       {return getBitsPoistion() - getOffsetInBits();          
       }
     virtual unsigned char getCurrentByteData()
       {return currentByteData;          
       }
     virtual unsigned char toPreviousByte()
       {return 0;          
       }
     virtual unsigned char toNextByte()
       {return 0;          
       }
     virtual void setCurrentByteData(unsigned char newValue, bool withOutReturningPosition)
       {this->setCurrentByteData(newValue);          
       }  
     virtual void setCurrentByteData(unsigned char newValue)
       {currentByteData = newValue;          
       }     
     static unsigned long long getPoistionInTheBytesByPositionInTheBits(unsigned long long position)
       {return position / BITS_COUNT_IN_A_BYTE;          
       }
     virtual unsigned long long getBytePoistion()
       {return getPoistionInTheBytesByPositionInTheBits(this->getBitsPoistion());          
       }
     virtual void setBytePosition(unsigned long long offset)
       {this->setBitsPoistion(getOffsetInBitsByBytes(offset) + getOffsetInBits());          
       }
     unsigned long long getOffsetInBits()
       {return this->getBitsPoistion() % BITS_COUNT_IN_A_BYTE;          
       }
     virtual void setBitsPoistion(unsigned long long position)
       {this->position = position;          
        this->currentByteData = this->getCurrentByteData();
        cout << endl << "New position in Binary Stream: " << position;
        cout << endl << "Current byte data: " << getBitsAsString(this->currentByteData);
       }
     virtual void setOffsetInBits(unsigned long long offset)
       {this->setBitsPoistion(getBitsPoistionAtTheStartOfTheByte() + offset);          
       }
     const unsigned long FROM_FILE = 1;
     BinaryStream()
       {this->assign();       
       }
     /*
     getBits - считать по адресу value bitsCount битов
     */
     void getBits(unsigned char *value, unsigned long int bitsCount)
       {/*
          thisValueToCopy - указатель на текущтий байт, куда идёт копирование данных
          MAX_BITS_COUNT - Индекс последнего бита в байте (начиная с нуля) = 7
          thisOffset - отступ от начала байта текущего указателя, bytePosition - адрес текущего указателя в байтах, index - индекс теущего бита, начиная с 0.
        */
        logPosition(to_string(__LINE__));
        unsigned char thisData = getCurrentByteData(), *thisValueToCopy, MAX_BITS_COUNT = BITS_COUNT_IN_A_BYTE - 1;
        logPosition(to_string(__LINE__));
        unsigned long long thisOffset = getOffsetInBits(), bytePosition = getBytePoistion(), index;
        /*if(thisOffset > 0)
          {thisData >>= thisOffset;             
          }
        */
        cout << endl << "Information about the current byte: " << getBitsAsString(thisData) << ", offset in bits = " << thisOffset;
        cout << endl << "Gettings bits, count = " << bitsCount;
        this->doAccordingBooleanSetting("restorePosition", false);
        const unsigned char defaultMask = (1 << MAX_BITS_COUNT);
        unsigned char mask;
        for(index = 0; index < bitsCount; index++)
          {/*
            index % BITS_COUNT_IN_A_BYTE - .
           */
           /*
             Если копируем новый байт (относительно адресации, куда идёт копирование данных), то устанавливает указатель в правильную позиции и обнуляем байт, куда нужно скопировать (делаем все его биты равными нулю), иначе, просто "сдвигаем" биты на 1 влево для копирования нового бита
           */
           if(index % BITS_COUNT_IN_A_BYTE == 0)
             {thisValueToCopy = value++;                
              *thisValueToCopy = 0;
              mask = defaultMask;
             }
           
           /*
             Добавляем текущий бит в результат
           */
           if(getValueOfTheBit(thisData, thisOffset))
             {*thisValueToCopy |= mask;                
             }
           mask >>= 1;
           cout << endl << "on " << index << ", offset = " << thisOffset << ": " << getBitsAsString(*thisValueToCopy);
           /*
             
           */
           position++;
           if(thisOffset == MAX_BITS_COUNT)
             {thisData = this->toNextByte();
              thisOffset = 0;
             }
           else
             {thisOffset++;                
             }
          }
        this->doAccordingBooleanSetting("restorePosition", true);
       }
     virtual void logPosition(string message)
       {cout << endl << message << ": " << "unknown";          
       }
     virtual void logPosition()
       {logPosition("Position in file (in bytes)");          
       }
     virtual void setBitsFromString(string valueAsString)
       {this->setBits(BinaryStream::getBytesFromString(valueAsString), valueAsString.size());       
       }
     virtual string getBitsToString(unsigned long theCount)
       {unsigned char *value = new unsigned char[getBytesCountInABits(theCount)];
        this->getBits(value, theCount);
        return getBitsAsString(value, theCount);
       }
     virtual void doAccordingBooleanSetting(string setting, bool isComplete)
       {if(this->getBooleanSetting(setting) && (setting == "restorePosition"))
          {if(isComplete)
             {unsigned long long theOriginalPosition = popUnsignedLongLongSetting(setting);
              cout << "Restoring original position (in bits) after operation (now: " << position << ", original: " << theOriginalPosition << ")";
              this->setBitsPoistion(theOriginalPosition);
             }
           else
             {cout << endl << "Have to restore position (in bits) after operation, saving position (" << to_string(position) << ")";
              this->pushSetting(setting, position);              
             }              
          }          
       }
     void setBits(unsigned char *value, unsigned long int bitsCount)
       {unsigned char thisData = getCurrentByteData(), thisValueToCopy, MAX_BITS_COUNT = BITS_COUNT_IN_A_BYTE - 1;
        unsigned long long thisOffset = getOffsetInBits(), bytePosition = getBytePoistion(), index, initialPosition;
        bool thisValue, isNotSetYet = true;
        unsigned char mask = (1 << MAX_BITS_COUNT);
        cout << endl << "Setting bits, position in the destination in bytes: " << to_string(bytePosition) << ", destination offset in bits (from start of the byte): " << to_string(thisOffset) << ", count of bits to set = " << bitsCount << ", current byte in the destiation: " << getBitsAsString(thisData) << endl;        
        logPosition();
        this->doAccordingBooleanSetting("restorePosition", false);
        for(index = 0; index < bitsCount; index++)
          {if(index % BITS_COUNT_IN_A_BYTE == 0)
             {thisValueToCopy = *(value++);                
             }
           else
             {thisValueToCopy <<= 1;                
             }
           thisValue = (thisValueToCopy & mask) ? true : false;
           cout << endl << "Setting bits, position in bits (zero-based) of the source (means variable) = " << to_string(index) << ", thisValueToCopy = " << getBitsAsString(thisValueToCopy) << ", this value of the bit: " << (thisValue ? "1" : "0");        
           /*cout << "thisValue = " << thisValue << endl;        
           */
           if(isNotSetYet)
             {isNotSetYet = false;                
             }
           else
             {if(thisOffset == 0)
                {cout << endl << "Saving this byte (" << to_string(getBytePoistion()) << "-th, value is: \"" << getBitsAsString(thisData) << "\") to the target stream";
                 cout << endl << "To next byte when trying to set bits, byte: \"" << getBitsAsString(thisData) << "\"";
                 //setBitsPoistion(getOffsetInBitsByBytes(++bytePosition));
                }           
             }
           thisData = setValueOfTheBit(thisData, thisOffset, thisValue);
           cout << endl << "Destination byte after copying " << to_string(index + 1) << "-th bit (" << (thisValue ? "1" : "0") << ") of the source: " << getBitsAsString(thisData) << ", offset in the destination: " << to_string(thisOffset);
           if(thisOffset == MAX_BITS_COUNT)
             {cout << endl << "thisOffset == MAX_BITS_COUNT, have to call setCurrentByteData";
              this->setCurrentByteData(thisData, true);                 
              thisOffset = 0;
             }
           else
             {thisOffset++;
             }
           position++;
          }
        if(!isNotSetYet)
          {cout << endl << "Saving this byte (" << to_string(getBytePoistion()) << "-th, value is: \"" << getBitsAsString(thisData) << "\") to the target stream";
           this->setCurrentByteData(thisData);
          }
        this->doAccordingBooleanSetting("restorePosition", true);
        cout << endl << "Position after writing: " << position;
       }
     void get()
       {          
       }     
  };