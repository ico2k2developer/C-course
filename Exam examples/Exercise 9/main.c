//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>

#define MAXN    15
#define MAXM    MAXN

void displRanking(int C[MAXN][MAXM],int n,int m);

int main(void)
{
    int n = 4;
    int m = 3;
    int C[MAXN][MAXM] =
    {
            {3,1,0},
            {0,1,1},
            {1,1,1},
            {1,1,3},
    };
    displRanking(C,n,m);
    return 0;
}

void displRanking(int C[MAXN][MAXM],int n,int m)
{
    if(n > 0 && m > 0)
    {
        printf("La squadra capolista in ognuna delle %i giornate e\': ",m);
        int teams[MAXN] = {0};
        int i,j,max,maxTeam;
        for(i = 0; i < m; i++)
        {
            max = 0;
            for(j = 0; j < n; j++)
            {
                teams[j] += C[j][i];
                if(teams[j] > max)
                {
                    max = teams[j];
                    maxTeam = j;
                }
            }
            printf("%i ",maxTeam);
        }
    }
}