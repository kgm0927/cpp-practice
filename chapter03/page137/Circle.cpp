#include <iostream>

using namespace std;
#include "Circle.h"
// 클래스마다 선언부는 헤더 파일에, 구현부는 cpp 파일에 분리하여 작성한다.
// main() 등 함수나 전역 변수는 한 개 이상의 cpp 파일에 나누어 작성한다.
// 
//

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius;
	cout << " 원 생성" << radius;
}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius;
	cout << " 원 생성 " << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}