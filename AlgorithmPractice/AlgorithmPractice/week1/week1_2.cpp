#include <iostream>

using namespace std;

int main()
{
	char words[100][101];
	char output[11];
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		cin >> words[i];
	}
	for (int j = 0; j < input; j++)
	{
		int len = strlen(words[j]);
		if (len > 10)
		{
			if (len > 11)
			{
				char* p = output;
				output[0] = words[j][0];
				int temp = len - 2;
			
				output[1] = temp / 10 + '0';
				output[2] = temp % 10 + '0';
				output[3] = words[j][len-1];
				output[4] = '\0';
			}
			else
			{
				char* p = output;
				output[0] = words[j][0];
				int temp = len - 2;

				output[1] = temp + '0';
				output[2] = words[j][len - 1];
				output[3] = '\0';
			}
		}
		else
		{
			strcpy_s(output, len+1, words[j]);
		}
		cout << output<<endl;
	}
	
	return 0;
}