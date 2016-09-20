/*
 @file: process-fork-1.cpp

 @author: Thomas Nix, tnix2@uncc.edu

 @description: A process to show how a child process can change to a different process using execvp()

 @course: ITSC 3146
 @assignment: Homework activity
 */



#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t id = fork();

	if(id == -1) {
		std::cout << "Error creating process\n";
	} else if (id == 0) {
		std::cout << "I am a child process!\n";
		std::cout << "I'm bored of my parent...switching programs now." << std::endl;
		char* arr[] = {(char*)"ls", (char*)"-al", (char*)NULL};
		execvp(arr[0], arr);
	} else {
		std::cout << "I just became a parent!\n";
	}
	
	return 0;
}
