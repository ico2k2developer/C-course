#include <stdio.h>
#include <ctype.h>

#define FILE_INPUT  "input.txt"
#define FILE_OUTPUT "output.txt"

#define LIMIT_LINE  25

int main(void)
{
    FILE* input = fopen(FILE_INPUT,"r");
    if(!input)
        return 1;
    FILE* output = fopen(FILE_OUTPUT,"w");
    if(!output)
    {
        fclose(input);
        return 2;
    }
    int c;
    char checkSpace = 0;
    char checkUpper = 0;
    unsigned long count = 0;
    while((c = fgetc(input)) != EOF)
    {
        if(checkSpace)
        {
            if(c != ' ' && c != '\n')
                fputc(' ',output);
            checkSpace = 0;
        }

        if(isdigit(c))
            fputc('*',output);
        else if(ispunct(c))
        {
            if(c == '.' || c == '!' || c == '?')
                checkUpper = 1;
            checkSpace = 1;
            fputc(c,output);
        }
        else if(isalpha(c))
        {
            fputc(checkUpper ? toupper(c) : c,output);
            checkUpper = 0;
        }
        else if(c == '\n')
        {
            unsigned long i,tmp = ftell(output);
            for(i = tmp; i < count + LIMIT_LINE; i++)
                fputc(' ',output);
            fprintf(output,"| c:%lu\n", tmp - count + 1);
            count = ftell(output);
        }
        else
            fputc(c,output);
        if((ftell(output) - count) == LIMIT_LINE)
        {
            fputs("| c:25\n",output);
            //fprintf(output,"| c:%lu\n", ftell(output) - count);
            count = ftell(output);
        }
    }
    unsigned long tmp = ftell(output);
    if(tmp != count)
    {
        unsigned long i;
        for(i = tmp; i < (count + LIMIT_LINE); i++)
            fputc(' ',output);
        fprintf(output,"| c:%lu\n", tmp - count);
    }
    fclose(input);
    fclose(output);
    return 0;
}