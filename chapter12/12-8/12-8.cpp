//
// 
// 
//				read() / write()로 블록 단위 파일 입출력
// 
// get()과 put()은 한 바이트 단위로 입출력을 수행하지만, read()와 write()는 '블록 단위로 입출력'한다.
// 
// read() 함수는 ifstream의 멤버로서 ifstream이 상속받으며, write() 함수 역시 ostream의 멤버이며 ostream에서
// 상속받아 사용한다.
// 
// 
// 
// 
// istream& read(char* s,int n)
// // 파일에서 최대 n개의 바이트를 배열 s에 읽어 들임.  파일의 끝을 만나면 읽기 중단
// 
// ostream& write(char* s, int n)
// 배열 s에 있는 처음 n개의 바이트를 파일에 저장
// 
// read(char* s,int n)는 읽는 도중에 파일 끝(EOF)에 도달하면 읽기를 중단하고 리턴한다. read() 함수과
// n개의 바이트를 모두 읽었다고 보장할 수는 없다. 그러므로 read() 후에 'gcount()'를 이용하여 '실제 읽은
// 바이트 수'를 알아낸다. 
// 
// 
// 다음과 같다.
// 
// ifstream fin;
// 
// fin.open("desert.jpg", ios::in | ios::binary);	// 바이너리 I/O 모드로 파일 읽기 지정
// 
// char s[1024];
// fin.read(s,1024);		// 파일로부터 1024 바이트를 읽어 배열 s에 저장
// int n=fin.gcount();		// 앞의 fin.read() 함수가 실제 읽은 바이트 수를 n에 리턴
//							// 배열 s[]에는 n개의 바이트만이 유효
// 
// 
// 
// read()를 사용하면 블록 단위로 한 번에 읽기 때문에, 한 바이트씩 읽어오는 get()을 이용하는 것보다 응용 프로그램의 '속도가 빠르다.'
// 
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";

	ifstream fin;

	fin.open(file, ios::in | ios::binary); // 바이너리 I/O 모드로 파일 열기
	
	if (!fin) {// 열기 실패 검사

		cout << "파일 열기 오류";
		return 0;

	}

	int count = 0;
	char s[32]; // 블록 단위로 읽어들이 버퍼

	while (!fin.eof())// 파일 끝까지 읽는다.
	{
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;

	}

	cout << "읽은 바이트 수는" << count << endl;
	fin.close();
	
}