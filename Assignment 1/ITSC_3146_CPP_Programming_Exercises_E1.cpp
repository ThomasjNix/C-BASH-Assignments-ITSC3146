#include <iostream>
using namespace std;

int main() {
    std::string uInput = "";
	cout << "Please enter your name" << endl;
	cin >> uInput;
    cout << "Hello " + uInput + ".\nHave a great day!" << endl;
	return 0;
}

