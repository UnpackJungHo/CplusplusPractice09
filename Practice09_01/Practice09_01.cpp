#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;

public:
	Converter() : Converter(1.0) {}
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을" << getDestString() << "로 바꿉니다.";
		cout << getSourceString() << "을 입력하세요>>";
		cin >> src;
		cout << "변환 결과: " << convert(src) << getDestString() << endl;
	}
};


class WonToDollar : public Converter {
public:
	double convert(double src) override {
		return src / ratio;
	}
	string getSourceString() override {
		return "원";
	}
	string getDestString() override {
		return "달러";
	}
	WonToDollar(double num) : Converter(num) {}
};


int main()
{
	WonToDollar wd(1010);
	wd.run();
}
