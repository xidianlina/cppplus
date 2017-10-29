#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA
{
private:
	char *label;
	int rating;
public:
	DMA(const char *l = "null", int r = 0);
	DMA(const DMA &d);
	virtual ~DMA();
	char *GetLabel()const { return label; }
	int GetRating()const { return rating; }
	DMA &operator=(const DMA &d);
	virtual void View()const = 0;
};

class baseDMA :public DMA
{
public:
	baseDMA(const char *l = "null", int r = 0);
	baseDMA(const baseDMA &d);
	baseDMA &operator=(const baseDMA &d);
	virtual void View()const;
};

class lacksDMA :public DMA
{
private:
	char *color;
public:
	lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
	lacksDMA(const lacksDMA &d);
	virtual void View()const;
};

class hasDMA :public DMA
{
private:
	char *style;
public:
	hasDMA(const char *s = "none", const char *l = "null", int r = 0);
	hasDMA(const hasDMA &hs);
	~hasDMA();
	hasDMA &operator=(const hasDMA &rs);
	virtual void View()const;
};

#endif