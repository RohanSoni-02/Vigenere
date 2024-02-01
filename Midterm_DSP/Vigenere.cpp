//
//  Vigenere.cpp
//  Midterm_DSP
//  Created by Rohan Soni on 26/4/2022.
//
// COS30008, Midterm, Problem 2, 2022

#include "Vigenere.h"
#include <iostream>

using namespace std;

void Vigenere::initializeTable()
{
	for ( char row = 0; row < CHARACTERS; row++ )
	{
		char lChar = 'B' + row;

		for ( char column = 0; column < CHARACTERS; column++ )
		{
            if ( lChar > 'Z' )
                lChar = 'A';

            fMappingTable[row][column] = lChar++;
		}
	}
}

Vigenere:: Vigenere(const std::string& aKeyword): fKeywordProvider(aKeyword), fKeyword(aKeyword)
{
    initializeTable();
}

string Vigenere:: getCurrentKeyword()
{
    string ltemp = "";
    for(size_t i=0; i <fKeyword.size(); i++)
    {
        ltemp+= *fKeywordProvider;
        fKeywordProvider << *fKeywordProvider;
    }
    return ltemp;
}

void Vigenere:: reset()
{
    fKeywordProvider.initialize(fKeyword);
}

char Vigenere::encode(char aCharacter)
{
    if (isalpha(aCharacter))
    {
        bool if_upperCase = isupper(aCharacter);
        char cipherChar = fMappingTable[*fKeywordProvider - 'A'][toupper(aCharacter) - 'A'];
        fKeywordProvider << aCharacter;
        if (if_upperCase)
        {
            return toupper(cipherChar);
        }
        else
        {
            return tolower(cipherChar);
        }
    }
    return aCharacter;
}

char Vigenere::decode(char aCharacter)
{
    if (isalpha(aCharacter))
    {
        bool if_upperCase = isupper(aCharacter);
        char decodedCipherChar = 'A';
        for (int i = 0; i <= CHARACTERS; i++)
        {
            if (fMappingTable[*fKeywordProvider-'A'][i] == toupper(aCharacter))
            {
                decodedCipherChar = i + 'A';
                fKeywordProvider << decodedCipherChar;
                if (if_upperCase)
                {
                    return toupper(decodedCipherChar);
                }
                else
                {
                    return tolower(decodedCipherChar);
                }
            }
        }
    }
    return aCharacter;
}

