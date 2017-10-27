#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	static const int Len = 20;
	char name[Len];
	int ci;
public:
	Plorg();
	Plorg(const char *n = "Plorg", int c = 50);
	void setname(const char *n);
	void setci(const int c);
	void show()const;
};

#endif