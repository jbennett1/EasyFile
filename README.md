# EasyFile
EasyFile is a small, open-source library with the intended use of simplifying file input, output, and control. Below are the notes, and documentation of functions.

# Notes
1) Not all exceptions are being used (yet).

2) Contact me over GitHub if you think a function should be renamed, or you have any feature-requests for the library.

3) There are two different versions of EasyFile currently available to download; these can be seen from the directories 
inside of this repo. The VC folder (representing the VC++ / Visual C++ compiler, used in the Visual Studio IDE) contain 
the required files for successful compliation when using VC++. Similarly, the MinGW folder (representing the MinGW / Windows GCC compiler, used in a lot of IDEs) contains the exact same files, with added includes and/or functions for successful compliation when using MinGW.

4) Other OS support **has not** been tested, *however*, EasyFile doesn't use any specific Windows libraries, therefore it *should* compile. Attempt the MinGW solution should you wish to compile on other systems, as GCC is the norm for most operating systems.

5) EasyFile opens the file using the
```c++
fstream::in | fstream::out | fstream::app
```
parameters, as these are considered the most useful. It allows input, the editing of non-empty files wihout overwriting them, and writing from the bottom of the file.

# How To Use
1) First of all, download the files from the download page on GitHub *not the source code pages*. The download will be a zip file containing a directory, which contains the two header files.

2a) *For Visual Studio / VC++ Users:* Move the folder inside the zip file to *(install location)\VC\include\*. The default location is *C:\Program Files (x86)\Visual Studio\VC\include\*.

2b) *For MinGW / GCC Users:* Move the folder inside of the zip file to *(install location)\include*. The default location is *C:\MinGW\include\*

2c) *For other users:* Attempt both the VC++ and MinGW versions on your system. Copy the folder inside the zip to your default compiler *include* directory.

3) In your IDE, add two new includes:
```c++
#include <EasyFile/EasyFile.h>
#include <EasyFile/EasyFileExceptions.h>
```
This gives you access to all EasyFile functions.

4) Begin the object declaration, by:
```c++
File file;
```
5) From there, use as you would any C++ class;
```c++
file.readLine(1); //readLine() function used as example
```
6) That's it! Amazing!

# Function Documentation
```c++
File()
File file; //Example
``` 
Default constructor, open() function must be called after to avoid a FileNullException().
```c++
File(string filename)
File file = "myfile.txt"; //Example
File file("myfile.txt"); //Example
``` 
Constructor, automatically calls open().
```c++
void open(string filename)
file.open("myfile.txt"); //Example
``` 
Opens the file with the specified filename.
```c++
void close()
file.close(); //Example
``` 
Closes the current file.
```c++
void reload()
file.reload(); //Example
``` 
Reloads the current file.
```c++
void writeToFile(string toWrite)
file.writeToFile("Hi\nthere!"); //Example
``` 
Write the specified string to the current file.
```c++
void clear()
file.clear(); //Example
``` 
Clear the current file.
```c++
string readEntireFile()
string s = file.readEntireFile(); //Example
``` 
Reads the entire file and returns it as a string.
```c++
string readLine(int linenum)
string s = file.readLine(1); //Example
``` 
Reads the specified line and returns it as a string.
```c++
string readLineRange(int from, int to)
string s = file.readLineRange(1, 4); //Example
``` 
Reads all the lines in the specified range, and returns them as strings.
```c++
int getLineAmount()
int x = file.getLineAmount(); //Example
``` 
Returns the amount of lines in the file.
```c++
string findLine(string s)
string s = file.findLine("first"); //Example
``` 
Return the line that the first occurrence of the specified string is on.
```c++
int findLineNumber(string s)
int x = file.findLineNumber("first"); //Example
``` 
Return the line *number* that the first occurrence of the specified string is on.
```c++
string findAllOccurrences(string s)
string s = file.findAllOccurrences("first"); //Example
``` 
Return the contents of every line the specified string is located.
```c++
string findAllOccurrencesLineNum(string s)
string lineNums = file.findAllOccurrencesLineNum("first"); //Example
``` 
Return the line numbers of every line the specified string is located.
```c++
fstream* getNative()
fstream* fs = file.getNative(); //Example
``` 
Return the native fstream pointer that the EasyFile object is currently using.
```c++
int getAmountOfCharacters()
int x = file.getAmountOfCharacters(); //Example
``` 
Return the amount of characters in the current file.
```c++
int getAmountOfCharactersOnLine(int linenum)
int x = file.getAmountOfCharactersOnLine(1); //Example
``` 
Return the amount of characters on the specified line.
