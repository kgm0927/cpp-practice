#include <iostream>
using namespace std;

// �ߺ� �Լ��� ���ø� �Լ����� �켱
// 
//  ���ø� �Լ��� �̸��� ������ �Լ��� �ߺ��Ǿ� ���� ��, �����Ϸ��� �ߺ��� �Լ���
// ���ø� �Լ����� �켱�Ͽ� ���ε��Ѵ�.
//

template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << '\t';

	}
	cout << endl;
}

void print(char array[], int n) {	// ���ø� �Լ��� ������ �̸��� �Լ� �ߺ�
	for (size_t i = 0; i < n; i++)
	{
		cout <<(int)array[i] << '\t';	// array[i]�� int Ÿ������ ��ȯ�Ͽ� ���� ���
	}
	cout << endl;
}

int main() {
	int x[] = {1,2,3,4,5};
	double d[5] = { 1.1,1.2,1.3,1.4,1.5 };
	print(x, 5);	// ���ø����κ��� ��üȭ�� �Լ� 
	print(d, 5);	// ���ø����κ��� ��üȭ�� �Լ�

	char c[5] = { 1,2,3,4,5 };
	print(c, 5);
}

// ���ø� �Լ��� ����Ʈ �Ű� ���� ���
// 
// ���ø����� �Լ� ���� ����Ʈ �Ű� ������ ����� �� �ִ�. ���� mcopy() ���ø��� ����Ʈ
// �Ű� ������ �������� �����ϸ� ������ ����.
// 
// template<class T1,class T2>
// void mcopy(T1 src[], T2 dest[], int n=5){
// 
//		for(int i=0; i<n;i++)
//			dest[i]=(T2)src[i];
// 
// }
//