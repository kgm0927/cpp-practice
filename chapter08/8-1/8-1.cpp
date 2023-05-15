#include <iostream>
#include <string>
using namespace std;

// * ���
//
// ���(Inheritance)�� ��ü ���� ����� �������� Ư���̴�.
// 
// 
// 
// * C++ Ŭ���� ���
// 
// C++������ �� Ŭ���� ���̿� �θ�-�ڽ��� ��� ���踦 �����Ѵ�. ����� �ڽ� Ŭ������ ��ü��
// ������ ��, �ڽ��� ����� �ƴ϶� �θ� Ŭ������ ����� ������ ���� �����Ѵ�.
// C++ ���� �θ� Ŭ������ �⺻ Ŭ����(base class), �ڽ� Ŭ������ �Ļ� Ŭ����(derived class)��� �Ѵ�.
// 
// C++ ������ ���� ���� Ŭ������ ���ÿ� ��ӹ޴� ���� ���(multiple inheritance)�� ����Ѵ�.
// 
// 
// * Ŭ���� ���� ������ �з� �� ������ ������
// 
// ����� ���� ���õ� Ŭ������ ���� ����� ǥ�������ν�, ���α׷��� �����ϴ� Ŭ�������� �������� ���� �ľ��� ���� ���ش�.
// 
// 
// * Ŭ���� ����� Ȯ���� ���� ����Ʈ������ ���꼺 Ȯ��
// 
// ����� ���� ū ������ ����Ʈ���� ���꼺�� ����ϴµ� �ִ�.
// 
// 
// * ��� ����
// 
// ����� class ���� �ڿ�, �ݷ�(:)�� �⺻ Ŭ���� �̸��� �����ϸ� �ȴ�. �̶� �⺻ Ŭ���� �̸� �տ� �ݵ�� ��� ������ �����ؾ� �ϴµ�,
// public, private, protected �� � �͵� �����ϴ�.  
//



class Point { // 2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� Point ����
	protected:
	int x, y;// ���� (x,y) ��ǥ��
public:
	void set(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void showPoint(){
		cout << "(" << x << ',' << y << ")" << endl;
	}
};

class ColorPoint :public Point { // 2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ���� ColorPoint. Point ��ӹ���
	string color; // ���� �� ǥ��
	
public:
	void setcolor(string color) {
		this->color = color;
	
	}
	void showColorPoint();// Point�� showPoint() ȣ��
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}
/*
// * �� ĳ����
//
// �� ĳ������ �Ļ� Ŭ������ ��ü�� �⺻ Ŭ������ �����ͷ� ����Ű�� ���� ���Ѵ�.
//


int main() {
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer;// ��ĳ����

	pDer->set(3,4);
	pBase->showPoint();
	pDer->setcolor("red");
	pDer->showColorPoint();// ����

	pBase->showPoint();
	// �̷� ����� ����ؾ� ������ ��ü pBase�� Point Ŭ���� �ɹ�(�ʵ�)�� ����� �� �ֵ��� �Ѵ�.
}*/

int main() {

	// �⺻ Ŭ���� �����Ͱ� ����Ű�� ��ü�� �Ļ� Ŭ������ �����ͷ� ����Ű�� ���� �ٿ� ĳ����(down-casting)�̶�� �Ѵ�.

	ColorPoint cp;
	ColorPoint* pDer;
	Point* pBase = &cp;



	cout << "pBase ��ü=";


	pBase->set(3, 4);
	pBase->showPoint(); // ���⼭�� ���� Point Ŭ������ ���(�ʵ�)�� �� �� �ִ�.
	

	cout << endl << endl;

	pDer = (ColorPoint *)pBase;// pBase�� ���� Ÿ�� ��ȯ���� �ٿ� ĳ����(�ݵ�� ���� ��ȯ�� �ʿ�.)

	cout << "pDer ��ü=" ;

	pDer->set(3, 5);
	pDer->setcolor("red");
	pDer->showColorPoint();
	cout << endl << endl;

	cout << "cp ��ü" ;
	cp.showColorPoint();
	




}