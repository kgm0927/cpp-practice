#include <iostream>
using namespace std;

class PrivateAccessError {
private:
	int a;
	void f();
	PrivateAccessError();
public:
	int b;
	PrivateAccessError(int r);
	void g();
};

PrivateAccessError::PrivateAccessError() {
	a = 1;
	b = 1;
}

PrivateAccessError::PrivateAccessError(int x) {
	a = x;
	b = x;
}


void PrivateAccessError :: f() {
	a = 5;
	b = 5;

}

void PrivateAccessError::g() {

	PrivateAccessError objA;

	cout << "private a:" << objA.a << " private b:" << objA.b << endl;

	a = 6;
	b = 6;
}


int main() {
	PrivateAccessError objB(100);
	objB.g();
}