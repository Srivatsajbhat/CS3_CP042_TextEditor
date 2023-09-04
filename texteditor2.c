// Notepad 2.0

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
	FILE *fptr;
	char in, file_name[35];

	int choice;
	char *old_str[100], *new_str[100];

	printf("\n\t\t\tNotepad 2.0\n");
	do
	{

		printf("\n\nEnter your choice\n1.Create a file\n2.Read a file\n3.Update a file\n4.Delete a file\n5.Copy and paste a file\n6.Cut and Paste a file\n7.Replace a String\n8.Find\n9.Exit\n");
		scanf("%d", &choice);
		printf("\n\t\t\tEnter file name: ");
		scanf("%s", file_name);
		switch (choice)
		{
		case 1:
			// Write mode
			CREATE_FILE(file_name);
			break;

		case 2:
			// Read mode
			READ_FILE(file_name);
			break;

		case 3:
			// Update mode
			UPDATE_FILE(file_name);
			break;

		case 4:
			// delete the file
			DELETE_FILE(file_name);
			break;

		case 5:
			// copy a file
			COPY_FILE(file_name);
			break;
		case 6:
			CUT_FILE(file_name);
			break;
		case 7:
			// replace
            printf("Enter old substring: ");
            scanf("%s", old_str);
            printf("Enter new substring: ");
            scanf("%s", new_str);
            REPLACE_FILE(file_name, old_str, new_str);
            break;
		case 8:
			// FIND_FILE(file_name);
		// 	break;
		case 9:
			// Exit
			exit(0);

		default:
			printf("Invalid choice! try again\n");
			break;
		}

	} while (1);

	return 0;
}
