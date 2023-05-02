#include <iostream>
using namespace std;

int main() {
	int* p;		//
	p = new int;//위 아래 합쳐서 정수 타입의 공간을 할당하는 것이다.

	if (!p) { // if(p==NULL)과 동일, p가 NULL이면,
		cout << "메모리를 할당할 수 없습니다.";
		return 0;// 메모리 할당받기 실패
	}
	*p = 5; // 할당받은 정수 공간에 5를 기록
	int n = *p; // 할당받은 공간에서 값 읽기. n=5
	cout << "*p=" << p << endl;
	cout << "n = " << n << endl;

	delete p; // 할당받은 정수 공간 반환. 이걸 하지 않을 시 공간이 부족해진다.
}