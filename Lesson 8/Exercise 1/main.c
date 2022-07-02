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

void leggiMatrice(unsigned char M[MAX_MATRIX_ROWS][MAX_MATRIX_COLS],unsigned char MAXR,
                  unsigned char* nr,unsigned char* nc);

unsigned char riconosciRegione(unsigned char M[MAX_MATRIX_ROWS][MAX_MATRIX_COLS],
                               unsigned char nr,unsigned char nc,
                               unsigned char r,unsigned char c,
                               unsigned char* b,unsigned char* h);

coord findMaxBase(matrixp m);
coord findMaxHeight(matrixp m);
coord findMaxArea(matrixp m);

int main(void)
{
    matrix m;

    leggiMatrice(m.matrix,MAX_MATRIX_ROWS,&m.size.row,&m.size.col);

    coord result;
    unsigned char base,height;

    result = findMaxBase(&m);
    riconosciRegione(m.matrix,m.size.row,m.size.col,result.row,result.col,&base,&height);
    printf("Max Base:\testr. sup. SX=<%hhu,%hhu> b=%hhu, h=%hhu, Area=%d\n",
           result.row,result.col,
           base,height,
           base * height);

    result = findMaxArea(&m);
    riconosciRegione(m.matrix,m.size.row,m.size.col,result.row,result.col,&base,&height);
    printf("Max Area:\testr. sup. SX=<%hhu,%hhu> b=%hhu, h=%hhu, Area=%d\n",
           result.row,result.col,
           base,height,
           base * height);

    result = findMaxHeight(&m);
    riconosciRegione(m.matrix,m.size.row,m.size.col,result.row,result.col,&base,&height);
    printf("Max Altezza:\testr. sup. SX=<%hhu,%hhu> b=%hhu, h=%hhu, Area=%d\n",
           result.row,result.col,
           base,height,
           base * height);

    return 0;
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
                //base = calculateBase(m,i);
                //area = base * calculateHeight(m, i);
                riconosciRegione(m->matrix,m->size.row,m->size.col,i.row,i.col,&base,&area);
                area *= base;
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

void leggiMatrice(unsigned char M[MAX_MATRIX_ROWS][MAX_MATRIX_COLS],unsigned char MAXR,
                  unsigned char* nr,unsigned char* nc)
{
    FILE* file;
    file = fopen(FILE_MAP,"r");
    if(!file)
        return;
    unsigned char i1,i2;
    fscanf(file, "%hhu %hhu",nr,nc);
    for(i1 = 0; i1 < *nr; i1++)
    {
        i2 = 0;
        while(i2 < *nc)
        {
            switch (fgetc(file))
            {
                case CHAR_MATRIX_BLACK:
                {
                    M[i1][i2] = MATRIX_BLACK;
                    i2++;
                    break;
                }
                case CHAR_MATRIX_WHITE:
                {
                    M[i1][i2] = MATRIX_WHITE;
                    i2++;
                    break;
                }
            }
        }
    }
    fclose(file);
}

unsigned char riconosciRegione(unsigned char M[MAX_MATRIX_ROWS][MAX_MATRIX_COLS],
                               unsigned char nr,unsigned char nc,
                               unsigned char r,unsigned char c,
                               unsigned char* b,unsigned char* h)
{
    *b = 0;
    *h = 0;
    if(M[r][c] == MATRIX_BLACK)
    {
        unsigned char i;
        for(i = c; i < nc && M[r][i] == MATRIX_BLACK; i++);
        *b = i - c;
        for(i = r; i < nr && M[i][c] == MATRIX_BLACK; i++);
        *h =  i - r;
        if(*b != 0 && *h != 0)
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}