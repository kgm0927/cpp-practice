#include <iostream>
using namespace std;


// * �������̵��� ����
// �⺻ Ŭ������ ���� �Լ��� ����� ������ �Ļ� Ŭ�������� �ڽ��� ������ �°� ���� �Լ��� ������ �ϵ��� �ϴ� ���̴�. 
// �⺻ Ŭ������ ���� �Լ��� ��ӹ޴� �Ļ� Ŭ�������� �����ؾ��� ������ �Լ� �������̽��� �����Ѵ�.
// 
// ���� �Լ��� '�ϳ��� �������̽��� ���� ���� �ٸ� ����� ����'�̶�� ��ü ���� ����� ������(polmorphism)�� �����ϴ� �����̴�.
// 
// 
// ���� ������ Shape�� �⺻ Ŭ�����μ�, ���� ������ �Ļ� Ŭ�����鿡�� ��ӵȴ�. Shape�� draw()�� �����Լ��� �����Ͽ��� ������,
// �Ļ� Ŭ�������� Shape�� draw() �Լ��� �������̵��Ͽ� �ڽŸ��� ����� �׸����� �ڵ��Ѵ�.
// 
// 
// void paint(Shape *p){
// p->draw();
// }
// 
// ���� �Լ��� p->draw()�� ���� ������ p�� ����Ű�� ��ü�� �������̵��� draw() �Լ��� ȣ���ϵ��� �ۼ��Ͽ���.
// 
// p->draw()�� p�� ����Ű�� ��ü ���� �������̵��� draw() �Լ��� ȣ���ϱ� �����̴�. �̰��� �ٷ� �������̵��� ���� �������� �����̴�.
//


class Shape {
protected:
	void paint(Shape* p) {
		p->draw();
	}
	virtual void draw();
};

class Circle :public Shape {
protected:
	virtual void draw() {

	}
}; class Rect :public Shape {
protected:
	virtual void draw() {

	}
}; class Line :public Shape {
protected:
	virtual void draw() {

	}
};

int main() {

}