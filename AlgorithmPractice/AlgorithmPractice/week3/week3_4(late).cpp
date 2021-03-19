#include <iostream>
#include <limits>

using namespace std;

typedef struct arr
{
	__int32 elements1 = 0;
	__int32 elements2 = 0;
	bool onlyOne = false;
	bool orAboveTwo = false;
	__int32 count = 0;
}arr_t;

int main()
{
	__int32 t;
	cin >> t;
	bool* res = new bool[t];

	while (t--)
	{
		__int32 n, m;
		cin >> n >> m;
		__int32* a = new __int32[n];
		arr_t** temp = new arr_t*[n];
		__int32 tempcount = 0;

		for(int i = 0;i<n;i++)
		{
			cin >> a[i];

			if (tempcount == 0)
			{
				temp[0] = new arr_t;
				temp[0]->elements1 = a[i];
				temp[0]->onlyOne = true;
				tempcount++;
			}
			else
			{
				bool nowhere = true;
				for (int j = 0; j < tempcount; j++)
				{
					if ((temp[j]->elements1 + a[i]) % m == 0)
					{
						if (temp[j]->onlyOne)
						{
							temp[j]->elements2 = a[i];
							temp[j]->onlyOne = false;
							temp[j]->orAboveTwo = true;
							nowhere = false;
							break;
						}
						else if((temp[j]->elements2 + a[i]) %m==0)
						{
							nowhere = false;
							break;
						}
						else
						{
							temp[j]->elements1 = a[i];
							nowhere = false;
							break;
						}
					}
					else if (temp[j]->elements2 != 0 &&(temp[j]->elements2 + a[i]) % m == 0)
					{
						temp[j]->elements2 = a[i];
						nowhere = false;
						break;
					}
				}
				if (nowhere)
				{
					temp[tempcount] = new arr_t;
					temp[tempcount]->elements1 = a[i];
					temp[tempcount]->onlyOne = true;
					tempcount++;
				}
				
			}
		}
		__int32 realcount = tempcount;
		for (int i = 0; i < tempcount; i++)
		{
			if (temp[i]->onlyOne)
			{
				for (int j = 0; j < tempcount; j++)
				{
					if ((i != j )&& (temp[j]->onlyOne == false))
					{
						if ((temp[j]->elements1 + temp[i]->elements1) % m == 0)
						{
							temp[j]->elements1 = temp[i]->elements1;
							temp[i]->onlyOne = false;
							realcount--;
							break;
						}
						else if (temp[j]->elements2 != 0 && (temp[j]->elements2 + temp[i]->elements1) % m == 0)
						{
							temp[j]->elements2 = temp[i]->elements1;
							temp[i]->onlyOne = false;
							realcount--;
							break;
						}
					}
				}
			}
		}


		cout << realcount << endl;
		
		for (int i = 0; i < tempcount; i++)
		{
			delete temp[i];
		}

		delete[]a;
		delete[]temp;
	}

	return 0;
}