#include <iostream>
#include <string>
using namespace std;


// += ������ �ߺ�
// 
// ���� ���� ���������� += �����ڴ� + �����ڿ� �޸� �ణ�� ���ǰ� �ʿ��ϴ�.
// 
// * ������ �Լ� ����
// 
// +=�� ������ ������ ��ü�� �����ϴ� ���� �ƴ� ���纻�� �����ϰ� �ȴ�. �� ������ �ذ��ϱ� ���ؼ��� (a+=b) ������ ��ü a�� ������
// �����ϸ� �ȴ�. �׷��Ƿ� += �������� ���� Ÿ���� Power&���� �ؾ� �Ѵ�.
// 
// a.+=(b);
// 
// Power ��ü a�� operator +=() �Լ��� ȣ���ϰ� ��ü b�� �Ű������� �ѱ��.
//


class Power {
	int kick;
	int punch;
	string word;
public:
	Power(int kick = 0, int punch = 0,string word="") {
		this->kick = kick;
		this->punch = punch;
		this->word = word;
	}
	void show();
	Power& operator +=(Power op2);
};



void Power::show() {
	cout << "kick= " << kick << "punch= " << punch<< word<<endl;
}

// operator += () ������ �Լ��� ������ ���� �����ȴ�.

Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;
	word += op2.word;
	return *this;	// ���� Ÿ���� Power& �̹Ƿ� ��ü �ڽ��� ������ ���ϵȴ�.
}
int main() {
	Power a(3, 5,"��"), b(4, 6,"����"), c;
	a.show();
	b.show();
	c = a+=b;
	a.show();
	c.show();
}
