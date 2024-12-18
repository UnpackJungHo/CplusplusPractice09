#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Printer {
	string model, manufacturer;
	int printedCount, availableCount;
public:
	Printer() : Printer("", "",0){}
	Printer(string m, string mf, int ac) {
		this->model = m;
		this->manufacturer = mf;
		this->availableCount = ac;
	}
	int getAC() { return availableCount; }
	virtual void print(int pages) {
		availableCount -= printedCount;
	}
	virtual void show() {
		cout << model << "," << manufacturer << "," << "남은 종이 " << availableCount;
	}
};

class RazerPrint : public Printer {
	int availableToner;
public:
	RazerPrint(string m, string mf, int ac, int availableToner) : Printer(m, mf, ac) {
		this->availableToner = availableToner;
	}
	void print(int page) override {
		int x = getAC();
		x -= page;
	}
};