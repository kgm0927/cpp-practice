//
// 
// get()과 EOF
// 
// '파일의 끝'을 만나면 읽기를 멈추어야 하는데,get()은 파일의 끝을 어떻게 인식할까?
// 
// 
// * get() 함수와 EOF 관계
// 
// get()은 한 바이트를 읽고 '파일 포인터'를 다음 바이트 위치로 '전진'시킨다. get()이 파일의 마지막 문자를 읽고 나면,
// 파일 포인터는 전진하여 파일의 끝을 가리킨다. 그러나 파일 끝에 도달하였는지는 아직 알 수 없기 대문에, 이때 eof() 함수를
// 호출하면 false(파일 끝에 도달하지 않았음)을 리턴한다. 만약 get()을 한 번 더 실행하면, 이 때 비로소 get()은 더 읽을 수 없는
// 파일 끝임을 알게 되어 EOF(-1)을 리턴하고, 스트림 내부에 'eofbit 플래그'를 1(true)로 설정한다. 이제 eof() 함수를 호출하면 true
// 를 호출한다.
// 
// 
// * get()으로 파일의 끝을 인지하는 방법
// 
// get()이 리턴한 값과 EOF를 다음과 같이 비교하면 된다.
// 
// 
// 
// 
// while(true){
// 
//		int c=fin.get();	// 파일에서 문자(바이트)를 읽는다.
//		if(c==EOF){
//			...	// 파일의 끝을 만난 경우. 이에 대응하는 코드를 작성
//			break;	// while 루프에서 빠져나온다.
//	}
//	else{
//			...  // 읽은 문자(바이트) c를 처리한다.
//	}
//}
// 
// 
// 
// 
// 이 코드는 다음과 같이 간단하게 작성되기도 한다.
// 
// while((c=fin.get())!=EOF){
//		...		// 파일에서 읽은 문자(바이트) c를 처리하는 코드
// }
// 
// 
// 앞의 코드들은 텍스트 I/O나 바이너리 I/O에 상관없이 파일을 읽는 경우에 사용된다.
// 
// 
// 
// * 파일의 끝을 잘못 인지하는 코드
// 
// 
// 
// eof()는 오직 eofbit 플래그의 값이 1인지만 확인하여 리턴한다. 그러므로 다음과 같이 eof()를 이용하여 파일의 끝을 검사하면
// 문제가 발생할 수 있다.
// 
// 
// while(!fin.eof()){
//		int c=fin.get();	// 문제의 위치. 마지막 읽은 EOF(-1) 값이 c에 리턴이 된다.
//			...// 읽은 값 c를 처리하는 코드.
//	}
// 
// 위의 코드는 fin.get()이 파일의 마지막 바이트를 읽고 파일 포인터가 끝을 가리키는 상황에서 while 문의 eof()가 실행되면 eof()는
// false를 리턴한다. 왜냐하면 eofbit가 1로 셋되어 있지 않기 때문이다. 이때 다시 int c=fin.get()이 실행되면 eofbit이 1로 셋 되고
// get()은 EOF(-1)를 리턴하여 c는 -1 값을 가진다.
// 
// 바로 그 다음 라인에서 c 값(-1)을 정상적으로 읽은 문자로 착각하고 처리하면 문제가 발생한다.
// 
// fin.get() 함수를 사용할 때는 호출한 이후에 바로 fin.get()를 호출하여 파일 데이터를 읽었는지 확인하면 모든 문제가 해결된다.
// 
// 
// 
// 
// 
// 
// 
// *잠깐!: get()의 리턴 타입이 int인 이유? EOF 때문
// 
// 다음 코드는 fin에 연결된 텍스트 파일을 읽고 화면에 출력하는 코드이다.
// 
// int c;
// 
// while((c=fin.get())!=EOF){
//		cout<<(char)c;
//		}
// 
// 두 가지 의문
// 
// 1: get() 함수는 한 바이트나 문자 하나를 리턴하는데 왜 리턴 타입이 char이 아니라 int일까?
// 
// 2: get()이 파일의 끝을 만나면 -1(EOF)을 리턴하는데, 파일에 -1이 있다면, 이 둘을 어떻게 구분할
// 수 있는가?
// 
// 
// 이 질문에 대한 답은 모두 파일 끝 처리와 연관되어 있다. 만일 스트림이나 파일에 0xFF의 값이
// 있다고 하면, get()은 0xFF를 리턴한다. 이 때 사람들은 '0xFF는 -1 인데, 파일의 끝을 표시하는 -1
// 과 혼동되네.'라고 생각할 수 있다.
// 하지만 get()은 int 타입으로 값을 리턴하므로, 읽는 바이트 0xFF를 32비트의 0x000000FF로 리턴한다. 이것은
// -1이 아니라 255이다. EOF는 -1로서 0xFFFFFFFF이다. get()이 파일에서 0xFF의 값을 읽거 리턴하는 것과 확연히
// 구분이 된다.
// 
// 
// 
// 
// 
// 
// 
//				ios::app 모드로 텍스트 파일 덧붙여 쓰기
// 
// ios::app 모드를 이용하며 파일의 끝에 다른 파일을 덧붙여 쓸 수 있다. 밑의 예제는
// fstream을 이용해서 c:\temp\student.txt 파일에다 c:\windows\system.ini 파일을 덧붙여
// 기록하는 예를 보인다.
// 
// 
// const char* firstFile="c:\\temp\\student.txt";
// const char* secondFile="c:\\windows\\system.ini";
// 
// fstream fout(firstFile, ios::out | ios::app);	// 첫 번째 파일을 추가 쓰기 모드로 열기
// fstream fin(secondFile, ios::in);				// 두 번째 파일을 읽기 모드로 열기
// 
// get() 함수를 이용하여 두 번째 파일 데이터를 읽고, put() 함수를 이용하여 첫 번째 파일 끝에
// 덧붙여 기록한다.
// 
// 
// 
// 
// 
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "c:\\temp\\student.txt";
	const char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);// 쓰기 모드로 파일 열기
	if (!fout) {
		cout << firstFile << " 열기 오류";
		return 0;
	}

	fstream fin(secondFile, ios::in);	// 읽기 모드로 파일 열기
	if (!fin) {// 열기 실패 검사
		cout << secondFile << " 열기 오류";
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {// 파일 끝까지 문자 읽기
		fout.put(c); // 읽은 문자 기록
	}

	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
}