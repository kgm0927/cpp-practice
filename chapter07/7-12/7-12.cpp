#include <iostream>
using namespace std;


// + �����ڸ� �ܺ� ������ �Լ��� �ۼ�

// �� ���� Power ��ü�� ���ϴ� + ������ �ܺ� �Լ��� �ۼ��غ���. ������ ���� + ������ �����ϴ� �ڵ尡 ���� ��
//
// Power a(3,4), b(4,5) ,c;
// c=a+b;
// 
// �����Ϸ��� a+b ���� �ܺο� ����� operator+(Power, Power) �Լ��� ȣ���ϰ� a,b ��� �Ű������� �����Ѵ�. �׸��� friend 
// �� �����Ѵ�.
// 
//  c=a+b -----> c=+(a,b);
//

class Power {
	int kick;
	int punch;

public:
	Power(int kick=0,int punch=0) {
		this->kick = kick;
		this->punch = punch;
	}

	void show();

	friend Power operator +(Power op1, Power op2);

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power operator+(Power op1, Power op2) {
	Power tmp;
	tmp.kick = op1.kick + op2.kick;
	tmp.punch = op1.punch + op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5), b(4, 6), c;
		c = a + b;
	a.show();
	b.show();
	c.show();

}