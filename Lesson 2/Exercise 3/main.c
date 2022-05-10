#include <stdio.h>

#define FILE_SOURCE "sorgente.txt"
#define FILE_ENCODE "ricodificato.txt"
#define FILE_DECODE "ridecodificato.txt"

int main(void)
{
    FILE* decode = fopen(FILE_SOURCE, "r");
    if(!decode)
        return 1;
    FILE* encode = fopen(FILE_ENCODE, "w+");
    if(!encode)
    {
        fclose(decode);
        return 2;
    }
    unsigned char count = 0;
    int c,last = EOF;
    while((c = fgetc(decode)) != EOF)
    {
        if(c == last)
        {
            count++;
            if(count == 9)
            {
                fprintf(encode, "$%u", count);
                count = 0;
                last = EOF;
            }
        }
        else
        {
            switch (count)
            {
                case 1:
                    fputc(last, encode);
                case 0:
                    fputc(c, encode);
                    break;
                default:
                    fprintf(encode, "$%u%c", count, c);
                    last = EOF;
            }
            last = c;
            count = 0;
        }
    }
    fclose(decode);
    decode = fopen(FILE_DECODE,"w");
    if(!decode)
    {
        fclose(encode);
        return 3;
    }
    fseek(encode,0,SEEK_SET);
    while((c = fgetc(encode)) != EOF)
    {
        if(c == '$')
        {
            for(count = (fgetc(encode) - '0'); count > 0; count--)
                fputc(last,decode);
        }
        else
        {
            fputc(c,decode);
            last = c;
        }
    }
    fclose(decode);
    fclose(encode);
    return 0;
}