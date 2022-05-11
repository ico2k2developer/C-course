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
void calculateH(unsigned int destination[MAX_ARRAY_SIZE],unsigned char size);
results shell_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size);

int main(void)
{
    FILE* file = fopen(FILE_SORT,"r");
    if(!file)
        return 1;
    unsigned short array[MAX_ARRAY_SIZE],ord[MAX_ARRAY_SIZE];
    unsigned char i1,n,i2,size;
    results res;
    fscanf(file,"%hhu",&n);
    for(i1 = 0; i1 < 1; i1++)
    {
        printf("Sequenza %u:\n",i1 + 1u);
        fscanf(file,"%hhu",&size);
        for(i2 = 0; i2 < size; i2++)
            fscanf(file,"%hu",&array[i2]);
        copy_array(ord, array, size);
        res = selection_sort(ord,size);
        printf("Selection sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
        res.swaps,res.ext_iterations);
        /*for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);*/
        for (i2 = 0; i2 < size; i2++)
        {
            printf("[%d]",ord[i2]);
        }

        copy_array(ord, array, size);
        res = insertion_sort(ord,size);
        printf("\n\nInsertion sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        /*for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);*/
        for (i2 = 0; i2 < size; i2++)
        {
            printf("[%d]",ord[i2]);
        }

        copy_array(ord, array, size);
        res = shell_sort(ord,size);
        printf("\n\nShell sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        /*for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);*/
        for (i2 = 0; i2 < size; i2++)
        {
            printf("[%d]",ord[i2]);
        }
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
            if(copy[i2] > array[i1])
            {
                array[i1] = copy[i2];
                res.swaps++;
            }
            res.int_iterations[i1]++;
        }
        res.ext_iterations++;
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

void calculateH(unsigned int destination[MAX_ARRAY_SIZE],unsigned char size)
{
    unsigned char i;
    destination[0] = 1;
    for(i = 1; i < size; i += 2)
        destination[i] = 8 * (2 << (i - 1)) - 6 * (2 << (i/2)) + 1;
    for(i = 2; i < size; i += 2)
        destination[i] = 9 * (2 << (i - 1)) - 9 * (2 << ((i - 1)/2)) + 1;
}

results shell_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size)
{
    results res;
    unsigned int h[MAX_ARRAY_SIZE];
    unsigned char i1,i2,hi;
    unsigned int offset;
    calculateH(h,size / 3);
    for(hi = size - 1; h[hi] > size/3; hi--);
    hi++;
    for(hi++; hi > 0; hi--)
    {
        offset = h[hi - 1];
        printf("Using h value %u.\n",offset);
        for(i1 = offset; i1 < size; i1 += offset)
        {
            for(i2 = i1 - offset + 1; i2 < i1; i2++)
            {
                if(array[i2 - 1] < array[i2])
                {
                    unsigned short tmp = array[i2 - 1];
                    array[i2 - 1] = array[i2];
                    array[i2] = tmp;
                    res.swaps++;
                }
            }
        }
    }


    return res;
}