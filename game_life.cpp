// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int get_lenght(int i)
{
	if (i < 0)
	{
		return 11;
	}
	if (i > 11)
	{
		return 0;
	}
	return i;
}

int get_widht(int j)
{
	if (j < 0)
	{
		return 9;
	}
	if (j > 9)
	{
		return 0;
	}
	return j;
}

int main()
{
	const char alive = '+';
	const char dead = '@';
	const int lenght = 12;
	const int width = 10;
	char arr[lenght][width];
	int logic_masc[lenght][width];

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < lenght; j++)
		{
			arr[j][i] = dead;
		}
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < lenght; j++)
		{
			logic_masc[j][i] = 0;
		}
	}

	arr[1][0] = alive;
	arr[2][1] = alive;
	arr[0][2] = alive;
	arr[1][2] = alive;
	arr[2][2] = alive;

	for (int i = 0; i < width; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < lenght; j++)
		{
			std::cout << arr[j][i] << " ";
		}
	}
	int count = 0;
	std::cout << "Enter the iteration number: ";
	std::cin >> count;

	for (int ct = 0; ct < count; ct++)
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "ITERATION: " << ct + 1;

		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < lenght; j++)
			{
				if (arr[j][i] == alive)
				{
					for (int k = (i - 1); k < (i + 2); k++)
					{
						for (int p = (j - 1); p < (j + 2); p++)
								logic_masc[get_lenght(p)][get_widht(k)]++;
					}
				}
			}
		}

		std::cout << std::endl;

		for (int i = 0; i < width; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < lenght; j++)
			{
				if (logic_masc[get_lenght(j)][get_widht(i)] == 3)
				{
					arr[get_lenght(j)][get_widht(i)] = alive;
				}
				else if (logic_masc[get_lenght(j)][get_widht(i)] < 3 || logic_masc[get_lenght(j)][get_widht(i)] > 4)
				{
					arr[get_lenght(j)][get_widht(i)] = dead;
				}
				std::cout << arr[j][i] << " ";
			}
		}
		
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < lenght; j++)
			{
				logic_masc[j][i] = 0;
			}
		}
	}	
    return 0;
}