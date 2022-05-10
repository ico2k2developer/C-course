#include <stdio.h>

#define PI      3.141592654

#define TYPE_SQUARE 'Q'
#define TYPE_CIRCLE 'C'

#define MODE_DIAG   'D'
#define MODE_SIDE   'L'
#define MODE_DIAM   'D'
#define MODE_RADIUS 'R'

#define LOWER(X)    X + ('a' - 'A')

int main(void)
{
    char type,mode;
    float value;
    printf("Inserisci il comando: ");
    scanf("%c %c%f",&type,&mode,&value);
    switch(type)
    {
        case TYPE_SQUARE:
        case LOWER(TYPE_SQUARE):
            switch(mode)
            {
                case MODE_DIAG:
                case LOWER(MODE_DIAG):
                    printf("L'area del quadrato di diagonale %.2f e\' %.2f\n",value,value * value / 2);
                    break;
                case MODE_SIDE:
                case LOWER(MODE_SIDE):
                    printf("L'area del quadrato di lato %.2f e\' %.2f\n",value,value * value);
                    break;
                default:
                    printf("\"%c\" non e\' una modalita\' di calcolo area del quadrato valida.\n",mode);
                    return 2;
            }
            break;
        case TYPE_CIRCLE:
        case LOWER(TYPE_CIRCLE):
            switch(mode)
            {
                case MODE_DIAM:
                case LOWER(MODE_DIAM):
                    printf("L'area del cerchio di diametro %.2f e\' %.2f\n",value,PI * value * value / 4);
                    break;
                case MODE_RADIUS:
                case LOWER(MODE_RADIUS):
                    printf("L'area del cerchio di raggio %.2f e\' %.2f\n",value,PI * value * value);
                    break;
                default:
                    printf("\"%c\" non e\' una modalita\' di calcolo area del cerchio valida.\n",mode);
                    return 3;
            }
            break;
        default:
            printf("\"%c\" non e\' una modalita\' di calcolo area valida.\n",type);
            return 1;
    }
    return 0;
}