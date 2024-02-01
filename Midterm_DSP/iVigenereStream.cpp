//
//  iVigenereStream.cpp
//  Midterm_DSP
//
//  Created by Rohan Soni on 27/4/2022.
//

#include <stdio.h>
#include <fstream>
#include "iVigenereStream.h"

using namespace std;

iVigenereStream:: iVigenereStream(Cipher aCipher, const std::string& aKeyword, const char* aFileName):
fCipherProvider(aKeyword), fCipher(aCipher)
{
    open(aFileName);
}

iVigenereStream:: ~iVigenereStream()
{
    close();
}

void iVigenereStream:: open(const char* aFileName)
{
    if ( aFileName )
    {
        fIStream.open( aFileName,  iostream::binary );
    }
}

void iVigenereStream:: close()
{
    fIStream.close();
}

void iVigenereStream:: reset()
{
    seekstart();
}

bool iVigenereStream:: good() const
{
    return fIStream.good();
}

bool iVigenereStream:: is_open() const
{
    return fIStream.is_open();
}

bool iVigenereStream:: eof() const
{
    return fIStream.eof();
}

iVigenereStream& iVigenereStream:: operator>>(char& aCharacter)
{
    aCharacter = fIStream.get();
    if (!bool())
    {
        aCharacter = fCipher(fCipherProvider, aCharacter);
    }
    return *this;
}






