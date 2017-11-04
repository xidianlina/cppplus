#ifndef CPMV_H_
#define CPMV_H_

#include <iostream>
#include <string>

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info *pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv &cp);
	Cpmv(Cpmv &&mv);
	~Cpmv();
	Cpmv &operator=(const Cpmv &cp);
	Cpmv &operator=(Cpmv &&mv);
	Cpmv operator+(const Cpmv &obj)const;
	void Display()const;
};

#endif

Cpmv::Cpmv()
{
	pi = new Info;
	pi->qcode = "Nothing";
	pi->zcode = "Nothing";
	std::cout << "Default constructor called:\n";
	Display();
}

Cpmv::Cpmv(std::string q, std::string z)
{
	pi = new Info;
	std::cout << "String constructor called:\n";
	pi->qcode = q;
	pi->zcode = z;
	Display();
}

Cpmv::Cpmv(const Cpmv &cp)
{
	pi = new Info;
	std::cout << "Copy constructor called:\n";
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	Display();
}

Cpmv::Cpmv(Cpmv &&mv)
{
	pi = new Info;
	std::cout << "Move constructor called:\n";
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "Nothing";
	mv.pi->zcode = "Nothing";
	Display();
}

Cpmv::~Cpmv()
{
	std::cout << "Destructor called!\n";
	delete pi;
}

Cpmv &Cpmv::operator=(const Cpmv &cp)
{
	std::cout << "Copy assignment operator called:\n";
	if (this == &cp)
		return *this;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	Display();
	return *this;
}

Cpmv &Cpmv::operator=(Cpmv &&mv)
{
	std::cout << "Move assignment operator called:\n";
	if (this == &mv)
		return *this;
	pi->qcode = mv.pi->qcode;
	pi->zcode = mv.pi->zcode;
	mv.pi->qcode = "Nothing";
	mv.pi->zcode = "Nothing";
	Display();
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv &obj)const
{
	std::cout << "Plus assignment operator calld!\n";
	Cpmv temp;
	temp.pi->qcode = pi->qcode + obj.pi->qcode;
	temp.pi->zcode = pi->zcode + obj.pi->zcode;
	return temp;
}

void Cpmv::Display()const
{
	std::cout << pi->qcode << ", " << pi->zcode << std::endl;
}

int main()
{
	{
		Cpmv zero, one("one", "one");
		std::cout << "object zero: ";
		zero.Display();
		std::cout << "object one: ";
		one.Display();
		Cpmv two = one + one;
		std::cout << "object two: ";
		two.Display();
		Cpmv three, four;
		std::cout << "three = one\n";
		three = one;
		std::cout << "now object three = ";
		three.Display();
		std::cout << "and object one = ";
		one.Display();
		std::cout << "four = one + two\n";
		four = one + two;
		std::cout << "now object four = ";
		four.Display();
		std::cout << "four = move(one)\n";
		four = std::move(one);
		std::cout << "now object four = ";
		four.Display();
		std::cout << "and object one = ";
		one.Display();
	}

	return 0;
}