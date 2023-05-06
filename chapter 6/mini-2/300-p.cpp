#include <iostream>
using namespace std;

// 300.page 

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
int Person::sharedMoney = 10; // 10���� �ʱ�ȭ


// main() �Լ�
int main() {
	Person han;
	han.money = 100; // han�� ���� �� =100
	han.sharedMoney = 200; // static ��� ���� ����=200

	Person lee;
	lee.money = 150;	// lee �� ���� �� =150
	lee.addMoney(200);	// lee �� ���� �� =350
	lee.addShared(200); // static ��� ����, ����=400

	cout << han.money << lee.money << endl;
	cout << han.sharedMoney << lee.sharedMoney << endl;
}

// *static ��� ���: Ŭ������� �������� ������(::)�� ����
//
// ������ ���� Ŭ���� �̸��� static ��� ���̿� ���� ���� ������(::)�� ����Ͽ� static ����� �����Ѵ�.
// 
// Ŭ������::static ���
// 
// ��ü �̸����� sharedMoney�� addShared() ����� �����ϴ� �ڵ�� ������ ���� Person Ŭ���������� �ٷ� ������ �� �ִ�.
// 
//		han.sharedMoney=200;		<-> Person::sharedMoney=200; // ������ ǥ��
//		lee.addShared(200);			<-> Person::sharedMoney=(200);	// ������ ǥ��
// 
// �׷��� �ν��Ͻ� ����δ� Ŭ���������� ������ �Ұ��ϴ�.
// 
//