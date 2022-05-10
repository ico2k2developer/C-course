#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILE_SOURCE "sorgente.txt"
#define FILE_DICTRY "dizionario.txt"
#define FILE_OUTPUT "ricodificato.txt"

#define MAX_LENGTH  40
#define MAX_COUNT   10

typedef struct item
{
    char original[MAX_LENGTH + 1];
    char encoded[MAX_LENGTH + 1];
}item;

int main(void)
{
    FILE* source = fopen(FILE_SOURCE,"rb");
    if(!source)
        return 1;
    FILE* dict = fopen(FILE_DICTRY,"r");
    if(!dict)
    {
        fclose(source);
        return 2;
    }
    FILE* output = fopen(FILE_OUTPUT,"wb");
    if(!output)
    {
        fclose(source);
        fclose(dict);
        return 3;
    }
    item replace[MAX_COUNT];
    unsigned char s,i,found;
    size_t pos,target;
    int c;
    fscanf(dict,"%hhu",&s);
    for(i = 0; i < s; i++)
    {
        fscanf(dict,"%s %s",replace[i].encoded,replace[i].original);
    }
    fclose(dict);
    while((c = fgetc(source)) != EOF)
    {
        if(isalpha(c))
        {
            found = 0;
            for(i = 0; i < s; i++)
            {
                pos = 0;
                if(replace[i].original[pos] == c)
                {
                    target = strlen(replace[i].original);
                    do
                    {
                        pos++;
                        if(target == pos)
                        {
                            fputs(replace[i].encoded,output);
                        }
                        else
                        {
                            c = fgetc(source);
                        }
                    }
                    while(replace[i].original[pos] == c);

                    if(pos != target)
                    {
                        fseek(source, -1-((long)pos), SEEK_CUR);
                        c = fgetc(source);
                    }
                    else
                    {
                        found = 1;
                        break;
                    }
                }

            }
            if(!found)
            {
                fseek(source,-1,SEEK_CUR);
                fputc(fgetc(source),output);
            }
        }
        else
            fputc(c,output);
    }
    fclose(source);
    fclose(output);
    return 0;
}