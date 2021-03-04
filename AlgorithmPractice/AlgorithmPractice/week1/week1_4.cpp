#include <iostream>

using namespace std;

int main()
{
	size_t numOfProblems;
	cin >> numOfProblems;
	
	char ability[3];
	size_t numOfAns = 0;

	for (size_t i = 0; i < numOfProblems; i++)
	{
		cin >> ability[0] >> ability[1] >> ability[2];
		if (ability[0] == '1')
		{
			if (ability[1] == '1' || ability[2] == '1')
			{
				numOfAns++;
			}
			
		}
		else
		{
			if (ability[1] == '1' && ability[2] == '1')
			{
				numOfAns++;
			}
		}
	}

	cout << numOfAns;
	

	return 0;
}