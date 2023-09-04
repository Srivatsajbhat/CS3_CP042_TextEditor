#include <stdio.h>
#include <stdlib.h>

void readFile(const char *file_name)
{
	FILE *fptr;
    char in;
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("File not found or unable to open.\n");
        exit(1);
    }
    printf("\n\n\t\t\tREAD MODE\n");
    while ((in = getc(fptr)) != EOF)
    {
        printf("%c", in);
    }
    fclose(fptr);
}

void deleteFile(const char *fileName){
	int status = remove(fileName);
    if (status == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("File not found or unable to delete.\n");
    }
}