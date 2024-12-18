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

class WhileLoopAdder : public LoopAdder {
public:
	int calculate() override {
		int sum = 0;
		int x = getX();
		int y = getY();

		while(true){
			sum += x;
			x++;

			if (x > y) {
				break;
			}
		}

		return sum;
	}

	WhileLoopAdder(string name) : LoopAdder(name) {}
};


class DoWhileLoopAdder : public LoopAdder {
public:
	int calculate() override {
		int sum = 0;
		int x = getX();
		int y = getY();

		do
		{
			sum += x;
			x++;

		} while (x <= y);

		return sum;
	}

	DoWhileLoopAdder(string name) : LoopAdder(name) {}
};

int main() {
	WhileLoopAdder whileLoop("While Loop");
	whileLoop.run();

	DoWhileLoopAdder DoWhileLoop("Do while Loop");
	DoWhileLoop.run();
}