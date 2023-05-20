#include <iostream>
using namespace std;

// 제네릭 스택의 제네릭 타입을 포인터나 클래스로 구제화하는 예
// 
// 제네릭 타입을 포인터나 클래스 타입으로 구체화할 수 있다. 밑의 예제인 MyStack 제네릭
// 클래스를 활용하여 int* Point 객체, Point* string 문자열 등을 저장하고 사용하는 예를 보여준다. 
//

template <class T>
class MyStack {
	int tos;
	T data[100];
public:
	MyStack();
	void push(T element);
	T pop();

};

template <class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	tos++;
	data[tos] = element;

}

template <class T>
T MyStack<T>::pop() {

	T retData;
	if (tos == -1) {
		cout << "stack empty";
		return 0;
	}
	retData = data[tos--];
	return retData;


}

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void show() { cout << x << '(' << ',' << y << ')' << endl; }
};

int main() {

	MyStack<int*> ipStack;	// int* 만 저장하는 스택

	int* p = new int[3];
	for (int i = 0; i < 3; i++)p[i] = i * 10;	// 0, 10, 20 으로 초기화
	ipStack.push(p);	// 포인터 푸시

	int* q = ipStack.pop();	// 포인터 팝
	for (int i = 0; i < 3; i++)	// 화면 출력
	{
		cout << q[i] << ' ';
	}
	cout << endl;
	delete[] p;

	MyStack<Point> pointStack;// Point 객체만 저장하는 스택
	Point a(2, 3), b;
	pointStack.push(a);	// Point 객체 푸시, 복사되어 저장
	b = pointStack.pop();	//Point 객체 팝
	b.show();	// Point 객체 출력

	MyStack<Point*> pStack;		//Point*만 저장하는 스택
	pStack.push(new Point(10,20));// 동적 생성 Point 객체 푸시, 포인터만 저장
	Point* pPoint = pStack.pop();
	pPoint->show();

	MyStack<string> stringStack;
	string s = "c++";
	stringStack.push(s);
	stringStack.push("java");
	cout << stringStack.pop() << ' ';
	cout << stringStack.pop() << endl;


}