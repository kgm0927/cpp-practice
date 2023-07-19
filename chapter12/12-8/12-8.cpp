//
// 
// 
//				read() / write()�� ��� ���� ���� �����
// 
// get()�� put()�� �� ����Ʈ ������ ������� ����������, read()�� write()�� '��� ������ �����'�Ѵ�.
// 
// read() �Լ��� ifstream�� ����μ� ifstream�� ��ӹ�����, write() �Լ� ���� ostream�� ����̸� ostream����
// ��ӹ޾� ����Ѵ�.
// 
// 
// 
// 
// istream& read(char* s,int n)
// // ���Ͽ��� �ִ� n���� ����Ʈ�� �迭 s�� �о� ����.  ������ ���� ������ �б� �ߴ�
// 
// ostream& write(char* s, int n)
// �迭 s�� �ִ� ó�� n���� ����Ʈ�� ���Ͽ� ����
// 
// read(char* s,int n)�� �д� ���߿� ���� ��(EOF)�� �����ϸ� �б⸦ �ߴ��ϰ� �����Ѵ�. read() �Լ���
// n���� ����Ʈ�� ��� �о��ٰ� ������ ���� ����. �׷��Ƿ� read() �Ŀ� 'gcount()'�� �̿��Ͽ� '���� ����
// ����Ʈ ��'�� �˾Ƴ���. 
// 
// 
// ������ ����.
// 
// ifstream fin;
// 
// fin.open("desert.jpg", ios::in | ios::binary);	// ���̳ʸ� I/O ���� ���� �б� ����
// 
// char s[1024];
// fin.read(s,1024);		// ���Ϸκ��� 1024 ����Ʈ�� �о� �迭 s�� ����
// int n=fin.gcount();		// ���� fin.read() �Լ��� ���� ���� ����Ʈ ���� n�� ����
//							// �迭 s[]���� n���� ����Ʈ���� ��ȿ
// 
// 
// 
// read()�� ����ϸ� ��� ������ �� ���� �б� ������, �� ����Ʈ�� �о���� get()�� �̿��ϴ� �ͺ��� ���� ���α׷��� '�ӵ��� ������.'
// 
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";

	ifstream fin;

	fin.open(file, ios::in | ios::binary); // ���̳ʸ� I/O ���� ���� ����
	
	if (!fin) {// ���� ���� �˻�

		cout << "���� ���� ����";
		return 0;

	}

	int count = 0;
	char s[32]; // ��� ������ �о���� ����

	while (!fin.eof())// ���� ������ �д´�.
	{
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;

	}

	cout << "���� ����Ʈ ����" << count << endl;
	fin.close();
	
}