#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	bool operation() override{
		if (x == y)
			return true;
		else
			return false;
	}
};


class ORGate : public AbstractGate {
public:
	bool operation() override {
		if (x == false && y == false)
			return false;
		else
			return true;
	}
};

class XORGate : public AbstractGate {
public:
	bool operation() override {
		if (x != y)
			return true;
		else
			return false;
	}
};



int main()
{
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);

	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}