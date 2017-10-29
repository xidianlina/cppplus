#define _CRT_SECURE_NO_WARNINGS
#include "chapter_13_03_dma.h"

DMA::DMA(const char *l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}
DMA::DMA(const DMA &d)
{
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	rating = d.rating;
}
DMA::~DMA()
{
	delete[]label;
}
DMA &DMA::operator=(const DMA &d)
{
	if (this == &d)
		return *this;
	delete[]label;
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	rating = d.rating;
	return *this;
}

baseDMA::baseDMA(const char *l, int r) :DMA(l, r) {}
baseDMA::baseDMA(const baseDMA &d) : DMA(d) {}
baseDMA &baseDMA::operator=(const baseDMA &d)
{
	if (this == &d)
		return *this;
	DMA::operator=(d);
	return *this;
}
void baseDMA::View()const
{
	std::cout << "label : " << GetLabel() << std::endl;
	std::cout << "rating : " << GetRating() << std::endl;
}

lacksDMA::lacksDMA(const char *c, const char *l, int r) :DMA(l, r)
{
	color = new char[std::strlen(c) + 1];
	std::strcpy(color, c);
}
lacksDMA::lacksDMA(const lacksDMA &d):DMA(d)
{
	color = new char[std::strlen(d.color) + 1];
	std::strcpy(color, d.color);
}
void lacksDMA::View()const
{
	std::cout << "label : " << GetLabel() << std::endl;
	std::cout << "rating : " << GetRating() << std::endl;
	std::cout << "color : " << color << std::endl;
}

hasDMA::hasDMA(const char *s, const char *l, int r) :DMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &hs) : DMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}
hasDMA::~hasDMA()
{
	delete[]style;
}
hasDMA &hasDMA::operator=(const hasDMA &rs)
{
	if (this == &rs)
		return *this;
	DMA::operator=(rs);
	delete[]style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

void hasDMA::View() const
{
	std::cout << "label : " << GetLabel() << std::endl;
	std::cout << "rating : " << GetRating() << std::endl;
	std::cout << "style : " << style << std::endl;
}