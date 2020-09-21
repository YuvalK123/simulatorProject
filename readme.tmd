# about the project:
The project is creating a specific coding language for the FlightGear simulator with specific command, such as Print,Sleep and variables
the projects uses 2 socket - one server socket to recieve values from simulator using an xml file, and another socket that connect to simulator to send commands.

* Finished project is at forLinux branch

## Process
The project is build using the Command pattern tool, and also uses few helping classes.
simulatorManager concenctrates fields that is important for the run of the program.
Interpreter and expression classes to calculate arithmetic expressions and save variables
simulatorHelper to save both interpreter and manager, and also parses the lex.

## command to run program with:
g++ -std=c++11  *.cpp  -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
./a.out <file_name>
