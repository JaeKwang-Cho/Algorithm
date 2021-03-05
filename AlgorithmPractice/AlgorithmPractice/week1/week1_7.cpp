#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	char input[100];

	char inputLine[400];

	fgetc(stdin);
	fgets(inputLine, 400, stdin);

	char* p = inputLine;

	int res = 0;

	int i = 0;
	
	while (*p != '\0' && *p != '\n')
	{
		int temp = 0;

		while (*p != ' ' && *p != '\n')
		{
			temp = temp * 10 + *p++  - '0';
		}
		p++;

		input[i] = temp % 2;

		if (i >= 2)
		{
			if (input[i-2] == input[i-1])
			{
				if (input[i -1] == input[i])
				{
					i++;
					continue;
				}
				else
				{
					res = i;
					break;
				}
			}
			else
			{
				if (input[i-1] == input[i])
				{
					res = i - 2;
					break;
				}
				else
				{
					res = i - 1;
					break;
				}
			}
		}
		i++;
	}


	cout << res+1;
	
	return 0;
}