#include <stdio.h>
#include <string.h>

void compressString(char * testo);

int main(void)
{
    compressString("abbabbbaAAAAAaCCaDDDeeeF");
    return 0;
}

void compressString(char * testo)
{
    size_t length = strlen(testo);


    // CORREZIONE: queste variabili non erano state dichiarate
    int i,j,count;


    for(i = 0; i < length; i++)
    {
        printf("%c",testo[i]);
        if(testo[i] == testo[i + 1])
        {
            count = 2;


            // ERRORE ORTOGRAFICO: precedentemente era lenght invece di length
            for(j = i + 2; j < length; j++)
            {
                if(testo[i] == testo[j])
                    count++;
                else
                    break;
            }
            printf("%i",count);


            /*
            CORREZIONE precedentemente era:
            i += count
            */
            i += count - 1;


        }
    }
}