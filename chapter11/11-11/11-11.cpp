#include <iostream>
using namespace std;


//		추출 연산자의 중복
// 
// cin과 함께 사용되는 >> 연산자를 추출 연산자(extraction operator)라고 부른다. >> 연산자는 cin으로부터 키를 입력받기도 하지만
// 파일에서 읽을 때도 사용된다. 원래 >> 연산자는 정수를 비트 단위로 오른쪽 시프트(shift)하는 C++의 기본 연산자이다.
// 
// class istream: virtual public ios{
// 
// public: 
//		istream& operator >> (int& n);		// 정수를 입력하는 >> 연산자
//		istream& operator >> (char& c);		// 문자를 입력하는 >> 연산자
//		istream& operator >> (const char* s); // 문자열을 입력하는 >> 연산자
// 
//



//
// * 사용자 정의 추출 연산자 함수의 원형
// 
// 사용자가 작성한 클래스의 객체에 cin>> 를 사용하여 값을 입력하기 위한 >> 연산자의 일반적인
// 함수 원형을 알아보자. 사용자가 작성한 UserClass 클래스의 객체에 값을 입력받기 위한 추출 연산자(>>)의
// 함수 원형은 다음과 같다.
// 
// istream& operator >> (istream& ins,UserClass& obj);
// 
// 
//



class Point {	// 한 점을 표현하는 클래스
	int x, y;	// private 멤버
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;

	}

	friend istream& operator >> (istream& ins, Point& a);	// friend 선언




	friend ostream& operator << (ostream& stream, Point a);	// friend 선언

};

istream& operator >> (istream& ins, Point&a) {// >> 연산자 함수//
	cout << "x 좌표>>";
	ins >> a.x;

	cout << "y 좌표>>";
	ins >> a.y;

	return ins;
	
	/*
		여기서 두 가지 사항이 필요하다. 
		
		1. 두 번째 매개변수를 참조 타입(Point &a)으로 선언한다. 이는 원본 객체 p에 값을 쓰기 위해서이다.
		
		2. 둘째 이 연산자 함수가 private 멤버, x,y를 접근하도록, Point 클래스에 friend로 선언한다.*/

}

ostream& operator << (ostream& stream, Point a) {// << 연산자 함수
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}


int main() {
	Point p;	// Point 객체 생성

	/* Point 객체 p를 생성하고 다음과 같이 cin>>를 사용하여 키 입력을 받으면 '컴파일 오류'가 발생한다.
	
	// Point p;		// 디폴트로 x=0, y=0
	// cin >> p;	// 컴파일 오류


	당연한 것이지만, Point 객체에 값을 읽어들이는 >> 연산자 istream 클래스에는 없기 때문이다. 컴파일러는
	cin>>p; 문장을 다움과 같이 변형하여 컴파일한다.

	>>(cin,p);

	이 때문에 >> 연산자 함수를 '외부 함수'로 작성해야 한다.
	
	*/
	cin >> p;	// >> 연산자를 호출하여 x 좌표와 y 좌표를 키보드로부터 읽어 객체 p 완성
	cout << p;	// << 연산자를 호출하여 객체 p 출력
}