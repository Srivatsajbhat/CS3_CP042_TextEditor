<!-- Text Editor in C -->
# Notepad 2.0 - Text File Viewer and Editor

TextEditor2 is a simple text-based interface for viewing and editing text files using the C language. It allows users to perform basic CRUD (Create, Read, Update, Delete) operations on text files, along with additional features like cut, copy, paste, find, and replace.

## Features

### 1. Create a File
Users can create a new text file by providing a filename and entering the content they want to save in the file.

### 2. Read a File
The application allows users to read the content of an existing text file. Users can specify the filename, and the program will display the text content on the screen.

### 3. Update a File
TextEditor2 enables users to update the content of an existing text file. Users can specify the filename and enter the new content they want to replace the original content with.

### 4. Delete a File
Users can delete an existing text file by providing the filename. The application will prompt for confirmation before proceeding with the deletion.

### 5. Copy, Cut, and Paste
TextEditor2 supports basic text manipulation operations. Users can copy, cut, and paste text from one part of the file to another. The application uses familiar keyboard shortcuts such as Ctrl+C (copy), Ctrl+X (cut), and Ctrl+V (paste) for these operations.

### 6. Find and Replace
Users can search for specific words or phrases within the text file using the "Find" feature. Additionally, they can replace all occurrences of a word or phrase with another provided text using the "Replace" feature.

## How to Use

1. Clone the repository and navigate to the project directory.

2. Compile the C program `texteditor2.c` using a C compiler:
   ```
   gcc texteditor2.c -o texteditor2
   ```

3. Run the compiled executable:
   ```
   ./texteditor2
   ```

4. The program will display a menu with options to perform various operations like creating, reading, updating, and deleting files, as well as additional features like cut, copy, paste, find, and replace.

5. Follow the on-screen instructions to interact with the text editor.

## Team - CP042

This project was developed by the following team members:

1. Shreyas S Kotian- 4MT21CS153
2. Srivatsa J Bhat - 4MT21CS163
3. Uttam - 4MT21CS175
4. Valluru Narendra - 4MT21CS177
5. Vipul Nayak - 4MT21CS182

## Note

This text-based interface may not have a fancy graphical user interface (GUI) like modern text editors, but it provides a straightforward way to view and manipulate text files through a terminal or command prompt. Feel free to contribute to the project and improve its features and functionality.