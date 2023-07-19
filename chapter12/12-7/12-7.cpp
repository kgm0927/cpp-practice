//
//
// 
// 
// 12.6 바이너리 I/O
// 
// 바이너리 I/O는 파일의 각 바이트를 바이너리 값 그대로 열거나, 변수나 버퍼의 바이너리
// 값을 그대로 파일에 저장하는 저수준(low level) 입출력 방식이다. 그러므로 텍스트 파일은
// 텍스트 I/O 바이너리 I/O로 읽고 쓰는 것이 둘 다 가능하지만, 바이너리 파일은 반드시
// I/O를 이용해야 한다.
// 
// 
// 
// 
//				바이너리 I/O로 파일 열기
// 
// 
// 바이너리 I/O를 사용하기 위해서는 파일을 열 때 'ios::binary 파일 모드'를 지정해야 한다.
// desert.jpg 파일을 바이너리 I/O로 입출력하기 위해 파일 스트림을 여는 코드이다.
// 
// 
// ifstream fin;
// fin.open("desert.jpg",ios::in | ios::binary);	// 바이너리 I/O로 파일 읽기 모드 설정
// 
// ofstream fout("desert.jpg",ios::out | ios::binary); // 바이너리 I/O로 파일 쓰기 모드 설정
// fstream fsin("desert.jpg", ios::in | ios::binary);	// 바이너리 I/O로 파일 읽기 모드 설정
// 
// 
//
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// 소스 파일과 목적 파일의 이름

	const char* srcFile = "c:\\temp\\desert.jpg";
	const char* destFile = "c:\\temp\\copydesert.jpg";

	// 소스 파일 열기

	ifstream fsrc(srcFile, ios::in | ios::binary); // 바이너리 I/O
	if (!fsrc) {// 열기 실패 검사
		cout << srcFile << " 열기 오류" << endl;
		return 0;

	}

	// 목적 파일 열기
	ofstream fdest(destFile, ios::out | ios::binary);	// 바이너리 I/O
	if (!fdest) {// 열기 실패 검사
		cout << destFile << " 열기 오류" << endl;
		return 0;

	}

	// 소스 파일에서 목적 파일로 복사하기

	int c;

	while ((c=fsrc.get())!=EOF)	// 소스 파일을 한 바이트씩 읽는다.
	{
		fdest.put(c); // 읽은 바이트를 파일에 출력한다.

	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();
}
