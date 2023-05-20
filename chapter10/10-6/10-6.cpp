#include <iostream>
using namespace std;


//
// 10.3 ���׸� Ŭ���� �����
// 
// * ���׸� Ŭ���� ����
// 
// template�� �̿��ϸ� ���׸� Ŭ����(generic class)�� ���� �� �ִ�.
// 
// * ���׸� Ŭ���� ����
// 
// ���׸� Ŭ������ ����� ����, Ŭ���� ����ο� �����θ� ��� template���� �����Ѵ�.
// ���׸� Ŭ������ ��� �Լ��� �ڵ� ���׸� �Լ��̴�.
// 
// 
// * ���׸� Ŭ���� �����
// 
// ���ÿ��� �ٷ�� ������ Ÿ���� �ϳ��̹Ƿ� ���׸� Ÿ���� T �ϳ��� �ʿ��ϴ�. ���׸� Ŭ����
// MyStack�� ���׸� Ÿ�� T�� �Բ� ������ ���� �����Ѵ�.
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
// * ���׸� Ŭ���� ������
// 
// Ŭ���� �����δ� ��� �Լ��� �ۼ��ϴ� ������, Ŭ���� �̸��� MyStack ���
// MyStack<T>�� ����ϰ�, �� ��� �Լ� �տ� template<class T>�� �ٿ��� ���׸� �Լ����� 
// �����Ѵ�. ������ ���� �����Ѵ�.
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
// * ���׸� Ŭ������ ��üȭ
// 
// ���׸� Ŭ������ �̿��� ������ Ŭ������ �̸��� �Բ� ���׸� Ÿ�� T�� ������ ��ü���� Ÿ���� �����ؾ� �Ѵ�.
// ������ MyStack�� ���׸� Ÿ�� T�� ��ü���� Ÿ���� ����� ����̴�.
// 
// MyStack <int> iStack;
// MyStack<double> dStack;
// 
// �����Ϸ��� �� �������κ��� ������ ���� ��üȭ ������ �����Ѵ�.
// 
// 1. MyStack ���ø��� T�� int�� double�� �����Ͽ� �� ���� ��üȭ�� ������ C++ Ŭ���� �ҽ�(specialized class)�� �����Ѵ�.
// 2. �� C++ Ŭ������ �������ϰ� iStack ��ü�� dStack ��ü�� �����ϵ��� �������Ѵ�.
// 
// 
// ������ ���� ���׸� Ŭ������ �����͸� �����ϰ� �������� ��ü�� ������ ���� �ִ�.
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
	T data[100];	// T Ÿ���� �迭. ���� ũ��� 100

public:
	MyStack();
	void push(T element);	// T Ÿ�� ���� element�� data [] �迭�� ����
	T pop();	// ������ ž�� �ִ� �����͸� data[] �迭���� ����

};

template <class T>
MyStack<T>::MyStack() {// ������
	tos = -1;	// ������ ��� ����
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
			return 0; // ���� ǥ��
		}
		retData = data[tos--];
		return retData;

	
}

int main() {
	MyStack<int> iStack;	// int �� ������ �� �ִ� ����
	iStack.push(3);
	cout << iStack.pop() << endl;

	MyStack<double> dStack;	// double �� ������ �� �ִ� ����
	dStack.push(3.5);
	cout <<dStack.pop() << endl;


	MyStack<char>* p = new MyStack<char>();	// char �� ������ �� �ִ� ����
	p->push('a');
	cout << p->pop() << endl;
	delete p;

}