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
	string getM() { return model; }
	string getMF() { return manufacturer; }
	void setAC(int availableCount) { this->availableCount = availableCount; }

	virtual void print(int pages) = 0;
	virtual void show() = 0;
};

class RazerPrint : public Printer {
	int availableToner;
public:
	RazerPrint(string m, string mf, int ac, int availableToner) : Printer(m, mf, ac) {
		this->availableToner = availableToner;
	}

	void print(int page) override {
		setAC(getAC() - page);
	}

	int useToner() {
		availableToner -= 1;
		return availableToner;
	}

	void show() override {
		cout << getM() << "," << getMF() << "," << "남은 종이 " << getAC() << ", 남은 토너" << availableToner << endl;
	}
};

class InkPrinter : public Printer {
	int availableInk;
public:
	InkPrinter(string m, string mf, int ac, int availableInk) : Printer(m, mf, ac) {
		this->availableInk = availableInk;
	}

	void print(int page) override {
		setAC(getAC() - page);
	}

	int useInk(int page) {
		availableInk -= page;
		return availableInk;
	}

	void show() override {
		cout << getM() << "," << getMF() << "," << "남은 종이 " << getAC() << ", 남은 잉크" << availableInk << endl;
	}
};

int main() {
	int selectNum = 0,printNum = 0;
	string yn;
	InkPrinter i("Officejet V40", "HP", 5, 10);
	RazerPrint r("SCX-6x45", "삼성전자", 3, 20);
	
	cout << "현재 작동중인 2대의 프린터는 아래와 같다. " << endl;
	i.show();
	r.show();
	cout << endl;
	

	while (true) {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >>";
		cin >> selectNum >> printNum;

		if (selectNum == 1)
		{	
			if (i.getAC() < printNum) {
				cout << "용지 부족하여 프린트 할 수 없습니다." << endl;
			}
			else {
				i.print(printNum);
				i.useInk(printNum);
			}
		}
		else if (selectNum == 2) {
			if (r.getAC() < printNum) {
				cout << "용지 부족하여 프린트 할 수 없습니다." << endl;
			}
			else {
				r.print(printNum);
				r.useToner();
			}
		}
		else {
			cout << "잘못 선택" << endl;
		}
		cout << "프린트 하였습니다." << endl;
		i.show();
		r.show();
		cout << "계속 프린트 하시겠습니까?(y/n) >>";
		cin >> yn;
		cout << endl;
		if (yn == "n")
			break;
		else {
			continue;
		}
		
	}
}