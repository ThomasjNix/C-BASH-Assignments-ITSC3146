#include <iostream>
using namespace std;
int main() {
    cout << "Please enter 10 numbers for array values:" << endl;
    
    int tempUserVar = 0;
    int intArray [10];
    float posEntries=0, negEntries=0, zeroEntries=0, sum=0, average = 0;
    for (int i = 0; i < 10; i++) 
    {
    	cin >> tempUserVar;
    	
    	intArray[i]=tempUserVar;
    	sum+=tempUserVar;
    	if(tempUserVar%2==0 && tempUserVar!=0)
    	{
    		posEntries+=1;
    		
    	}else if (tempUserVar%2!=0 && tempUserVar!=0)
    	{
    		negEntries+=1;
    	}else
    	{
    		zeroEntries+=1;
    	}
    	tempUserVar=0;
    }
    cout << "The number of positive numbers entered is: " << posEntries << endl;
	cout << "The number of negative numbers entered is: " << negEntries << endl;
	cout << "The number of zeros entered is: " << zeroEntries << endl;
	cout << "The sum of all numbers entered is: " << sum << endl;
	cout << "The average of all numbers entered is: " << sum/10 << endl;
	cout << "In reverse order, the numbers entered are: " << endl;
	
	for (int i = 9; i >= 0; i--) 
	{
		cout << intArray[i] << ", ";
	}
}