#pragma once
#include "short/classes/standarddatatype.h"
#include "short/classes/binarystreaminformationexchangemode.h"
#include "short/classes/typespecifier.h"
StandardDataType::StandardDataType()
  {this->exchangeModeForReading = new BinaryStreamInformationExchangeMode();
   this->exchangeModeForWriting = new BinaryStreamInformationExchangeMode(); 
  }
TypeSpecifier &StandardDataType::getTypeSpecifier() const
  {return TypeSpecifier::getById();          
  }

bool StandardDataType::readingModeIsOn(unsigned long long theMode) const
  {return this->exchangeModeForReading->has(theMode);          
  }
bool StandardDataType::writingModeIsOn(unsigned long long theMode) const
  {return this->exchangeModeForWriting->has(theMode);        
  }
