//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>
#include <string.h>

#define MAXM    10

int count(char A[][MAXM],int n,int m,char str[]);

int main(void)
{
    int n = 4,m = 5;
    char A[][MAXM] =
    {
        "xceca",
        "waecq",
        "dtpaz",
        "pcatf",
    };
    char str[] = "cat";
    printf("\"%s\" has %i occurencies.\n",str,count(A,n,m,str));
    return 0;
}

int count(char A[][MAXM],int n,int m,char str[])
{
    size_t length = strlen(str);
    if(length > n && length > m || length == 0)
        return 0;
    else
    {
        int i,j,k,count = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(A[i][j] == str[0])
                {
                    for(k = 1; k < length && (i + k) < n && A[i + k][j] == str[k]; k++);
                    if(k == length)
                        count++;
                    if(length > 1)
                    {
                        for(k = 1; k < length && (j + k) < m && A[i][j + k] == str[k]; k++);
                        if(k == length)
                            count++;
                    }
                }
            }
        }
        return count;
    }
}