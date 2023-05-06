#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 묵시적 복사 생성

// 지금까지 다룬 아래 코드는 명시적으로 father를 원본으로 daughter를 복사 생성하기 때문에, 복사 생성자가
// 호출될 것을 독자들이 인지할 가능성이 매우 높다.

// Person daughter(father); // 복사 생성자를 명시적으로 호출하는 사례

// 그러나 개발자도 모르게 복사 생성자가 호출되는 다른 경우들이 있다. 그렇게 되서 디버깅에 애를 먹는 경우가 있는데,
// 이런 경우에 대비하여 가능하면 깊은 복사 생성자를 구현해 놓아야 한다.
// 
// 묵시적 복사 생성의 경우는 다음 3가지이다.
// 
// 
// 
// 1. 객체로 초기화하여 객체가 생성될 때
// 
// 다음은 son 객체를 생성할 때 father 객체로 초기화하도록 하는 선언문이다.
// 
// person son=father;
// 
// 컴파일러는 이 문장을 다음과 같이 변환하여 복사 생성자를 호출한다.
// Person son(father);
// 
// 이것은 다음의 치환문과 혼돈해선 안된다.
// 
// Person son;
// son=father;
// 
// 
// 
// 2. '값에 의한 호출'로 객체가 전달될 때
// 
// '값에 의한 호출'로 객체가 전달되면, 함수의 매개 변수 객체가 생성될 때 복사 생성자가 자동으로 호출된다.
// 
// void f(Person person){
//  .....
// }
// 
// Person father(1,"Kitae");
// f(father);
// 
// 함수 f()가 호출되어 매개 변수 person이 생성이 될 때, 다음과 유사한 모양으로 복사 생성자가 호출되도록 컴파일된다.
// 
// Person person(father);
// 
// 
// '값에 의한 호출'로 매개 변수가 생성될 때, 생성자가 실행되지 않는다. 대신 복사 생성자가 생성이 된다. 그리고 복사 생성자가 구현되지 않을 경우
// , 컴파일러가 삽입한 디폴트 복사 생성자가 실행된다.
// 
// 
// 3. 함수가 객체를 리턴할 때
// 
// 함수가 객체를 리턴할 때, return 문은 객체의 복사본을 생성하여 호출한 것으로 전달한다.
// 이 때 복사 생성자가 호출된다.
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

Person::Person(int id, const char* name) {// 생성자
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

Person::Person(const Person& person) {// 복사 생성자

	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "복사 생성자 실행. 원본 객체 " << this->name << endl;
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

void f(Person person) {// 2.'값에 의한 호출'로 객체가 전달될 때, person 객체의 복사 생성자로 호출
	person.changeName("dummy");
}

Person g() {	
	Person mother(2,"Jane");
	return mother; // 함수에서 객체를 리턴할 때. mother 객체의 복사본 생성. 복사본의 복사 생성자 호출
}

int main() {
	Person father(1, "kitae");
	Person son = father;// 복사 생성자 호출 // 객초로 초기화하여 객체가 생성될 때, son 객체의 복사 생성자 호출
	f(father);
	g();
}

// 연산자 중복을 이용해서 깊은 복사가 가능하지 않을 까?
