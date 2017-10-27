#include "chapter_11_04_time.h"

int main()
{
	using namespace std;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = 1.17*aida;
	cout << "Aida * 1.17: " << temp << endl;
	temp = aida - tosca;
	cout << "Aida - Tosca: " << temp << endl;

	return 0;
}