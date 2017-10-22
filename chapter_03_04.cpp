#include <iostream>

using namespace std;

const int Hours_Per_Day = 24;
const int Minutes_Per_Hour = 60;
const int Seconds_Per_Minute = 60;

int main()
{
	cout << "Enter the number of seconds: ";
	long long seconds;
	cin >> seconds;
	long second = seconds%Seconds_Per_Minute;
	long minute = seconds / Seconds_Per_Minute%Minutes_Per_Hour;
	long hour = seconds / Seconds_Per_Minute / Minutes_Per_Hour%Hours_Per_Day;
	long day = seconds / Seconds_Per_Minute / Minutes_Per_Hour / Hours_Per_Day;
	cout << seconds << " seconds = " << day << " days, " << hour << " hours, " << minute << " minutes, " << second << " seconds" << endl;
	

}