#include <iostream>
using namespace std;
// 참조에 의한 호출 call by reference

// 참조는 c++의 새로운 인자 전달 방식인 '참조에 의한 호출'에 많이 사용된다.

//'참조에 의한 호출'은 함수의 매개 변수를 참조 타입으로 선언하며, 매개 변수가 함수를 호출하는 쪽의
// 실인자를 참조(reference)하여 실인자와 공간을 공유하도록 하는 인자 전달 방식이다. 이 참조 타입으로 선언된
// 함수의 매개 변수를 참조 매개 변수(reference parameter)라고 부른다.
//
// 
// 
//
void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int m = 2, n = 9;
	swap(m, n);
	cout << m << ' ' << n;
}
// swap() 함수가 호출이 되면, 참조 매개 변수 a,b는 실인자 m,n을 참조하돌고 초기화
// 되며,  함수 내에서는 보통 변수처럼 사용한다. 변수 m,n은 main() 스택에 생성되지만,
// 참조 매개 변수 a,b는 이름만 존재하며 swap()의 스택에 공간을 할당받지 않는다. swap() 함수가
// 실행되어 a와 b의 값이 교환이 되면, 결과적으로 m과 n의 값이 교환된다.
//
