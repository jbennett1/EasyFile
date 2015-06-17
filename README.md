# EasyFile
EasyFile is a small, open-source library with the intended use of simplifying file input, output, and control. Below are the notes, and documentation of functions.

# Notes
1) Not all exceptions are being used (yet).

2) Contact me over GitHub if you think a function should be renamed, or you have any feature-requests for the library.

3) There are two different versions of EasyFile currently available to download; these can be seen from the directories 
inside of this repo. The VC folder (representing the VC++ / Visual C++ compiler, used in the Visual Studio IDE) contain 
the required files for successful compliation when using VC++. Similarly, the MinGW folder (representing the MinGW / Windows GCC compiler, used in a lot of IDEs) contains the exact same files, with added includes and/or functions for successful compliation when using MinGW.

4) Other OS support **has not** been tested, *however*, because EasyFile doesn't use any specific Windows libraries, therefore it *should* compile. Attempt the MinGW solution should you wish to compile on other systems, as GCC is the norm for most operating systems.

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

4) That's it! Amazing!

# Function Documentation
