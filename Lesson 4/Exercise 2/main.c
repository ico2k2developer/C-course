#include <stdio.h>

#define SIZE_MAX    30

#define KEY_RIGHT   -1
#define KEY_LEFT    1

void ruota(int v[SIZE_MAX],int N,int P,int dir);

int main(void)
{
    unsigned char i,N;
    char dir;
    int p;
    int V[SIZE_MAX];
    printf("Inserisci il numero di elementi da inserire:\n");
    scanf("%hhu",&N);
    for(i = 0; i < N; i++)
    {
        printf("Elemento %d: ",i + 1);
        scanf("%i",V + i);
    }
    printf("Inserisci il numero di posizioni e la direzione (%i o %i) separati da spazio:\n",KEY_LEFT,KEY_RIGHT);
    if(scanf("%i %hhi",&p,&dir) < 2)
        p = 0;
    while(p != 0)
    {
        ruota(V,N,p,dir);
        printf("Inserisci il numero di posizioni e la direzione:\n");
        if(scanf("%i %hhi",&p,&dir) < 2)
            p = 0;
    }
    printf("Vettore risultante:\n[");
    for(i = 0; i < N; i++)
    {
        printf("%i,",V[i]);
    }
    printf("\b]\n");
    return 0;
}

void ruota(int v[SIZE_MAX],int N,int P,int dir)
{
    short i,i2,n2;
    int tmp;
    P = P % N;
    n2 = N - P;
    if(KEY_LEFT == dir)
        P *= -1;
    for(i = 0; i < n2; i++)
    {
        i2 = i + P;
        if(i2 >= N)
            i2 -= N;
        else if(i2 < 0)
            i2 += N;
        tmp = v[i2];
        v[i2] = v[i];
        v[i] = tmp;
    }
}