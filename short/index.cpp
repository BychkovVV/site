#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <future>
#include <fstream>
#include "short/include.h"
using namespace std;
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
   FileBinaryStream element11("C:\\s2.txt");
   element11.setBitsPoistion(0);
   element11.setBitsFromString(theValue1 = "1111111101111111000010111101111100011001010010101111111101111111");
   FileBinaryStream element12("C:\\s2.txt");
   theValue2 = element12.getBitsToString(64);
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
   FileBinaryStream element13("C:\\s2.txt");
   element13.setBitsPoistion(0);
   element13.setBitsFromString(theValue1 = "1111111101111111110111110001100101001010111111110111111101111111");
   FileBinaryStream element14("C:\\s2.txt");
   theValue2 = element14.getBitsToString(64);
   Tester::assertEqual(theValue1, theValue2, "Value, saved to file", "Value, that have read from the file");
  }
void testWritingAndReadingTypes()
  {FileBinaryStream element("C:\\s3.txt");
   unsigned long long theIntegerValue = 9223172036854775807, theOtherIntegerValue;
   IntegerType a(theIntegerValue), a2(0);     
   element << a;
   FileBinaryStream element2("C:\\s3.txt");
   element2 >> a2;
   Tester::assertEqual(a, a2, "Initial value", "Value, got from file");
   theOtherIntegerValue = a2.getValue();
   cout << endl << BinaryStream::getBitsAsString((unsigned char *) &theIntegerValue, 64) << " == " << BinaryStream::getBitsAsString((unsigned char *) &theOtherIntegerValue, 64);
   
   FileBinaryStream element3("C:\\s4.txt");
   double theDoubleValue1 = 1.33, theDoubleValue2;
   DataType<double> ad(theDoubleValue1), ad2(0);     
   element3 << ad;
   FileBinaryStream element4("C:\\s4.txt");
   element4 >> ad2;
   Tester::assertEqual(ad, ad2, "Initial value", "Value, got from file");
   theDoubleValue2 = ad2.get();
   
   element3.assign("C:\\s4_string.txt");
   string stringValue1 = "sss", stringValue2;
   StringType adString1(stringValue1), adString2(stringValue2);     
   element3 << adString1;
   element4.assign("C:\\s4_string.txt");
   element4 >> adString2;
   Tester::assertEqual(adString1, adString2, "Initial value", "Value, got from file");
   stringValue2 = adString2.get();
   
   element3.assign("C:\\s5_string_and_numbers2.txt");
   string stringValue3 = "sss", stringValue4;
   double theDoubleValue3 = 1.3312, theDoubleValue4;
   DataType<double> ad3(theDoubleValue3), ad4(0);  
   StringType adString3(stringValue3), adString4(stringValue4);     
   element3 << adString3;
   cout << endl << "Writing double";
   element3 << ad3;
   cout << endl <<  "End Writing double";
   element4.assign("C:\\s5_string_and_numbers2.txt");
   element4 >> adString4;
   Tester::assertEqual(adString3, adString4, "Initial value", "Value, got from file");
   cout << endl << "Reading double";
   element4 >> ad4;
   cout << endl << "End reading double";
   Tester::assertEqual(ad3, ad4, "Initial value", "Value, got from file");
   stringValue4 = adString4.get(); 
   
   /*cout << endl << BinaryStream::getBitsAsString((unsigned char *) &theIntegerValue, 64) << " == " << BinaryStream::getBitsAsString((unsigned char *) &theDoubleValue2, 64);
   */
  }
void testAll()
  {testGetBytesCountInABits();
   testGetBitsAsString();
   testGetBytesFromString();
   testFileReadAndWrite();
   testWritingAndReadingTypes();
  };
int main()
  {if(true)
     {cout << "ss";
      return 0;
      testAll();
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