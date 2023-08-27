#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool endsWithEnd(const char *str)
{
    size_t len = strlen(str);
    if (len < 3)
    {
        return false; // String is too short to match "End"
    }
    return strcmp(str + len - 4, "Stop") == 0;
}

// Read a file
void READ_FILE(const char *file_name)
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

// Create a file
void CREATE_FILE(const char *file_name)
{
    FILE *fptr;
    bool status;
    char content[1000];
    fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("File not found or unable to open.\n");
    }
    printf("\n\n\t\t\tWRITE MODE\n");
    printf("Enter the content to write (Press Ctrl+Z or Ctrl+D to stop):\n");
    while (fgets(content, sizeof(content), stdin) != NULL)
    {
        // Remove the trailing newline character
        int len = strlen(content);
        if (len > 0 && content[len - 1] == '\n')
        {
            content[len - 1] = '\0'; // Replace '\n' with '\0' (null character)
        }
        status = endsWithEnd(content);
        if (status)
        {
            break; // Stop if user enters "End"
        }
        fputs(content, fptr);
    }
    fclose(fptr);
}

// Update a file
void UPDATE_FILE(const char *file_name)
{
    FILE *fptr;
    bool status;
    char content[1000];
    fptr = fopen(file_name, "a");
    if (fptr == NULL)
    {
        printf("File not found or unable to open.\n");
        exit(1);
    }
    printf("\n\n\t\t\tAPPEND MODE\n");
    printf("Enter the content to append (Press Ctrl+Z or Ctrl+D to stop):\n");
    while (fgets(content, sizeof(content), stdin) != NULL)
    {
        // Remove the trailing newline character
        int len = strlen(content);
        if (len > 0 && content[len - 1] == '\n')
        {
            content[len - 1] = '\0'; // Replace '\n' with '\0' (null character)
        }
        status = endsWithEnd(content);
        if (status)
        {
            break; // Stop if user enters "End"
        }
        fputs(content, fptr);
    }
    fclose(fptr);
}

// Delete a file
void DELETE_FILE(const char *fileName)
{
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

// Copy and Paste a file
void COPY_FILE(const char *source_file)
{
    char destination_file[35];
    printf("Enter destination file name: ");
    scanf("%s", destination_file);
    FILE *source, *destination;
    char ch;
    source = fopen(source_file, "r");
    if (source == NULL)
    {
        printf("Source file not found or unable to open.\n");
        return;
    }
    destination = fopen(destination_file, "w");
    if (destination == NULL)
    {
        printf("Unable to create or open the destination file.\n");
        fclose(source);
        return;
    }
    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }
    fclose(source);
    fclose(destination);
    printf("File copied successfully.\n");
}

// Cut and Paste a file
void CUT_FILE(const char *source_file)
{
    char destination_file[35];
    printf("Enter destination file name: ");
    scanf("%s", destination_file);
    FILE *source, *destination;
    char buffer[1024];
    source = fopen(source_file, "r");
    if (source == NULL)
    {
        printf("Source file not found or unable to open.\n");
        return;
    }
    destination = fopen(destination_file, "w");
    if (destination == NULL)
    {
        printf("Unable to create or open the destination file.\n");
        fclose(source);
        return;
    }
    while (fgets(buffer, sizeof(buffer), source) != NULL)
    {
        fputs(buffer, destination);
    }
    fclose(source);
    source = fopen(source_file, "w");
    fclose(source);
    fclose(destination);
    printf("File copied successfully.\n");
}
