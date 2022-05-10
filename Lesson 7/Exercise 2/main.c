#include <stdio.h>
#include <string.h>

#define FILE_SORT       "sort.txt"

#define MAX_ARRAY_SIZE  100

typedef struct
{
    unsigned char swaps,ext_iterations;
    unsigned char int_iterations[MAX_ARRAY_SIZE];
}results;

void copy_array(unsigned short destination[MAX_ARRAY_SIZE], unsigned short source[MAX_ARRAY_SIZE], unsigned char size);
results selection_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size);
results insertion_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size);
results shell_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size);

int main(void)
{
    FILE* file = fopen(FILE_SORT,"r");
    if(!file)
        return 1;
    unsigned short array[MAX_ARRAY_SIZE],ord[MAX_ARRAY_SIZE];
    unsigned char i1,n,i2,size;
    results res;
    scanf("%hhu",&n);
    for(i1 = 0; i1 < n; i1++)
    {
        printf("Sequenza %u:\n",i1 + 1u);
        scanf("%hhu",&size);
        for(i2 = 0; i2 < size; i2++)
        {
            scanf("%hu",&array[i2]);
        }
        copy_array(array, ord, size);
        res = selection_sort(ord,size);
        printf("Selection sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
        res.swaps,res.ext_iterations);
        for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);

        copy_array(array, ord, size);
        res = insertion_sort(ord,size);
        printf("Insertion sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);

        copy_array(array, ord, size);
        res = shell_sort(ord,size);
        printf("Shell sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);
        fputc('\n',stdout);
    }
    return 0;
}

void copy_array(unsigned short destination[MAX_ARRAY_SIZE], unsigned short source[MAX_ARRAY_SIZE], unsigned char size)
{
    memcpy(destination,source,size / sizeof(unsigned short));
}

results selection_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size)
{
    results res = {0};
    unsigned char i1,i2;
    unsigned short copy[MAX_ARRAY_SIZE];
    copy_array(copy, array, size);
    for(i1 = 0; i1 < size; i1++)
    {
        for(i2 = i1; i2 < size; i2++)
        {

        }
    }

    return res;
}

results insertion_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size)
{
    results res = {0};
    short i1,i2;
    for(i1 = 1; i1 < size; i1++)
    {
        for(i2 = ((short)(i1 - 1)); i2 >= 0 && array[i1] < array[i2]; i2--)
        {
            array[i2 + 1] = array[i2];
            res.swaps++;
            res.int_iterations[i1 - 1]++;
        }
    }
    res.ext_iterations = i1 - 1;
    return res;
}

results shell_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size)
{
    results res;

    return res;
}