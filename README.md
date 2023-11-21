# Assignment-Test description

The program is a console application to parse command line arguments and execute commands. 
The program gets name of file and executues commands based on given parameters.
Three commands are supported: 
<br> **commandName -h** :  Gives information about the program.
<br> **commandName -f fileName -m checksum**: Prints 32bit checksum, checksum = word1 + word2 + ...  
**commandName -f fileName -m words -v mother**: Returns number  of mother word in file

## Build: 
From build folder 

<br> cmake ..
<br> cmake --build ./

## Run
Test.exe optionName optionValue
