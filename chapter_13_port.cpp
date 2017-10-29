#define _CRT_SECURE_NO_WARNINGS
#include "chapter_13_port.h"

Port::Port(const char *pr, const char *st, int b)
{
	brand = new char[std::strlen(pr) + 1];
	std::strcpy(brand, pr);
	std::strcpy(style, st);
	bottles = 0;
}
Port::Port(const Port &p)
{
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}
Port & Port::operator=(const Port & p)
{
	if (this == &p)
		return *this;
	delete[] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}
Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}
Port & Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}
void Port::Show() const
{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}
std::ostream &operator<<(std::ostream &os, const Port &p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

VintagePort::VintagePort() : Port()
{
	nickname = NULL;
	year = 0;
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "Vintage", b)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (this == &vp)
		return *this;
	delete[] nickname;
	Port::operator=(vp);
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}
void VintagePort::Show() const
{
	Port::Show();
	std::cout << "nick name: " << nickname << std::endl;
	std::cout << "year: " << year << std::endl;
}
std::ostream &operator<<(std::ostream &os, const VintagePort &vp)
{
	os << (Port &)vp;
	std::cout << ", " << vp.nickname << ", " << vp.year;
	return os;
}