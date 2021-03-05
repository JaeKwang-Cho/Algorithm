#include <iostream>
#include <cassert>
#pragma warning (disable: 4996)

using namespace std;

int main()
{
	int n;
	cin >> n;

	char** IDs = new char* [n];
	char** DB = new char*[n];
	int* Dup = new int[n];

	if (Dup != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			Dup[i] = 0;
		}
	}

	if (IDs !=NULL && DB != NULL)
	{
		for (int i = 0; i < n; i++)
		{
			IDs[i] = new char[33];
			DB[i] = new char[39];
			if (DB[i] != NULL )
			{
				memset(DB[i],0,33);
			}
			if (IDs[i]!=NULL)
			{
				cin >> IDs[i];
			}
		}

		for (int j = 0; j < n; j++)
		{
DUP:
			if (j == 0)
			{
				strcpy(DB[j], IDs[j]);
				cout << "OK\n";
				continue;
			}
			
			for (int k = 0; k <= j; k++)
			{
				if (strcmp(IDs[j], DB[k]) != 0)
				{
					continue;
				}
				else
				{
					Dup[k]++;
					sprintf(DB[j], "%s%d", DB[k], Dup[k]);
					cout << DB[j] << endl;
					j++;
					if (j == n)
					{
						goto END;
					}
					goto DUP;
				}
			}
			strcpy(DB[j], IDs[j]);
			cout << "OK\n";
		}
	}



END:

	if (IDs != NULL && DB != NULL && Dup!=NULL)
	{
		for (int i = 0; i < n; i++)
		{
			if (IDs[i] != NULL && DB[i] != NULL)
			{
				delete[] IDs[i];
				IDs[i] = NULL;
				delete[] DB[i];
				DB[i]=NULL;
			}
		}
		delete[] IDs;
		IDs = NULL;
		delete[] DB;
		DB = NULL;
		delete[] Dup;
		Dup = NULL;
	}

	return 0;
}