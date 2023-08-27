#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void createFile(const char *file_name){
    FILE *fptr;
    char content[1000];
    fptr = fopen(file_name, "w");
		if (fptr == NULL)
		{
			printf("File not found or unable to open.\n");
		}
		printf("\n\n\t\t\tWRITE MODE\n");
		printf("Enter the content to write (Press Ctrl+Z or Ctrl+D to stop):\n");
		while (fgets(content, sizeof(content), stdin) != NULL) {
            // Remove the trailing newline character
            int len = strlen(content);
            if (len > 0 && content[len - 1] == '\n') {
                content[len - 1] = '\0'; // Replace '\n' with '\0' (null character)
            }
            fputs(content, fptr);
        }
        fclose(fptr);
}


void updateFile(const char *file_name){
    FILE *fptr;
    char content[1000];
    fptr = fopen(file_name, "a");
		if (fptr == NULL)
		{
			printf("File not found or unable to open.\n");
			exit(1);
		}
		printf("\n\n\t\t\tAPPEND MODE\n");
		printf("Enter the content to append (Press Ctrl+Z or Ctrl+D to stop):\n");
		while (fgets(content, sizeof(content), stdin) != NULL) {
            // Remove the trailing newline character
            int len = strlen(content);
            if (len > 0 && content[len - 1] == '\n') {
                content[len - 1] = '\0'; // Replace '\n' with '\0' (null character)
            }
            fputs(content, fptr);
        }
		fclose(fptr);
}

void copyFile(){
    
}