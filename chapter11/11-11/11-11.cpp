#include <iostream>
using namespace std;


//		���� �������� �ߺ�
// 
// cin�� �Բ� ���Ǵ� >> �����ڸ� ���� ������(extraction operator)��� �θ���. >> �����ڴ� cin���κ��� Ű�� �Է¹ޱ⵵ ������
// ���Ͽ��� ���� ���� ���ȴ�. ���� >> �����ڴ� ������ ��Ʈ ������ ������ ����Ʈ(shift)�ϴ� C++�� �⺻ �������̴�.
// 
// class istream: virtual public ios{
// 
// public: 
//		istream& operator >> (int& n);		// ������ �Է��ϴ� >> ������
//		istream& operator >> (char& c);		// ���ڸ� �Է��ϴ� >> ������
//		istream& operator >> (const char* s); // ���ڿ��� �Է��ϴ� >> ������
// 
//



//
// * ����� ���� ���� ������ �Լ��� ����
// 
// ����ڰ� �ۼ��� Ŭ������ ��ü�� cin>> �� ����Ͽ� ���� �Է��ϱ� ���� >> �������� �Ϲ�����
// �Լ� ������ �˾ƺ���. ����ڰ� �ۼ��� UserClass Ŭ������ ��ü�� ���� �Է¹ޱ� ���� ���� ������(>>)��
// �Լ� ������ ������ ����.
// 
// istream& operator >> (istream& ins,UserClass& obj);
// 
// 
//



class Point {	// �� ���� ǥ���ϴ� Ŭ����
	int x, y;	// private ���
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;

	}

	friend istream& operator >> (istream& ins, Point& a);	// friend ����




	friend ostream& operator << (ostream& stream, Point a);	// friend ����

};

istream& operator >> (istream& ins, Point&a) {// >> ������ �Լ�//
	cout << "x ��ǥ>>";
	ins >> a.x;

	cout << "y ��ǥ>>";
	ins >> a.y;

	return ins;
	
	/*
		���⼭ �� ���� ������ �ʿ��ϴ�. 
		
		1. �� ��° �Ű������� ���� Ÿ��(Point &a)���� �����Ѵ�. �̴� ���� ��ü p�� ���� ���� ���ؼ��̴�.
		
		2. ��° �� ������ �Լ��� private ���, x,y�� �����ϵ���, Point Ŭ������ friend�� �����Ѵ�.*/

}

ostream& operator << (ostream& stream, Point a) {// << ������ �Լ�
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}


int main() {
	Point p;	// Point ��ü ����

	/* Point ��ü p�� �����ϰ� ������ ���� cin>>�� ����Ͽ� Ű �Է��� ������ '������ ����'�� �߻��Ѵ�.
	
	// Point p;		// ����Ʈ�� x=0, y=0
	// cin >> p;	// ������ ����


	�翬�� ��������, Point ��ü�� ���� �о���̴� >> ������ istream Ŭ�������� ���� �����̴�. �����Ϸ���
	cin>>p; ������ �ٿ�� ���� �����Ͽ� �������Ѵ�.

	>>(cin,p);

	�� ������ >> ������ �Լ��� '�ܺ� �Լ�'�� �ۼ��ؾ� �Ѵ�.
	
	*/
	cin >> p;	// >> �����ڸ� ȣ���Ͽ� x ��ǥ�� y ��ǥ�� Ű����κ��� �о� ��ü p �ϼ�
	cout << p;	// << �����ڸ� ȣ���Ͽ� ��ü p ���
}