#include <iostream>

using namespace std;
void put_one(bool* arr, __int64 num, __int64 indexing);

int main()
{
	__int64 n;
	__int32 l, r;

	__int64 to_size[50];
	__int64 numofones = 0;

	__int64 input = 1;
	for (int i = 0; i < 50; i++)
	{
		to_size[i] = input;
		input << 1 ;
	}

	cin >> n >> l >> r;

	bool* ones;
	__int64 indexing;

	for (int i = 0; i < 50; i++)
	{
		if (to_size[i] >= n)
		{
			indexing = to_size[i];
		}
	}

	ones = new bool[indexing];
	if (ones)
	{
		put_one(ones, n, indexing);
	}

	for (int i = l-1; i < r; i++)
	{
		if (ones[i])
		{
			numofones++;
		}
	}

	cout << numofones;
	return 0;
}

void put_one(bool* arr, __int64 num,__int64 indexing)
{
	if (num == 1)
	{
		return;
	}
	if (num % 2 == 0)
	{
		arr[indexing / 2] = true;
		put_one(arr, num / 2, indexing * 3 / 4);
		put_one(arr, num / 2, indexing / 4);
	} 
	else
	{
		arr[indexing / 2] = false;
		put_one(arr, num / 2, indexing * 3 / 4);
		put_one(arr, num / 2, indexing / 4);
	}

}