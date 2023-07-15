#include<iostream>
#include <vector>
using namespace std;

int square(int x) { return x * x; }

//
// 10.5 auto�� ���ٽ�
// 
// 
// 
// 
// auto�� �̿��� ���� ���� ����
// 
// auto Ű����� C++ ǥ�غ��� �ǹ̰� �����Ǿ�, ���� �������κ��� ������ Ÿ���� �߷��Ͽ�
// �����ϵ��� �����Ѵ�.
// 
// 
// 
// 
// 
// 
// 
// 
// 
// * �⺻ ���
// 
// ������ auto�� �̿��Ͽ� ���� pi�� �Ǽ� 3.14�� �ʱ�ȭ�ϴ� �����̴�.
// 
// auto pi=3.14;
// 
// 
// 
// 
// 
// �����Ϸ��� 3.14f�κ��� �߷��� ��� pi�� double Ÿ������ �����Ѵ�. auto�� ����ϴ�
// �ٸ� ���� ��� ������ ����.
// 
// auto n=3;	// 3�� �����̹Ƿ� n�� int��
// auto *p=&n;	// ���� p�� int* Ÿ������ �ڵ� ����
// 
// 
// 
// 
// 
// 
// 
// 
// ���� ������ ���� ���� ���� ���𿡵� auto�� ����� �� �ִ�.
// 
// 
// int n=10;
// int & ref=n;
// auto ref2=ref;
// 
// 
// * �Լ��� ���� Ÿ������ �߷��Ͽ� ���� Ÿ�� ����
// 
// int square(int x) {return x*x}
// 
// auto ret=square(3);
// 
// �����Ϸ��� square()�� ���� Ÿ���� int �̹Ƿ� ���� ref�� Ÿ���� int�� �߷��Ѵ�.
// 
// 
// 
// 
// 
// 
// 
// * STL ���ø��� Ȱ��
// 
// auto�� vector, map ���� ���ø��� ����ϸ� ������ ���� ������ ����ȭ�� �� �ִ�.
// 
// vector<int> v={1,2,3,4,5};
// 
// iterator�� �̿��Ͽ� ���� v�� ���Ҹ� ����Ϸ��� ���� ���� �ڵ带 �ۼ��Ѵ�.
// 
// vector<int>::iterator it;	// ������ ����� it ���� ����
// for(it=v.begin(); it!=v.end(); it++)
// cout<<*it<<endl;
// 
// 
// 
// �� �ڵ�� auto�� �̿��Ͽ� ���� it�� �����ϸ� ������ ���� ������ �ۼ��� �� �ִ�.
// 
// for(auto it=v.begin(); it != v.end(); it++)	// ���� it�� vector<int>::iterator
//		cout<<*it<<endl;						// Ÿ������ �߷е�
// 
//


int main() {

	// �⺻ Ÿ�� ���� auto Ȱ��

	auto c = 'a';		// c�� char Ÿ������ ����
	auto pi = 3.14;		// pi�� double Ÿ������ ����
	auto ten = 10;		// ten�� int Ÿ������ ����
	auto* p = &ten;		// ���� p�� int* Ÿ������ ����

	cout << c << " " << pi << " " << ten << " " << *p  << endl;


	// �Լ��� ���� Ÿ������ �߷�
	auto ret = square(3);	// square() �Լ��� ���� Ÿ���� int�̹Ƿ� ret�� int�� ����
	cout << *p << " " << ret << endl;

	vector<int> v = { 1,2,3,4,5 };	// ���� v�� 5���� ����, 1,2,3,4,5 ����
	vector<int>::iterator it;

	for ( it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
		cout << endl;

	}



	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
}