#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <new>

const int BUF = 512;
const int N = 2;
char buffer[BUF];

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
	chaff *pc1 = new chaff[N];
	chaff *pc2 = new (buffer)chaff[N];
	char dross[20];
	int slag;

	for (int i = 0; i < N; i++)
	{
		std::cout << "Enter dross: ";
		std::cin.getline(dross, 20);
		strcpy(pc1[i].dross, dross);
		strcpy(pc2[i].dross, dross);
		std::cout << "Enter slag: ";
		std::cin >> slag;
		pc1[i].slag = slag;
		pc2[i].slag = slag;
		std::cin.get();
	}
	for (int i = 0; i < N; i++)
	{
		std::cout << "#" << i + 1 << std::endl << pc1[i].dross 
			      << std::endl << pc1[i].slag << std::endl;
		std::cout << "#" << i + 1 << std::endl << pc2[i].dross
			<< std::endl << pc2[i].slag << std::endl;
	}
}