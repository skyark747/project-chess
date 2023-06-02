#include <iostream>
#include <iomanip>
#include <string>
#include "Timer.h"
#include"Utility.h"
using namespace std;

Timer::Timer()
	:screen_position{},minute(0), sec(0)
{
}
void Timer::setTimer(int m, int s, int sr, int sc)
{
	minute = m;
	sec = s;
	screen_position.ri = sr;
	screen_position.ci = sc;
}
void Timer::printstandard()
{
	gotoRowCol(screen_position.ri + 1, screen_position.ci);
	cout << setfill('0')<< setw(2) << minute << ":" << setw(2) << sec<< endl;
}
void Timer::increment()
{
	if (sec <=60)
	{
		sec--;
		if (sec == 0)
		{
			sec = 60;
			if (minute <= 60)
			{
				minute--;
				if (minute == 0)
				{
					minute = 60;
				}
			}
		}
		Sleep(500);
	}

}


