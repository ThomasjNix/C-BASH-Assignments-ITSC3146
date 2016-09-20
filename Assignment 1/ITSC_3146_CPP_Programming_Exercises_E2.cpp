#include <iostream>
using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    int tempNum = 0;
    
	cout << "Please enter the first number: ";
	cin >> num1;
	cout << "Please enter the second number: ";
	cin >> num2;
	sum=num1+num2;
	cout << "The sum of the numbers is: " << sum << endl;
	
	tempNum = num2;
	num2 = num1;
	num1 = tempNum;
	
	cout << "After swapping, the first number is " << num1 << "\nand the second number is " << num2;
	
	return 0;
}

