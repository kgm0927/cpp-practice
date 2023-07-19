//
// 
//			텍스트 파일의 라인 단위 읽기
// 
// 텍스트 파일을 라인 단위로 읽는 경우가 많다. 파일을 라인 단위로 읽는 방법은 두 가지가 있다.
// 
// 
//		* istream의 getline(char *line,int n) 함수 사용
//		* getline(ifstream &fin,string& line) 함수 이용
// 
// 
// 
// * istream의 getline(char* line, int n)
//		istream의 getline() 함수는 스트림에 연결된 입력장치나 파일로부터 한 줄을 읽는 함수로서, 다음과 같이
//		파일로부터 읽는다.
// 
//		char buf[81];	// 한 라인이 최대 80개의 문자로 구성된다고 가정
//	
//		ifstream fin("c:\\windows\\sysyem.ini");
//		while(fin.getline(buf,81)){		// 한 라인이 최대 80개의 문자로 구성. 끝에 '\0' 문자 추가
//				...		// 읽은 라인(buf[])을 활용하는 코드
// 
//		}
//
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "c:\\windows\\system.ini 열기 실패" << endl;
		return 0;
	}
	char buf[81];
	while (fin.getline(buf, 81)) {
		cout << buf << endl;
	}

	fin.close();
}