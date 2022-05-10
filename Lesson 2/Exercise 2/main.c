#include <stdio.h>
#include "main.h"

#define APPROFONDIMENTO NO

#if APPROFONDIMENTO
#define X0  1
#define X1  2
#else
#define X0  0
#define X1  1
#endif

int main(void)
{
    unsigned int x0 = X0;
    unsigned int x1 = X1;
    unsigned int n,i,tmp;
    scanf("%u",&n);
    if(n >= 1)
        printf("%u\t",x0);
    if(n >= 2)
        printf("%u\t",x1);
    for(i = 2; i < n; i++)
    {
        printf("%u\t",
#if APPROFONDIMENTO
                tmp = x0 * x1
#else
               tmp = x0 + x1
#endif
        );
        x0 = x1;
        x1 = tmp;
    }
    return 0;
}