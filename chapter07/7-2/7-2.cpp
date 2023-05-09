#include <iostream>
using namespace std;

// * 프렌드 멤버 선언
// 다른 클래스의 멤버 함수를 클래스의 프렌드 함수로 선언할 수 있다. 다음은 RectManager 클래스의 멤버 함수 equals(Rect r,Rect s)를 Rect 클래스에 
// 프렌드로 선언하는 사례이다.
//


class Rect;

class RectManager {
public:
	bool equals(Rect r, Rect s); 
};

class Rect {
	int width, height;
public:
	Rect(int width, int height) {
		this->width = width;
		this->height = height;
	}

	friend bool RectManager::equals(Rect r, Rect s);// RectManager의 equals() 멤버 함수를 프렌드로 초대
};

bool RectManager::equals(Rect r, Rect s) { // RectManager::equals() 구현
	
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;	// RectManager 객체 생성

	if (man.equals(a, b))
	{
		cout << "equal" << endl;
	}
	else cout << "not equal" << endl;
}