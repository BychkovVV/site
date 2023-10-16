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
using namespace std;
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
        return this->size;
       }
     void setSizeInBytes(unsigned long long size)
       {this->size = size;
       }
     virtual void assign(string value)
       {this->unassign();
        if(this->theValue == NULL)
          {this->theValue = new fstream(value, this->theValue->binary | this->theValue->in | this->theValue->out);
           sizeIsDefined = false;
           if(!this->theValue->is_open())
             {this->theValue = new fstream(value, this->theValue->binary | this->theValue->out);              
              this->theValue->close();
              this->theValue = new fstream(value, this->theValue->binary | this->theValue->in | this->theValue->out);
             }
           cout << endl << "Attempt to to open file \"" << value << "\", result: " << (this->theValue->is_open() ? "" : "not ") << "opened, good: " << (this->theValue->good() ? "yes" : "no") << ((this->theValue->is_open() && this->theValue->good()) ? string("") : (string(", error: ") + string(strerror(errno))));
           this->theValue->seekg(0, ios_base::end);
           cout << endl << "Size: " << this->theValue->tellp();
           this->theValue->seekg(0, ios_base::beg);
           cout << endl << "Position: " << this->theValue->tellp();             
           BinaryStream::assign();
          }           
       }
     virtual void unassign()
       {if(this->theValue != NULL)
          {cout << endl << "Closing file";
           this->theValue->close();               
           this->theValue = NULL;
           BinaryStream::unassign();
          }          
       }
     FileBinaryStream(string value): BinaryStream()
       {theValue = NULL;
        this->assign(value);
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
     bool isAtStart()
       {return this->theValue->tellp() == 0;          
       }
     bool isAtEnd()
       {return this->theValue->tellp() == this->getSizeInBytes();          
       }
     unsigned char getCurrentByteData()
       {return this->getCurrentByteData(!WITH_RETURNING_POSITION);        
       }
     unsigned char getCurrentByteData(bool withoutReturningPosition)
       {unsigned char result = 0;
        long long startPosition = theValue->tellp(), thisPosition;
        cout << endl << "startPosition before getting current byte data in file: " << theValue->tellp();
        if(!this->isAtEnd())
          {cout << endl << "startPosition after is at end checking: " << theValue->tellp();
           theValue->read((char *) &result, 1);
           cout << endl << "startPosition after reading: " << theValue->tellp();
          }
        cout << endl << "startPosition after getting current byte data in file: " << theValue->tellp();
        if(!withoutReturningPosition && ((thisPosition = theValue->tellp()) != startPosition))
          {cout << endl << "Position was chanbged, returning it (thisPosition: " << thisPosition << ", startPosition: " << startPosition << ")";
           if(thisPosition > startPosition)
             {theValue->seekp(startPosition - thisPosition, ios_base::cur);            
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
        cout << endl << "Getting byte from file, position: " << to_string(theValue->tellp()) << ", value: " << to_string(result) << " (In bits: \"" << getBitsAsString(result) << "\")";
        return result;
       }
     virtual unsigned char toPreviousByte()
       {unsigned char result;
        if(!this->isAtStart())
          {theValue->seekp(-1, ios_base::cur);          
           result = this->getCurrentByteData();                 
          }
        else
          {result = 0;             
          }
        return result;
       }
     virtual unsigned char toNextByte()
       {if(this->isAtEnd())
          {cout << endl << "Have to move to the next byte, but it is already at the end , this position: " << to_string(theValue->tellp()) << " and the size is: " << to_string(this->size) << ", sot trying to write \"" << getBitsAsString(this->getCurrentByteData()) << "\" byte to this position";
           unsigned char value = this->getCurrentByteData();
           theValue->write((char *) &value, 1);
           cout << endl << "Position after writing is: " << to_string(theValue->tellp());
           this->size++;
          }
        else
          {theValue->seekp(1, ios_base::cur);          
          }
        cout << endl << "to next byte, new position: " << to_string(theValue->tellp());
        return this->getCurrentByteData();
       }     
     virtual void setCurrentByteData(unsigned char newValue)
       {return this->setCurrentByteData(newValue, !WITH_RETURNING_POSITION);
       }
     virtual void setCurrentByteData(unsigned char newValue, bool withoutReturningPosition)
       {cout << endl << "Called setCurrentByteData on file class with new Value = " << newValue << " (In bits: \"" << getBitsAsString(newValue) << "\"), initial position: " << theValue->tellp() << endl;
        long long startPosition = theValue->tellp(), thisPosition;
        theValue->write((char *) &newValue, 1);          
        if(!withoutReturningPosition && ((thisPosition = theValue->tellp()) != startPosition))
          {theValue->seekp(startPosition - thisPosition, ios_base::cur);
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
       {this->unassign();       
       }
  };