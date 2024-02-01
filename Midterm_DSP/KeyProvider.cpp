//
//  KeyProvider.cpp
//  Midterm_DSP
//
//  Created by Rohan Soni on 26/4/2022.
//

#include <stdio.h>
#include <string>
#include "KeyProvider.h"

using namespace std;

KeyProvider:: KeyProvider(const std::string& aKeyword )
{
    initialize(aKeyword);
}

KeyProvider:: ~KeyProvider()
{
    delete [] fKeyword;
}

void KeyProvider:: initialize(const std::string &aKeyword)
{
    (*this).~KeyProvider();
    fSize = aKeyword.size();
    fKeyword = new char[fSize];
    
    for(size_t i =0; i < fSize; i++)
    {
        fKeyword[i] = toupper(aKeyword[i]);
    }
    
    fIndex = 0;
}

char KeyProvider:: operator*() const
{
    return fKeyword[fIndex%fSize];
}

KeyProvider& KeyProvider:: operator<<(char aKeyCharacter)
{
    fKeyword[fIndex%fSize] = toupper(aKeyCharacter);
    fIndex++;
    return *this;
}


