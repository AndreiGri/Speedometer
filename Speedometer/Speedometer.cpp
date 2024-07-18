#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool comparisonOfNumbers1(float f, float s, float e)
{
	return (f - s < e);
}

bool comparisonOfNumbers2(float f, float s, float e)
{
	return (f - s >= e);
}

int main()
{
	system("color 70");
	system("chcp 1251>nul");

	float epsilon = 0.01f;
	float buffer = 0.f;
	float speed = 0.f;
	float minSpeed = 0.f;
	float maxSpeed = 150.f;
	char text[6];

	do
	{
		nextin:
		cout << " Ускорение: ";
		cin >> buffer;
		speed += buffer;
		if (comparisonOfNumbers1(speed, minSpeed, 0.01))
		{
			sprintf_s(text, "%.1f", minSpeed);
			std::cout << " Автомобиль остановился! Скорость = " << text << std::endl;
			break;
		}
		else
		{
			if (comparisonOfNumbers2(speed, maxSpeed, 0.01))
			{
				sprintf_s(text, "%.1f", maxSpeed);
				std::cout << " Максимальная скорость: " << text << std::endl;
				speed = maxSpeed;
				goto nextin;
			}
			else
			{
				sprintf_s(text, "%.1f", speed);
				std::cout << " Скорость: " << text << std::endl;
			}
		}

	} while (speed > 0.);

	system("pause>nul");
	return 0;
}