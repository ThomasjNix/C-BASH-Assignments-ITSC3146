/*
 @file: process-fork-1.cpp

 @author: Thomas Nix, tnix2@uncc.edu

 @description: Basic process showing how the fork() command operates.

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
	} else {
		std::cout << "I just became a parent!\n";
	}

}
