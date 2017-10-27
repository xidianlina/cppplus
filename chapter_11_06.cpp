#include "chapter_11_06_stonewt.h"

int main()
{
	using namespace std;

	Stonewt sw[6] = { 10.0,11.0,12.5 };
	Stonewt temp(11.0);
	for (int i = 3; i < 6; i++)
	{
		double input;
		cout << "Enter #" << i + 1 << ": ";
		cin >> input;
		sw[i] = input;
	}
	for (int i = 0; i < 6; i++)
		cout << "#" << i << ": " << sw[i] << endl;
	int cnt = 0;
	Stonewt Min = sw[0];
	Stonewt Max = sw[0];
	for (int i = 1; i < 6; i++)
	{
		Max = Max > sw[i] ? Max : sw[i];
		Min = Min < sw[i] ? Min : sw[i];
		if (temp >= sw[i])
			cnt++;
	}
	cout << "The Min pounds: " << Min;
	cout << "\nThe Max pounds: " << Max;
	cout << "\nThe numbers not under 11 pounds: " << cnt << endl;

	return 0;
}