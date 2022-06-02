#include <stdio.h>

unsigned char isLittleEndian();
void stampaCodifica(void* data,size_t size,unsigned char bigEndian);

int main(void)
{
    float af;
    double ad;
    unsigned char bigEndian = !isLittleEndian();
    printf("Il sistema e\' %s endian\n",bigEndian ? "big" : "little");
    printf("Dimensione float: %llu bytes\n",sizeof(af));
    printf("Dimensione double: %llu bytes\n",sizeof(ad));
    fputs("Inserisci un numero: ",stdout);
    scanf("%lf",&ad);
    af = ad;
    fputs("Codifica float:\t\t",stdout);
    stampaCodifica(&af,sizeof(af),bigEndian);
    fputs("\nCodifica double:\t",stdout);
    stampaCodifica(&ad,sizeof(ad),bigEndian);
}

unsigned char isLittleEndian()
{
    union test
    {
        unsigned short n;
        unsigned char c;
    };
    union test t;
    t.n = 1;
    return t.c;
}

void stampaCodifica(void* data,size_t size,unsigned char bigEndian)
{
    unsigned char byte,i;
    if(bigEndian)
    {
        size_t index;
        for(index = 0; index < size; index++)
        {
            byte = *(((char*)data) + index);
            for(i = 0; i < 8; i++)
                fputc(byte & (1 << i) ? '1' : '0',stdout);
        }
    }
    else
    {
        for(; size > 0; size--)
        {
            byte = *(((char*)data) + (size - 1));
            for(i = 8; i > 0; i--)
                fputc(byte & (1 << (i - 1)) ? '1' : '0',stdout);
        }
    }
}