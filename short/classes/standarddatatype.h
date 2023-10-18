#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include <iostream>
#include "short/classes/standard.h"
#include "short/classes/binarystream.h"
#include "short/classes/binary_stream_information_exchange_modes.h"
#include "short/classes/tester.h"
using namespace std;
class BinaryStreamInformationExchangeMode;
class TypeSpecifier;
class StandardDataType : public Standard
  {protected:
     unsigned char *data;
     unsigned long long bitsCount;
     bool isAllocated;
     BinaryStreamInformationExchangeMode *exchangeModeForReading, *exchangeModeForWriting;
     virtual unsigned long long getOptionsSizeInBits() const
       {return 0;          
       }
     /*
     Выделение памяти в data:
     */
     virtual void allocate();
   public:   
     virtual TypeSpecifier &getTypeSpecifier() const;
     virtual bool readingModeIsOn(unsigned long long theMode) const;
     virtual bool readingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES theMode) const
       {return this->readingModeIsOn((unsigned long long) theMode);          
       }
     virtual bool writingModeIsOn(unsigned long long theMode, BINARY_STREAM_INFORMATION_EXCHANGE_MODES) const;
     virtual bool writingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES theMode) const
       {return this->writingModeIsOn((unsigned long long) theMode);
       }
     template <typename TYPE_OF_THE_SOURCE> virtual unsigned long long typeSpecifierFromBinary(TYPE_OF_THE_SOURCE value)
       {TypeSpecifier theTypeSpecifier;
        unsigned long long result = theTypeSpecifier.fromBinary(value);
        Tester::assertEqual(theTypeSpecifier, this->getTypeSpecifier());
        return result;
       }
     virtual unsigned long long optionsFromBinary(unsigned char *value)
       {return 0;
       }
     virtual unsigned long long optionsFromBinary(BinaryStream &value)
       {return 0;
       }
     virtual unsigned long long dataToBinary(unsigned char *value)
       {return 0;
       }
     virtual unsigned long long dataToBinary(BinaryStream &value)
       {return 0;
       }
     /*
     Writing this data to binary and return quantity of bits that was wrote
     */
     virtual unsigned long long toBinary(unsigned char * &target)
       {return 0;          
       }
     virtual unsigned long long typeSpecifierToBinary(unsigned char * &target) const
       {return this->getTypeSpecifier().toBinary(target);      
       }
     virtual unsigned long long typeSpecifierToBinary(BinaryStream &target) const
       {const typeSpecifier = this->getTypeSpecifier();
        unsigned char* bytes;
        unsigned long long countInBits = this->typeSpecifierToBinary(bytes);
        target->setBits(bytes, countInBits);
        return countInBits;
       }
     virtual unsigned long long optionsToBinary(BinaryStream &target)
       {unsigned char* bytes;
        unsigned long long countInBits = this->optionsToBinary(bytes, theMode);
        target->setBytes(bytes, BinaryStream::getBytesCountInABits(countInBits));
        return countInBits;          
       }
     virtual unsigned long long optionsToBinary(unsigned char * &target)
       {return 0;          
       }
     virtual unsigned long long dataToBinary(BinaryStream &target)
       {unsigned char* bytes;
        unsigned long long countInBits = this->dataToBinary(bytes, theMode);
        target->setBytes(bytes, BinaryStream::getBytesCountInABits(countInBits));
        return countInBits;          
       }
     virtual unsigned long long dataToBinary(unsigned char * &target)
       {return 0;          
       }
     virtual unsigned long long fromBinary(unsigned char *value, BINARY_STREAM_INFORMATION_EXCHANGE_MODES mode)
       {unsigned long long result = 0;
        switch(mode)
          {case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::TYPE:
             result = this->typeSpecifierFromBinary(value);
             break;
           case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS:
             result = this->optionsFromBinary(value);
             break;
           case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA:
             result = this->dataToBinary(value);
             break;
          }
        return result;     
       }
     virtual unsigned long long toBinary(BinaryStream &target, BINARY_STREAM_INFORMATION_EXCHANGE_MODES theMode) const
       {unsigned char* bytes;
        unsigned long long countInBits = this->toBinary(bytes, theMode);
        target->setBytes(bytes, BinaryStream::getBytesCountInABits(countInBits));
        return countInBits;           
       }
     virtual unsigned long long toBinary(unsigned char* &bytes, BINARY_STREAM_INFORMATION_EXCHANGE_MODES theMode) const
       {unsigned long long result = 0;
        switch(theMode)
          {case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::TYPE:
             result = this->typeSpecifierToBinary(bytes);
             break;
           case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS:
             result = this->optionsToBinary(bytes);
             break;
           case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA:
             result = this->dataToBinary(bytes);
             break;
          }
        return result;
       }
     /*virtual void toBinary(unsigned char* &bytes) const
       {unsigned long long result = 0;
        switch(theMode)
          {case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::TYPE:
             result = this->typeSpecifierToBinary(bytes);
             break;
           case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS:
             result = this->optionsToBinary(bytes);
             break;
           case BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA:
             result = this->dataToBinary(bytes);
             break;
          }
        return result;
       }
     */
     virtual unsigned long long toBinary(BinaryStream &target) const
       {unsigned long long result = 0;
        if(this->writingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::TYPE))
          {result += this->toBinary(target, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::TYPE);            
          }          
        if(this->writingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS))
          {result += this->toBinary(target, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS);            
          }          
        if(this->writingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA))
          {result += this->toBinary(target, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA);            
          }          
        return result;          
       }
     virtual unsigned long long fromBinary(unsigned char *value)
       {unsigned long long offset = 0;
        if(this->readingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS))
          {offset += this->fromBinary(value + offset, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS);          
          }
        if(this->readingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA))
          {offset += this->fromBinary(value + offset, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA);          
          }          
        return offset;
       }
     virtual void fromBinary(BinaryStream &theStream)
       {if(this->readingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS))
          {this->fromBinary(theStream, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::OPTIONS);          
          }
        if(this->readingModeIsOn(BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA))
          {this->fromBinary(theStream, BINARY_STREAM_INFORMATION_EXCHANGE_MODES::DATA);          
          }
       }
     virtual void fromBinary(BinaryStream &theStream, BINARY_STREAM_INFORMATION_EXCHANGE_MODES mode)
       {          
       }
     virtual void readOptionsFromBinaryStream(BinaryStream &theStream)
       {
       }
     virtual void readDataFromBinaryStream(BinaryStream &theStream)
       {
       }     
     StandardDataType();
  };