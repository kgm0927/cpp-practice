#include <iostream>
using namespace std;


class Point {		// 한 점을 표현하는 클래스
	int x, y;		// private 멤버

// Point 클래스 객체를 다음과 같이 << 연산자를 이용해 화면에 출력해본다.

public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;

	}

	friend ostream& operator <<(ostream& stream,Point a);

};

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";		// 이것은 외부에 작성된 << 연산자에 대한 호출이므로,		
													// 이에 맞추어 독자는 다음과 같이 '외부 함수로 << 연산자 함수를 작성'해야 한다.
	return stream;

	/* stream 참조 매개 변수에 cout이 전달이 되고, a에는 객체 p가 전달이 된다. private 멤버 x,y를 접근할 수 있도록 << 연산자 함수를 Point 클래스에 friend로 연결한다.
		결국 이 연산자 함수는 cout에 a.x와 a.y값을 출력한다.*/
}

int main() {
	Point p(3, 4);	// Point 객체 생성 // 다음 코드는 (3,4)의 점을 표현하는 객체 p를 화면에 출력한다.
	cout << p << endl;		// Point 객체 화면 출력

	Point q(1, 100), r(2, 200);		// Point 객체 생성
	cout << q << r << endl;			// Point 객체들 연속하여 화면 출력
}

//
// 
// * 사용자 정의 삽입 연산자 함수의 원형
// 
// 사용자가 작성한 클래스 객체를 cout <<로 출력하기 위해 삽입 연산자 (<<)의 일반적인 함수 원형을 알아본다.
// 사용자가 작성한 UserClass 클래스의 객체를 출력하기 위한 삽입 연산자(<<)의 함수 원형을 다음과 같다. 둘 다 가능하다.
// 
// 
//			ostream& operator << (ostream& outs, Userclass obj);
//			ostream& operator << (ostream& outs, Userclass& obj);
// 
// 그리고 이들 연산자 함수는 '외부 함수로만 작성'되어야 하며 UserClass의 private 멤버에 접근하는 경우, UserClass
// 클래스에 '프렌드'로 선언되어야 한다. 
//
