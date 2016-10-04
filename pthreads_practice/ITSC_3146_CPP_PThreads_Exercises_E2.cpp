#include <pthread.h>
#include <iostream>

using namespace std;
int arraySize = 0;
void* getPositive(void* arg){
    int* thisArray = (int*) arg;
    int numPositive = 0;
    for (int i = 0; i < arraySize+1; i++){
        if (thisArray[i]>0){
            numPositive+=1;
        }
    }
    cout << "The number of positive numbers is " << numPositive << endl;
    return 0;
}
void* getNegative(void* arg){
    int* thisArray = (int*) arg;
    int numNegative = 0;
    for (int i = 0; i < arraySize+1; i++){
        if (thisArray[i]<0){
            numNegative+=1;
        }
    }
    cout << "The number of negative numbers is " << numNegative << endl;
    return 0;
}
void* getZeros(void* arg){
    int* thisArray = (int*) arg;
    int numZero = 0;
    for (int i = 0; i < arraySize+1; i++){
        if (thisArray[i]==0){
            numZero+=1;
        }
    }
    cout << "The number of zeros is " << numZero << endl;
    return 0;
}
void* getSum(void* arg){
    int* thisArray = (int*) arg;
    int sum = 0;
    for (int i = 0; i < arraySize+1; i++){
        sum+=thisArray[i];
    }
    cout << "The sum is " << sum << endl;
    return 0;
}
void* getAverage(void* arg){
    int* thisArray = (int*) arg;
    float sum = 0.0;
    float average = 0.0;
    for (int i = 0; i < arraySize+1; i++){
        sum+=thisArray[i];
    }
    average = sum/arraySize;
    cout << "The average is " << average << endl;
    return 0;
}
void* getReverse(void* arg){
    int* thisArray = (int*) arg;
    int holderArray[arraySize];
    int holderArrayCounter=0;
    for (int i = arraySize-1; i >= 0; i--){
        holderArray[holderArrayCounter]=thisArray[i];
        holderArrayCounter++;
    }
    
    cout << "In reverse order, the numbers you entered were: " << endl;
    for (int i = 0; i < holderArrayCounter; i++){
        cout << holderArray[i] << endl;
    }
    return 0;
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
   int inArray[10];
   arraySize=10;
   for (int i = 0; i < 10; i++){
       cout << "Please enter the number to store." << endl;
       cin >> inArray[i];
   }
   cout << "\n\n";
   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   for (int index = 0; index < 6; index++){
      pthread_t newId;
      switch (index){
          case 0:
            rc = pthread_create(&newId, NULL, getPositive, (void*)&inArray);
            pthread_join(newId, NULL);
            break;
          case 1:
            rc = pthread_create(&newId, NULL, getNegative, (void*)&inArray);
            pthread_join(newId, NULL);
            break;
          case 2:
            rc = pthread_create(&newId, NULL, getZeros, (void*)&inArray);
            pthread_join(newId, NULL);
            break;
          case 3:
            rc = pthread_create(&newId, NULL, getSum, (void*)&inArray);
            pthread_join(newId, NULL);
            break;
          case 4:
            rc = pthread_create(&newId, NULL, getAverage, (void*)&inArray);
            pthread_join(newId, NULL);
            break;
          case 5:
            rc = pthread_create(&newId, NULL, getReverse, (void*)&inArray);
            pthread_join(newId, NULL);
            break;
          default:
            break;
      }
   }
   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   
   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}