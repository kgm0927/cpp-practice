#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������ ���� ����

// ���ݱ��� �ٷ� �Ʒ� �ڵ�� ��������� father�� �������� daughter�� ���� �����ϱ� ������, ���� �����ڰ�
// ȣ��� ���� ���ڵ��� ������ ���ɼ��� �ſ� ����.

// Person daughter(father); // ���� �����ڸ� ��������� ȣ���ϴ� ���

// �׷��� �����ڵ� �𸣰� ���� �����ڰ� ȣ��Ǵ� �ٸ� ������ �ִ�. �׷��� �Ǽ� ����뿡 �ָ� �Դ� ��찡 �ִµ�,
// �̷� ��쿡 ����Ͽ� �����ϸ� ���� ���� �����ڸ� ������ ���ƾ� �Ѵ�.
// 
// ������ ���� ������ ���� ���� 3�����̴�.
// 
// 
// 
// 1. ��ü�� �ʱ�ȭ�Ͽ� ��ü�� ������ ��
// 
// ������ son ��ü�� ������ �� father ��ü�� �ʱ�ȭ�ϵ��� �ϴ� �����̴�.
// 
// person son=father;
// 
// �����Ϸ��� �� ������ ������ ���� ��ȯ�Ͽ� ���� �����ڸ� ȣ���Ѵ�.
// Person son(father);
// 
// �̰��� ������ ġȯ���� ȥ���ؼ� �ȵȴ�.
// 
// Person son;
// son=father;
// 
// 
// 
// 2. '���� ���� ȣ��'�� ��ü�� ���޵� ��
// 
// '���� ���� ȣ��'�� ��ü�� ���޵Ǹ�, �Լ��� �Ű� ���� ��ü�� ������ �� ���� �����ڰ� �ڵ����� ȣ��ȴ�.
// 
// void f(Person person){
//  .....
// }
// 
// Person father(1,"Kitae");
// f(father);
// 
// �Լ� f()�� ȣ��Ǿ� �Ű� ���� person�� ������ �� ��, ������ ������ ������� ���� �����ڰ� ȣ��ǵ��� �����ϵȴ�.
// 
// Person person(father);
// 
// 
// '���� ���� ȣ��'�� �Ű� ������ ������ ��, �����ڰ� ������� �ʴ´�. ��� ���� �����ڰ� ������ �ȴ�. �׸��� ���� �����ڰ� �������� ���� ���
// , �����Ϸ��� ������ ����Ʈ ���� �����ڰ� ����ȴ�.
// 
// 
// 3. �Լ��� ��ü�� ������ ��
// 
// �Լ��� ��ü�� ������ ��, return ���� ��ü�� ���纻�� �����Ͽ� ȣ���� ������ �����Ѵ�.
// �� �� ���� �����ڰ� ȣ��ȴ�.
//


class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
	Person(const Person& person);
	~Person();
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, const char* name) {// ������
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::Person(const Person& person) {// ���� ������

	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "���� ������ ����. ���� ��ü " << this->name << endl;
}

Person::~Person() {
	if (name)
		delete[] name;
}

void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name))
		return;
	strcpy(this->name, name);
}

void f(Person person) {// 2.'���� ���� ȣ��'�� ��ü�� ���޵� ��, person ��ü�� ���� �����ڷ� ȣ��
	person.changeName("dummy");
}

Person g() {	
	Person mother(2,"Jane");
	return mother; // �Լ����� ��ü�� ������ ��. mother ��ü�� ���纻 ����. ���纻�� ���� ������ ȣ��
}

int main() {
	Person father(1, "kitae");
	Person son = father;// ���� ������ ȣ�� // ���ʷ� �ʱ�ȭ�Ͽ� ��ü�� ������ ��, son ��ü�� ���� ������ ȣ��
	f(father);
	g();
}

// ������ �ߺ��� �̿��ؼ� ���� ���簡 �������� ���� ��?
