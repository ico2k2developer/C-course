//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>

#define MAXR    15
#define MAXC    MAXR
#define MAXN    15

int buildMatrix(int V[],int N,int M[MAXR][MAXC],int nr,int nc);

int main(void)
{
    int V[MAXN] = {1,2,17,2,3,1,8,4,6,1,7,3,5,2};
    int nr = 3;
    int nc = 5;
    int N = 14;
    int M[MAXR][MAXC] =
    {
            {1,1,17,17,3},
            {8,8,8,8,6},
            {7,7,7,5,5},
    };
    puts(buildMatrix(V,N,M,nr,nc) ? "correct" : "incorrect");
    return 0;
}

int buildMatrix(int V[],int N,int M[MAXR][MAXC],int nr,int nc)
{
    if(N > 0)
    {
        int k,i,j,count;
        for(k = i = j = 0; k < N; k += 2)
        {
            for(count = 0; count < V[k + 1]; count++)
            {
                M[i][j++] = V[k];
                if(j == nc)
                {
                    i++;
                    j = 0;
                }
            }
        }
        if((nr == i) && (j == 0))
            return 1;
    }
    return 0;
}