#include <iostream>
using namespace std;

int main() {
    float width = 0;
	float height = 0;
	float area = 0;
	
	cout << "Please enter the width of the rectangle. ";
	cin >> width;
	cout << "\nPlease enter the height of the rectangle. ";
	cin >> height;
	
	area = width*height;
	
	cout << "\nThe area of the rectangle is: " << area;
	return 0;
}

