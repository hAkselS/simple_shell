#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h>


int main(){

   int exitStatus = 0; //0 is normal exit, -1 is failure 
   int run = 1; 
	while( run == 1 ){
	
   //character array where the command is help 
	char command[1300];
   char * token; 
	char * tokens[30];

    
	//shell prompt 
	printf("aksel's shell $ "); 
	
	//get the user's input command
	fgets( command, 1201, stdin ); //store location, max size, input location 
	int commandLength = strlen(command);
   
   //break in the command up into tokens 
   const char delim[2] = " \n"; 
   const char * nulPtr = NULL; 

   token = strtok( command, delim ); 
   
   //put the input string into tokens 
   int tokenCount = 0; 
   while( token != NULL ) {
      tokens[tokenCount++] = token; 
      token = strtok( NULL, delim );
      //make sure ther is 20 or less tokens 
      if ( tokenCount > 20 ){
         printf("too many tokens\n");
         return -1; 
      }
   }
   
   /*
	printf("user input: [%s]\n", command);
	printf("length of input: %d\n", commandLength);
   printf("token[0] = [%s]\n", tokens[0]); 
   printf("token[1] = [%s]\n", tokens[1]); 
   printf("token[2] = [%s]\n", tokens[2]); 
   */ 

   //end program if user types exit 
   if ( strcmp( tokens[0], "exit" ) == 0){
       printf("exiting aksel's shell...\n"); 
       return 0;
       } 

   //create a child process	
   int forkStatus = fork(); //- is error, + is parent, 0 is child 
                            // child process ID returned to parent  
                            // fork status goes back to zero when child is terminated
   //case: failed to start child process 
   if ( forkStatus < 0 ){
      printf("failed to fork, exiting\n");
      return -1; 
   } 
   //case: child process will execute the command 
   if ( forkStatus == 0 ){
      //printf("I am the child and my PID is %d\n", getpid());
      char * pathName = tokens[0]; 

      //execute the command 
      execvp( pathName, tokens);  
      
      printf("invalid command\n");
      return -1; 
   }
   //case: child process in progress, parent will wait here until child is finished 
   else 
   { 
      //printf("waiting for child process\n"); 
      int waitStatus = wait(&forkStatus); 
      //printf("I am the parent, waitStatus = %d\n", waitStatus);
   }

   //clear old tokens 
   for (int i = 0; i <= tokenCount; i++){ 
      tokens[i] = NULL; 
   }

   }//end of main while loop
   
   //should never get here
   printf("end of program");  
   return 0; 
}//end of main  



