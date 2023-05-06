#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


//* 디폴트 복사 생성자
// 밑의 Circle 클래스는 복사 생성자를 가지고 있지 않다.
//
// 컴파일러가 삽입하는 디폴트 복사 생성자 코드는 소위 얕은 복사를 하도록 한다. 클래스의 멤버 변수가 radius 하나 뿐이므로
// radius 값만 복사하는 코드로 구성되어 있다.
// 
// Circle::Circle(const Circle& c){
// 
// this->radius=radius;
// 
//	}
// 
// * 얕은 복사 생성자의 문제점
// 
// 포인터 타입의 멤버 변수가 없는 클래스의 경우, 얕은 복사는 전혀 문제가 없다. 모든 멤버 변수를 일대일로 복사해도
// 공유의 문제가 발생하지 않기 때문이다. 그러나 클래스가 포인터 멤버 변수를 가지고 있는 경우, 원본 객체의 포인터 멤버 
// 변수가 사본 객체의 포인터 멤버 변수에 복사되면, 이 둘은 같은 메모리를 가리키게 되어 심각한 문제를 야기한다.
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

	// 따로 복사 생성자가 존재하지 않고, 디폴트로 사용한다.
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

	cout << "daughter 객체 생성 직후 ----" << endl;

	father.show();
	daugther.show();

	daugther.changeName("Grace");
	cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
	father.show();
	daugther.show();


	return 0;
}