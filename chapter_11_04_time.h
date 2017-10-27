#ifndef TIME_H_
#define TIME_H_
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddHr(int h);
	void AddMin(int m);
	void Reset(int h = 0, int m = 0);
	friend Time operator+(const Time &t1, const Time &t2);
	friend Time operator-(const Time &t1, const Time &t2);
	friend Time operator*(double m, const Time &t);
	friend std::ostream &operator<<(std::ostream &os, const Time &t);
	
};

#endif