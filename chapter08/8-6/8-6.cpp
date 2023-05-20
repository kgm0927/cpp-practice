#include <iostream>
using namespace std;



class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};

class Derived : private Base {
	int b;
protected:
	void setB(int b) {
		this->b = b;
	
	}
public:

	void ShowB() {
		setA(5);	// 1 // ���� ������. setA()�� Base Ŭ������ protected ����̱� ������ �Ļ�Ŭ���� Derived ���� ���� ���.
		showA();	// 2 // ���� ������. showA()�� Base Ŭ������ public ����̱� ������ �Ļ� Ŭ���� Derived ���� ���� ���.
		cout << b;
	
	}
};

class GrandDerived:private Derived {
	int c;
protected:
	void setAB(int x) {
		setA(x);	// 3 // ������ ����. setA()�� private �Ӽ����� ����Ǿ� Derived Ŭ������ ��ӵǱ� ������ GrandDerived Ŭ�������� ���� �Ұ�
	showA();		// 4 // ������ ����. private  �Ӽ����� ����Ǿ� Derived Ŭ������ ��ӵǱ� ������ GrandDerived Ŭ�������� ���� �Ұ�
		setB(x);	// 5 // ���� ������. setB()�� Derived Ŭ������ protected ����̱� ������ �Ļ� Ŭ���� GrandDerived ���� ��� ����Լ��� ������ �����ϴ�.
		
	}
};