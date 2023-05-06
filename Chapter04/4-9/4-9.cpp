#include <iostream>
using namespace std;

// * ��ü �迭�� ���� ���� �� ��ȯ
// new �� delete�� �̿��ϸ� ��ü �迭�� �������� �����ϰ� ��ȯ�� �� �ִ�.
// new�� �̿��Ͽ� ��ü �迭�� �������� �����ϴ� ������ �̷��ϴ�.
// Ŭ�����̸� *�����ͺ���=new Ŭ�����̸� [�迭ũ��];
// 
// 
// 3���� Circle ��ü�� ������ �迭�� ���� �����ϴ� ���̴�.
// Circle *pArray=new Circle[3];
// 
// �� �ڵ�� ���ӵ� 3���� Circle ��ü �迭�� ���� �Ҵ��ϰ�, �迭�� �ּҸ� pArray�� �����Ѵ�. �̶� �� ��ü�� �⺻ ������ Circle()�� ȣ��ȴ�.
// ������ �������� �迭�� ������ ��, �Ű� ������ �ִ� �����ڸ� ȣ���ؼ��� �ȵȴ�.
// 
// Circle *pArray=new Circle[3](30);
// 
// ��� ������ ���� �迭�� �� ���� ��ü�� �ʱ�ȭ �� �� �ִ�.
// 
// Circle *pArray=new Circle[3]{Circle(1), Circle(2), Circle(3)};
// 
// 
// 
// pArray�� �������̹Ƿ� ������ ���� �ۼ��� �����ϴ�.
// pArray->setRadius(10);
// (pArray+1)->setRadius(20);
// (pArray+2)->setRadius(30);
// for (int i=0; i<3;i++)
//	cout<<(pArray+i)->getArea();
//
// 
// delete �����ڸ� �̿��Ͽ� �������� �Ҵ���� �迭�� ��ȯ�ϴ� ������ ������ ����.
// 
// delete [] �����ͺ���;
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
	cout << "������ ���� radius=" << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "������ ���� radius=" << radius << endl;
}
Circle::~Circle() {
	
	cout << "�Ҹ��� ���� radius=" << radius << endl;
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


	//delete�� pArray�� ����Ű�� �迭�� ��ȯ�ϱ� ����, �迭�� �� ���� ��ü�� �Ҹ��ڸ� �����Ѵ�. �Ҹ����� ���� ������ ������ ���� ������ �ݴ� ���̴�.
	// 
	// pArray[2] ��ü�� �Ҹ��� ==> pArray[1] ��ü�� �Ҹ��� ==> pArray[2] ��ü�� �Ҹ���
	//
	//

	delete[] pArray;

}