#include <iostream>
using namespace std;

//
// * 참조 매개 변수로 인한 모호성
// 
// 중복된 함수 중에서 참조 매개 변수를 가진 함수가 있는 경우, 이들 사이에 모호성이 존재할 수 있다.
// 중복된 다음 두 함수를 보자.
// 
// 
//


int add(int a, int b) {
	return a + b;
}

int add(int a, int &b) {
	b = b + a;
	return b;
}

int main() {
	int s = 10, t = 20;
	cout << add(s, t); // 컴파일 오류. 참조 매개 변수로 인해 함수 호출이 모호함.
}