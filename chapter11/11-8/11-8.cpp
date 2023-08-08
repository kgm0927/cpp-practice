//
//	* �Ű������� ������ ������
// 
// �̵��� <iomanip> ��� ���Ͽ� ���ǵǾ� �ֱ� ������, �̵��� ����ϱ� ���ؼ��� <iomanip> ���
// ������ include �ؾ� �Ѵ�.
// 
// 
// 
// 
// <ǥ 11-4> �Ű������� ������ ������
// 
//		������						|		I/O				|		�뵵
//	resetioflages(long flags)				IO					flags�� ������ �÷��׵� ����
// ----------------------------------------------------------------------------------------------------------------
//	setbase(int base)						O					base�� ����� ���� ������ ����
// ----------------------------------------------------------------------------------------------------------------
//	setfill(char cFill)						I					�ʵ带 ����ϰ� ���� ������ cFill ���ڷ� ä��
// -------------------------------------------------------------------------------------------------------------------
//	setioflags(long flags)					O					flags�� ��Ʈ�� ����� �÷��׷� ����
// ------------------------------------------------------------------------------------------------------------------
//	setprecision(int np)					O					��µǴ� ���� ��ȿ ���� �ڸ����� np���� ����. �Ҽ���(.)�� ������ ī��Ʈ
// ------------------------------------------------------------------------------------------------------------------------------------
//	setw(int minWidth)						O					�ʵ��� �ʼ� �ʺ� minWidth�� ����
// 
// 
// 
//  0���� 50������ 5�� ����� 10����, 8����, 16������ ����Ѵ�.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << showbase;


	cout << setw(8) << "Number";

	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;


	// �ϳ��� ���� ������, 8����, 16���� ���·� �� �ٿ� ����Ѵ�.
	for (int i = 0; i < 50; i+=5)
	{
		cout << setw(8) << setfill('.') << dec << i;// 10����
		cout << setw(10) << setfill(' ') << oct << i;// 8 ����
		cout << setw(10) << setfill(' ') << hex << i << endl;// 16 ����

	}
}

//
//		�������� Ư¡
// 
// �����ڴ� ����ϱ� ���� ��� �ڵ带 �����ϰ� ����� ����, setf(), width(), fill(),precision() ���� ��� �Լ���Ÿ �������� ����� ���Ѵ�.
// �׷��� �����ڷ� ������ ������ �� ���� ����¿��� ����ǹǷ� ����¸��� ������ �����ؾ� �Ѵ�.
// 
// 
// ��κ��� �����ڴ� ���ο��� setf() �Լ��� ȣ���Ѵ�. hex ������ �Լ��� cout.setf(ios::hex);�� ȣ���ϸ� showbase ������ �Լ��� cout.setf(ios::showbase);
// �� ȣ���Ѵ�.
// 
// 
//