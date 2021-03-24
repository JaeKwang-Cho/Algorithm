#include <iostream>

using namespace std;

int main()
{
	__int32 y_hp, y_atk, y_def;
	cin >> y_hp >> y_atk >> y_def;
	__int32 m_hp, m_atk, m_def;
	cin >> m_hp >> m_atk >> m_def;
	__int32 p_hp, p_atk, p_def;
	cin >> p_hp>> p_atk>> p_def;

	__int32 true_of_yang;
	__int32 true_of_monster;

	if (0 < y_atk - m_def)
	{
		true_of_yang = y_atk - m_def;
	}
	else
	{
		true_of_yang = 0;
	}
	if (0 < m_atk - y_def)
	{
		true_of_monster = m_atk - y_def;
	}
	else
	{
		true_of_monster = 0;
	}
	__int32 coins = 0;

	__int32 punches_of_monster;
	__int32 punches_of_yang;
	__int32 need_hp = 0, need_atk = 0, need_def = 0;


	if (true_of_monster == 0 && true_of_yang != 0)
	{
		goto END;
	}
	else if( true_of_monster != 0 && true_of_yang == 0 )
	{
		punches_of_monster = y_hp / true_of_monster + (y_hp % true_of_monster);
		punches_of_yang = 30000;
	}
	else if (true_of_monster == 0 && true_of_yang == 0)
	{
		punches_of_yang = 30000;
		punches_of_monster = 30000;
	}
	else
	{
		if ((y_hp % true_of_monster) == 0)
		{
			punches_of_monster = y_hp / true_of_monster;
		}
		else
		{
			punches_of_monster = y_hp / true_of_monster + 1;
		}
		if ((m_hp % true_of_yang) == 0)
		{
			punches_of_yang = (m_hp / true_of_yang);
		}
		else
		{
			punches_of_yang = (m_hp / true_of_yang) +1 ;
		}
		
		
	}



	
	if (y_hp > m_hp)
	{
		if (true_of_yang >= true_of_monster && true_of_yang != 0)
		{
			goto END;
		}
		else
		{
			if (punches_of_yang < punches_of_monster)
			{
				goto END;
			}
			else // yh ya yd / mh ma md
				// 
			{
				need_hp = (punches_of_yang - punches_of_monster + 1) * (true_of_monster);
				if (need_hp <= 0)
				{
					need_hp = 30000;
				}
				if (punches_of_monster == 1)
				{
					need_atk = 30000;
				}
				else
				{
					if (y_atk < m_def && m_atk < y_def)
					{
						need_atk = m_def - y_atk + 1;
					}
					else
					{
						need_atk = (m_hp / (punches_of_monster - 1)) - true_of_yang;
					}
				}

				if (y_hp % m_hp == 0)
				{
					need_def = m_atk - y_def - (punches_of_yang / punches_of_monster);
					if (need_def <= 0)
					{
						need_def = 30000;
					}
				}
				else
				{
					need_def = m_atk - y_def - (punches_of_yang / punches_of_monster) - 1;
					if (need_def <= 0)
					{
						need_def = 30000;
					}
				}
			}
		}
	}
	else if(y_hp ==  m_hp)
	{
		if (true_of_yang > true_of_monster)
		{
			goto END;
		}
		else
		{
			need_hp = (punches_of_yang - punches_of_monster + 1) * (true_of_monster);
			if (need_hp <= 0)
			{
				need_hp = 30000;
			}
			if (punches_of_monster == 1)
			{
				need_atk = 30000;
			}
			else
			{
				if (y_atk < m_def && m_atk < y_def)
				{
					need_atk += m_def - y_atk + 1;
				}
				else
				{
					need_atk = (m_hp / (punches_of_monster - 1)) - true_of_yang;
				}
			}

			if (y_hp % m_hp == 0)
			{
				need_def = m_atk - y_def - (punches_of_yang / punches_of_monster);
				if (need_def <= 0)
				{
					need_def = 30000;
				}
			}
			else
			{
				need_def = m_atk - y_def - (punches_of_yang / punches_of_monster) - 1;
				if (need_def <= 0)
				{
					need_def = 30000;
				}
			}
		}
	}
	else 
	{
		need_hp = (punches_of_yang - punches_of_monster + 1) * (true_of_monster);
		if (need_hp <= 0)
		{
			need_hp = 30000;
		}
		if (punches_of_monster == 1)
		{
			need_atk = 30000;
		}
		else
		{
			if (y_atk < m_def && m_atk < y_def)
			{
				need_atk = m_def - y_atk + 1;
			}
			else
			{
				need_atk = (m_hp / (punches_of_monster - 1)) - true_of_yang;
			}
		}

		if (y_hp % m_hp == 0)
		{
			need_def = m_atk - y_def - (punches_of_yang / punches_of_monster);
			if (need_def <= 0)
			{
				need_def = 30000;
			}
		}
		else
		{
			need_def = m_atk - y_def - (punches_of_yang / punches_of_monster) - 1;
			if (need_def <= 0)
			{
				need_def = 30000;
			}
		}
	}

	need_def *= p_def;
	need_atk *= p_atk;
	need_hp *= p_hp;

	if (need_def > need_atk)
	{
		if (need_atk > need_hp)
		{
			coins = need_hp;
		}
		else
		{
			coins = need_atk;
		}
	}
	else
	{
		if (need_def > need_hp)
		{
			coins = need_hp;
		}
		else
		{
			coins = need_def;
		}
	}

END:
	cout << coins;
	return 0;
}