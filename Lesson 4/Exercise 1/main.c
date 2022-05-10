#include <stdio.h>

#define FILE_INPUT  "input.txt"

#define SIZE_MAX    30

void sottoSequenze(int V[],int N);

int main(void)
{
    FILE* input = fopen(FILE_INPUT,"r");
    if(!input)
        return 1;
    int V[SIZE_MAX];
    int tmp;
    unsigned char i;
    for(i = 0; i < SIZE_MAX; i++)
    {
        if(fscanf(input,"%i",&tmp) > 0)
            V[i] = tmp;
        else
            break;
    }
    fclose(input);
    sottoSequenze(V,i);
    return 0;
}

void sottoSequenze(int V[],int N)
{
    int i,i2,i3;
    int pos[SIZE_MAX],length[SIZE_MAX];
    int max = 0;
    unsigned char zero = 1;
    for(i = i2 = 0; i < N; i++)
    {
        if(V[i] == 0)
        {
            if(i != 0 && !zero)
            {
                length[i2] = i - pos[i2];
                if(max < length[i2])
                    max = length[i2];
                i2++;
            }
            zero = 1;
        }
        else
        {
            if(zero)
            {
                zero = 0;
                pos[i2] = i;
            }
        }
    }
    if(i != 0 && !zero)
    {
        length[i2] = i - pos[i2];
        if(max < length[i2])
            max = length[i2];
        i2++;
    }
    for(i = 0; i < i2; i++)
    {
        if(length[i] == max)
        {
            fputc('[',stdout);
            for(i3 = pos[i]; i3 < (pos[i] + length[i]); i3++)
                printf("%i,",V[i3]);
            printf("\b]\n");
        }
    }
}