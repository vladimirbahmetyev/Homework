#include <iostream>
#include <string>

using namespace std;

bool syntaxAnalyzer(const string &inputString)
{
	int state = 0;
	for (int i = 0; i < inputString.length(); i++)
	{
		char symbol = inputString[i];
		switch (state)
		{
		case 0:
		{
			if (symbol >= '0' && symbol <= '9')
			{
				state = 1;
				break;
			}
			else
			{
				return false;
			}
		}
		case 1:
		{
			if (symbol >= '0' && symbol <= '9')
			{
				break;
			}
			if (symbol == '.')
			{
				state = 2;
				break;
			}
			if (symbol == 'E')
			{
				state = 4;
				break;
			}
			return false;
		}
		case 2:
		{
			if (symbol >= '0' && symbol <= '9')
			{
				state = 3;
				break;
			}
			if (symbol == 'E')
			{
				state = 4;
			}
			else
			{
				return false;
			}
		case 3:
			if (symbol >= '0' && symbol <= '9')
			{
				break;
			}
			if (symbol == 'E')
			{
				state = 4;
				break;
			}
			return false;
		}
		case 4:
		{
			if (symbol >= '0' && symbol <= '9' || symbol == '-' || symbol == '+')
			{
				state = 5;
				break;
			}
			else
			{
				return false;
			}
		}
		case 5:
		{
			if (symbol >= '0' && symbol <= '9')
			{
				break;
			}
			else
			{
				return false;
			}
		}
		}
	}
	return state != 2 && state != 4;
}

void test1()
{
	string testString = "234.4";
	if (syntaxAnalyzer(testString))
	{
		cout << "Test 1 complited" << endl;
	}
	else
	{
		cout << "Test 1 failed" << endl;
	}
}

void test2()
{
	string testString = "234.4E";
	if (!syntaxAnalyzer(testString))
	{
		cout << "Test 2 complited" << endl;
	}
	else
	{
		cout << "Test 2 failed" << endl;
	}
}

void test3()
{
	string testString = "234.4E-1234";
	if (syntaxAnalyzer(testString))
	{
		cout << "Test 3 complited" << endl;
	}
	else
	{
		cout << "Test 3 failed" << endl;
	}
}

void main()
{
	cout << "Input number" << endl;
	string inputString = {};
	cin >> inputString;
	if (syntaxAnalyzer(inputString))
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	test1();
	test2();
	test3();
	system("pause");
}