//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>

void prodCartFilt(int *v1,int d1,int *v2,int d2);

int main(void)
{
    int v1[] = {1,2,3};
    int v2[] = {3,4,5,6};
    prodCartFilt(v1,sizeof(v1)/sizeof(v1[0]),v2,sizeof(v2)/sizeof(v2[0]));
    return 0;
}

void prodCartFilt(int *v1,int d1,int *v2,int d2)
{
    int i,j,diff;
    for(i = 0; i < d1; i++)
    {
        for(j = 0; j < d2; j++)
        {
            diff = v1[i] - v2[j];
            if(diff > 1)
                printf("(%i,%i)\n",v2[j],v1[i]);
            else if(diff < -1)
                printf("(%i,%i)\n",v1[i],v2[j]);
        }
    }
}