#include <iostream>
using namespace std;

// 300.page 

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
int Person::sharedMoney = 10; // 10으로 초기화


// main() 함수
int main() {
	Person han;
	han.money = 100; // han의 개인 돈 =100
	han.sharedMoney = 200; // static 멤버 접근 공금=200

	Person lee;
	lee.money = 150;	// lee 의 개인 돈 =150
	lee.addMoney(200);	// lee 의 개인 돈 =350
	lee.addShared(200); // static 멤버 접근, 공금=400

	cout << han.money << lee.money << endl;
	cout << han.sharedMoney << lee.sharedMoney << endl;
}

// *static 멤버 사용: 클래스명과 범위지정 연산자(::)로 접근
//
// 다음과 같이 클래스 이름과 static 멤버 사이에 범위 지정 연산자(::)를 사용하여 static 멤버를 접근한다.
// 
// 클래스명::static 멤버
// 
// 객체 이름으로 sharedMoney와 addShared() 멤버를 접근하는 코드는 다음과 같이 Person 클래스명으로 바로 접근할 수 있다.
// 
//		han.sharedMoney=200;		<-> Person::sharedMoney=200; // 동일한 표현
//		lee.addShared(200);			<-> Person::sharedMoney=(200);	// 동일한 표현
// 
// 그러나 인스턴스 멤버로는 클래스명으로 접근이 불가하다.
// 
//