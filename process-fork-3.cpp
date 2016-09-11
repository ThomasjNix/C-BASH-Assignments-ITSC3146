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
		std::cout << "I'm bored of my parent...switching programs now." << std::endl;
		char* arr[] = {(char*)"ls", (char*)"-al", (char*)NULL};
		execvp(arr[0], arr);
	} else {
		std::cout << "I just became a parent!\n";
	}
	
	return 0;
}
