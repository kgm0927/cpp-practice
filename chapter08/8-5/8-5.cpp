#include <iostream>
using namespace std;

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived :protected Base {
	int b;
protected:
	void setB(int b) {  this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	x.a = 5;	// 1 // Derived Ŭ������ ��ӵ����� private ����̹Ƿ� ���� �Ұ�
	x.setA(10);	// 2
	x.showA();	// 3 // ������ ����, setA(), showA(), ����� protected ����� ����Ǿ� Derived Ŭ������ ��ӵǱ� ������ Derived Ŭ���� �ܺο��� ���� �Ұ�
	x.showB = 10;	// 4 // b�� private ����̱� ������ Derived Ŭ���� �ܺο��� ���� �Ұ�
	x.setB(10);	// 5 // ������ ����. setB()�� protected ����̱� ������ main() �Լ����� ���� �Ұ�
	x.showB();	// 6 // ���� ������. showB() public ����̱� ������ ������ ������ �����ϴ�.
}