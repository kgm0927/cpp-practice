#include <iostream>
using namespace std;


// 참조 개념
// C++ 에서는 C언어에는 없는 참조(reference) 개념을 도입하였다. 포인터 변수를 선언하기 위해 * 기호를 사용하지만,
// 선언하기 위해서는 & 기호를 사용한다. &를 참조자라고 부른다.
// 
// 참조 변수(reference variable)dms 한 '사람'에게 붙이 별명처럼 이미 선언된 변수에 대한 별명(alias)이다.(또 다른 이름)
// 
// * 참조 변수
// 
// 참조 변수는 이미 선언된 변수에 대한 별명으로써, 참조자(&)를 이용하여 선언하며, 선언시 반드시 원본 변수로 초기화하여야 한다.
// 밑의 예제는 참조 변수 refn과 refc를 선언하는 코드이다.
// 
// int n=2;
// int &refn=n;
// 
// Circle circle;
// Circle &refc=circle;
// 
// refn은 이미 선언된 변수 n에 대한 별명이며, refc는 circle 객체에 대한 별명이다. refn과 refc는 따로 변수 공간을 가지지 않고,
// 각각 n과 circle을 공유한다.
// 
// Tip) 참조 변수는 포인터가 아니므로, 다음과 같이 사용하지 않도록 주의한다.
// 
// refc-> setRadius(30);
//
int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;

	int& refn = n;
	n = 41;

	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	refn = i;
	refn++;
	i = 3;
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn;
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;
}