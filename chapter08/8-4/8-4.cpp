#include <iostream>
using namespace std;
//
// 8.6 ����� ����: public, protected, private ���
// 
// ����� ���Ͽ� �⺻ Ŭ������ ������� �Ļ� Ŭ������ ����� Ȯ���� �� ��, �⺻ Ŭ���� ����� ���������� ��ӿ� ���� �޶�����.
// 
// 'public ���'�� ����ϸ� Base�� ����� ������� ���� ������ �״�� ������ ä Derived�� ����� Ȯ��ȴ�. ������ 'private ���'�̳� 'protected ���'
// �� �⺻ Ŭ������ ����� ������� ��� ���� ������ �����Ѵ�.
// 
// - public ���
// �⺻ Ŭ������ public���� ��ӹ�����, �⺻ Ŭ������ protected, public ������� ���� ���� ���� ���� �Ļ� Ŭ������ �״�� ��ӵȴ�.
// 
// - protected ���
// �⺻ Ŭ������ protected�� ��� ������, �⺻ Ŭ������ protected, public ������� ��� protected ���� �������� ����Ǿ� �Ļ� Ŭ������ ��� Ȯ��ȴ�.
// 
// - private ���
// �⺻ Ŭ������ private���� ��ӹ�����, �⺻Ŭ������ protected, public ������� ��� private ���� �������� ����Ǿ� �Ļ� Ŭ������ ��� Ȯ��ȴ�.
// 
//

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
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};

int main() {
	Derived x;
	x.a = 5;	// 1 // ������ ����, a�� Derived Ŭ������ ��ӵ�����  private ����̹Ƿ� ���� �Ұ� 
	x.setA(10);	// 2 // 
	x.showA();	// 3 // 2,3 ������ ���� setA(), showA()�� private ����� ����Ǿ� Derived Ŭ������ ��ӵǱ� ������ Derived Ŭ���� �ܺο��� ���� �Ұ�
	x.b = 10;	// 4 // ������ ����, b�� private ����̱� ������  Derived Ŭ���� �ܺο��� ���ٺҰ�
	x.setB(10);	// 5 // ������ ���� setB()�� protected ����̱� ������ main()���� ���� �Ұ�
	x.showB();	// 6 // ���� ������, show()�� public ����̱� ������ ������ ���� ����
}