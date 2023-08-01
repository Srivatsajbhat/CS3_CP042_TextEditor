// Notepad 2.0

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	char in, file_name[35];
	char content[1000];
	int choice;
	printf("\n\t\t\tNotepad 2.0\n");

	printf("\n\t\t\tEnter file name: ");
	scanf("%s", file_name);
	printf("\n\nEnter your choice\n1.Read\n2.Write\n3.Add\n4.Exit\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		// Read mode
		fptr = fopen(file_name, "r");
		if (fptr == NULL)
		{
			printf("File not found or unable to open.\n");
			exit(1);
		}
		printf("\n\n\t\t\tREAD MODE\n");
		while ((in = fgetc(fptr)) != EOF)
		{
			printf("%c", in);
		}
		fclose(fptr);
		break;

	case 2:
		// Write mode
		fptr = fopen(file_name, "w");
		if (fptr == NULL)
		{
			printf("File not found or unable to open.\n");
			return 1;
		}
		printf("\n\n\t\t\tWRITE MODE\n");
		printf("Enter the content to write (Press Ctrl+Z or Ctrl+D to stop):\n");
		while (fgets(content, sizeof(content), stdin) != NULL)
		{
			fputs(content, fptr);
		}
		fclose(fptr);
		break;

	case 3:
		// Add mode
		fptr = fopen(file_name, "a");
		if (fptr == NULL)
		{
			printf("File not found or unable to open.\n");
			exit(1);
		}
		printf("\n\n\t\t\tAPPEND MODE\n");
		printf("Enter the content to append (Press Ctrl+Z or Ctrl+D to stop):\n");
		while ((in = getchar()) != EOF)
		{
			putc(in, fptr);
		}
		fclose(fptr);
		break;

	case 4:
		exit(0);

	default:
		printf("Invalid choice! try again\n");
		break;
	}

	return 0;
}
