//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>

#define MAXN    15

int sommaCornici(const int mat[MAXN][MAXN],int N,int vet[]);

int main(void)
{
    const int mat[MAXN][MAXN] =
    {
            {1,2,3,4,5},
            {6,7,8,9,0},
            {1,2,3,4,5},
            {6,7,8,9,0},
            {1,1,1,1,1},
    };
    const int N = 5;
    int vet[MAXN / 2 + 1];
    int count = sommaCornici(mat,N,vet);
    int i;
    for(i = 0; i < count; i++)
    {
        printf("Element %i has sum %i\n",i + 1,vet[i]);
    }
    return 0;
}

int sommaCornici(const int mat[MAXN][MAXN],int N,int vet[])
{
    if(N > 0)
    {
        int i,k,v = 0;
        k = N >> 1;
        vet[v++] = mat[k][k];
        if(N > 1)
        {
            for(k--; k >= 0; k--)
            {
                vet[v] = 0;
                for(i = k; i < (N - k); i++)
                    vet[v] += mat[k][i] + mat[N - k - 1][i];
                for(i = k + 1; i < (N - k - 1); i++)
                    vet[v] += mat[i][k] + mat[i][N - k - 1];
                v++;
            }
        }
        return v;
    }
    else
        return 0;
}