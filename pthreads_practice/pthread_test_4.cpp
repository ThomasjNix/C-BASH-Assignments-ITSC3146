#include <pthread.h>
#include <iostream>

struct my_args
{
   char arg1;
   char arg2;
};

void *PrintHelloWithParameters(void *arg)
{
	my_args* actual_args = (my_args*) arg;
	std::cout << "Hello world! Here are the two characters I was given "
			<< actual_args->arg1 << ", "
			<<  actual_args->arg2 << "!\n";
	return 0; //   pthread_exit(0);
}

int main()
{
   pthread_t id;
   int rc;
   std::cout << "In main: creating thread \n";

   my_args args;
   args.arg1 = 38; args.arg2 = 'g';
   rc = pthread_create(&id, NULL, PrintHelloWithParameters, (void*) &args);

   if (rc){
      std::cout << "ERROR; return code from pthread_create() is " << rc << std::endl;
      return -1;
   }

   pthread_exit(0);
}
