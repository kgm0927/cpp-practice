#include <iostream>
#include <string>
using namespace std;

// 디폴트 매개 변수

// 함수가 호출이 될 때 매개 변수에 값이 넘어오지 않다면, 미리 정해진 디폴트 값을 받도록 선언된 매개 변수를 디폴트 매개 변수(default parameter)라고
// 혹은 기본 매개 변수 라고 한다.
// 
// 디폴트 매개 변수 선언
// 

// 
//
//

// 디폴트 매개 변수는 '매개 변수=디폴트 값'형태로 선언된다. 다음은 디폴트 매개 변수를 가진 star() 함수 사례이다.
void star(int a = 5);
//int a는 디폴트 매개 변수로서 디폴트 값으로 5를 가지도록 선언되었다. 디폴트 매개 변수를 가진 함수를 호출할 때는 디폴트 매개 변수에 값을 넘겨주어도 되고
// 생략해도 된다.
// 
// star 함수는 2가지 형태로 호출할 수 있다.
// star(); // 매개 변수 a에 디폴트 값 5 자동전달. star(5); 와 동일
// star(10); // 매개 변수 a에 10 전달
// 
// 디폴트 매개 변수에 디폴트 값을 전달하는 것은 컴파일러에 의해 처리된다.
//

void msg(int id, string text = "");
// msg()는 다음과 같이 호출이 가능하다.
// 
// msg(10); // id에 10, text에 "Hello" 전달. msg(10,"Hello");로 처리됨
// msg(20,"Good Morning"); // id에 20, text에 "Good Morning" 전달
// 
// Tip) 만약 여러개의 매개변수 중 하나만 디폴트로 초기화 했을 때, 하나만 전달하거나 아니면 둘 다 전달을 하지 않거나, 같은 방식은 쓸 수 없다.
//


// *디폴트 매개 변수에 대한 제약 조건
// 
// 디폴트 매개 변수를 가진 함수를 선언할 때 지켜야 할 규칙이 있다. 디폴트 매개 변수는 모두 끝 쪽에 몰려 선언되어야 한다.
// 
// void calc(int a,int b=5,int c=0,int d=0);
// 
// * 매개 변수에 값을 정하는 규칙
// 
// 디폴트 매개 변수를 가지고 있는 함수의 호출문을 컴파일할 때, 컴파일러는 함수 호출문에 나열된 실인자 값들을 앞에서부터 순서대로 함수의 매개변 수에 전달하고, 나머지
// 는 디폴트 값으로 전달된다.
//



void star(int a) {
	for (int i = 0; i < a; i++)
	{
		cout << '*';
	}
	cout << endl;
}

void msg(int id, string text) {
	cout << id << ' ' << text << endl;
}

int main() {
	star();
	star(10);

	msg(10);
	msg(10, "Hello");
}

