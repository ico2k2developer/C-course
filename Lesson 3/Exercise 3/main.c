#include <stdio.h>
#include <limits.h>

#define FILE_INPUT  "numeri.txt"

unsigned char check(short value,short a,short b);

int main(void)
{
    short a,b,tmp,min = SHRT_MAX,max = SHRT_MIN;
    unsigned char i = 0,skip = 0;
    FILE* input = fopen(FILE_INPUT,"r");
    if(!input)
        return 1;
    while((fscanf(input,"%hi",&tmp)) > 0) {
        if (i < 2) {
            if (i > 0)
                b = a;
            a = tmp;
            if (max < a)
                max = a;
            if (min > a)
                min = a;
            i++;
        }
        else
        {

            if (check(tmp, a, b)) {
                b = a;
                a = tmp;
                if (max < a)
                    max = a;
                if (min > a)
                    min = a;
            } else {
                skip++;
            }
        }
    }
    fclose(input);

    printf("Numero massimo: %hi\n"
           "Numero minimo: %hi\n"
           "Numeri scartati: %i\n",
           max,min,skip);

    return 0;
}


unsigned char check(short value,short a,short b)
{
    if(value == (b + a))
        return 1;
    if(value == (b - a))
        return 1;
    if(value == (b * a))
        return 1;
    if(a != 0)
        if(value == (b / a))
            return 1;
    return 0;
}