#define _CRT_SECURE_NO_WARNINGS
#include "chapter_12_string2.h"
#include <cstring>

using std::cout;
using std::cin;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}
String::String(const char *s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}
String::String()
{
	len = 1;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const String &st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}
String::~String()
{
	--num_strings;
	delete [] str;
}
String &String::operator=(const String &st)
{
	if (this == &st)
		return *this;
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}
String &String::operator=(const char *s)
{
	delete[]str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}
char &String::operator[](int i)
{
	return str[i];
}
const char &String::operator[](int i)const
{
	return str[i];
}
bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String &st1, const String &st2)
{
	return st1 < st2;
}
bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}
std::ostream &operator<<(std::ostream &os, const String &st)
{
	os << st.str;
	return os;
}
std::istream &operator>>(std::istream &is, String &st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is&&is.get() != '\n')
		continue;
	return is;
}

String operator+(const String &st1, const String &st2)
{
	char *res = new char[st1.length() + st2.length() + 1];
	strcpy(res, st1.str);
	strcat(res, st2.str);
	String temp(res);
	delete[]res;
	return temp;
}
void String::stringlow()
{
	for (int i = 0; i < len; i++)
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
}
void String::stringup()
{
	for (int i = 0; i < len; i++)
		if (islower(str[i]))
			str[i] = toupper(str[i]);
}
int String::has(char ch)
{
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == ch)
			cnt++;

	return cnt;
}