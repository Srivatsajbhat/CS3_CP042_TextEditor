# Notepad 2.0 - Text File Viewer and Editor

Notepad 2.0 is a simple text-based interface for viewing and editing text files using the C language. It allows users to perform basic CRUD (Create, Read, Update, Delete) operations on text files, along with additional features like cut, copy, paste, find, and replace.

## Features

### 1. Create a File

Users can create a new text file by providing a filename and entering the content they want to save in the file.

### 2. Read a File

The application allows users to read the content of an existing text file. Users can specify the filename, and the program will display the text content on the screen.

### 3. Update a File

Notepad 2.0 enables users to update the content of an existing text file. Users can specify the filename and enter the new content they want to replace the original content with.

### 4. Delete a File

Users can delete an existing text file by providing the filename. The application will prompt for confirmation before proceeding with the deletion.

### 5. Copy, Cut, and Paste

Notepad 2.0 supports basic text manipulation operations. Users can copy, cut, and paste text from one part of the file to another. The application uses familiar keyboard shortcuts such as Ctrl+C (copy), Ctrl+X (cut), and Ctrl+V (paste) for these operations.

### 6. Find and Replace

Users can search for specific words or phrases within the text file using the "Find" feature. Additionally, they can replace all occurrences of a word or phrase with another provided text using the "Replace" feature.

## How to Use

1. Clone the repository and navigate to the project directory.

2. Compile the C program `notepad2.c` using a C compiler:

   ```
   gcc notepad2.c -o notepad2
   ```

3. Run the compiled executable:

   ```
   ./notepad2
   ```

4. The program will display a menu with options to perform various operations like creating, reading, updating, and deleting files, as well as additional features like cut, copy, paste, find, and replace.

5. Follow the on-screen instructions to interact with Notepad 2.0.

## Note

Notepad 2.0 provides a simple yet effective text-based interface for manipulating text files. While it may not have a graphical user interface like modern text editors, it offers essential functionalities for everyday text editing tasks. Contributions to the project are welcome to enhance its features and functionality further.
