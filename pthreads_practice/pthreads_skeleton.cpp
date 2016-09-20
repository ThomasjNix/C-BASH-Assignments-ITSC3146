#include <pthread.h>
#include <iostream>

using namespace std;

const char* my_messages[4] = {"English: Hello!",
                              "French: Bonjour!",
                              "Spanish: Hola!",
                              "German: Guten Tag!"
};

// This function implements the routine that is
// executed by the thread
void* printMessage(void* arg)
{
   int* index = (int*) arg;
   cout << my_messages[*index] << "\n";
}


int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   // TODO: Add code to perform any needed initialization
   //       or to process user input

   // Create thread(s)
   // TODO: Modify according to assignment requirements
   for (int index = 0; index < 4; index++){
      pthread_t newId;
      rc = pthread_create(&newId, NULL, printMessage, (void*)&index);
      pthread_join(newId, NULL);
   }

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   
   // NOTE: Using exit here will immediately end execution of all threads
   
   pthread_exit(0);
}