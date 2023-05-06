#include <iostream>
using namespace std;

//
// static�� Ư��
// 
// static Ű����: ������ �Լ��� ���� �ֱ�(life cycle)�� ��� ����(scope)�� �����ϴ� ���(storage class) �� �ϳ��ν�,
// static���� ����� ������ �Լ��� ���� �ֱ�� ��� ������ ������ ���� Ư¡�� ������.
// 
//  -���� �ֱ� - ���α׷��� ������ �� �����ǰ� ���α׷��� ������ �� �Ҹ�
//	-��� ���� - ������ �Լ��� ����� ���� ������ ���. ����(global) Ȥ�� ���� ���� ����
// 
// static ����� ��ü�� ���������, ��ü�� ����� ���� �̹� �����Ǿ� �ְ� ��ü�� �������
// �Ҹ���� �ʴ´�.
// 
// * static ��� ����
// ��� ������� static���� ����� �� �ָ���, static ������� private, public, protected �� � ���� ������ �����ϴ�.
// 
// * static ��� ������ �ܺο� ����(global) ������ ����Ǿ�� �Ѵ�.
// 
// static ��� ������ ������ ������ �Ҵ�޴� ������ �߰������� �ʿ��ϴ�. �� ������ Ŭ���� �ٱ��� ���� ������ ����Ǿ�� �Ѵ�.
//




class Person {
public:
	int money; // ���� ������ ��
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney; // ����
	static void addShared(int n) {
		sharedMoney += n;
	}


};
// static ���� ����. ���� ������ ����
int Person::sharedMoney = 10;//10���� �ʱ�ȭ

int main() {
	Person han;
	han.money = 100;
	han.sharedMoney = 200;

	Person lee;
	lee.money = 150;
	lee.addMoney(200);
	lee.addShared(200);

	cout << han.money <<' ' << lee.money << endl;
	cout << han.sharedMoney<<' ' << lee.sharedMoney << endl;

}