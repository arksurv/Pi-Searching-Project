COMPILING THE PROGRAM:
1. Install GCC and insure that g++ can be invoked via the command line: https://gcc.gnu.org/
2. Run compile.bat

RUNNING THE PROGRAM TO SEARCH FOR "1234567890" AND "0123456789" IN PI:
1. Put your .txt file containing Pi into this directory
2. Rename it to "pi-estimate.txt"
3. Run run.bat

RUNNING THE PROGRAM TO SEARCH FOR ANY OTHER STRING:
1. Put the text file containing your string to search into this directory
2. Using the command line or creating a .bat file, invoke the following command, filling in the information as needed:
GeneralizedStringFinder.exe [inputFilenameWithExtension] [outputFilenameWithExtension] [startingSearchString] {[nextSearchString], [nextSearchString2], ...}

PROGRAM INFO:
The program will read the entire input file into a string internally (make sure you have enough RAM to read the entire input file at once). Next, it will search for the [startingSearchString]. Once it finds that, it will check to see if the next character(s) match the character(s) of the [nextSearchString]. It will continue to loop through this process until it stops finding matches or it runs out of strings to match against. Based on how many characters matched with the desired full string (concatenate all of your strings together to see what this is), the program will store its findings. When the program goes to output its findings, it will output each occurence of each level of string match into the provided output file.
