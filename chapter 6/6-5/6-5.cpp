#include <iostream>
using namespace std;


// �Լ� �ߺ� ����ȭ

// Circle Ŭ������ �ߺ� �����ڵ��� ����Ʈ �Ű� ������ ���� �ϴ��� �����ڷ� ����ȭ
// ��Ų ��ʸ� �����ش�.
// 
// Circle class{
//		public:
//			Circle(int r=1){radius=r;}
//		}

void fillLine(int n = 25, char c = '*') {

	for (int i = 0; i < n; i++)
	{
		cout << c;
	}
	cout << endl;
}

int main() {
	fillLine();
	fillLine(10, '%');
}