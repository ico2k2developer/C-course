#include <stdio.h>

void analyseBill(FILE* fp,int* res);

int main(void)
{
    FILE * fp;
    int num;
    fp = fopen("bills.txt","r");
    if(fp == NULL)
        return -1;
    analyseBill(fp, &num);
    printf("Number of customers: %d \n", num);
    return 0;
}

void analyseBill(FILE* fp,int* res)
{
    float bills[10] = {0};
    int tmp,i = 0,n,k;
    float min;
    float value;
    if(fp)
    {


        /*
        CORREZIONE precedentemente era:
        while(fscanf(fp,"C%i %f",&tmp,&value) > 0)
        */
        while(fscanf(fp," C%i %f",&tmp,&value) > 0)
        {
            bills[tmp - 1] += value;
            if(i < tmp)
                i = tmp;
        }
        min = bills[0];
        for(n = 0; n < i; n++)
        {


            /*
            CORREZIONE precedentemente era:
            printf("customer C%03d: %f",n,bills[n]);
            */
            printf("customer C%03d: %f\n",n + 1,bills[n]);


            /*
            CORREZIONE precedentemente era:
            if(min > bills[n])
            */
            if(min < bills[n])
            {
                min = bills[n];
                k = n;
            }
        }


        /*
        CORREZIONE precedentemente era:
        printf("Customer with highest debt: C%03d, %f\n",k,min);
        */
        printf("Customer with highest debt: C%03d, %f\n",k + 1,min);


        /*
        CORREZIONE precedentemente era:
        return i;
        */
        *res = i;
    }
}