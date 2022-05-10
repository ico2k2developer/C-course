#include <stdio.h>

#define OPERATOR_SUM    '+'
#define OPERATOR_DIFF   '-'
#define OPERATOR_PROD   '*'
#define OPERATOR_DIV    '/'

char checkOp(char op);

int main(void)
{
    float op1,op2;
    char op;
    printf("Inserisci un operatore (%c %c %c %c): ",
           OPERATOR_SUM,OPERATOR_DIFF,OPERATOR_PROD,OPERATOR_DIV);
    op = getchar();
    if(!checkOp(op))
    {
        printf("Operatore non valido.\n");
        return 1;
    }

    printf("Inserisci i due operandi separati da spazio:\n"
           "NOTA: i numeri decimali vanno scritti usando il punto, non la virgola\n");
    scanf("%f %f",&op1,&op2);
    switch(op)
    {
        case OPERATOR_SUM:
            op1 += op2;
            break;
        case OPERATOR_DIFF:
            op1 -= op2;
            break;
        case OPERATOR_PROD:
            op1 *= op2;
            break;
        case OPERATOR_DIV:
            op1 /= op2;
            break;
    }
    printf("%c %.2f\n",op,op1);
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