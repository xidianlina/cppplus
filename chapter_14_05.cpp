#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

using namespace std;

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp();
	abstr_emp(const string &fn, const string &ln,const string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
	friend ostream &operator<<(ostream&os, const abstr_emp &e);
	virtual ~abstr_emp() = 0;
};

class employee :public abstr_emp
{
public:
	employee();
	employee(const string &fn, const string &ln,
		const string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
};

class manager :virtual public abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf()const { return inchargeof; }
	int &InChargeOf() { return inchargeof; }
public:
	manager();
	manager(const string &fn, const string &ln,const string &j, int ico = 0);
	manager(const abstr_emp&e, int ico = 0);
	manager(const manager &m);
	virtual void ShowAll()const;
	virtual void SetAll();
	void getInCharge() {
		cout << "Enter inchargeof: ";
		cin >> inchargeof;
	}
};

class fink :virtual public abstr_emp
{
private:
	string reportsto;
protected:
	const string ReportsTo()const { return reportsto; }
	string&ReportsTo() { return reportsto; }
public:
	fink();
	fink(const string &fn, const string &ln,
		const string &j, const string &rpo);
	fink(const abstr_emp&e, const string &rpo);
	fink(const fink &e);
	virtual void ShowAll()const;
	virtual void SetAll();
	void getReportsTo() {
		cout << "Enter reportsto: ";
		cin >> reportsto;
	}
};

class highfink:public manager, public fink
{
public:
	highfink();
	highfink(const string &fn, const string &ln, const string &j, const string &rpo, int ico = 0);
	highfink(const abstr_emp&e, const string &rpo, int ico = 0);
	highfink(const fink &f, int ico = 0);
	highfink(const manager &m, const string &rpo);
	highfink(const highfink&h);
	virtual void ShowAll()const;
	virtual void SetAll();
};
#endif

abstr_emp::abstr_emp() :fname("no one"), lname("no one"), job("no job"){}
abstr_emp::abstr_emp(const string &fn, const string &ln,	const string &j) : fname(fn), lname(ln), job(j){ }
void abstr_emp::ShowAll()const
{
	cout << "Firstname: " << fname << endl;
	cout << "Lastname: " << lname << endl;
	cout << "Job is: " << job << endl;
}
void abstr_emp::SetAll()
{
	cout << "Enter firstname: ";
	getline(cin, fname);
	cout << "Enter lastname: ";
	getline(cin, lname);
	cout << "Enter position: ";
	getline(cin, job);
}
ostream&operator<<(ostream&os, const abstr_emp&e)
{
	os << e.fname << " " << e.lname << ", " << e.job << endl;
	return os;
}
abstr_emp::~abstr_emp(){}

employee::employee() :abstr_emp() {}
employee::employee(const string &fn, const string &ln,const string &j) : abstr_emp(fn, ln, j){}
void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager() :abstr_emp(){}
manager::manager(const string &fn, const string &ln,const string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico){}
manager::manager(const abstr_emp&e, int ico) : abstr_emp(e), inchargeof(ico){}
manager::manager(const manager &m) : abstr_emp(m){}
void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << InChargeOf() << endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	(cin >> inchargeof).get();
}

fink::fink() :abstr_emp(){}
fink::fink(const string &fn, const string &ln,	const string &j, const string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo){}
fink::fink(const abstr_emp&e, const string &rpo) : abstr_emp(e), reportsto(rpo){}
fink::fink(const fink &e) : abstr_emp(e){}
void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << ReportsTo() << endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	cin >> reportsto;
}

highfink::highfink() :abstr_emp(), manager(), fink(){}
highfink::highfink(const string &fn, const string &ln,
	const string &j, const string &rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo){}
highfink::highfink(const abstr_emp&e, const string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo){}
highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f){}
highfink::highfink(const manager &m, const string &rpo) : abstr_emp(m), manager(m), fink(m, rpo){}
highfink::highfink(const highfink&h) : abstr_emp(h), manager(h), fink(h){}
void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "InChargeOf: " << manager::InChargeOf() << endl;
	cout << "ReportsTo: " << fink::ReportsTo() << endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	manager::getInCharge();
	fink::getReportsTo();
}

int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp *tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i< 4; i++)
		tri[i]->ShowAll();

	return 0;
}