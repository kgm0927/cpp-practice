#include <iostream>
using namespace std;

//
// ���� ������ �ߺ�
// 
// ���� �����ڴ� �������� ��ġ�� ���� ���� ������(prefix operator)�� ���� ������(postfix operator)�� ������.
// 
// 
// *���� ++ ������ �ߺ�
// 
// ���� ++ �������� ��ʷ� ���� �����ڸ� �ߺ��ϴ� ����� ���ؼ� �˾ƺ���.
// 
// ++a ���� ��ü a�� ��� ������� ���� 1�� ������Ų ��, ����� ��ü a�� ������ �����ϴ� ������ �����Ѵ�.
// 
// * ������ �Լ� ����
// 
// �����Ϸ��� ++a ���� ������ ���� �����Ͽ� Power Ŭ������ ����� operator++() ������ �Լ��� ȣ���Ѵ�.
// 
// a.++();
// 
// �� ȣ���� �����ϵ��� �ϱ� ���� , �Ű� ���� ���� operator++() ������ �Լ��� ������ ���� �����Ѵ�. ���� Ÿ���� Power& �̴�.
// 
// * ������ �����ϴ� ������ �Լ� ����
// 
// operator++() ������ �Լ��� ������ ���� �ڽ��� kick�� punch�� ���� ���� 1�� ������Ų ��, �ڽ�(*this)�� ���� ������ �����Ѵ�.
// 
//

class Power {
	int kick;
	int punch;
	int score;
public:
	Power(int kick=0,int punch=0,int score=0) {
		this->kick = kick;
		this->punch = punch;
		this->score = score;
	}
	void show();
	Power& operator++();

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch <<"score="<<score<< endl;
}

Power& Power::operator++() {// ���� ++������ ��� �Լ� ����
	kick++;
	punch++;
	for (int i = 0; i < 10; i++)
	{
		score++;
	}
	return *this;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a; //���� ������ ���

	a.show();
	b.show();
}