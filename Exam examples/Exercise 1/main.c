//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>
#include <string.h>

int charErase(char str[],const int pos[]);

int main(void)
{
    char str[] = "ThisIsAString";
    int pos[] = {7,4,2,0,11,-1};
    printf("%i characters deleted.\nResulting string: \"%s\"\n",charErase(str,pos),str);
    return 0;
}

int charErase(char str[],const int pos[])
{
    size_t result,i,j,size;
    result = 0;
    for(size = 0; pos[size] != -1; size++);
    size_t length = strlen(str);
    for(i = 0; i < size; i++)
    {
        str[pos[i]] = '\0';
        result++;
    }
    for(i = length; i > 0; i--)
    {
        if(str[i - 1] == '\0')
        {
            for(j = i - 1; j < length; j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
    return result;
}