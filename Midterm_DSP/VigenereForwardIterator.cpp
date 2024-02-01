//
//  VigenereForwardIterator.cpp
//  Midterm_DSP
//
//  Created by Rohan Soni on 27/4/2022.
//

#include <stdio.h>
#include "VigenereForwardIterator.h"

using namespace std;

VigenereForwardIterator:: VigenereForwardIterator(iVigenereStream& aIStream): fIStream(aIStream), fCurrentChar(0), fEOF(aIStream.eof())
{
    if (!fEOF) {
        fIStream >> fCurrentChar;
    }
}

char VigenereForwardIterator:: operator*() const
{
    return fCurrentChar;
}

VigenereForwardIterator& VigenereForwardIterator:: operator++()
{
    if (!fEOF)
    {
        fIStream >> fCurrentChar;
        fEOF = fIStream.eof();
    }
    return *this;
}

VigenereForwardIterator VigenereForwardIterator:: operator++( int )
{
    VigenereForwardIterator result = *this;
    
    ++(*this);
    
    return result;
}

bool VigenereForwardIterator:: operator==( const VigenereForwardIterator& aOther ) const
{
    return fIStream.position() == aOther.fIStream.position() && fEOF == aOther.fEOF;
    
}

bool VigenereForwardIterator:: operator!=( const VigenereForwardIterator& aOther) const
{
    return !(*this == aOther);
}

VigenereForwardIterator VigenereForwardIterator:: begin() const
{
    VigenereForwardIterator Result = *this;
    Result.fIStream.reset();
    Result.fEOF = Result.fIStream.eof();
    
    if (!Result.fEOF) {
        Result.fIStream >> Result.fCurrentChar;
    }
    
    else
    {
        Result.fCurrentChar = 0;
    }
    
    return Result;
    
}

VigenereForwardIterator VigenereForwardIterator:: end() const
{
    VigenereForwardIterator Result = *this;
    Result.fEOF = true;
    
    Result.fCurrentChar = 0;
    
    return Result;
}

