#include <iostream>
#include <string>
using namespace std;



//
// 
// auto�� ���ٽ� ���� �� ȣ��
// 
// ���ٽ��� ������ �����Ϸ����� �˷��� �ֱ� ������, �����ڰ� ���ٽ��� �����ϴ� ������ ���� ������ �� ����.
// auto�� �̿��ϸ� ���ٽ��� �����ϴ� ������ ���� ������ �� �ִ�.
// 
//
int main() {
	auto love = [](string a, string b) {
		cout << a << "���� " << b << "�� ����" << endl;
	};

	love("��", "��");
	love("�ø�", "����");


}