#include<iostream>
#include <vector>
using namespace std;

int square(int x) { return x * x; }

//
// 10.5 auto와 람다식
// 
// 
// 
// 
// auto를 이용한 쉬운 변수 선언
// 
// auto 키워드는 C++ 표준부터 의미가 수정되어, 변수 선언문으로부터 변수의 타입을 추론하여
// 결정하도록 지시한다.
// 
// 
// 
// 
// 
// 
// 
// 
// 
// * 기본 사례
// 
// 다음은 auto를 이용하여 변수 pi를 실수 3.14로 초기화하는 선언문이다.
// 
// auto pi=3.14;
// 
// 
// 
// 
// 
// 컴파일러는 3.14f로부터 추론한 결과 pi를 double 타입으로 결정한다. auto를 사용하는
// 다른 예를 들면 다음과 같다.
// 
// auto n=3;	// 3이 정수이므로 n을 int로
// auto *p=&n;	// 변수 p는 int* 타입으로 자동 선언
// 
// 
// 
// 
// 
// 
// 
// 
// 또한 다음과 같이 참조 변수 선언에도 auto를 사용할 수 있다.
// 
// 
// int n=10;
// int & ref=n;
// auto ref2=ref;
// 
// 
// * 함수의 리턴 타입으로 추론하여 변수 타입 선언
// 
// int square(int x) {return x*x}
// 
// auto ret=square(3);
// 
// 컴파일러는 square()의 리턴 타입이 int 이므로 변수 ref의 타입을 int로 추론한다.
// 
// 
// 
// 
// 
// 
// 
// * STL 템플릿에 활용
// 
// auto를 vector, map 등의 템플릿에 사용하면 복잡한 변수 선언을 간소화할 수 있다.
// 
// vector<int> v={1,2,3,4,5};
// 
// iterator를 이용하여 벡터 v의 원소를 출력하려면 보통 다음 코드를 작성한다.
// 
// vector<int>::iterator it;	// 복잡한 모양의 it 변수 선언
// for(it=v.begin(); it!=v.end(); it++)
// cout<<*it<<endl;
// 
// 
// 
// 이 코드는 auto를 이용하여 변수 it를 선언하면 다음과 같이 간략히 작성할 수 있다.
// 
// for(auto it=v.begin(); it != v.end(); it++)	// 변수 it는 vector<int>::iterator
//		cout<<*it<<endl;						// 타입으로 추론됨
// 
//


int main() {

	// 기본 타입 선언에 auto 활용

	auto c = 'a';		// c는 char 타입으로 결정
	auto pi = 3.14;		// pi는 double 타입으로 결정
	auto ten = 10;		// ten은 int 타입으로 결정
	auto* p = &ten;		// 변수 p는 int* 타입으로 결정

	cout << c << " " << pi << " " << ten << " " << *p  << endl;


	// 함수의 리턴 타입으로 추론
	auto ret = square(3);	// square() 함수의 리턴 타입이 int이므로 ret는 int로 결정
	cout << *p << " " << ret << endl;

	vector<int> v = { 1,2,3,4,5 };	// 벡터 v에 5개의 원소, 1,2,3,4,5 삽입
	vector<int>::iterator it;

	for ( it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
		cout << endl;

	}



	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " ";
}