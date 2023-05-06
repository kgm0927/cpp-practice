#include <iostream>
using namespace std;


int sum(int a, int b) {// a에서 b까지 합하기.
	int s = 0;
	for (int i = a; i <= b; i++)
	{
		s += i;
	}
	return s;
}

int sum(int a) { //0에서 a까지 합하기.
	int s = 0;
	for (int i = 0; i <= a; i++)
	{
		s += i;
	}
	return s;
}

int main() {
	cout << sum(3, 5) << endl;
	cout << sum(3) << endl;
	cout << sum(100) << endl;

}

//
//  생성자 함수 중복
// 
// 이와 같이 생성자 함수도 중복이 가능하다. 이러한 이유는 객체를 생성할 때 매개 변수를 통하여 다양한 형태로 초깃값을 전달하기 위해 생성자 함수를 중복
// 선언한다. 예를 들어 C++ 표준의 string 클래스는 다음과 같은 다양한 생성자를 제공하여, 사용자가 다양한 초깃값으로 string 객체를 생성할 수 있도록 한다.
// 
// 
// 소멸자 함수는 중복이 불가능하다.
//