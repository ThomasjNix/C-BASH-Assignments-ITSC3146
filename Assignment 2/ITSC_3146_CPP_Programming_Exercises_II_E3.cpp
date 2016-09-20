#include <iostream>
using namespace std;

int main(){
	cout << "Please enter a score between 0 and 100:" << endl;
	
	float userScore = 0;
	string userResult = "";
	cin >> userScore;
	
	if (userScore<90)
	{
		if (userScore<80)
		{
			if (userScore<70)
			{
				if (userScore<60)
				{
					userResult = "F";
				}else
				{
					userResult = "D";
				}
			}else
			{
				userResult = "C";
			}
		}else
		{
			userResult = "B";
		}
	}else
	{
		userResult = "A";
	}
	
	cout << "A score of " << userScore << " receives an " << userResult << "." << endl;
	
}

