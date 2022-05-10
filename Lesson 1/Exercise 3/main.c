#include <stdio.h>

#define FILE_INPUT      "Bronte.txt"
#define FILE_OUTPUT_O   "Output_odd.txt"
#define FILE_OUTPUT_E   "Output_even.txt"

int main(void)
{
    FILE *fp_read,*fp_write_odd,*fp_write_even;
    char file_string[100],name[20];
    int counter = 0;
    if ((fp_read = fopen(FILE_INPUT, "r")) == NULL)
    {
        printf("Error opening file %s\n",FILE_INPUT);
        return 1;
    }
    if ((fp_write_odd = fopen(FILE_OUTPUT_O, "w")) == NULL)
    {
        printf("Error opening file %s\n",FILE_OUTPUT_O);
        return 2;
    }
    if ((fp_write_even = fopen(FILE_OUTPUT_E, "w")) == NULL)
    {
        printf("Error opening file %s\n",FILE_OUTPUT_E);
        return 3;
    }
    printf("What's your name? ");
    fgets(name,20,stdin);
    while (!feof(fp_read))
    {
        counter++;
        if (counter%2==0)
        {
            fscanf(fp_read, "%s", file_string);
            if (!feof(fp_read))
            {
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        }
        else
        {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read)) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write_even);
    fclose(fp_write_odd);
    return 0;
}