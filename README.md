
Aksel's Simple Shell

Description: The following programs implement a simple shell.
Commands and options can be input into the shell and run. 
The shell makes use of fork and execvp to create a second thread
to run the user's input command. When running, Aksel's Shell 
gives the user the following prompt, "aksel's shell $ ". 
This shell does not encorporate pipe or read from / write to...
yet. 

Usage: Type "make" to compile. Type "make test" to compile 
and run. Type "make clean" to remove object and executable files.
While running, Aksel's Shell gives the following prompt,
"aksel's shell $ ". Users may input commands here.
When finished, a user my type "exit" to leave the shell.

Known Bugs: If the user runs "top" the cursor will be invisible
when the user exits top. Certain invalid commands will cause the 
core to dump. One example is "ls ls". Certain command will
not run. One example of a command that will not run is "cd". 

System: This program has been written on / designed for Minix. 
All the libraries are standard. 
