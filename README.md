The program is a console application to parse command line arguments and execute commands. 
The program gets name of file and executues commands based on given parameters.
Three commands are supported:
<commandName> -h :  Gives information about the program.
<commandName> -f <fileName> -m checksum: Prints 32bit checksum, checksum = word1 + word2 + ...  
<commandName> -f <fileName> -m words -v mother: Returns number of <mother> word in <fileName> file

## Build: 
From build folder 

cmake ..
cmake --build ./

## Run
Test.exe  optionName optionValue
