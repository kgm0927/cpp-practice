#include <iostream>
#include <cstring>
using namespace std;



//
//		한 줄 읽기
// 
// 키보드나 파일로부터 읽는 프로그램을 작성하다보면, 한 줄 단위로 읽는 경우가 많다.
// 다음은 입력 스트림부터 한 줄을 읽어 배열에 저장하는 함수이다.
// 
// 
// istream& get(char* s,int n,char delim='\n'): 입력 스트림으로부터 최대 n-1개의 문자를 읽어 배열 s에 저장하고
//												마지막에 '\0' 문자 삽입. 입력 도중 delim에 지정된 구분 문자를 만나면
//												지금까지 읽은 문자를 배열 s에 저장하고 리턴
// 
// 
// istream& getline(char* s, int n, char delim='\n'): get()과 동일. 하지만 delim에 지정된 구분문자를 스트림에 제거
// 
// 
// 
// 
// 
// getline()은 delim에 지정된 구분 문자를 만날 때까지, 혹은 n-1개의 문자를 모두 읽을 때까지
// 배열 s에 문자를 읽어들이는 함수이다. delim 매개변수가 생략되면 <Enter>키가 입력될 때까지
// 한 라인을 읽는다.
// 
// char line[80];
// cin.getline(line,80);
// 
// getline()이 delim 문자를 스트림 버퍼에서 제거하는 것과 달리, get()은 delim 문자를 버퍼에 그대로 
// 남겨 둔다. 그러므로 get()으로 한줄 읽기를 한 후, 연이어 get()으로 입력 스트림에서 읽으면 delim
// 문자를 다시 마주치게 되어 읽지 않고 리턴한다.
// 
// 그래서 get()으로 여러 라인을 연속하여 읽을 때 각 라인마다 스트림 버퍼에서 강제로 '\n'을 제거하지 않으면
// '무한 루프'에 빠질 수 있다.
// 
// 
// 
// 잠깐: 한줄을 읽고자 할 때 get()과 getline() 중 어떤 것이 좋은가?
//		getline()을 쓰는 것이 좋다. getline()은 한 줄의 끝을 표시하는 '\n' 문자를 cin 버퍼에서 제거하기 때문에,
//		그 다음에 다시 한 줄을 읽을 때 '\n' 처리에 고민하지 않아도 된다.
// 
//


int main() {
	char line[80];
	cout << "cin.getline() 함수로 라인을 읽는다." << endl;
	cout << "exit을 입력하면 루프가 끝난다." << endl;
	int no = 1; //라인 번호
	while (true)
	{
		cout << "라인 " << no << ">>";
		cin.getline(line, 80); /// 한 라인의 문자열 읽기, 79개의 문자 읽음
		if (strcmp(line, "exit") == 0)
			break;
		cout << "echo -->";
		cout << line << endl;	// 읽은 라인은 화면에 출력
		no++;	// 라인 번호 증가


	}
}

//
//		입력 스트림의 문자 건너 뛰기
// 
// 다음 ignore() 멤버 함수를 이용하면 버퍼에서 문자들을 제거할 수 있다.
// 
// istream& ignore(int n=1,int delim=EOF)		: 입력 스트림에서 n개 문자 제거. 도중에 delim 문자를
//												  delim 문자를 제거하고 리턴
// 
// 
// ex)
// 
// cin.ignore(10);// 입력 스트림에서 10개의 문자 제거
// cin.ignore(10,'\n'); // 입력 스트림에서 10개의 문제 제거. 제거 도중 '\n'을 만나면 '\n'을 제거하고 중단
// 
// 
// 
//		
// 
//		읽은 개수 알아내기
// 
// istream의 gcount() 멤버 함수를 이용하여 최근에 읽은 문자의 개수를 알아낼 수 있다.
// 
// 
// 
// gcount()를 이용하면 <Enter> 키를 포함하여 실제 읽은 문자의 개수를 알아낼 수 있다. 다음 사례를 보자.
// 
// char line[80];
// cin.getline(line,80);
// int n=cin.gcount();	// cin.getline()에서 읽은 문자의 개수 리턴
// 
// 
// 
// 
// 위의 코드에서 사용자가 'Hello<Enter>'를 입력하면 cin.getline(line,80)가 읽은 문자의 개수는 6개이다.
// 그러므로 cin.gcount()는 6을 리턴한다. 그리고 line[] 배열에는 'Hello\0'가 들어있다.
// 
// 하지만 다음과 같이 get()으로 라인을 읽을 경우 ,사용자가 'Hello<Enter>' 키를 입력하면 cin.gcount()는 5를 
// 리턴한다.
// 
// getline()과 달리 get() '\n' (<Enter> 키)을 cin의 스트림 버퍼에 그대로 남겨두기 때문이다.
//								
//
