//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>

void maxOdd(int v[],int N);

int main(void)
{
    int v[] = {1,3,7,1,0,1,9,3,1,0};
    maxOdd(v,sizeof(v)/sizeof(v[0]));
    return 0;
}

void maxOdd(int v[],int N)
{
    unsigned int i,maxSize = 0,size = 0;
    for(i = 0; i <= N; i++)
    {
        if(i == N)
        {
            if(size > maxSize)
                maxSize = size;
        }
        else if(v[i] & 1)
            size++;
        else if(size != 0)
        {
            if(size > maxSize)
                maxSize = size;
            size = 0;
        }
    }
    for(size = i = 0; i <= N; i++)
    {
        if(size == maxSize)
        {
            fputs("[",stdout);
            for(size = i - maxSize; size < i; size++)
            {
                printf("%i,",v[size]);
            }
            fputs("\b]\n",stdout);
            size = 0;
        }
        else if(v[i] & 1)
            size++;
    }
}