#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME    "file.txt"

int printReservations(FILE * fp);
char * numberToDay(int number);
int dayToNumber(char * name);

int main(void)
{
    FILE* file = fopen(FILENAME,"r");
    if(file)
    {
        printf("\nIl valore ritornato e\' %d\n", printReservations(file));
        fclose(file);
    }
    else
        return 1;
    return 0;
}

int printReservations(FILE * fp)
{
    int n,i = 0,max = 0;
    int res[7][10] = {0},days[7] = {0};
    char tmp[100];
    if(fp)
    {
        while(fscanf(fp,"%s %i",tmp,&n) > 0)
        {


            /* ERRORE ORTOGRAFICO precedentemente era
            res[dayToNumber(tmp)][day[dayToNumber(tmp)]++] = n;
            */
            res[dayToNumber(tmp)][days[dayToNumber(tmp)]++] = n;


        }
        for(i = 0; i < 7; i++)
        {
            float avrg = 0.0;
            int count = 0;
            for(n = 0; n < 10 && res[i][n] != 0; n++)
            {
                avrg += res[i][n];
                count += res[i][n];
            }


            if(n > 0)
                avrg /= n;
            if(count > max)
                max = count;

            printf("%s: %d prenotazioni, %f clienti in media per tavolo\n",numberToDay(i),days[i],avrg);
        }
        return max;
    }
    else
        return 0;
}

char * numberToDay(int number)
{
    char* day = (char*)malloc(15);
    switch (number)
    {
        case 0:
        {
            strcpy(day, "Lunedi");
            break;
        }
        case 1:
        {
            strcpy(day, "Martedi");
            break;
        }
        case 2:
        {
            strcpy(day, "Mercoledi");
            break;
        }
        case 3:
        {
            strcpy(day, "Giovedi");
            break;
        }
        case 4:
        {
            strcpy(day, "Venerdi");
            break;
        }
        case 5:
        {
            strcpy(day, "Sabato");
            break;
        }
        case 6:
        {
            strcpy(day, "Domenica");
            break;
        }
        default:
        {
            day[0] = '\0';
        }
    }
    return day;
}

int dayToNumber(char * name)
{
    if(strcmp(name,"Lunedi") == 0)
        return 0;
    else if(strcmp(name,"Martedi") == 0)
        return 1;
    else if(strcmp(name,"Mercoledi") == 0)
        return 2;
    else if(strcmp(name,"Giovedi") == 0)
        return 3;
    else if(strcmp(name,"Venerdi") == 0)
        return 4;
    else if(strcmp(name,"Sabato") == 0)
        return 5;
    else if(strcmp(name,"Domenica") == 0)
        return 6;
    return -1;
}