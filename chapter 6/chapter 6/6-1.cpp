#include <iostream>
using namespace std;


//
// 6.1 함수 중복
// 
// c++에서는 같은 이름의 함수를 여러개 만드는 것이 가능하다.(c에서는 불가능하다.)이를 함수 중복(function overloading)이라고 부른다.
// 함수 중복은 다형성의 한 사례로, 전역 함수와 멤버 함수 모두에 적용이 되며, 상속 관계에 있는 기본 클래스와 파생 클래스 사이에도 허용된다.
// C 언어가 중복이 되지 않는 이유는 나중에 설명한다.
// 
// 
// * 중복 함수 조건
// 
// 다음과 같은 조건이 모두 만족되어야 한다.
// 
// - 중복된 함수들의 이름이 동일해야 한다.
// - 중복된 함수들은 매개 변수 타입이나 매개 변수의 개수가 달라야 한다.
// - 함수 중복에 리턴 타입은 고려되지 않는다.
// 
// * 함수 중복 실패 사례
// 
// 컴파일러는 중복된 함수를 구분할 때 리턴 타입은 고려하지 않는다. 즉 매개변수의 개수와 타입이 같고, 
// 리턴 타입이 다를 경우, 이는 오류 처리 된다.
//


int big(int a, int b) { // a와 b 중 큰 수 리턴
	if (a > b) return a;
	else return b;
}

int big(int a[], int size) {  // 배열 a[]에서 가장 큰 수 리턴
	int res = a[0];
	for (int i = 1; i < size; i++)
		if (res < a[i])res = a[i];

	return res;
}

int main() {
	int array[5] = { 1,9,-2,8,6 };
	cout << big(2, 3) << endl; // int big(int a, int b) 호출
	cout << big(array, 5) << endl; // int big(int a[],int size) 호출
}