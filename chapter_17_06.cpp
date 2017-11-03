#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum classtype{ Employee, Manager, Fink, Highfink };

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	abstr_emp();
	abstr_emp(const string &fn, const string &ln,
		const string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
	friend ostream&operator<<(ostream&os, const abstr_emp&e);
	virtual ~abstr_emp() = 0;
	virtual void writeall(ofstream&ofs);
	virtual void getall(ifstream&ifs);
};

class employee :public abstr_emp
{
public:
	employee();
	employee(const string &fn, const string &ln,
		const string &j);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall(ofstream&ofs);
	virtual void getall(ifstream&ifs);
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
	manager(const string &fn, const string &ln,
		const string &j, int ico = 0);
	manager(const abstr_emp&e, int ico = 0);
	manager(const manager &m);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall(ofstream&ofs);
	virtual void getall(ifstream&ifs);
	void getInCharge() 
	{
		cout << "Enter inchargeof: ";
		cin >> inchargeof;
	}
	void writeInCharge(ofstream&ofs) 
	{
		ofs << inchargeof << endl;
	}
	void readInCharge(ifstream&ifs)
	{
		ifs >> inchargeof;
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
	virtual void writeall(ofstream&ofs);
	virtual void getall(ifstream&ifs);
	void getReportsTo()
	{
		cout << "Enter reportsto: ";
		cin >> reportsto;
	}
	void writeReportsTo(ofstream&ofs)
	{
		ofs << reportsto << endl;
	}
	void readReportsTo(ifstream&ifs)
	{
		ifs >> reportsto;
	}
};

class highfink:public manager, public fink
{
public:
	highfink();
	highfink(const string &fn, const string &ln,
		const string &j, const string &rpo, int ico = 0);
	highfink(const abstr_emp&e, const string &rpo, int ico = 0);
	highfink(const fink &f, int ico = 0);
	highfink(const manager &m, const string &rpo);
	highfink(const highfink&h);
	virtual void ShowAll()const;
	virtual void SetAll();
	virtual void writeall(ofstream&ofs);
	virtual void getall(ifstream&ifs);
};

#endif

abstr_emp::abstr_emp() :fname("no one"), lname("no one"), job("no job"){}
abstr_emp::abstr_emp(const string &fn, const string &ln,const string &j) : fname(fn), lname(ln), job(j){}
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
void abstr_emp::writeall(ofstream&ofs)
{
	ofs << fname << "\n" << lname << "\n" << job << "\n";
}
void abstr_emp::getall(ifstream&ifs)
{
	getline(ifs, fname);
	getline(ifs, lname);
	getline(ifs, job);
}

employee::employee() :abstr_emp(){}
employee::employee(const string &fn, const string &ln,const string &j) : abstr_emp(fn, ln, j){}
void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}
void employee::writeall(ofstream&ofs)
{
	ofs << Employee << endl;
	abstr_emp::writeall(ofs);
}
void employee::getall(ifstream&ifs)
{
	abstr_emp::getall(ifs);
}

manager::manager() :abstr_emp(){}
manager::manager(const string &fn, const string &ln,
	const string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{

}
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
void manager::writeall(ofstream&ofs)
{
	ofs << Manager << endl;
	abstr_emp::writeall(ofs);
	ofs << inchargeof << endl;
}
void manager::getall(ifstream&ifs)
{
	abstr_emp::getall(ifs);
	ifs >> inchargeof;
}

fink::fink() :abstr_emp(){}
fink::fink(const string &fn, const string &ln,const string &j, const string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo){}
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
void fink::writeall(ofstream&ofs)
{
	ofs << Fink << endl;
	abstr_emp::writeall(ofs);
	ofs << reportsto << endl;
}
void fink::getall(ifstream&ifs)
{
	abstr_emp::getall(ifs);
	ifs >> reportsto;
}

highfink::highfink() :abstr_emp(), manager(), fink(){}
highfink::highfink(const string &fn, const string &ln,
	const string &j, const string &rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{

}
highfink::highfink(const abstr_emp&e, const string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}
highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{

}
highfink::highfink(const manager &m, const string &rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{

}
highfink::highfink(const highfink&h) : abstr_emp(h), manager(h), fink(h)
{

}
void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "InChargeOf: ";
	cout << manager::InChargeOf() << endl;
	cout << "ReportsTo: ";
	cout << fink::ReportsTo() << endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	manager::getInCharge();
	fink::getReportsTo();
}
void highfink::writeall(ofstream&ofs)
{
	ofs << Highfink << endl;
	abstr_emp::writeall(ofs);
	manager::writeInCharge(ofs);
	fink::writeReportsTo(ofs);
}

void highfink::getall(ifstream&ifs)
{
	abstr_emp::getall(ifs);
	manager::readInCharge(ifs);
	fink::readReportsTo(ifs);
}

const int MAX = 5;
const char *file = "a.txt";

int main(void)
{
	abstr_emp *pc[MAX];
	char ch;
	ifstream fin;
	fin.open(file);
	int i = 0;
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		int classtype;
		i = 0;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
				case Employee:
					pc[i] = new employee;
					break;
				case Manager:
					pc[i] = new manager;
					break;
				case Fink:
					pc[i] = new fink;
					break;
				case Highfink:
					pc[i] = new highfink;
					break;
			}
			cout << classtype << endl;
			pc[i]->getall(fin);
			pc[i++]->ShowAll();
		}
	}
	fin.close();
	ofstream fout;
	fout.open(file, ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "e to employee, m to manager\n"
		<< "f to fink, h to highfink\n"
		<< "q to quit: ";
	int index = 0;
	while (cin.get(ch).get() && ch != 'q'&&index < MAX)
	{
		switch (ch)
		{
			case'e':
				pc[index] = new employee;
				pc[index]->SetAll();
				index++;
				break;
			case'm':
				pc[index] = new manager;
				pc[index]->SetAll();
				index++;
				break;
			case'f':
				pc[index] = new fink;
				pc[index]->SetAll();
				index++;
				break;
			case'h':
				pc[index] = new highfink;
				pc[index]->SetAll();
				index++;
				break;
			default:
				cout << "Try again";
				break;
		}
		if (index > MAX)
			break;
		cout << "e to employee, m to manager\n"
			<< "f to fink, h to highfink\n"
			<< "q to quit: ";
	}
	for (i = 0; i< index; i++)
		pc[i]->writeall(fout);
	fout.close();

	fin.clear();
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the "
			<< file << " file:\n";
		int classtype;
		i = 0;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
				case Employee:
					pc[i] = new employee;
					break;
				case Manager:
					pc[i] = new manager;
					break;
				case Fink:
					pc[i] = new fink;
					break;
				case Highfink:
					pc[i] = new highfink;
					break;
			}
			cout << classtype << endl;
			pc[i]->getall(fin);
			pc[i++]->ShowAll();
		}
	}
	cout << "Done.\n";

	return 0;
}