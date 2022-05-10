#include <stdio.h>

#define FILE_MAP    "mappa.txt"

#define MAX_MATRIX_ROWS     50
#define MAX_MATRIX_COLS     50

#define CHAR_MATRIX_WHITE   '0'
#define CHAR_MATRIX_BLACK   '1'

#define MATRIX_WHITE        0
#define MATRIX_BLACK        1

typedef struct {
    unsigned char row, col;
}coord;

typedef struct {
    unsigned char matrix[MAX_MATRIX_ROWS][MAX_MATRIX_COLS];
    coord size;
}matrix;

typedef matrix* matrixp;

unsigned char calculateBase(matrixp m, coord c);
unsigned char calculateHeight(matrixp m, coord c);
coord findMaxBase(matrixp m);
coord findMaxHeight(matrixp m);
coord findMaxArea(matrixp m);

int main(void)
{
    FILE* file;
    file = fopen(FILE_MAP,"r");
    if(!file)
        return 1;
    unsigned char i1,i2;
    matrix m;
    fscanf(file, "%hhu %hhu", &m.size.row, &m.size.col);
    for(i1 = 0; i1 < m.size.row; i1++)
    {
        i2 = 0;
        while(i2 < m.size.col)
        {
            switch (fgetc(file))
            {
                case CHAR_MATRIX_BLACK:
                {
                    m.matrix[i1][i2] = MATRIX_BLACK;
                    i2++;
                    break;
                }
                case CHAR_MATRIX_WHITE:
                {
                    m.matrix[i1][i2] = MATRIX_WHITE;
                    i2++;
                    break;
                }
            }
        }
    }
    fclose(file);

    coord result;
    unsigned char base,height;

    result = findMaxBase(&m);
    base = calculateBase(&m,result);
    height = calculateHeight(&m,result);
    printf("Max Base:\testr. sup. SX=<%hhu,%hhu> b=%hhu, h=%hhu, Area=%d\n",
           result.row,result.col,
           base,height,
           base * height);

    result = findMaxArea(&m);
    base = calculateBase(&m,result);
    height = calculateHeight(&m,result);
    printf("Max Area:\testr. sup. SX=<%hhu,%hhu> b=%hhu, h=%hhu, Area=%d\n",
           result.row,result.col,
           base,height,
           base * height);

    result = findMaxHeight(&m);
    base = calculateBase(&m,result);
    height = calculateHeight(&m,result);
    printf("Max Altezza:\testr. sup. SX=<%hhu,%hhu> b=%hhu, h=%hhu, Area=%d\n",
           result.row,result.col,
           base,height,
           base * height);

    return 0;
}

unsigned char calculateBase(matrixp m, coord c)
{
    unsigned char i;
    for(i = c.col; i < m->size.col && m->matrix[c.row][i] == MATRIX_BLACK; i++);
    return i - c.col;
}

unsigned char calculateHeight(matrixp m, coord c)
{
    unsigned char i;
    for(i = c.row; i < m->size.row && m->matrix[i][c.col] == MATRIX_BLACK; i++);
    return i - c.row;
}

coord findMaxBase(matrixp m)
{
    coord result = {0};
    unsigned char i1,i2,count,max;
    max = 0;
    for(i1 = 0; i1 < m->size.row; i1++)
    {
        count = 0;
        for(i2 = 0; i2 < m->size.col; i2++)
        {
            if(m->matrix[i1][i2] == MATRIX_BLACK)
                count++;
            else
            {
                if(count > max)
                {
                    max = count;
                    result.row = i1;
                    result.col = i2 - count;
                }
                count = 0;
            }
        }
    }
    if(count > max)
    {
        result.row = i1 - 1;
        result.col = i2 - count;
    }
    return result;
}

coord findMaxHeight(matrixp m)
{
    coord result = {0};
    unsigned char i1,i2,count,max;
    max = 0;
    for(i2 = 0; i2 < m->size.col; i2++)
    {
        count = 0;
        for(i1 = 0; i1 < m->size.row; i1++)
        {
            if(m->matrix[i1][i2] == MATRIX_BLACK)
                count++;
            else
            {
                if(count > max)
                {
                    max = count;
                    result.row = i1 - count;
                    result.col = i2;
                }
                count = 0;
            }
        }
    }
    if(count > max)
    {
        result.row = i1 - count;
        result.col = i2 - 1;
    }
    return result;
}

coord findMaxArea(matrixp m)
{
    coord i,result = {0};
    unsigned char max,base,area;
    max = 0;
    for(i.row = 0; i.row < m->size.row; i.row++)
    {
        for(i.col = 0; i.col < m->size.col; i.col++)
        {
            if(m->matrix[i.row][i.col] == MATRIX_BLACK)
            {
                base = calculateBase(m,i);
                area = base * calculateHeight(m, i);
                if(area > max)
                {
                    max = area;
                    result = i;
                }
                i.col += base;
            }
        }
    }
    return result;
}