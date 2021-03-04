#include <iostream>

using namespace std;
int main()
{
	char input[101];
	char output[201];
	cin >> input;
	char* pchar = input; 
	int i = 0;
QUICKOUT:
	while (*pchar != '\0')
	{
		for (char vowel : { 'A', 'O', 'Y', 'E', 'U', 'I', 'a', 'o', 'y', 'e', 'u', 'i' })
		{
			if (*pchar == vowel)
			{
				pchar++;
				goto QUICKOUT;
			}
		} 
		if (*pchar <= 90 && *pchar >= 65)
		{
			output[i++] = '.';
			output[i++] = *pchar + 32;
		}
		else
		{
			output[i++] = '.';
			output[i++] = *pchar;
		}
		pchar++;
	}
	output[i] = '\0';
	cout << output;
	return 0;
}