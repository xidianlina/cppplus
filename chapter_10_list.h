#ifndef LIST_H_
#define LIST_H_

typedef int Item;

class List
{
private:
	static const int SIZE = 10;
	Item data[SIZE];
	int length;
public:
	List() { length = 0; }
	bool add(const Item data);
	bool isempty() const;
	bool isfull() const;
	void visit(void(*pf)(Item &data));
};

#endif