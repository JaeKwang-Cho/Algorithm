#include <iostream>

using namespace std;

int main()
{
	__int16 y_hp, y_atk, y_def;
	cin >> y_hp >> y_atk >> y_def;
	__int16 m_hp, m_atk, m_def;
	cin >> m_hp >> m_atk >> m_def;
	__int16 p_hp, p_atk, p_def;
	cin >> p_hp>> p_atk>> p_def;

	__int16 true_of_yang = max(0, y_atk - m_def);
	__int16 true_of_monster = max(0, m_atk - y_def);
	
	__int16 coins = 0;

	if (y_hp > m_hp)
	{
		if (true_of_yang >= true_of_monster)
		{
			
		}
		else
		{

		}
	}
	else if(y_hp ==  m_hp)
	{
		if (true_of_yang > true_of_monster)
		{

		}
		else
		{

		}
	}
	else
	{
		
	}

	cout << coins;
	return 0;
}