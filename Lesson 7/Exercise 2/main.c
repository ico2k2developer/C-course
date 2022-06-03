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
    for(i1 = 0; i1 < n; i1++)
    {
        fscanf(file,"%hhu",&size);
        printf("Sequenza %u di %hhu elementi:\n",i1 + 1u,size);
        for(i2 = 0; i2 < size; i2++)
            fscanf(file,"%hu",&array[i2]);

        copy_array(ord, array, size);

        copy_array(ord, array, size);
        res = selection_sort(ord,size);
        printf("\n\nSelection sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);

        copy_array(ord, array, size);
        res = insertion_sort(ord,size);
        printf("\n\nInsertion sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);

        copy_array(ord, array, size);
        res = shell_sort(ord,size);
        printf("\n\nShell sort:\n"
               "\t%hhu scambi.\n"
               "\t%hhu iterazioni del ciclo esterno:\n",
               res.swaps,res.ext_iterations);
        for(i2 = 0; i2 < res.ext_iterations; i2++)
            printf("\t\tIterazione %d: %hhu iterazioni nel ciclo interno.\n",
                   i2 + 1,res.int_iterations[i2]);
    }
    return 0;
}

void copy_array(unsigned short destination[MAX_ARRAY_SIZE], unsigned short source[MAX_ARRAY_SIZE], unsigned char size)
{
    memcpy(destination,source,size * sizeof(unsigned short));
}

results selection_sort(unsigned short array[MAX_ARRAY_SIZE],unsigned char size)
{
    results res = {0};
    unsigned char i1,i2;
    for(i1 = 0; i1 < size; i1++)
    {
        for(i2 = i1 + 1; i2 < size; i2++)
        {
            if(array[i1] > array[i2])
            {
                unsigned short tmp = array[i1];
                array[i1] = array[i2];
                array[i2] = tmp;
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
    unsigned char i1,i2,i3;
    for(i1 = 1; i1 < size; i1++)
    {
        unsigned short tmp = array[i1];
        for(i2 = 0; i2 < i1 && array[i1] > array[i2]; i2++);
        for(i3 = i1; i3 > i2; i3--)
        {
            array[i3] = array[i3 - 1];
            res.swaps++;
            res.int_iterations[i1 - 1]++;
        }
        array[i2] = tmp;
        res.swaps++;
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
    results res = {0};
    unsigned int h[MAX_ARRAY_SIZE];
    unsigned char i1,i2,i3,i4,hi;
    unsigned int offset;
    unsigned char hsize = size / 3;
    calculateH(h,hsize);
    for(hi = hsize - 1; h[hi] > hsize; hi--);
    for(hi++; hi > 0; hi--)
    {
        offset = h[hi - 1];
        for(i1 = 0; i1 < offset; i1++)
        {
            for(i2 = i1; i2 < size; i2 += offset)
            {
                unsigned short tmp = array[i2];
                for(i3 = i1; i3 < i2 && array[i2] > array[i3]; i3 += offset);
                for(i4 = i2; i4 > i3; i4 -= offset)
                {
                    array[i4] = array[i4 - offset];
                    res.swaps++;
                }
                array[i3] = tmp;
                res.int_iterations[(i2 - i1) / offset]++;
            }
            res.ext_iterations++;
        }
    }


    return res;
}