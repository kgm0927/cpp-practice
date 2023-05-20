#include <iostream>
using namespace std;


//
// 10.3 제네릭 클래스 만들기
// 
// * 제네릭 클래스 개요
// 
// template을 이용하면 제네릭 클래스(generic class)도 만들 수 있다.
// 
// * 제네릭 클래스 선언
// 
// 제네릭 클래스를 만들기 위해, 클래스 선언부와 구현부를 모두 template으로 선언한다.
// 제네릭 클래스의 멤버 함수는 자동 제네릭 함수이다.
// 
// 
// * 제네릭 클래스 선언부
// 
// 스택에서 다루는 데이터 타입은 하나이므로 제네릭 타입은 T 하나만 필요하다. 제네릭 클래스
// MyStack은 제네릭 타입 T와 함께 다음과 같이 선언한다.
// 
// template <class T>
// class MyStack{
//		int tos;
//		T data
// public:
//	MyStack();
//	void push(T element);
//	T pop();
// }
// 
// * 제네릭 클래스 구현부
// 
// 클래스 구현부는 멤버 함수를 작성하는 곳으로, 클래스 이름을 MyStack 대신
// MyStack<T>로 사용하고, 각 멤버 함수 앞에 template<class T>를 붙여서 제네릭 함수임을 
// 선언한다. 다음과 같이 선언한다.
// 
// template <class T>
// void MyStack<T>::push(T element){
//		...
// }
// 
// template <class T> T MyStack<T>::pop(){
//		...
// }
// 
// 
// 
// * 제네릭 클래스의 구체화
// 
// 제네릭 클래스를 이용할 때에는 클래스이 이름과 함께 제네릭 타입 T에 적용할 구체적인 타입을 지정해야 한다.
// 다음은 MyStack의 제네릭 타입 T에 구체적인 타입을 사용한 사례이다.
// 
// MyStack <int> iStack;
// MyStack<double> dStack;
// 
// 컴파일러는 이 선언문으로부터 다음과 같은 구체화 과정을 진행한다.
// 
// 1. MyStack 템플릿의 T에 int나 double을 적용하여 두 개의 구체화된 버전의 C++ 클래스 소스(specialized class)를 생성한다.
// 2. 두 C++ 클래스를 컴파일하고 iStack 객체와 dStack 객체를 생성하도록 컴파일한다.
// 
// 
// 다음과 같이 제네릭 클래스의 포인터를 선언하고 동적으로 객체를 생성할 수도 있다.
// 
// MyStack<char> *p=new MyStack<char>();
// p->push('a');
// char c= p->pop();
// delete p;
// 
//
template <class T>
class MyStack {
	int tos;	// top of stack
	T data[100];	// T 타입의 배열. 스택 크기는 100

public:
	MyStack();
	void push(T element);	// T 타입 원소 element를 data [] 배열에 삽입
	T pop();	// 스택의 탑에 있는 데이터를 data[] 배열에서 리턴

};

template <class T>
MyStack<T>::MyStack() {// 생성자
	tos = -1;	// 스택은 비어 있음
}

template <class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack full";
		return;
	}
	tos++;
	data[tos]=element;

}

template <class T>
T MyStack<T>::pop() {

		T retData;
		if (tos == -1) {
			cout << "stack empty";
			return 0; // 오류 표시
		}
		retData = data[tos--];
		return retData;

	
}

int main() {
	MyStack<int> iStack;	// int 만 저장할 수 있는 스택
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;	// double 만 저장할 수 있는 스택
	dStack.push(3.5);
	cout <<dStack.pop() << endl;


	MyStack<char>* p = new MyStack<char>();	// char 만 저장할 수 있는 스택
	p->push('a');
	cout << p->pop() << endl;
	delete p;

}