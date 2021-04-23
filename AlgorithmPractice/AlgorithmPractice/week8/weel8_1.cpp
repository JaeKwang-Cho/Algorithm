#include <iostream>
#include <vector>
#include <algorithm>

#define _XOPEN_SOURCE 200

using namespace std;

typedef struct city
{
	vector<city*> to_me_cities;
	vector<city*> from_me_cities;
	int name;
}city;

void make_list_to_me(city* inCity);
void make_tree(int n);

city* cities;

vector<int> max_cities;
int need;

void make_tree(int n)
{
	for (int i = 0; i < n; i++)
	{
		cities[i].name = i;
	}
	for (int i = 0; i < n-1; i++)
	{
		int to, from;
		cin >> to >> from;
		cities[from - 1].from_me_cities.push_back(cities + to - 1);
	}
	for (int i = 0; i < n; i++)
	{
		make_list_to_me(cities+i);
	}
}

void make_list_to_me(city* inCity)
{
	int num_next = inCity->from_me_cities.size();
	city* next_city = NULL;
	while (num_next--)
	{
		next_city = inCity->from_me_cities[num_next];
		next_city->to_me_cities.push_back(inCity);
		make_list_to_me(next_city);
	}
	return;
}

bool compare_size(city c1, city c2)
{
	size_t c1_size = static_cast<city>(c1).to_me_cities.size();
	size_t c2_size = static_cast<city>(c2).to_me_cities.size();

	if (c1_size > c2_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n;
	cin >> n;

	cities = new city[n];

	make_tree(n);

	need = 0;

	sort(cities, cities + n, compare_size);



	return 0;
}