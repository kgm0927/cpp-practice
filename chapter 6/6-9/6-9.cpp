#include <iostream>
#include <string>
using namespace std;

void msg(int id) {
	cout << id << endl;
}

void msg(int id, string s = "") {
	cout << id << ":" << s << endl;
}

int main() {
	msg(5, "Good Morning");
	msg(6);
}

//
// 틀린 함수 중복
// 배열의 이름은 포인터이기 때문에, 다음 두 함수는 같은 함수로서, 공존할 수 없다.
// 
// void f(int a[]);
// void f(int* a);
//