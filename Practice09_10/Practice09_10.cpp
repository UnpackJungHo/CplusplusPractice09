#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Shape {
	string ownShape;
public:
	Shape() : Shape(""){}
	Shape(string o) : ownShape(o){}
	string getOwn() {
		return ownShape;
	}
	void setOwn(string o) {
		this->ownShape = o;
	}
	virtual string myShape() = 0;
};

class Line :public Shape {
public:
	string myShape() override {
		return "Line";
	}
};

class Circle :public Shape {
public:
	string myShape() override {
		return "Circle";
	}
};

class Rect :public Shape {
public:
	string myShape() override {
		return "Rect";
	}
};

class GraphEditor {
	int selectNum,selectShape,index;
	int top;
	int pStart, pLast, capacity = 100;
	string *graph;
	Line L;
	Rect R;
	Circle C;
public:
	GraphEditor(): top(0),pStart(0),pLast(0), selectNum(0), selectShape(0),index(-1){
		graph = new string[capacity];
	}
	void insert(int selectShape) {
		if (selectShape == 1)
			graph[top++] = L.myShape();
		else if (selectShape == 2)
			graph[top++] = C.myShape();
		else if (selectShape == 3)
			graph[top++] = R.myShape();
	}
	void pop(int index) {
		for (int i = index; i < top - 1; i++) {
			graph[i] = graph[i + 1];
		}
		top--;
	}
	void show() {
		for (int i = 0; i < top; i++) {
			cout << i << ":" << graph[i] << endl;
		}
	}
	void run();
};

void GraphEditor::run() {
	cout << "그래프 에디터입니다." << endl;
	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> selectNum;
		if (selectNum == 1) {
			cout << "선:1, 원:2, 사각형:3 >>";
			cin >> selectShape;
			insert(selectShape);
		}
		else if (selectNum == 2) {
			cout << "삭제하고자 하는 도형의 인덱스 >>";
			cin >> index;
			pop(index);
		}
		else if (selectNum == 3) {
			show();
		}
		else if (selectNum == 4) {
			break;
		}
	}
}

int main() {
	GraphEditor g;
	g.run();
}