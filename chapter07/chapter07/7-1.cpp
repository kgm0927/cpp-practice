#include <iostream>
using namespace std;
// chapter07 ������ ������ �ߺ�
// 
// C++������ Ŭ���� �ܺο� �ۼ��� �Լ��� Ŭ���� ���� friend Ű����� �����Ͽ�, Ŭ������ ��� �Լ��� ������ ���� �ڰ���
// �ο��� �� �ִ�. ���� ����� �ƴϹǷ� ��ӵ����� �ʴ´�. Ŭ���� ���� friend Ű����� ����� �ܺ��Լ��� friend �Լ���� �θ���,
// ������ �Լ��� ��ġ Ŭ������ ����� ��ó�� Ŭ������ ��� ������ �Լ��� ������ �� �ִ�.
// 
// 
// 
// Ư¡
// 
// ���� : Ŭ���� �ܺο� �ۼ��� �Լ�. ����� �ƴ�
// �ڰ� : Ŭ������ ��� �ڰ� �ο�. Ŭ���� ��� ����� ���� ������ ����
// ���� : Ŭ���� ���� friend Ű����� ����
// ���� : ������ �Լ� ������ ���� ���� ����
// 
// 
//  *���� ����
// 
//  Ŭ������ private, protected ����� �����ؾ� �ϴ� ���, �� �Լ��� �ܺ� �Լ��� �ۼ��ϰ� ������� ���b����. �� ��ǥ���� �Լ���
// '������ �Լ�'�̴�.
// 
// *������ �Լ��� ������ �� �ִ� �ܿ� 3����.
// 
// -Ŭ���� �ܺο� �ۼ��� �Լ��� ������� ����
// -�ٸ� Ŭ������ ��� �Լ��� ������� ����
// -�ٸ� Ŭ������ ��� �Լ��� ������� ����
// 
//


class Rect; // Rect Ŭ������ ����Ǳ� ���� ���� �����Ǵ� ������ ����(forward reference)�� ���� ���� ����(forward declaration)

bool equals(Rect r, Rect s);// equals() �Լ� ����

class Rect { // Rect Ŭ���� ����
	int width, height;
public:
	Rect(int width, int height) {
		this->height = height;
		this->width = width;
	}
	friend bool equals(Rect r, Rect s); //������ �Լ� ����
};

bool equals(Rect r,Rect s) { // �ܺ� �Լ� 
	if (r.width == s.width && r.height == s.height) // equals() �Լ��� private �Ӽ��� ���� width, height�� ������ �� �ִ�.
	{
		return true;
	}
	else return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl; 
	else cout << "not equal" << endl;
}