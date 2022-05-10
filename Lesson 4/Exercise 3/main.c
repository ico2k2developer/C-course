#include <stdio.h>
#include <string.h>
#include <limits.h>

#define SIZE_MAX_        20
#define FILENAME_MAX_2  (20 + 1)
#define FILENAME_MAX_   (FILENAME_MAX > FILENAME_MAX_2) ? FILENAME_MAX_2 : FILENAME_MAX

#define MATRIX_MIN      1

int main(void)
{
    int matrix[SIZE_MAX_][SIZE_MAX_];
    char filename[FILENAME_MAX_];
    unsigned char x,y,i,i2,i3,i4,sq,dim,maxx,maxy;
    short sum,maxsum = SHRT_MIN;
    printf("Inserisci il nome del file:\n");
    fgets(filename,FILENAME_MAX_,stdin);
    filename[strlen(filename) - 1] = '\0';
    FILE* input = fopen(filename,"r");
    if(!input)
        return 1;
    fscanf(input,"%hhu %hhu",&y,&x);
    if(x > y)
        sq = y;
    else
        sq = x;
    if(sq < MATRIX_MIN)
    {
        fclose(input);
        return 2;
    }
    for(i = 0; i < y; i++)
    {
        for(i2 = 0; i2 < x; i2++)
        {
            fscanf(input,"%i",matrix[i] + i2);
        }
    }
    fclose(input);
    printf("Inserisci la dimensione delle matrici quadrate da disegnare (da %u a %u).\n",
           MATRIX_MIN,sq);
    scanf("%hhu",&dim);
    printf("\nLe sottomatrici quadrate di dimensione %hhu sono:\n\n",dim);
    for(i = 0; (dim + i) <= y; i++)
    {
        for(i2 = 0; (dim + i2) <= x; i2++)
        {
            sum = 0;
            for(i3 = i; i3 < (dim + i); i3++)
            {
                for(i4 = i2; i4 < (dim + i2); i4++)
                {
                    sum += matrix[i3][i4];
                    printf("%i ",matrix[i3][i4]);
                }
                fputc('\n',stdout);
            }
            fputc('\n',stdout);
            if(sum > maxsum)
            {
                maxsum = sum;
                maxx = i2;
                maxy = i;
            }
        }
    }
    printf("La sottomatrice con somma degli elementi massima (%hu) e\':\n\n",maxsum);
    for(i = maxy; i < (dim + maxy); i++)
    {
        for(i2 = maxx; i2 < (dim + maxx); i2++)
        {
            printf("%i ",matrix[i][i2]);
        }
        fputc('\n',stdout);
    }
    return 0;
}