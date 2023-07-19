#include <iostream>
using namespace std;


//
// 11.3 istream의 멤버 함수를 이용한 문자 입력
// 
// 
// istream 클래스도 >> 연산자 외에 다양한 입력 멤버 함수를 가지고 있다. >> 연산자는 빈칸, 탭, 뉴라인, 공백문자 키를 읽을 수 없지만,
// istream의 멤버 함수를 사용하면 공백 문자를 읽을 수 있다.
// 
// 
// 
// 
// * 문자 입력
// 
// 
// 문자를 입력받는 get() 함수는 2가지 종류가 있다. 앞서 설명한 바와 같이 2 바이트로 되어있는 한글 문자는 읽을 수 없다.
// 
// 
// 
// int get(): 입력 스트림에서 문자를 읽어 리턴, EOF를 만나면 -1(EOF)를 리턴
// 
// istream& get(char& ch): 입력 스트림에서 문자를 읽어 ch에 저장, 현재 입력 스트림 객체(*this)의 참조 리턴, 오류나 EOF를 만나면, 
//							스트림 내부의 오류 플래그 (failbit) 세팅(12.7절 참조)
// 
// 
// 
// 
// * int get()
//
// get()은 입력 스트림에서 한 개의 문자를 읽어 리턴하며 '<Enter> 키 등의 공백 문자도 읽어 리턴'한다. get()을 이용하여 한 라인을 읽는 코드를 본다.
// 
// 
// int ch;
// 
// while((ch=cin.get())!=EOF){
//		cout.put(ch);
//		if(ch=='\n')
//			break;
// }
// 
// while 문 안에 cin.get()은 키 입력을 대기하다, 사용자가 <Enter> 키를 입력하면
// 읽기를 시작한다. 한 번에 한 문자씩 ch 변수에 읽어 들이고 다시 화면에 출력한다.
// 
// cin.get() 뿐만 아니라 '\n'키도 읽어서 리턴한다.
// 
// 
// 
// 
// 참고: get()의 리턴 타입이 char가 아니고 왜 int 타입인가?
// 
// get()은 문자를 리턴하지만, 입력 스트림의 끝을 만나면 EOF를 리턴한다. EOF는 C++ 표준 헤더 파일에
// "#define EOF -1"로 int 타입으로 선언되어 있다. 이것이 get()의 리턴 타입이 int인 이유이다.
// 
// 
// 
// 
// 
// * istream& get(char& ch)
// 
// get(char& ch) 함수는 문자를 읽어 참조 매개 변수 ch에 저장하고 리턴한다. 이 함수도 역시 ' ', '\n' 등
// '공백 문자를 읽어 리턴'할 수 있다. get(char& ch)을 이용하여 한 라인을 읽어 들이는 코드는 다음과 같다.
// 
// 
// 
// char ch;
// while(true){
//		cin.get(ch);			// 키에 ch에 읽어옴
//		if(cin.eof()) break;	// EOF 문자 즉 ctrl-z 키가 입력된 경우, 읽기 종료
//		cout.put(ch);			// 읽은 문자 출력
//		if(ch=='\n')			// <Enter> 키가 입력된 경우 읽기 중단
//			break;
// }
// 
// 
// cin.get(ch)이 EOF를 만나면 cin 스트림 내부에 'eofbit 플래그'를 세팅하기 때문에, 
// ch에 읽혀진 값이 정확한지 확인하기 위해 cin.eof()를 호출한다. eof() 함수는 스트림 상태에 관한
// 12.7절을 참고하기 바란다. 
// 
// 
// 


void get1() {
	cout << "cin.get()로 <Enter> 키까지 입력 받고 출력한다>>";
	
	int ch;	// EOF와의 비교를 위해 int 타입으로 선언


	while ((ch = cin.get()) != EOF) {	// 문자 읽기

		cout.put(ch);	// 읽은 문자 출력
		if (ch == '\n')
			break;		// <Enter> 키가 입력되면 읽기 중단




	}
}

void get2() {
	cout << "cin.get(char&)로 <Enter> 키까지 입력 받고 출력한다.>>";
	char ch;

	while (true) {
		cin.get(ch);	// 문자 읽기
		if (cin.eof())break;	// EOF를 만나면 읽기 종료
		cout.put(ch);	// ch의 문자 출력
		if (ch == '\n')
			break;		// <Enter> 키가 입력이 되면 읽기 중단
	}
}


int main() {
	get1();	// cin.get()을 이용하는 사례
	get2();	// cin.get(char&)을 이용하는 사례


}