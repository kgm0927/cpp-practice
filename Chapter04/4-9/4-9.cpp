#include <iostream>
using namespace std;

// * 객체 배열의 동적 생성 및 반환
// new 와 delete를 이용하면 객체 배열을 동적으로 생성하고 반환할 수 있다.
// new를 이용하여 객체 배열을 동적으로 생성하는 구문은 이러하다.
// 클래스이름 *포인터변수=new 클래스이름 [배열크기];
// 
// 
// 3개의 Circle 객체로 구성된 배열을 동적 생성하는 예이다.
// Circle *pArray=new Circle[3];
// 
// 이 코드는 연속된 3개의 Circle 객체 배열을 동적 할당하고, 배열의 주소를 pArray에 저장한다. 이때 각 객체에 기본 생성자 Circle()이 호출된다.
// 하지만 동적으로 배열을 생성할 때, 매개 변수가 있는 생성자를 호출해서는 안된다.
// 
// Circle *pArray=new Circle[3](30);
// 
// 대신 다음과 같이 배열을 각 원소 객체로 초기화 할 수 있다.
// 
// Circle *pArray=new Circle[3]{Circle(1), Circle(2), Circle(3)};
// 
// 
// 
// pArray는 포인터이므로 다음과 같이 작성이 가능하다.
// pArray->setRadius(10);
// (pArray+1)->setRadius(20);
// (pArray+2)->setRadius(30);
// for (int i=0; i<3;i++)
//	cout<<(pArray+i)->getArea();
//
// 
// delete 연산자를 이용하여 동적으로 할당받은 배열을 반환하는 형식은 다음과 같다.
// 
// delete [] 포인터변수;
//

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius=" << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius=" << radius << endl;
}
Circle::~Circle() {
	
	cout << "소멸자 실행 radius=" << radius << endl;
}


int main() {
	Circle* pArray = new Circle[3];

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for (int i = 0; i < 3; i++)
	{
		cout << pArray[i].getArea() << endl;

	}
	Circle* p = pArray;

	for (int i = 0; i < 3; i++)
	{
		cout << p->getArea() << endl;
		p++;
	}


	//delete는 pArray가 가리키는 배열을 반환하기 직전, 배열의 각 원소 객체의 소멸자를 실행한다. 소멸자의 실행 순서는 다음과 같이 생성의 반대 순이다.
	// 
	// pArray[2] 객체의 소멸자 ==> pArray[1] 객체의 소멸자 ==> pArray[2] 객체의 소멸자
	//
	//

	delete[] pArray;

}