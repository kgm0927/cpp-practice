#include <iostream>
using namespace std;

//
// static의 특성
// 
// static 키워드: 변수와 함수의 생명 주기(life cycle)와 사용 범위(scope)를 지정하는 방식(storage class) 중 하나로써,
// static으로 선언된 변수와 함수의 생명 주기와 사용 범위는 다음과 같은 특징을 가진다.
// 
//  -생명 주기 - 프로그램이 시작할 때 생성되고 프로그램이 종료할 때 소멸
//	-사용 범위 - 변수나 함수가 선언된 범위 내에서 사용. 전역(global) 혹은 지역 으로 구분
// 
// static 멤버는 객체의 멤버이지만, 객체가 생기기 전에 이미 생성되어 있고 객체가 사라져도
// 소멸되지 않는다.
// 
// * static 멤버 선언
// 모든 멤버들이 static으로 선언될 수 있르며, static 멤버들은 private, public, protected 등 어떤 접근 지정도 가능하다.
// 
// * static 멤버 변수는 외부에 전역(global) 변수로 선언되어야 한다.
// 
// static 멤버 변수는 변수의 공간을 할당받는 선언문이 추가적으로 필요하다. 이 선언문은 클래스 바깥의 전역 공간에 선언되어야 한다.
//




class Person {
public:
	int money; // 개인 소유의 돈
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney; // 공금
	static void addShared(int n) {
		sharedMoney += n;
	}


};
// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10;//10으로 초기화

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