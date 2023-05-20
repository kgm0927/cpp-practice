#include <iostream>
#include <string>
using namespace std;
//
//// �Ļ� Ŭ������ ��ü�� ������ ��, �Ļ� Ŭ������ �����ڸ� ���� �⺻ Ŭ������ �����ڿ��Ա��� 
// �Ű������� �����Ѵ�. ���� 8-3�� �̷��� ��ʸ� �� �����ش�.
// 
// * �����Ϸ� �⺻ �������� ȣ�� �ڵ� ����
// 
// �ٽ� �ڵ�� ���ư� ����, Ŭ���� B�� �����ڰ� �⺻ Ŭ������ ������ A()��
// ���������� ȣ���ϰ� �Ǵ� ����, ��ǻ� �����Ϸ��� ������ ���� ��������� 
// A()�� ȣ���ϵ��� Ŭ���� B�� �����ڸ� �����ϱ� �����̴�.
// 
// 
// class B{
// B(): A(){
//	cout<<"������ B"<<endl;
// }
// 
// B(int x):A(){
// cout<<"�Ű����������� B"<<endl;
// }
// 
// }
// 


class TV {
	int size;// ��ũ�� ũ��
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};

class WideTV :public TV {// TV�� ��ӹ޴� WideTV
	bool videoIn;
public:
	WideTV(int size, bool videoIn) :TV(size) {
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTv :public WideTV {// WideTV�� ��ӹ޴� SmartTV
	string ipAddr;// ���ͳ� �ӵ�
public:
	SmartTv(string ipAddr, int size) : WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() {
		return ipAddr;
	}
};

int main() {

	// 32��ġ ũ�⿡ "192.0.0.1"�� ���ͳ� �ּҸ� ������ ����Ʈ TV ��ü ����
	SmartTv htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "IP=" << htv.getIpAddr() << endl;
}