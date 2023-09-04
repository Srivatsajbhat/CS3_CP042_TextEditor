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
    printf("Press Enter and type Stop to end input.\n");
    FILE *fptr;
    bool status;
    char content[1000];
    fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("File not found or unable to open.\n");
    }
    printf("\n\t\t\tWRITE MODE\n");
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
    printf("\n\t\t\tEnter destination file name: ");
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
    printf("\n\t\t\tEnter destination file name: ");
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


// find
// void FIND_FILE(const char *file_name)
// {
//    char sub_str;
//    printf("Enter the string to find: ");
//    scanf("%s",sub_str);
//    FILE *fptr;
//    char buffer[1024];
//    char *pos;
//    int index = -1;
//    fptr = fopen(file_name, "r");
//    if (fptr == NULL)
//    {
//        printf("File not found or unable to open.\n");
//    }
//    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
//    {
//        pos = strstr(buffer, sub_str);
//        if (pos != NULL)
//        {
//            index = pos - buffer;
//            break;
//        }
//    }
//    printf("The string is found!\n");
//    fclose(fptr);
// }

// replace function
void REPLACE_FILE(const char *file_name, const char *old_str, const char *new_str) {
    FILE *fptr;
    FILE *tempFile;
    char buffer[1024];
    char new_buffer[1024];
    char *pos;

    fptr = fopen(file_name, "r");
    if (fptr == NULL) {
        printf("File not found or unable to open.\n");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(fptr);
        return;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        pos = strstr(buffer, old_str);

        if (pos != NULL) {
            // Copy characters before the old_str
            strncpy(new_buffer, buffer, pos - buffer);
            new_buffer[pos - buffer] = '\0'; // Null-terminate the new string

            // Append the new_str
            strcat(new_buffer, new_str);

            // Append the characters after the old_str
            strcat(new_buffer, pos + strlen(old_str));

            // Write the modified line to the temporary file
            fputs(new_buffer, tempFile);
        } else {
            // If old_str not found, write the original line
            fputs(buffer, tempFile);
        }
    }

    fclose(fptr);
    fclose(tempFile);

    // Remove the original file and rename the temporary file
    remove(file_name);
    rename("temp.txt", file_name);
}


int isStringInFile(const char *file_name, const char *search_str) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 0; // Return 0 to indicate failure
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, search_str) != NULL) {
            fclose(file);
            return 1; // Return 1 to indicate success (string found)
        }
    }

    fclose(file);
    return 0; // Return 0 to indicate failure (string not found)
}