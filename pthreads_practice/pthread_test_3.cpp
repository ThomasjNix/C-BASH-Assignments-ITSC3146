#include <pthread.h>
#include <iostream>

void *PrintHello(void *arg)
{
   int actual_arg = *((int*) arg);
   std::cout << "Hello World from thread with arg: " << actual_arg << "!\n";
   return 0; //   pthread_exit(0);
}

int main()
{
   pthread_t id;
   int rc;
   std::cout << "Please enter an argument to be passed:";
   int t;
   std::cin >> t;
   std::cout << "In main: creating thread \n";
   rc = pthread_create(&id, NULL, PrintHello, (void*) &t);

   if (rc){
      std::cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
      return -1;
   }

   pthread_exit(0);
}
