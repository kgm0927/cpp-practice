//
//
// 
// 
// 12.6 ���̳ʸ� I/O
// 
// ���̳ʸ� I/O�� ������ �� ����Ʈ�� ���̳ʸ� �� �״�� ���ų�, ������ ������ ���̳ʸ�
// ���� �״�� ���Ͽ� �����ϴ� ������(low level) ����� ����̴�. �׷��Ƿ� �ؽ�Ʈ ������
// �ؽ�Ʈ I/O ���̳ʸ� I/O�� �а� ���� ���� �� �� ����������, ���̳ʸ� ������ �ݵ��
// I/O�� �̿��ؾ� �Ѵ�.
// 
// 
// 
// 
//				���̳ʸ� I/O�� ���� ����
// 
// 
// ���̳ʸ� I/O�� ����ϱ� ���ؼ��� ������ �� �� 'ios::binary ���� ���'�� �����ؾ� �Ѵ�.
// desert.jpg ������ ���̳ʸ� I/O�� ������ϱ� ���� ���� ��Ʈ���� ���� �ڵ��̴�.
// 
// 
// ifstream fin;
// fin.open("desert.jpg",ios::in | ios::binary);	// ���̳ʸ� I/O�� ���� �б� ��� ����
// 
// ofstream fout("desert.jpg",ios::out | ios::binary); // ���̳ʸ� I/O�� ���� ���� ��� ����
// fstream fsin("desert.jpg", ios::in | ios::binary);	// ���̳ʸ� I/O�� ���� �б� ��� ����
// 
// 
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// �ҽ� ���ϰ� ���� ������ �̸�

	const char* srcFile = "c:\\temp\\desert.jpg";
	const char* destFile = "c:\\temp\\copydesert.jpg";

	// �ҽ� ���� ����

	ifstream fsrc(srcFile, ios::in | ios::binary); // ���̳ʸ� I/O
	if (!fsrc) {// ���� ���� �˻�
		cout << srcFile << " ���� ����" << endl;
		return 0;

	}

	// ���� ���� ����
	ofstream fdest(destFile, ios::out | ios::binary);	// ���̳ʸ� I/O
	if (!fdest) {// ���� ���� �˻�
		cout << destFile << " ���� ����" << endl;
		return 0;

	}

	// �ҽ� ���Ͽ��� ���� ���Ϸ� �����ϱ�

	int c;

	while ((c=fsrc.get())!=EOF)	// �ҽ� ������ �� ����Ʈ�� �д´�.
	{
		fdest.put(c); // ���� ����Ʈ�� ���Ͽ� ����Ѵ�.

	}
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}
