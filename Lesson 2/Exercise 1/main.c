#include <stdio.h>

int main(void)
{
    unsigned int a,b,tmp;
    printf("Inserisci due numeri interi positivi separati da spazio:\n");
    scanf("%u %u",&a,&b);
    if(a == 0 && b == 0)
        return 1;
    if(b < a)
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    while((tmp = a % b) != 0)
    {
        a = b;
        b = tmp;
    }
    printf("Il massimo comune divisore e\' %u.\n",b);
    return 0;
}