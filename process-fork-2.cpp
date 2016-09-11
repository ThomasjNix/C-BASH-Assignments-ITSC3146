/*
 @file: process-fork-1.cpp

 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu

 @description: A program that demonstrates processes.

 @course: ITSC 3146
 @assignment: in-class activity [n]
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
		pid_t my_id = getpid();
		pid_t parent_id = getppid();
		std::cout << "My ID is: " << my_id << std::endl;
		std::cout << "My parent's ID is: " << parent_id << std::endl;
	} else {
		std::cout << "I just became a parent!\n";
		waitpid(id, NULL, 0);
		std::cout << "My child process just terminated!" << std::endl;
	}
}
