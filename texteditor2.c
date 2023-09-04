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
	char search_str[100];

	printf("\n\t\t\tNotepad 2.0\n");
	do
	{

		printf("\n\nEnter your choice\n1.Create a file\n2.Read a file\n3.Update a file\n4.Delete a file\n5.Copy and paste a file\n6.Cut and Paste a file\n7.Replace a String\n8.Find\n9.View Files\n10.Exit\n");
		scanf("%d", &choice);
		
		switch (choice)
		{
		case 1:
			// Write mode
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			CREATE_FILE(file_name);
			break;

		case 2:
			// Read mode
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			READ_FILE(file_name);
			break;

		case 3:
			// Update mode
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			UPDATE_FILE(file_name);
			break;

		case 4:
			// delete the file
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			DELETE_FILE(file_name);
			break;

		case 5:
			// copy a file
			COPY_FILE(file_name);
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			break;
		case 6:
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			CUT_FILE(file_name);
			break;
		case 7:
			// replace
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			printf("Enter old substring: ");
			scanf("%s", old_str);
			printf("Enter new substring: ");
			scanf("%s", new_str);
			REPLACE_FILE(file_name, old_str, new_str);
			break;
		case 8:
			printf("\n\t\t\tEnter file name: ");
			scanf("%s", file_name);
			printf("Enter the string to search for: ");
			scanf("%s", search_str);
			// FIND_FILE(file_name);
			if (isStringInFile(file_name, search_str))
			{
				printf("String found in the file.\n");
			}
			else
			{
				printf("String not found in the file.\n");
			}
			break;
		case 9:
		VIEW_FILES();
		break;
			case 10:
			// Exit
			exit(0);

		default:
			printf("Invalid choice! try again\n");
			break;
		}

	} while (1);

	return 0;
}
