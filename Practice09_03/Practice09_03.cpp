#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}
void LoopAdder::write() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << "입니다." << endl;
}
void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder {
public:
	int calculate() override {
		int sum = 0;
		int x = getX();
		int y = getY();

		for (int i = x; i <= y; i++) {
			sum += i;
		}

		return sum;
	}

	ForLoopAdder(string name) : LoopAdder(name) {}
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}