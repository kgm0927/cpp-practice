#include <iostream>
using namespace std;

// *함수 중복의 모호성
// 이는 3가지 종류가 있다.
//
// - 형 변환으로 인한 모호성
// - 참조 매개 변수로 인한 모호성
// - 디폴트 매개 변수로 인한 모호성
// 
// 
// * 형 변환으로 인한 모호성
// 
// 일반적으로 함수의 매개 변수 타입과 호출 문의 실인자 타입이 일치하지 않는 경우,
// 컴파일러는 호이지 않게 형 변환(type conversion)을 시도한다.
// 
// double square(double a);
// square(3);
// 
// 실인자는 3인 int 타입이지만,컴파일러는 double 타입으로 형 변환하여 square() 함수 호출에 문제가 없게 한다.
// 
// 컴파일러는 다음과 같이 작은 타입을 큰 타입으로 자동 형 변환한다. 
// 
// char -> int -> long -> float -> double
// 
// 
//


// 밑의 함수처럼  2개의 중복된 square() 함수가 작성되어 있는 경우,
//  컴파일 오류가 발생한다.
//
float square(float a) {
	return a * a;
}

double square(double a) {
	return a * a;
}

int main() {
	cout << square(3.0); //square(double a); 호출
	cout << square(3); // 중복된 함수에 대한 모호한 호출로서, 컴파일 오류
}