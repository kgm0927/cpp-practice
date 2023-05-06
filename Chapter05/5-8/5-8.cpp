#include <iostream>
using namespace std;
// 참조 리턴
//
// 
// c++에서는 함수가 참조를 리턴할 수 있다. 참조 리턴이란 변수 등과 같이 현존하는 공간에 대한
// 참조의 리턴이다.
// 
// 참조를 리턴하는 함수를 선언해보자.
// 
// char에 대한 참조를 리턴하는 find() 함수는 다음과 같이 선언한다.
//  =============================================
// char c='a';
// 
// char& find(){ // char 타입의 참조 리턴
// return c;
// } // 변수 c에 대한 참조 리턴
// 
// 
// char a=find(); // a='a'가 됨
// 
// char &ref=find();// ref는 c에 대한 참조
// ref='M';	// c='M'
// 
// find()='b'; // c='b'가 됨
// ==============================================
// 
// 참조를 리턴하는 return 문은 보통 return 문과 다를 바 없다. 다음 코드는 find() 함수 내에서 char 타입의 변수 c에 대한 참조를 리턴한다.
// 
// 
// * 참조 리턴에 대한 치환문
// 
// find() 가 치환문(=)의 오른쪽에 온다면 변수 c의 값 'a'가 변수 a에 치환된다.
// 
// 그러나 다음과 같이 참조 변수로 참조를 리턴받을 수 있다.
// 
// char& ref=find();
// 
// 이 코드의 실행 결과 ref는 find()가 리턴한 변수 c의 참조가 된다. 그러므로 다음과 같이 ref에 대한 연산은 모두 변수 c에 대해 이루어지는 연산이 된다.
// ref='M';
// 
// 
// 
// 
//


// 배열 s의 원소 공간에 대한 참조를 리턴하는 함수
char& find(char s[],int index) {

	return s[index];// 참조 리턴
}

int main() {
	char name[] = "Mike";
	cout << name << endl;

	find(name, 0) = 'S'; // name[0]='S'로 변경
	cout << name << endl;

	char& ref = find(name,2);
	ref = 't'; //name="Site"
	cout << name << endl;

}