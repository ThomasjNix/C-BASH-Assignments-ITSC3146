#include <iostream>
using namespace std;

void fib_gen(int userNum){
	int fibArray[userNum];
	fibArray[0]=0;
	fibArray[1]=1;
	cout << fibArray[0] << endl << fibArray[1] << endl;
	for (int i = 2; i < userNum; i++)
	{
		fibArray[i]=fibArray[i-2]+fibArray[i-1];
		cout << fibArray[i] << endl;
	}
	
}

int main() {
	cout << "Please enter the number of places to count the Fibonacci sequence:" << endl;
	int userVar = 0;
	cin >> userVar;
    fib_gen(userVar);
}