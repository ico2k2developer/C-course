#include <stdio.h>

#define FILE_INPUT  "Guide.txt"
#define FILE_OUTPUT "Output.txt"

int main(void)
{
    FILE *fp_read,*fp_write;
    char file_char,choice;

    if((fp_read = fopen(FILE_INPUT,"r")) == NULL)
    {
        printf("Error opening file %s\n",FILE_INPUT);
        return 1;
    }
    if((fp_write = fopen(FILE_OUTPUT,"w")) == NULL)
    {
        printf("Error opening file %s\n",FILE_OUTPUT);
        return 2;
    }

    printf("Print on console (C) or on file (F): ");
    choice = getchar();

    while (!feof((fp_read)))
    {
        file_char = fgetc(fp_read);
        if(!feof(fp_read))
        {
            switch (choice)
            {
                case 'C':
                case 'c':
                    printf("\nChar printed on the console %c",file_char);
                    break;
                case 'F':
                case 'f':
                    fputc(file_char,fp_write);
                    printf("\nChar saved on file: ");
                    putchar(file_char);
                    break;
                default:
                    printf("Wrong choice\n");
                    return 3;
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write);
    return 0;
}