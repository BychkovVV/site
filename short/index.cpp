#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
using namespace std;
class Standard
  {public:
     map<string, stack<bool>> booleanSettings;
     map<string, stack<unsigned long long>> unsignedLongLongSettings;
     void pushSetting(string theSetting, bool theValue)
       {booleanSettings[theSetting].push(theValue);
       }
     void pushSetting(string theSetting, unsigned long long theValue)
       {unsignedLongLongSettings[theSetting].push(theValue);
       }
     bool popBooleanSetting(string theSetting)
       {bool result = getBooleanSetting(theSetting);
        booleanSettings[theSetting].pop();
        return result;
       }
     unsigned long long popUnsignedLongLongSetting(string theSetting)
       {unsigned long long result = getUnsignedLongLongSetting(theSetting);
        unsignedLongLongSettings[theSetting].pop();
        return result;
       }
     bool getBooleanSetting(string theSetting)
       {const stack<bool> STACK = booleanSettings[theSetting];
        return (STACK.size() == 0) ? false : STACK.top();          
       }
     unsigned long long getUnsignedLongLongSetting(string theSetting)
       {const stack<unsigned long long> STACK = unsignedLongLongSettings[theSetting];
        return (STACK.size() == 0) ? 0 : STACK.top();          
       }
     virtual void doAccordingBooleanSetting(string setting, bool isComplete)
       {          
       }
     virtual void doAccordingUnsignedLongLongSetting(string setting, bool isComplete)
       {          
       }
     
  };
class Event : public Standard
  {protected:
     string id;
     bool defaultIsPrevented;          
   public:  
     void preventDefault()
       {defaultIsPrevented = true;          
       }
  };
class DataSource : public Standard
  {     
  };
class BinaryStream : public DataSource
  {protected:
     inline static unsigned long long BITS_COUNT_IN_A_BYTE = 8;
     unsigned long long position; 
     /*
     Данные текущего байта информации
     */
     unsigned char currentByteData;     
   public:
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
       {position = 0;       
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
        unsigned char mask = (1 << MAX_BITS_COUNT);
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
       {unsigned char *values = BinaryStream::getBytesFromString(valueAsString);
        this->setBits(BinaryStream::getBytesFromString(valueAsString), thisString.size());       
        this->doAccordingBooleanSetting("restorePosition", false);
        pushSetting("restorePosition", false);
        string thisString;
        const unsigned long long theLength = valueAsString.size();
        for(unsigned long long thisIndex = 0; thisIndex < theLength; thisIndex += BITS_COUNT_IN_A_BYTE)
          {unsigned char value = BinaryStream::getByteFromString(thisString = valueAsString.substr(thisIndex, BITS_COUNT_IN_A_BYTE));
           cout << endl << "Byte: " << to_string(value) << ", size: " << thisString.size();
           this->setBits(&value, thisString.size());
          }
        popBooleanSetting("restorePosition");
        this->doAccordingBooleanSetting("restorePosition", true);
       }
     virtual string getBitsToString(unsigned long theCount)
       {unsigned char *value = new unsigned char[getBytesCountInABits(theCount)];
        getBits(value, theCount);
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
                 this->setCurrentByteData(thisData);
                 thisData = this->toNextByte();
                 //setBitsPoistion(getOffsetInBitsByBytes(++bytePosition));
                }           
             }
           thisData = setValueOfTheBit(thisData, thisOffset, thisValue);
           cout << endl << "Destination byte after copying " << to_string(index + 1) << "-th bit (" << (thisValue ? "1" : "0") << ") of the source: " << getBitsAsString(thisData);
           if(thisOffset == MAX_BITS_COUNT)
             {thisOffset = 0;
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
class FileBinaryStream : public BinaryStream
  {protected:
     std::fstream *theValue;
     bool sizeIsDefined;
     unsigned long long size;
     inline static bool WITH_RETURNING_POSITION = true;
   public:
     /*virtual void setBitsPoistion(unsigned long long position)
       {theValue->seekg(getPoistionInTheBytesByPositionInTheBits(position));
        BinaryStream::setBitsPoistion(position);          
       }
     */
     unsigned long long getSizeInBytes()
       {if(!sizeIsDefined)
          {unsigned long long thePosition = theValue->tellp();
           theValue->seekg(0, ios_base::end);
           if((size = theValue->tellp()) != thePosition)
             {theValue->seekg(thePosition, ios_base::beg);                
             }
           sizeIsDefined = true;
          }
        return size;
       }
     void setSizeInBytes(unsigned long long size)
       {this->size = size;
       }
     FileBinaryStream(string value): BinaryStream()
       {theValue = new fstream(value, theValue->binary | theValue->in | theValue->out);
        sizeIsDefined = false;
        if(!theValue->is_open())
          {theValue = new fstream(value, theValue->binary | theValue->out);              
           theValue->close();
           theValue = new fstream(value, theValue->binary | theValue->in | theValue->out);
          }
        cout << endl << "Attempt to to open file \"" << value << "\", result: " << (theValue->is_open() ? "" : "not ") << "opened, good: " << (theValue->good() ? "yes" : "no") << ((theValue->is_open() && theValue->good()) ? string("") : (string(", error: ") + string(strerror(errno))));
        theValue->seekg(0, ios_base::end);
        cout << endl << "Size: " << theValue->tellp();
        theValue->seekg(0, ios_base::beg);
        cout << endl << "Position: " << theValue->tellp();
        /*this->setBitsPoistion(0);
        */
       }
     virtual void logPosition(string message)
       {cout << endl << message << ": " << theValue->tellp();          
       }
     virtual void logPosition()
       {logPosition("Position in file (in bytes)");          
       }
     virtual unsigned long long getBitsPoistion()
       {return BinaryStream::getBitsPoistion();          
       }
     virtual void setBitsPoistion(unsigned long long position)
       {cout << endl << "Seeking to: " << getPoistionInTheBytesByPositionInTheBits(position);
        theValue->seekg(getPoistionInTheBytesByPositionInTheBits(position));
        BinaryStream::setBitsPoistion(position);
       }
     bool isAtEnd()
       {return this->theValue->tellp() == this->getSizeInBytes();          
       }
     unsigned char getCurrentByteData()
       {char result = 0;
        long long startPosition = theValue->tellp(), thisPosition;
        cout << endl << "startPosition before getting current byte data in file: " << theValue->tellp();
        if(!this->isAtEnd())
          {*theValue >> result;          
          }
        cout << endl << "startPosition after getting current byte data in file: " << theValue->tellp();
        if(WITH_RETURNING_POSITION && ((thisPosition = theValue->tellp()) != startPosition))
          {cout << endl << "Position was chanbged, returning it";
           if(thisPosition > startPosition)
             {theValue->seekp(-1, ios_base::cur);            
             }
           else
             {theValue->seekp(0);
              cout << endl << "This position: " << theValue->tellp();
             }
          }
        BinaryStream::getCurrentByteData();
        cout << endl << "Tellp after getting byte: " << theValue->tellp();
        if(theValue->tellp() == -1)
          {cout << endl << "Tellp after getting byte is -1";
           theValue->seekp(0, ios_base::beg);             
           cout << endl << "Tellp after getting byte and seekp is " << theValue->tellp();
          }
        return result;
       }
     virtual unsigned char toPreviousByte()
       {theValue->seekp(-1, ios_base::cur);          
        return this->getCurrentByteData();                 
       }
     virtual unsigned char toNextByte()
       {theValue->seekp(1, ios_base::cur);          
        return this->getCurrentByteData();
       }     
     virtual void setCurrentByteData(unsigned char newValue)
       {cout << "Called setCurrentByteData on file class with new Value = " << newValue << ", initial position: " << theValue->tellp() << endl;
        *theValue << newValue;          
        if(WITH_RETURNING_POSITION)
          {theValue->seekp(-1, ios_base::cur);
          }
       }       
     bool getBit()
       {unsigned char result = 0;
        getBits(&result, 1);
        cout << endl << "Getting bit, got: " << getBitsAsString(result);
        cout << endl << "1: " << getBitsAsString(1);
        cout << endl << "(result & (1)): " << getBitsAsString((result & (1)));
        
        return (result & (1)) ? true : false;
       }
     void setBit(bool value)
       {unsigned char result = value ? (1 << BITS_COUNT_IN_A_BYTE - 1) : 0;
        setBits(&result, 1);
       }
     unsigned char getByte()
       {unsigned char result = 0;
        getBits(&result, BITS_COUNT_IN_A_BYTE);
        return result;
        //streambuf buffer;
        //.sputn((char *) value);
       }
     void set(unsigned char *value, unsigned long int count)
       {setBits(value, count * BITS_COUNT_IN_A_BYTE);
        //streambuf buffer;
        //.sputn((char *) value);
       }
     ~FileBinaryStream()
       {cout << endl << "Closing file";
        theValue->close();         
       }
  };
template <typename TYPE> class DataType : public Standard
  {protected:
     TYPE theValue;
   public:
     DataType(TYPE value)
       {set(value);        
       }
     void set(TYPE value)
       {theValue = value;
       }
     TYPE get()
       {return theValue;
       }
  };
class IntegerType : DataType<int>
  {
  };
template <typename THE_CLASS> class Behavior : public Standard
  {protected:
     THE_CLASS element;
   public:
     Behavior(THE_CLASS &element)
       {this->element = element;          
       }
     void set(THE_CLASS value)
       {Event theEvent("set", value);        
        if(passedTriggers(theEvent, false))
          {element.set(value);
           passedTriggers(theEvent, true);             
          }
        element = value;
       }
     THE_CLASS &get()
       {return element;
       }
  };
class Tester : public Standard
  {protected:
     inline static bool OUTPUT_THIS = true;
   public:
     template <typename TYPE> static bool assertEqual(TYPE value1, TYPE value2, string value1Name, string value2Name)
       {bool result = assertEqual(value1, value2, false);
        if(OUTPUT_THIS || !result)
          {cout << endl << "Checking equality: " << value1Name << " (calculated value: \"" << value1 << "\") = " << value2Name << " (calculated value: \"" << value2 << "\") ?";
           if(result)
             {cout << " - ok";               
             }
           else
             {error("Is not equal");                
             }
          }
        return result;
       }
     template <typename TYPE> static bool assertEqual(TYPE value1, TYPE value2, bool outErrors = true)
       {bool result;
        if(!(result = (value1 == value2)) && outErrors)
          {error("Is not equal");             
          }          
        return result;
       }
     static void error(string message)
       {cerr << endl << "Error: " << message;          
       }     
  };
void testGetBytesCountInABits()
  {Tester::assertEqual((unsigned long long) 1, BinaryStream::getBytesCountInABits(4), "1 byte", "BinaryStream::getBytesCountInABits(4)");    
   Tester::assertEqual((unsigned long long) 1, BinaryStream::getBytesCountInABits(7), "1 byte", "BinaryStream::getBytesCountInABits(7)");
   Tester::assertEqual((unsigned long long) 2, BinaryStream::getBytesCountInABits(12), "2 byte", "BinaryStream::getBytesCountInABits(12)");
   Tester::assertEqual((unsigned long long) 4, BinaryStream::getBytesCountInABits(32), "4 byte", "BinaryStream::getBytesCountInABits(32)");
  };
void testGetBitsAsString()
  {unsigned char values[2];
   values[0] = 128;
   values[1] = 129;  
   string value = "1000000010000001";
   Tester::assertEqual(value, BinaryStream::getBitsAsString(values, 16), value, "BinaryStream::getBitsAsString(values, 16)");
   value = "00000001000000";
   Tester::assertEqual(value, BinaryStream::getBitsAsString(values, 14, 1), value, "BinaryStream::getBitsAsString(values, 14, 1)");
   value = "010";
   Tester::assertEqual(value, BinaryStream::getBitsAsString(values, 3, 7), value, "BinaryStream::getBitsAsString(values, 3, 7)");
   value = "1000000010000001";
   Tester::assertEqual(value, BinaryStream::getBitsAsString(values, 16), value, "BinaryStream::getBitsAsString(values, 16)");
   value = "100000001";
   Tester::assertEqual(value, BinaryStream::getBitsAsString(values, 9), value, "BinaryStream::getBitsAsString(values, 9)");
  };
void testGetBytesFromString()
  {unsigned char *values;
   string title = "(*BinaryStream::getBytesFromString(\"01\") = ";
   values = BinaryStream::getBytesFromString("01");
   title += to_string(*values) + ")";
   Tester::assertEqual(*values, (unsigned char) 64, title, "64");
   values = BinaryStream::getBytesFromString("01000001011");
   title = "(*BinaryStream::getBytesFromString(\"01000001011\") = " + to_string(*values) + ")";
   Tester::assertEqual(*values, (unsigned char) 65, title, "65");
   title = "(*(BinaryStream::getBytesFromString(\"01000001011\") + 1) = " + to_string(*(values + 1)) + ")";
   Tester::assertEqual(*(values + 1), (unsigned char) 96, title, "96");
  }
void testFileReadAndWrite()
  {FileBinaryStream element("C:\\s2.txt");
   string theValue1;
   element.setBitsFromString(theValue1 = "01");
   FileBinaryStream element2("C:\\s2.txt");
   string theValue2 = element2.getBitsToString(2);
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
   FileBinaryStream element3("C:\\s2.txt");
   element3.setBitsFromString(theValue1 = "10");
   FileBinaryStream element4("C:\\s2.txt");
   theValue2 = element4.getBitsToString(2);
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
   FileBinaryStream element5("C:\\s2.txt");
   element5.setBitsPoistion(1);
   element5.setBitsFromString(theValue1 = "10");
   FileBinaryStream element6("C:\\s2.txt");
   theValue2 = element6.getBitsToString(3);
   theValue1 = "110";
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
   FileBinaryStream element7("C:\\s2.txt");
   element7.setBitsPoistion(7);
   element7.setBitsFromString(theValue1 = "101");
   FileBinaryStream element8("C:\\s2.txt");
   element8.setBitsPoistion(7);
   theValue2 = element8.getBitsToString(3);
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
   FileBinaryStream element9("C:\\s2.txt");
   element9.setBitsPoistion(0);
   element9.setBitsFromString(theValue1 = "1011011011011011");
   FileBinaryStream element10("C:\\s2.txt");
   theValue2 = element10.getBitsToString(16);
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
  }
void testAll()
  {testGetBytesCountInABits();
   testGetBitsAsString();
   testGetBytesFromString();
   testFileReadAndWrite();
  };
int main()
  {if(true)
     {testAll();
      return 0;
      unsigned char values[2];
      values[0] = 128;
      values[1] = 129;      
      cout << endl << BinaryStream::getBitsAsString(values, 16);
      cout << endl << BinaryStream::getBitsAsString(values, 15);
      cout << endl << BinaryStream::getBitsAsString(values, 9);
      return 0;
      cout << endl << "4 bits stored in " << to_string(BinaryStream::getBytesCountInABits(4)) << " byte";
      cout << endl << "7 bits stored in " << to_string(BinaryStream::getBytesCountInABits(7)) << " byte";
      cout << endl << "12 bits stored in " << to_string(BinaryStream::getBytesCountInABits(12)) << " byte";
      cout << endl << "32 bits stored in " << to_string(BinaryStream::getBytesCountInABits(32)) << " byte";
      return 0;
      cout << to_string(BinaryStream::getByteFromString("10000001"));
      return 0;
     }
   FileBinaryStream element("C:\\s2.txt");
   element.pushSetting("restorePosition", true);
   element.setBitsFromString("01");
   return 0;
   cout << endl << "value of ss (Is false ?): " << element.getBooleanSetting("ss");   
   cout << endl << "value of ss (Is true ?): " << element.getBooleanSetting("ss");
   element.popBooleanSetting("ss");
   cout << endl << "value of ss:  (Is false ?)" << element.getBooleanSetting("ss");
   element.popBooleanSetting("ss");
   cout << endl << "value of ss:  (Is ?)" << element.getBooleanSetting("ss") << "??";
   return 0;
   element.setBitsFromString("01");
   return 0;
   element.setBit(true);
   element.setBit(true);
   bool value;
   value = element.getBit();
   cout << endl << "First bit: " << value;
   value = element.getBit();
   cout << endl << "Second bit: " << value;
   value = element.getBit();
   cout << endl << "Third bit: " << value;
   return 0;   
   element.logPosition(to_string(__LINE__));
   cout << endl << "value: " << to_string((int) FileBinaryStream::setValueOfTheBit(0, 0, true));
   /*cout << endl << "Byte: " << result;
   */
   value = element.getBit();
   cout << endl << "First bit: " << value;
   value = element.getBit();
   cout << endl << "Second bit: " << value;
   value = element.getBit();
   cout << endl << "Third bit: " << value;
   return 0;
   unsigned char result = element.getByte();
   cout << endl << "Byte: " << result;
   value = element.getBit();
   cout << endl << "First bit: " << value;
   value = element.getBit();
   cout << endl << "Second bit: " << value;
   value = element.getBit();
   cout << endl << "Third bit: " << value;
   /*element.setBit(true);
   element.setBit(true);
   */
   /*element.logPosition(to_string(__LINE__));
   unsigned char value = 76;
   element.set(&value, 1);
   */
   /*element.logPosition(string(__LINE__));
   cout << endl << element.getBitsPoistion();
   element.logPosition(string(__LINE__));
   unsigned char index = 64;
   */
   /*element.getBits(&index, 6);
   cout << endl << index << endl;
   */
   //element.setBits(&index, 6);
   //BinaryStream::outBits(4, 3, 1);
   //cout << element.getBytePoistion() << endl; 
   cout << endl << "End";   
  }