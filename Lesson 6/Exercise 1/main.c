#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LOG            "corse.txt"
#define MAX_STRING_LENGTH   (30 + 1)
#define OFFSET_YEAR         2010

#define MODE_INTERVAL           "date"
#define MODE_STARTED_FROM       "partenza"
#define MODE_ARRIVED_TO         "capolinea"
#define MODE_INTERVAL_DELAY     "ritardo"
#define MODE_CODE_TOTAL_DELAY   "ritardo_tot"
#define MODE_QUIT               "fine"
#define MAX_MODE_LENGTH    15

typedef enum comando_e
{
    r_date,
    r_partenza,
    r_capolinea,
    r_ritardo,
    r_ritardo_tot,
    r_fine,
}comando_e;

typedef struct data
{
    unsigned char code;
    char* start;
    char* destination;
    unsigned char year,month,day;
    unsigned char starth,startm,starts;
    unsigned char arrivalh,arrivalm,arrivals;
    unsigned char delay;
}data;

comando_e leggiComando(void);
void menuParola(data* logs,unsigned short count,comando_e mode);
void mostraRisultato(data* log);

int main(void)
{
    FILE* log = fopen(FILE_LOG,"r");
    if(!log)
        return 1;
    unsigned short count,i;
    fscanf(log,"%hu",&count);
    data* logs = (void*)malloc(sizeof(data) * count);
    if(!logs)
        return 2;
    for(i = 0; i < count; i++)
    {
        unsigned short year;
        logs[i].start = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
        logs[i].destination = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
        if(!logs[i].start || !logs[i].destination)
            return 3;
        fscanf(log, " %*c%*c%*c%hhu %s %s %hu/%hhu/%hhu %hhu:%hhu:%hhu %hhu:%hhu:%hhu %hhu",
               &logs[i].code,
               logs[i].start,
               logs[i].destination,
               &year,
               &logs[i].month,
               &logs[i].day,
               &logs[i].starth,
               &logs[i].startm,
               &logs[i].starts,
               &logs[i].arrivalh,
               &logs[i].arrivalm,
               &logs[i].arrivals,
               &logs[i].delay
        );
        logs[i].year = year - OFFSET_YEAR;

    }
    fclose(log);
    printf("Sono state caricate %hu corse.\n",count);
    comando_e mode = leggiComando();
    if(mode != r_fine)
    {
        menuParola(logs,count,mode);
    }

    for(i = 0; i < count; i++)
    {
        free(logs[i].start);
        free(logs[i].destination);
    }
    free(logs);
    return 0;
}

comando_e leggiComando(void)
{
    unsigned char found = 0;
    comando_e result;
    printf("\nScegliere un\'azione mediante una parola tra le seguenti:\n");
    printf("\"%s\": elencare tutte le corse partite in un certo intervallo di date\n",
           MODE_INTERVAL);
    printf("\"%s\": elencare tutti le corse partite da una certa fermata (partenza)\n",
           MODE_STARTED_FROM);
    printf("\"%s\": elencare tutti le corse aventi una data destinazione (capolinea)\n",
           MODE_ARRIVED_TO);
    printf("\"%s\": elencare tutte le corse che hanno raggiunto la destinazione in ritardo,"
           " in un certo intervallo di date\n",
           MODE_INTERVAL_DELAY);
    printf("\"%s\": elencare il ritardo complessivo accumulato dalle corse identificate da"
           " un certo codice di tratta\n",
           MODE_CODE_TOTAL_DELAY);
    printf("\"%s\": terminare il programma\n",
           MODE_QUIT);
    char buffer[MAX_MODE_LENGTH];
    do
    {
        fgets(buffer,MAX_MODE_LENGTH,stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if(strcmp(buffer,MODE_INTERVAL) == 0)
        {
            found = 1;
            result = r_date;
        }
        else if(strcmp(buffer,MODE_STARTED_FROM) == 0)
        {
            found = 1;
            result = r_partenza;
        }
        else if(strcmp(buffer,MODE_ARRIVED_TO) == 0)
        {
            found = 1;
            result = r_capolinea;
        }
        else if(strcmp(buffer,MODE_INTERVAL_DELAY) == 0)
        {
            found = 1;
            result = r_ritardo;
        }
        else if(strcmp(buffer,MODE_CODE_TOTAL_DELAY) == 0)
        {
            found = 1;
            result = r_ritardo_tot;
        }
        else if(strcmp(buffer,MODE_QUIT) == 0)
        {
            found = 1;
            result = r_fine;
        }
    }while(!found);
    return result;
}

void menuParola(data* logs,unsigned short count,comando_e mode)
{
    unsigned char i;
    switch (mode)
    {
        case r_date:
        case r_ritardo:
        {
            unsigned char startm,startd,endm,endd;
            unsigned short starty,endy;
            unsigned short start,end,current;
            printf("Inserisci la prima data nel formato yyyy/mm/dd: ");
            scanf("%hu/%hhu/%hhu",&starty,&startm,&startd);
            start = startd + 31*(startm + 12 * (starty - OFFSET_YEAR));
            printf("Inserisci la seconda data nel formato yyyy/mm/dd: ");
            scanf("%hu/%hhu/%hhu",&endy,&endm,&endd);
            end = endd + 31*(endm + 12 * (endy - OFFSET_YEAR));
            for(i = 0; i < count; i++)
            {
                current = logs[i].day + 31*(logs[i].month + 12 * logs[i].year);
                if(start <= current && end >= current)
                {
                    if(mode == r_date || logs[i].delay != 0)
                        mostraRisultato(logs + i);
                }
            }
            break;
        }
        case r_partenza:
        {
            char buffer[MAX_STRING_LENGTH];
            printf("Inserisci il nome della fermata di partenza: ");
            fgets(buffer,MAX_STRING_LENGTH,stdin);
            buffer[strlen(buffer) - 1] = '\0';
            for(i = 0; i < count; i++)
            {
                if(strcmp(buffer,logs[i].start) == 0)
                    mostraRisultato(logs + i);
            }
            break;
        }
        case r_capolinea:
        {
            char buffer[MAX_STRING_LENGTH];
            printf("Inserisci il nome della fermata di arrivo: ");
            fgets(buffer,MAX_STRING_LENGTH,stdin);
            buffer[strlen(buffer) - 1] = '\0';
            for(i = 0; i < count; i++)
            {
                if(strcmp(buffer,logs[i].destination) == 0)
                    mostraRisultato(logs + i);
            }
            break;
        }
        case r_ritardo_tot:
        {
            unsigned char code;
            unsigned short sum = 0;
            printf("Inserisci il codice della tratta: ");
            scanf("%*c%*c%*c%hhu",&code);
            for(i = 0; i < count; i++)
            {
                if(logs[i].code == code)
                    sum += logs[i].delay;
            }
            printf("Il ritardo complessivo delle tratte con codice GTT%03hhu e\' %hu.\n",
                   code,sum);
            break;
        }
    }
}

void mostraRisultato(data* log)
{
    printf("GTT%03hhu %s %s %04d/%02hhu/%02hhu %02hhu:%02hhu:%02hhu %02hhu:%02hhu:%02hhu %hhu\n",
           log->code,
           log->start,
           log->destination,
           ((unsigned short)log->year) + OFFSET_YEAR,
           log->month,
           log->day,
           log->starth,
           log->startm,
           log->starts,
           log->arrivalh,
           log->arrivalm,
           log->arrivals,
           log->delay
    );
}