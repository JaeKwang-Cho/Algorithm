#include <iostream>

using namespace std;

int main()
{
	char* input = new char[100001];

	cin >> input;

	bool ABflag1 = false, ABflag2 = false, BAflag1 = false, BAflag2 = false, overlaped = false, overlaped2 = false;

	char* p = input;
	char* dupcheck = NULL;

	while (*p != '\0' && *p != '\n' && !(ABflag1&& ABflag2&& BAflag1&& BAflag2))
	{
		if (ABflag1 && !ABflag2 )
		{
			if (*p == 'B' && !BAflag1)
			{
				ABflag2 = true;
				BAflag1 = true;
				dupcheck = p;
			}
			else if(*p == 'B' && BAflag1){
				if (BAflag2)
				{
					if (p == dupcheck + 1)
					{
						if (overlaped)
						{
							overlaped2 = true;
							break;
						}
						else
						{
							overlaped = true;
							BAflag1 = false;
							BAflag2 = false;
							ABflag1 = false;
							ABflag2 = false;
						}
						
					}
					else
					{
						ABflag2 = true;
					}
					
				}
				else
				{
					ABflag2 = true;
					BAflag1 = false;
				}
			}
			else if (*p == 'A')
			{
				overlaped = NULL;
			}
			else
			{
				ABflag1 = false;
			}
		}
		else if(BAflag1 && !BAflag2)
		{
			if (*p == 'A' && !ABflag1)
			{
				BAflag2 = true;
				ABflag1 = true;
				dupcheck = p;
			}
			else if (*p == 'A' && ABflag1)
			{
				if (ABflag2)
				{
					if (p == dupcheck + 1)
					{
						if (overlaped)
						{
							overlaped2 = true;
							break;
						}
						else
						{
							overlaped = true;
							BAflag1 = false;
							BAflag2 = false;
							ABflag1 = false;
							ABflag2 = false;
						}
					}
					else
					{
						BAflag2 = true;
					}
				}
				else
				{
					BAflag2 = true;
					ABflag1 = false;
				}
			}
			else if (*p == 'B')
			{
				dupcheck = NULL;
			}
			else
			{
				BAflag1 = false;
			}
		}
		else if (!ABflag1 || !BAflag1)
		{
			if (*p == 'A')
			{
				ABflag1 = true;
			}
			else if (*p == 'B')
			{ 
				BAflag1 = true;
			}
		}
		p++;
	}

	if ((ABflag1 && ABflag2 && BAflag1 && BAflag2) || (overlaped && ((ABflag1 && ABflag2)||(BAflag1 && BAflag2) || overlaped2)))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}


	delete[] input;

	return 0;
}