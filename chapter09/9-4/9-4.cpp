#include <iostream>
using namespace std;

//
// �������̵��� ���� ���� ������(::)
// 
// ���� ���� ������(::)�� �̿��Ͽ� �⺻ Ŭ������ ���� �Լ��� ȣ���� �� �ִ�. ���� ���� �����ڸ� �̿��Ͽ� �⺻ Ŭ���� Shape�� ���� �Լ���
// ���� ���ε����� ȣ���ϴ� ��ʸ� �����ش�.
// 
// ���� ���� �����ڸ� ����ϴ� �� ���� ��츦 ��� �����ش�.
// 
// ù°, main() �Լ��� ���� Ŭ���� �ܺο��� ȣ���ϴ� ����̴�. ���� �ڵ�� ���� ���ε����� Shape�� draw()�� ȣ���Ѵ�.
// 
// Circle circle;
// Shape* pShape=&Circle;
// pShape->Shape::draw();	// ���� ���ε�. Shape�� ��� �Լ� draw() ȣ��
// 
// 
// 
// 
// ��°, Ŭ������ �޸� �Լ������� ���� ���� �����ڸ� �̿��Ͽ� �⺻ Ŭ������ ���� �Լ��� ȣ���� �� �ִ�. �� ��쿡�� ���� ���ε��� �̷������.
// 
// class Circle: public Shape{
// public:
// 
//		virtual void draw(){
//		shape::draw();		// �⺻ Ŭ���� Shape�� draw()����. ���� ���ε�
//		// �ʿ��� ��� �߰�
//		}
// }
// 
// �� �� ��°�� ���� ���� ���뿡�� ���� Ȱ��ȴ�. �Ϲ������� �Ļ� Ŭ������ ���� �Լ�(Circle::draw())�� �ۼ��ϴ� �����ڴ�
// �⺻ Ŭ������ ���� �Լ�(Shape::draw())�� �״�� Ȱ���ϰ� ����� �߰��Ͽ� �����Ѵ�.
//


class Shape {
public:
	virtual void draw() {
		cout << "--Shape--";
	}
};

class Circle :public Shape {
public:
	int x;
	virtual void draw() {
		Shape::draw();	// �⺻ Ŭ������ draw() ȣ��
		cout << "Circle" << endl;
	}
};

int main() {
	Circle circle;
	Shape* pShape = &circle;

	pShape->draw();	// ���� ���ε� �߻�. draw()�� virtual�̹Ƿ� 
	pShape->Shape::draw();	// ���� ���ε� �߻�. ���� ���� �����ڷ� ����
}