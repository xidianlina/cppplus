#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "chapter_11_vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;

	fstream outFile;
	outFile.open("result.txt",'w');

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		outFile << "Target Distance: " << target << ", Step Size: " << dstep << "\r\n";
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			outFile << steps << ": " << result << "\r\n";
			steps++;
		}
		cout << "After " << steps << " steps, the subject has the following location:\n" << result << endl;
		outFile << "After " << steps << ", the subject has the following location:\r\n" << result << "\r\n";
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		outFile << " or\r\n" << result << "\r\n"
			    << "Average outward distance per step = " << result.magval() / steps << "\r\n";
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	outFile.close();
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}