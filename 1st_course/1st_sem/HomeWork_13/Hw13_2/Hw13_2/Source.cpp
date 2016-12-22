#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int **createTable()
{
	ifstream fileWithTable("table.txt");
	int **table = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		table[i] = new int[4]{0};
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fileWithTable >> table[i][j];
		}
	}
	fileWithTable.close();
	return table;
}

void main()
{
	ifstream inputFile("test.txt");
	int **table = createTable();
	char symbol = {};
	int state = 0;
	while (!inputFile.eof())
	{
		inputFile >> symbol;
		if (state == 2 && symbol !='*')
		{
			cout << symbol;
		}
		else
		{
			if (symbol == '/')
			{
				int previosState = state;
				state = table[0][state];
				if (previosState == 3 && state == 0)
				{
					cout << "*/";
				}
			}
			else
			{
				if (symbol == '*')
				{
					int previosState = state;
					state = table[1][state];
					if (state == 2 && previosState == 1)
					{
						cout << "/*";
					}
				}
				else
				{
					state = table[2][state];
				}
			}
		}
	}
	inputFile.close();
}