#include <iostream>
#include <string>
using namespace std;



//
// 
// auto로 람다식 저장 및 호출
// 
// 람다식의 형식은 컴파일러에만 알려져 있기 때문에, 개발자가 람다식을 저장하는 변수를 직접 선언할 수 없다.
// auto를 이용하면 람다식을 저장하는 변수를 쉽게 선언할 수 있다.
// 
//
int main() {
	auto love = [](string a, string b) {
		cout << a << "보다 " << b << "가 좋아" << endl;
	};

	love("돈", "너");
	love("냉면", "만두");


}