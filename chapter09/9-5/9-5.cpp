#include <iostream>
using namespace std;


//
// ���� �Ҹ���
// 
// �⺻ Ŭ������ �Ҹ��ڸ� ���� �� ���� �Լ��� �ۼ��� ���� ���Ѵ�. �� ������ �Ļ� Ŭ������ ��ü�� �⺻ Ŭ������ ���� �����ͷ� delete �Ǵ� ��Ȳ������
// �������� �Ҹ��� �ǵ��� �ϱ� ���ؼ��̴�.
// 
// 
// * �Ҹ��ڸ� ���� �Լ��� �������� ���� ���
// 
// class Base{
// public:
// ~Base();
// };
// 
// class Derived : public Base{
// 
//	public:
//		~Derived();
// }
// 
// int main(){
//  Base *p=new Derived();
//	delete p;
// }
// 
// p�� Base Ÿ���̹Ƿ� �����Ϸ��� ~Base() �Ҹ��ڸ� ȣ���ϵ��� �������Ѵ�. �׷��Ƿ� ~Base()�� ����ǰ� ~Derived()�� ������� �ʴ´�.
// 
// 
// * �Ҹ��ڸ� ���� �Լ��� ������ ������ ���
// 
// class Base{
//	public:
// virtual ~Base();
// };
// 
// class Derived : public Base{
// public:
// virtual ~Derived();
// };
// 
// int main(){
// Base *p=new Derived();
// delete p;
// }
// 
// 
// �Ҹ��ڸ� ���� �Լ��� �����ϸ�, ~Base()�� ���� ȣ���� ���� �߿� ���� ���ε��� ���� ~Derived()�� ���� ȣ��� ���ϰ� �Ǿ� ~Derived()��
// ����ȴ�. ~Derived() �ڵ� ���� �� ~Base() �ڵ尡 ����Ǿ� �⺻ Ŭ������ �Ļ� Ŭ������ �Ҹ��ڰ� ��� ������� ����ȴ�.
// 
// 
// �����ϸ�, �Ҹ��ڸ� ���� �Լ��� �����ϸ�, ��ü�� �⺻ Ŭ������ �����ͷ� �Ҹ��ϵ�,
// �Ļ� Ŭ������ �����ͷ� �Ҹ��ϵ� �Ļ� Ŭ������ �⺻ Ŭ������ �Ҹ��ڸ� ��� �����ϴ�
// �������� �Ҹ��� ������ ����ȴ�.
// 
// ���ڵ��� �⺻ Ŭ������ �Ҹ��ڸ� �ۼ��� ��, ����� �� ���� �ٷ� virtual�� �����ؾ� �Ѵ�.
// 
//

class Base {
public:
	virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base {
public:
	virtual ~Derived() { cout << "~Derived()" << endl; }
};

int main() {
	Derived* dp = new Derived();
	Base* bp = new Derived();

	delete dp;	// Derived�� �����ͷ� �Ҹ�
	delete bp;	// Base�� �����ͷ� �Ҹ�
}