#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


//* ����Ʈ ���� ������
// ���� Circle Ŭ������ ���� �����ڸ� ������ ���� �ʴ�.
//
// �����Ϸ��� �����ϴ� ����Ʈ ���� ������ �ڵ�� ���� ���� ���縦 �ϵ��� �Ѵ�. Ŭ������ ��� ������ radius �ϳ� ���̹Ƿ�
// radius ���� �����ϴ� �ڵ�� �����Ǿ� �ִ�.
// 
// Circle::Circle(const Circle& c){
// 
// this->radius=radius;
// 
//	}
// 
// * ���� ���� �������� ������
// 
// ������ Ÿ���� ��� ������ ���� Ŭ������ ���, ���� ����� ���� ������ ����. ��� ��� ������ �ϴ��Ϸ� �����ص�
// ������ ������ �߻����� �ʱ� �����̴�. �׷��� Ŭ������ ������ ��� ������ ������ �ִ� ���, ���� ��ü�� ������ ��� 
// ������ �纻 ��ü�� ������ ��� ������ ����Ǹ�, �� ���� ���� �޸𸮸� ����Ű�� �Ǿ� �ɰ��� ������ �߱��Ѵ�.
// 
//

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);
	~Person();
	void changeName(const char* name);
	void show() { cout << id << ',' << name << endl; }

	// ���� ���� �����ڰ� �������� �ʰ�, ����Ʈ�� ����Ѵ�.
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name,name);
}

Person::~Person() {
	if (name)
	{
		delete[] name;
	}
}


void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name))
		return;

	strcpy(this->name, name);
}

int main() {
	Person father(1, "Kitae");
	Person daugther(father);

	cout << "daughter ��ü ���� ���� ----" << endl;

	father.show();
	daugther.show();

	daugther.changeName("Grace");
	cout << "daughter �̸��� Grace�� ������ �� ----" << endl;
	father.show();
	daugther.show();


	return 0;
}