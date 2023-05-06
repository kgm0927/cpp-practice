#include <iostream>
using namespace std;


// 함수 중복 간소화

// Circle 클래스의 중복 생성자들을 디폴트 매개 변수를 가진 하니의 생성자로 간소화
// 시킨 사례를 보여준다.
// 
// Circle class{
//		public:
//			Circle(int r=1){radius=r;}
//		}

void fillLine(int n = 25, char c = '*') {

	for (int i = 0; i < n; i++)
	{
		cout << c;
	}
	cout << endl;
}

int main() {
	fillLine();
	fillLine(10, '%');
}