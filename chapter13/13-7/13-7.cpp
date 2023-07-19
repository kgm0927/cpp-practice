#include <iostream>
using namespace std;

#include "MyStack.h"

int main() {
	MyStack intstack;
	try {
		intstack.push(100);		// 100 Ǫ��
		intstack.push(200);		// 200 Ǫ��
		cout << intstack.pop() << endl; // �� 200
		cout << intstack.pop() << endl;	// �� 100
		cout << intstack.pop() << endl;	// "Stack Empty" ���� �߻�
	}
	catch (const char* s) {
		cout << "���� �߻� : " << s << endl;
	}
}