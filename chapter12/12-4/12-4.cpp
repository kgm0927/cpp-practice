//
// 
// get()�� EOF
// 
// '������ ��'�� ������ �б⸦ ���߾�� �ϴµ�,get()�� ������ ���� ��� �ν��ұ�?
// 
// 
// * get() �Լ��� EOF ����
// 
// get()�� �� ����Ʈ�� �а� '���� ������'�� ���� ����Ʈ ��ġ�� '����'��Ų��. get()�� ������ ������ ���ڸ� �а� ����,
// ���� �����ʹ� �����Ͽ� ������ ���� ����Ų��. �׷��� ���� ���� �����Ͽ������� ���� �� �� ���� �빮��, �̶� eof() �Լ���
// ȣ���ϸ� false(���� ���� �������� �ʾ���)�� �����Ѵ�. ���� get()�� �� �� �� �����ϸ�, �� �� ��μ� get()�� �� ���� �� ����
// ���� ������ �˰� �Ǿ� EOF(-1)�� �����ϰ�, ��Ʈ�� ���ο� 'eofbit �÷���'�� 1(true)�� �����Ѵ�. ���� eof() �Լ��� ȣ���ϸ� true
// �� ȣ���Ѵ�.
// 
// 
// * get()���� ������ ���� �����ϴ� ���
// 
// get()�� ������ ���� EOF�� ������ ���� ���ϸ� �ȴ�.
// 
// 
// 
// 
// while(true){
// 
//		int c=fin.get();	// ���Ͽ��� ����(����Ʈ)�� �д´�.
//		if(c==EOF){
//			...	// ������ ���� ���� ���. �̿� �����ϴ� �ڵ带 �ۼ�
//			break;	// while �������� �������´�.
//	}
//	else{
//			...  // ���� ����(����Ʈ) c�� ó���Ѵ�.
//	}
//}
// 
// 
// 
// 
// �� �ڵ�� ������ ���� �����ϰ� �ۼ��Ǳ⵵ �Ѵ�.
// 
// while((c=fin.get())!=EOF){
//		...		// ���Ͽ��� ���� ����(����Ʈ) c�� ó���ϴ� �ڵ�
// }
// 
// 
// ���� �ڵ���� �ؽ�Ʈ I/O�� ���̳ʸ� I/O�� ������� ������ �д� ��쿡 ���ȴ�.
// 
// 
// 
// * ������ ���� �߸� �����ϴ� �ڵ�
// 
// 
// 
// eof()�� ���� eofbit �÷����� ���� 1������ Ȯ���Ͽ� �����Ѵ�. �׷��Ƿ� ������ ���� eof()�� �̿��Ͽ� ������ ���� �˻��ϸ�
// ������ �߻��� �� �ִ�.
// 
// 
// while(!fin.eof()){
//		int c=fin.get();	// ������ ��ġ. ������ ���� EOF(-1) ���� c�� ������ �ȴ�.
//			...// ���� �� c�� ó���ϴ� �ڵ�.
//	}
// 
// ���� �ڵ�� fin.get()�� ������ ������ ����Ʈ�� �а� ���� �����Ͱ� ���� ����Ű�� ��Ȳ���� while ���� eof()�� ����Ǹ� eof()��
// false�� �����Ѵ�. �ֳ��ϸ� eofbit�� 1�� �µǾ� ���� �ʱ� �����̴�. �̶� �ٽ� int c=fin.get()�� ����Ǹ� eofbit�� 1�� �� �ǰ�
// get()�� EOF(-1)�� �����Ͽ� c�� -1 ���� ������.
// 
// �ٷ� �� ���� ���ο��� c ��(-1)�� ���������� ���� ���ڷ� �����ϰ� ó���ϸ� ������ �߻��Ѵ�.
// 
// fin.get() �Լ��� ����� ���� ȣ���� ���Ŀ� �ٷ� fin.get()�� ȣ���Ͽ� ���� �����͸� �о����� Ȯ���ϸ� ��� ������ �ذ�ȴ�.
// 
// 
// 
// 
// 
// 
// 
// *���!: get()�� ���� Ÿ���� int�� ����? EOF ����
// 
// ���� �ڵ�� fin�� ����� �ؽ�Ʈ ������ �а� ȭ�鿡 ����ϴ� �ڵ��̴�.
// 
// int c;
// 
// while((c=fin.get())!=EOF){
//		cout<<(char)c;
//		}
// 
// �� ���� �ǹ�
// 
// 1: get() �Լ��� �� ����Ʈ�� ���� �ϳ��� �����ϴµ� �� ���� Ÿ���� char�� �ƴ϶� int�ϱ�?
// 
// 2: get()�� ������ ���� ������ -1(EOF)�� �����ϴµ�, ���Ͽ� -1�� �ִٸ�, �� ���� ��� ������
// �� �ִ°�?
// 
// 
// �� ������ ���� ���� ��� ���� �� ó���� �����Ǿ� �ִ�. ���� ��Ʈ���̳� ���Ͽ� 0xFF�� ����
// �ִٰ� �ϸ�, get()�� 0xFF�� �����Ѵ�. �� �� ������� '0xFF�� -1 �ε�, ������ ���� ǥ���ϴ� -1
// �� ȥ���ǳ�.'��� ������ �� �ִ�.
// ������ get()�� int Ÿ������ ���� �����ϹǷ�, �д� ����Ʈ 0xFF�� 32��Ʈ�� 0x000000FF�� �����Ѵ�. �̰���
// -1�� �ƴ϶� 255�̴�. EOF�� -1�μ� 0xFFFFFFFF�̴�. get()�� ���Ͽ��� 0xFF�� ���� �а� �����ϴ� �Ͱ� Ȯ����
// ������ �ȴ�.
// 
// 
// 
// 
// 
// 
// 
//				ios::app ���� �ؽ�Ʈ ���� ���ٿ� ����
// 
// ios::app ��带 �̿��ϸ� ������ ���� �ٸ� ������ ���ٿ� �� �� �ִ�. ���� ������
// fstream�� �̿��ؼ� c:\temp\student.txt ���Ͽ��� c:\windows\system.ini ������ ���ٿ�
// ����ϴ� ���� ���δ�.
// 
// 
// const char* firstFile="c:\\temp\\student.txt";
// const char* secondFile="c:\\windows\\system.ini";
// 
// fstream fout(firstFile, ios::out | ios::app);	// ù ��° ������ �߰� ���� ���� ����
// fstream fin(secondFile, ios::in);				// �� ��° ������ �б� ���� ����
// 
// get() �Լ��� �̿��Ͽ� �� ��° ���� �����͸� �а�, put() �Լ��� �̿��Ͽ� ù ��° ���� ����
// ���ٿ� ����Ѵ�.
// 
// 
// 
// 
// 
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "c:\\temp\\student.txt";
	const char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);// ���� ���� ���� ����
	if (!fout) {
		cout << firstFile << " ���� ����";
		return 0;
	}

	fstream fin(secondFile, ios::in);	// �б� ���� ���� ����
	if (!fin) {// ���� ���� �˻�
		cout << secondFile << " ���� ����";
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {// ���� ������ ���� �б�
		fout.put(c); // ���� ���� ���
	}

	fin.close(); // �Է� ���� �ݱ�
	fout.close(); // ��� ���� �ݱ�
}