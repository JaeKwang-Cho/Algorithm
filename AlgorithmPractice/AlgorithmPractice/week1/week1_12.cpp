#include <iostream>

using namespace std;

int main()
{
	char input[101];
	char hello[] = { 'h','e','l','l','o' };
	fgets(input, 101, stdin);

	char* p = input;
	char* hp = hello;
	char counter = 0;

	while (*p != '\n' && *p != '\0')
	{
		if (counter == 5)
		{
			break;
		}
		if (*hp == *p)
		{
			counter++;
			hp++;
		}
		p++;
	}

	if (counter == 5)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}