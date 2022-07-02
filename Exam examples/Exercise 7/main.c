//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>
#include <string.h>

int conta(char *parole[],int nparole,char *cerca);
char equalNoCase(char a,char b);

int main(int argc,char** argv)
{
    if(argc > 1)
        printf("\"%s\" has %i occurrences in arguments.\n",argv[argc - 1],conta(argv + 1,argc - 2,argv[argc - 1]));
    return 0;
}

int conta(char *parole[],int nparole,char *cerca)
{
    size_t targetLength = strlen(cerca);
    if(nparole > 0 && targetLength > 0)
    {
        int i,j,occ,count = 0;
        size_t currentLength;
        for(i = 0; i < nparole; i++)
        {
            currentLength = strlen(parole[i]);
            if(targetLength <= currentLength)
            {
                for(occ = j = 0; j < currentLength; j++)
                {
                    if(equalNoCase(parole[i][j],cerca[occ]))
                        occ++;
                    else
                    {
                        if(occ == targetLength)
                            count++;
                        occ = 0;
                    }
                }
                if(occ == targetLength)
                    count++;
                
            }
        }
        return count;
    }
    else
        return 0;
}

char equalNoCase(char a,char b)
{
    if(a >= 'a' && a <= 'z')
        a += 'A' - 'a';
    if(b >= 'a' && b <= 'z')
        b += 'A' - 'a';
    return a == b;
}