//
// 
//			�ؽ�Ʈ ������ ���� ���� �б�
// 
// �ؽ�Ʈ ������ ���� ������ �д� ��찡 ����. ������ ���� ������ �д� ����� �� ������ �ִ�.
// 
// 
//		* istream�� getline(char *line,int n) �Լ� ���
//		* getline(ifstream &fin,string& line) �Լ� �̿�
// 
// 
// 
// * istream�� getline(char* line, int n)
//		istream�� getline() �Լ��� ��Ʈ���� ����� �Է���ġ�� ���Ϸκ��� �� ���� �д� �Լ��μ�, ������ ����
//		���Ϸκ��� �д´�.
// 
//		char buf[81];	// �� ������ �ִ� 80���� ���ڷ� �����ȴٰ� ����
//	
//		ifstream fin("c:\\windows\\sysyem.ini");
//		while(fin.getline(buf,81)){		// �� ������ �ִ� 80���� ���ڷ� ����. ���� '\0' ���� �߰�
//				...		// ���� ����(buf[])�� Ȱ���ϴ� �ڵ�
// 
//		}
//
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "c:\\windows\\system.ini ���� ����" << endl;
		return 0;
	}
	char buf[81];
	while (fin.getline(buf, 81)) {
		cout << buf << endl;
	}

	fin.close();
}