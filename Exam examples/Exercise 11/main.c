//
// Created by ico2k2 on 30/6/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME    "file.txt"

#define TABLE_X     (5000)
#define TABLE_Y     (TABLE_X)
#define TABLE_EL    (TABLE_X * TABLE_Y)

#define TABLE_EL_TYPE   unsigned char
#define TABLE_EL_BYTE   sizeof(TABLE_EL_TYPE)
#define TABLE_EL_BIT    (TABLE_EL_BYTE * 8)
#define TABLE_EL_COUNT  (TABLE_EL / TABLE_EL_BIT + ((TABLE_EL & (TABLE_EL_BIT - 1)) != 0) + 1)
#define TABLE_BYTE      TABLE_EL_BYTE * TABLE_EL_COUNT

#define TABLE_GET_EL(table,x,y)     ((table)[(((y)*TABLE_X + (x))/TABLE_EL_BIT + 1)])
#define TABLE_GET(table,x,y)        (TABLE_GET_EL(table,x,y) & (1 << (((y)*TABLE_X + (x)) & (TABLE_EL_BIT - 1))))
#define TABLE_SET(table,x,y,val)    ((val) ? \
                                    (TABLE_GET_EL(table,x,y) |= (1 << (((y)*TABLE_X + (x)) & (TABLE_EL_BIT - 1)))) : \
                                    (TABLE_GET_EL(table,x,y) ^= (1 << (((y)*TABLE_X + (x)) & (TABLE_EL_BIT - 1)))))

int areaTot(FILE *fp);

int main(void)
{
    FILE* file = fopen(FILENAME,"r");
    if(file)
    {
        printf("%dx%d table memory size is going to be %llu bytes.\n",TABLE_X,TABLE_Y,TABLE_BYTE);
        printf("Total covered area is %i.\n", areaTot(file));
        fclose(file);
    }
    else
        return 1;
    return 0;
}

int areaTot(FILE *fp)
{
    if(fp)
    {
        fseek(fp,0,SEEK_SET);
        TABLE_EL_TYPE* table = (TABLE_EL_TYPE*)malloc(TABLE_BYTE);
        if(table)
        {
            memset(table,0,TABLE_BYTE);
            unsigned short bx,by,tx,ty;
            unsigned int i,j,count;
            while(fscanf(fp," %hu%hu%hu%hu",&bx,&by,&tx,&ty) > 0)
            {
                for(i = bx; i < tx; i++)
                {
                    for(j = by; j < ty; j++)
                        TABLE_SET(table,i,j,1);
                }
            }
            for(count = i = 0; i < TABLE_EL_COUNT; i++)
            {
                if(table[i])
                {
                    for(j = 0; j < TABLE_EL_BIT; j++)
                    {
                        if(table[i] & (1 << j))
                            count++;
                    }
                }
            }
            free(table);
            return count;
        }
    }
    return 0;
}