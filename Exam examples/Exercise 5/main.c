//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>
#include <stdlib.h>

void prodCartOrd(const int *v1,int d1,const int *v2,int d2);

int main(void)
{
    int v1[] = {2,1,3};
    int v2[] = {6,4,3,6};
    prodCartOrd(v1,sizeof(v1)/sizeof(v1[0]),v2,sizeof(v2)/sizeof(v2[0]));
    return 0;
}

void prodCartOrd(const int *v1,int d1,const int *v2,int d2)
{
    int** results = (int**)malloc(sizeof(v1)*d1*d2);
    if(results)
    {
        int i,j,k = 0;
        for(i = 0; i < d1; i++)
        {
            for(j = 0; j < d2; j++)
            {
                results[k] = (int*)malloc(sizeof(*v1)*2);
                results[k][0] = v1[i];
                results[k][1] = v2[j];
                k++;
            }
        }
        for(i = 0; i < k; i++)
        {
            printf("(%i,%i)\n",results[i][0],results[i][1]);
        }
        for(i = 0; i < k; i++)
        {
            for(j = 0; j < k && j != i; j++)
            {
                if((results[i][0] + results[i][1]) < (results[j][0] + results[j][1]))
                {
                    int a,b;
                    a = results[i][0];
                    b = results[i][1];
                    results[i][0] = results[j][0];
                    results[i][1] = results[j][1];
                    results[j][0] = a;
                    results[j][1] = b;
                }
            }
        }
        for(i = 0; i < k; i++)
        {
            printf("(%i,%i)\n",results[i][0],results[i][1]);
            free(results[i]);
        }
        free(results);
    }
}