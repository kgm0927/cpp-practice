#include <iostream>
#include <string>
using namespace std;
//
//// 파생 클래스의 개체를 생성할 때, 파생 클래스의 생성자를 통해 기본 클래스의 생성자에게까지 
// 매개변수가 전달한다. 예제 8-3은 이러한 사례를 잘 보여준다.
// 
// * 컴파일러 기본 생성자의 호출 코드 삽입
// 
// 다시 코드로 돌아가 보면, 클래스 B의 생성자가 기본 클래스의 생성자 A()를
// 묵시적으로 호출하게 되는 것은, 사실상 컴파일러가 다음과 같이 명시적으로 
// A()를 호출하도록 클래스 B의 생성자를 변형하기 때문이다.
// 
// 
// class B{
// B(): A(){
//	cout<<"생성자 B"<<endl;
// }
// 
// B(int x):A(){
// cout<<"매개변수생성자 B"<<endl;
// }
// 
// }
// 


class TV {
	int size;// 스크린 크기
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }
	int getSize() { return size; }
};

class WideTV :public TV {// TV를 상속받는 WideTV
	bool videoIn;
public:
	WideTV(int size, bool videoIn) :TV(size) {
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTv :public WideTV {// WideTV를 상속받는 SmartTV
	string ipAddr;// 인터넷 속도
public:
	SmartTv(string ipAddr, int size) : WideTV(size, true) {
		this->ipAddr = ipAddr;
	}
	string getIpAddr() {
		return ipAddr;
	}
};

int main() {

	// 32인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트 TV 객체 생성
	SmartTv htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "IP=" << htv.getIpAddr() << endl;
}