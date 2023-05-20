#include <iostream>
using namespace std;



//
// 10.2 다양한 제네릭 함수 만들기
// 
// * 두 개의 매개 변수로부터 큰 값 구하기
// 
// 두 수를 매개 변수로 받아 큰 값을 리턴하는 제네릭 함수 bigger()를 만들어보자.
// bigger()는 2개의 매개 변수와 리턴 타입이 동일하니, bigger() 함수의 템플릿 원형은 이러하다.
// 
// template <class T>
// T bigger(T a,T b);
// 
// 
//

template <class T>
T bigger(T a, T b) {
	if (a > b)return a;
	else return b;
}

int main() {
	int a = 20, b = 50;

	char c = 'a', d = 'z';

	cout << "bigger(20,50)의 결과는" << bigger(a, b) << endl;
	cout << "bigger('a','z')의 결과는" << bigger(c, d) << endl;
}