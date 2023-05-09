#include <iostream>
using namespace std;
// chapter07 프렌드 연산자 중복
// 
// C++에서는 클래스 외부에 작성된 함수를 클래스 내에 friend 키워드로 선언하여, 클래스의 멤버 함수와 동일한 접근 자격을
// 부여할 수 있다. 물론 멤버가 아니므로 상속되지는 않는다. 클래스 내에 friend 키워드로 선언된 외부함수를 friend 함수라고 부르며,
// 프렌드 함수는 마치 클래스의 멤버인 것처럼 클래스의 모든 변수나 함수에 접근할 수 있다.
// 
// 
// 
// 특징
// 
// 존재 : 클래스 외부에 작성된 함수. 멤버가 아님
// 자격 : 클래스의 멤버 자격 부여. 클랫의 모든 멤버에 대해 접근이 가능
// 선언 : 클래스 내에 friend 키워드로 선언
// 개수 : 프렌드 함수 개수에 대한 제한 없음
// 
// 
//  *존재 이유
// 
//  클래스의 private, protected 멤버를 접근해야 하는 경우, 이 함수를 외부 함수로 작성하고 프렌드로 선얺난다. 그 대표적인 함수가
// '연산자 함수'이다.
// 
// *프렌드 함수를 선언할 수 있는 겨우 3가지.
// 
// -클래스 외부에 작성된 함수를 프렌드로 선언
// -다른 클래스의 멤버 함수를 프렌드로 선언
// -다른 클래스의 모든 함수를 프렌드로 선언
// 
//


class Rect; // Rect 클래스가 선언되기 전에 먼저 참조되는 컴파일 오류(forward reference)를 막기 위한 선언문(forward declaration)

bool equals(Rect r, Rect s);// equals() 함수 선언

class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) {
		this->height = height;
		this->width = width;
	}
	friend bool equals(Rect r, Rect s); //프렌드 함수 선언
};

bool equals(Rect r,Rect s) { // 외부 함수 
	if (r.width == s.width && r.height == s.height) // equals() 함수는 private 속성을 가진 width, height에 접근할 수 있다.
	{
		return true;
	}
	else return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl; 
	else cout << "not equal" << endl;
}