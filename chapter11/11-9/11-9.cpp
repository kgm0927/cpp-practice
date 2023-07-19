#include <iostream>
using namespace std;


class Point {		// �� ���� ǥ���ϴ� Ŭ����
	int x, y;		// private ���

// Point Ŭ���� ��ü�� ������ ���� << �����ڸ� �̿��� ȭ�鿡 ����غ���.

public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;

	}

	friend ostream& operator <<(ostream& stream,Point a);

};

ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";		// �̰��� �ܺο� �ۼ��� << �����ڿ� ���� ȣ���̹Ƿ�,		
													// �̿� ���߾� ���ڴ� ������ ���� '�ܺ� �Լ��� << ������ �Լ��� �ۼ�'�ؾ� �Ѵ�.
	return stream;

	/* stream ���� �Ű� ������ cout�� ������ �ǰ�, a���� ��ü p�� ������ �ȴ�. private ��� x,y�� ������ �� �ֵ��� << ������ �Լ��� Point Ŭ������ friend�� �����Ѵ�.
		�ᱹ �� ������ �Լ��� cout�� a.x�� a.y���� ����Ѵ�.*/
}

int main() {
	Point p(3, 4);	// Point ��ü ���� // ���� �ڵ�� (3,4)�� ���� ǥ���ϴ� ��ü p�� ȭ�鿡 ����Ѵ�.
	cout << p << endl;		// Point ��ü ȭ�� ���

	Point q(1, 100), r(2, 200);		// Point ��ü ����
	cout << q << r << endl;			// Point ��ü�� �����Ͽ� ȭ�� ���
}

//
// 
// * ����� ���� ���� ������ �Լ��� ����
// 
// ����ڰ� �ۼ��� Ŭ���� ��ü�� cout <<�� ����ϱ� ���� ���� ������ (<<)�� �Ϲ����� �Լ� ������ �˾ƺ���.
// ����ڰ� �ۼ��� UserClass Ŭ������ ��ü�� ����ϱ� ���� ���� ������(<<)�� �Լ� ������ ������ ����. �� �� �����ϴ�.
// 
// 
//			ostream& operator << (ostream& outs, Userclass obj);
//			ostream& operator << (ostream& outs, Userclass& obj);
// 
// �׸��� �̵� ������ �Լ��� '�ܺ� �Լ��θ� �ۼ�'�Ǿ�� �ϸ� UserClass�� private ����� �����ϴ� ���, UserClass
// Ŭ������ '������'�� ����Ǿ�� �Ѵ�. 
//
