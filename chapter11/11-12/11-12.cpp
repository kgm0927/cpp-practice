#include <iostream>
using namespace std;


//
// 
// 11.6 ����� ������ �����
// 
//	
// 
//  	�������� ���� ����
// 
// ����ڴ� ���ο� �����ڸ� ���� �� �ִ�. �� ���� �����ڰ� ��� �۵��Ǵ��� �˾ƺ���. �����ڴ� <<,>>�� �Բ� �����̵Ǵµ�,
// ���� ���ô� ���� ������ endl �����ڰ� ȣ��ǰ� ����Ǵ� ������ �����Ѵ�.
// 
// cout<< endl;
// 
// 
// 
// 
// 
// 
// 
// 
// �����Ϸ��� << �����ڰ� ó���ϴ� ��İ� �����ϰ� ���� ������ ������ ���� �����Ѵ�.
// 
// cout. <<(endl);
// 
// 
// 
// 
// 
// 
// 
// �� �ڵ�� ���� << ������ �Լ��� ȣ���ϸ�, 'endl() �Լ��� �ּ�'�� �Ű� ���� _f�� ���޵ȴ�. endl�� <ostream> Ŭ������ �ۼ���
// endl() �Լ��� �̸��̹Ƿ� �Լ��� �ּ��̴�.
// 
// ostream& ostream:: operator << (ostream& (* _f)(ostream&)){
//		(*_f)(*this);
//		return *this;
// }
// 
// 
// 
// 
// 
// ���� �ڵ忡�� (*_f)(*this);�� �ǹ̸� ����ȭ�ϸ� ������ ����.
// 
//			(*_f)		--> endl() �Լ� ȣ�⹮
//			(*this)		-->	cout() ��ü
//			(*_f)(*this)--> endl(cout); �Լ� ȣ��
// 
// 
// 
// 
// �ᱹ << ������ �Լ��� 'endl(cout)'�� 'ȣ��'�Ѵ�. endl() �Լ��� <ostream> ��� ���Ͽ� �����Ǿ� �ִµ�,
// �̷��� �ܼ�ȭ �� ���Ҵ�.
// 
// ostream& endl(ostream& outs){
// 
//		outs.put('\n');
//		outs.flush();
//		return outs;
// }
// 
// 
// 
// 
//		���ο� ������ �����
// 
// '�Ű� ���� ���� ������'�� ������ ���� ��� ������ '����'�� ������.
// 
//		istream& manipulatorFunction(istream& ins)
//			�Է� ��Ʈ���� ���Ǵ� ������ ����
// 
//		ostream& manipulatorFunction(ostream& outs)
//			��� ��Ʈ���� ����ϴ� ������ ����
// 
// 
// 
// 
// �����ڵ��� ��� <<�� >> �����ڿ� ���� ������ �������� ȣ��Ǳ� ������, �ٸ� �������� ������ �Լ���
// ���� �� ����.
// 
//  
// 
//

ostream& fivestar(ostream& outs) {
	return outs << "*****";

}

ostream& rightarrow(ostream& outs) {
	return outs << "---->";

}




ostream& beep(ostream& outs) {
	return outs << '\a';

}

int main() {
	cout << "���� �︳�ϴ�." << beep << endl;
	cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}