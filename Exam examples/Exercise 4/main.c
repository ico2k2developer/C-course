//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>

#define VOW_COUNT   2

void countAndPrint(char str[],int n);
char isVowel(char c);

int main(void)
{
    char S[] = "forExample";
    int n = 4;
    countAndPrint(S,n);
    return 0;
}

void countAndPrint(char str[],int n)
{
    unsigned int i,j,vow,result = 0;
    char c;
    for(i = 0; str[i] != '\0'; i++)
    {
        for(vow = j = 0; j < n; j++)
        {
            c = str[i + j];
            if(isVowel(c))
                vow++;
        }
        if(vow == VOW_COUNT)
            result++;
    }
    printf("%u substrings of length %i have %u vowels.\n",result,n,VOW_COUNT);
}

char isVowel(char c)
{
    switch(c)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        {
            return 1;
        }
        default:
        {
            return 0;
        }
    }
}