#include <iostream>
using namespace std;

#include "MyStack.h"

int main() {
	MyStack intstack;
	try {
		intstack.push(100);		// 100 Çª½Ã
		intstack.push(200);		// 200 Çª½Ã
		cout << intstack.pop() << endl; // ÆË 200
		cout << intstack.pop() << endl;	// ÆË 100
		cout << intstack.pop() << endl;	// "Stack Empty" ¿¹¿Ü ¹ß»ý
	}
	catch (const char* s) {
		cout << "¿¹¿Ü ¹ß»ý : " << s << endl;
	}
}