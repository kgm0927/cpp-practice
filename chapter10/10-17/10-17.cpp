#include <iostream>
using namespace std;

//
// 
// 캡쳐 리스트와 리턴 타입을 가지는 람다식 만들기
// 
// 람다식은, 캡쳐 리스트를 이용하여 주변의 non-static 변수들(지역 변수나 멤버 변수)에 대해
// 값을 복사하여 받거나 참조를 활용할 수 있다.
// 
// 예제 10-17 코딩은 람다식이 캡쳐 리스트를 통하여 외부 변수의 값을 전달받는 사례.
//



int main() {
	double pi = 3.14;
	auto calc = [pi](int r)->double{return pi * r * r; };
	cout << "면적은" << calc(3);
}