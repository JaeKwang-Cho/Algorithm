#include <iostream>

using namespace std;
int main()
{
	int numOfParticipants;
	int cutOfAdvancers;

	int numOfAdvancers = 0;

	int scores[100];

	cin >> numOfParticipants >> cutOfAdvancers;
	for (int j = 0; j < numOfParticipants; j++)
	{
		cin >> scores[j];
	}

	for (int i = 0; i < numOfParticipants; i++)
	{
		if (scores[i] <= 0)
		{
			break;
		}
		if (cutOfAdvancers <= numOfAdvancers+1)
		{
			if (i == numOfParticipants-1)
			{
				numOfAdvancers++;
				break;
			}
			else
			{
				if (scores[i] == scores[i + 1])
				{
					numOfAdvancers++;
					continue;
				}
				else
				{
					numOfAdvancers++;
					break;
				}
			}
		}
		else
		{
			numOfAdvancers++;
		}
		
	}

	cout << numOfAdvancers;


	return 0;
}