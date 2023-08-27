// Notepad 2.0

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"



int main()
{
	FILE *fptr;
	char in, file_name[35];
	
	int choice;
	printf("\n\t\t\tNotepad 2.0\n");

	printf("\n\t\t\tEnter file name: ");
	scanf("%s", file_name);
	printf("\n\nEnter your choice\n1.Read\n2.Write\n3.Update\n4.Delete\n5.Exit\n");
	scanf("%d", &choice);
	switch (choice)
	{

	case 1:
		// Read mode
		readFile(file_name);
		break;
	case 2:
		// Write mode
		createFile(file_name);
		break;

	case 3:
		// Add mode
		updateFile(file_name);
		break;
	case 4:

		// Attempt to delete the file
		deleteFile(file_name);
		break;
	case 5:
		exit(0);

	default:
		printf("Invalid choice! try again\n");
		break;
	}

	return 0;
}
