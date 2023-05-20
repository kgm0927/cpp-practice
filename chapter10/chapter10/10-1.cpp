#include <iostream>
using namespace std;


//
// 10.1 일반화와 템플릿
// 
// 함수 중복은 편리하지만 약점도 있다. 중복된 myswap() 함수를 보자.
// 
// 
// 
// 일반화와 템플릿 선언
// 
// 템플릿(template)이란 국어사전에서 '형판'이란 뜻이다. 다른 말로 '본 떠 찍어내기 위해
// 만들어진 틀' 정도로 해석할 수 있다. C++ 언어에도 템플릿의 개념이 있다. C++ 템플릿은 함수나 템플릿은
// 함수나 클래스 코드를 찍어내듯이 생산할 수 있도록 일반화(generic)시키는 도구이다.
// 
// 
// 
// * 중복 함수의 일반화
// template 키워드를 이용하면, 중복 함수들을 일반화시킨 특별한 함수를 만들 수 있다.
// 이를 템플릿 함수(template function) 혹은 제네리 함수(generic function)라고 부른다.
// 
// 
// 
// * 템플릿 선언과 제네리 타입
// 
// 템플릿 함수나 클래스를 작성할 때, 다음과 같이 template이란 키워드로 시작하여 <class T>나 <typename T>를 선언한다.
// 
// template <class T>
// template <typename T>
// 
// 
// 제네릭 타입(generic type)이란 C++의 기본 타입은 아니며, 이들을 일반화시킨 새로운 타입으로 일반 타입이라고
// 부르기도 한다. 다음은 T1, T2, T3의 3개의 제네릭 타입을 선언한 타입이다.
// 
// template <class T1, class T2, class T3>
// 
// 
// 그리고 템플릿 선언부는 다음과 같이 한 줄에 붙여 써도 상관이 없다.
// 
// template <class T> void myswap(T &a,T &b){
//  ...
// }
// 
// * 템플릿으로부터의 구체화
// 
// 구체화(specialization): 중복 함수들을 템플릿화하는 과정의 역과정
// 
// 컴파일러가 함수의 호출문을 컴파일 할 때, 구체화를 통해 제네릭 함수로부터 구체적인 함수의 소스코드를 만들어낸다.
// 
// 
// 
// 
// 구체화 과정을 보여주며, 자세히 설명하면 다음과 같다.
// 
// 1. 컴파일러는 myswap(a,b); 호출문을 컴파일할 때 myswap()함수를 찾는다.
// 2. 템플릿으로 선언된 myswap() 함수를 발견한다.
// 
// 
// 3. 구체화한다. 컴파일러는 myswap(a,b);의 함수 호출문에서 실인자 a,b 모두 int 타입이므로, 템플릿의 제네릭 타입 T에
// int를 적용시켜 구체화된 버전의 myswap(int &a,int &b)의 소스 코드를 만들어 낸다.
// 
// 4. 구체화된 함수의 소스 코드를 컴파일하고, 이 함수를 호출하도록 컴파일한다.
//
class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
};

template <class T>
void myswap(T& a, T& b) {// 제네릭 함수
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int a = 4,  b = 5;
	myswap(a,b);
	cout << "a=" << a << ", " << "b=" << b << endl;

	double c = 0.3, d = 12.5;
	myswap(c, d);
	cout << "c=" << c << "d=" << d << endl;

	Circle donut(5), pizza(20);
	myswap(donut, pizza);
	cout << "donut반지름=" << donut.getRadius() << ", ";
	cout << "pizza반지름=" << pizza.getRadius() << endl;

}

//
// 템플릿 역할
// 템플릿 함수는 컴파일되지도 호출되지도 않는, 그저 함수의 틀이다. 템플릿 역할은 제네릭 함수를 선언하고
// , 컴파일 시점에 구체화시키기 위한 틀을 만드는 것이다.
//