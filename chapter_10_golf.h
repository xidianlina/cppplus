#ifndef GOLF_H_
#define GOLF_H_

class Golf
{
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf();
	Golf(const char *fn, const int hc = 0);
	int setGolf();
	void setHandicap(const int hc);
	void showGolf()const;
};

#endif