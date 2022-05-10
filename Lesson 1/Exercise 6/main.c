#include <stdio.h>

#define FILE_INPUT      "Operations.txt"
#define FILE_OUTPUT     "Results.txt"

#define OPERATOR_SUM    '+'
#define OPERATOR_DIFF   '-'
#define OPERATOR_PROD   '*'
#define OPERATOR_DIV    '/'

char checkOp(char op);
float execute(char op,float op1,float op2);

int main(void)
{
    FILE *in,*out;
    float op1,op2;
    char op;
    if((in = fopen(FILE_INPUT,"r")) == NULL)
    {
        printf("Errore nell'apertura del file %s\n",FILE_INPUT);
        return 1;
    }
    if((out = fopen(FILE_OUTPUT,"w")) == NULL)
    {
        printf("Errore nell'apertura del file %s\n",FILE_OUTPUT);
        return 2;
    }
    while (!feof(in))
    {
        fscanf(in,"%c %f %f\n",&op,&op1,&op2);
        if(checkOp(op))
            fprintf(out,"%c %.2f\n",op,execute(op,op1,op2));
        else
        {
            fprintf(out,"Operatore non valido.\n");
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}

char checkOp(char op)
{
    switch (op)
    {
        case OPERATOR_SUM:
        case OPERATOR_DIFF:
        case OPERATOR_PROD:
        case OPERATOR_DIV:
            return 1;
        default:
            return 0;
    }
}

float execute(char op,float op1,float op2)
{
    switch(op)
    {
        case OPERATOR_SUM:
            return op1 + op2;
        case OPERATOR_DIFF:
            return op1 - op2;
        case OPERATOR_PROD:
            return op1 * op2;
        case OPERATOR_DIV:
            return op1 / op2;
        default:
            return 0;
    }
}