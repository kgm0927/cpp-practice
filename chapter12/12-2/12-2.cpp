// 
// 
//			>> �����ڸ� �̿��� �ؽ�Ʈ ���� �б�
// 
// ������ �д� ������ ���Ͽ� ���� ������ �����ϴ�. �켱 ������ ���� ifstream Ŭ������ �̿��Ͽ� ���� �Է� ��Ʈ�� ��ü��
// �����Ѵ�.
// 
// 
// ifstream fin; // ���� �Է� ��Ʈ�� ��ü fin ����
// 
// 
// �׸��� open() �Լ��� �̿��Ͽ� ������ �а�, ������ ���� ���θ� �˻��Ѵ�.
// 
// fin.open("c:\\temp\\student.txt");
// if(!fin){
//		cout<<" ������ �� �� ����.";
//		return 0;
// }
// 
// 
// �׸��� �б⸦ ��ġ���� �ϸ� ������ ���� ������ �ݴ´�.
// 
// 
// fin.close();
// 
// 
// ���! : ������ ��θ�
// 
// �ݵ�� �齽����('\')�� �ι� �������� �Ѵ�.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;

	fin.open("c:\\temp\\student.txt");
	if (!fin) {// ���� ���� ����
		cout << "������ �� �� ����.";
		return 0;
	}

	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();// ���� �б⸦ ��ġ�� ������ �ݴ´�.

}