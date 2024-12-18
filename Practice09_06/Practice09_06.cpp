#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class AbstrackStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstrackStack {
	int num;
	int capacity;
	int *p;
public:
	IntStack(int capacity = 100) {
		this->num = 0;
		this->capacity = capacity;
		p = new int[capacity];
	}
	bool push(int n) {
		if (num >= capacity)
			return false;
		else
		{
			p[num++] = n;
			return true;
		}
	}
	bool pop(int& n) {
		if (num == -1)
			return false;
		else {
			n = p[--num];
			return true;
		}
	}
	int size() {
		return num;
	}

	void show() {
		for (int i = 0; i < num; i++) {
			cout << p[i] << "|";
		}
	}
};

int main() {
	IntStack intStack(10); 

	intStack.push(1);
	intStack.push(2);
	intStack.push(3);

	cout << "스택 내용: ";
	intStack.show();
	cout << endl;

	int n;
	if (intStack.pop(n)) {
		cout << "pop된 값: " << n << endl;
	}

	cout << "스택 크기: " << intStack.size() << endl;

	return 0;
}