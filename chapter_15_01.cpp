#ifndef TV_H_
#define TV_H_

#include <iostream>

using namespace std;

class Tv
{
	friend class Remote;
public:
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	enum { USUAL, EXCHANGE };

	Tv(int s = Off, int mc = 125) :state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	~Tv() {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison()const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings()const;
	void set_rmode(Remote &r);
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
};

class Remote
{
private:
	friend class Tv;
	enum { USUAL, EXCHANGE };
	int mode;
	int fmode;
public:
	Remote(int m = Tv::TV, int f = USUAL) :mode(m), fmode(f) {}
	bool volup(Tv&t) { return t.volup(); }
	bool voldown(Tv&t) { return t.voldown(); }
	void onoff(Tv&t) { t.onoff(); }
	void chanup(Tv&t) { t.chanup(); }
	void chandown(Tv&t) { t.chandown(); }
	void set_chan(Tv&t, int c) { t.channel = c; }
	void set_mode(Tv&t) { t.set_mode(); }
	void set_input(Tv&t) { t.set_input(); }
	void mode_show()const { cout << "Remote pretent mode is " << fmode << endl; }
};

inline void Tv::set_rmode(Remote &r)
{
	if (ison())
	{
		r.fmode = Remote::EXCHANGE;
		r.mode_show();
	}
}

#endif

bool Tv::volup()
{
	if (volume <MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if (volume>MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if (channel <maxchannel)
		channel++;
	else
		channel = 1;
}
void Tv::chandown()
{
	if (channel>1)
		channel--;
	else
		channel = maxchannel;
}
void Tv::settings()const
{
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On)
	{
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}

int main()
{
	Tv s42;
	Remote grey;
	grey.mode_show();
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	s42.set_rmode(grey);
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\" settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" settings:\n";
	s58.settings();
	s58.set_rmode(grey);

	return 0;
}