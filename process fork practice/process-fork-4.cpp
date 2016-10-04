/*
 @file: process-fork-1.cpp

 @author: Thomas Nix, tnix2@uncc.edu

 @description: This file takes user input and splits it up, then assigns commands to an array using pointers for execution with execvp().

 @course: ITSC 3146
 @assignment: Homework activity
 */


#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#define CMD_STR_LEN 80
#define NUM_ARGS 5

int main()
{
    char cmd_str[CMD_STR_LEN];
	std::cout << "myshell>" << std::endl;
	std::cin.getline(cmd_str, 80);
	
	/*
	 * Parse command string and set up array of parameters (args) to pass to execvp.
	 */
	char* args[NUM_ARGS+1];
	/*
	 * Point the first argument element to the first argument in cmd_str
	 * args_element_counter and last_white_space are counters for keeping track of placement for args and cmd_str
     */
	args[0]=&cmd_str[0]; 
	int args_element_counter = 0;
	int last_white_space=0;
	for (int current_char = 0; cmd_str[current_char]!='\0'; current_char++){
		if (isspace(cmd_str[current_char])>0){
			cmd_str[current_char]='\0';
			last_white_space=current_char;
			args_element_counter++;
			args[args_element_counter]=&cmd_str[last_white_space+1];
		}
	}
	args[args_element_counter+1]=NULL;
	
	/*
 	 * Spawn a process to execute the user's command.
	 */
	pid_t id = fork();
	if(id == -1) {
		std::cout << "Error creating process\n";
	} else if (id == 0) {
		int err = execvp(args[0], args);
	} else {
		int status;
		waitpid(id, &status, 0);
	}

	return 0;
}
