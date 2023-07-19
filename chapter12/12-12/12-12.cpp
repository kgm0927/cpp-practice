//
//
// 
// 
// 
// 12.8 임의 접근
// 
// 순차 접근과 임의 접근
// 
// 순차 접근(sequential file access): 파일의 처음부터 끝까지 순차적으로 읽거나 순차적으로 파일에
// 기록하는 방식이다.
// 
// 
// 임의 접근(random file access): 파일 내의 임의의 위치로 옮겨 다니면서 읽거나 쓰는 방식
// 
// 
// C++ 파일 입출력 시스템의 '디폴트'는 '순차 접근'이다.
// 
// 
// 
// 파일 포인터
// 
// 파일은 연속된 바이트의 집합이다. 
// 
// 파일 포인터(file pointer): 파일 내의 읽고 쓸 바이트의 위치를 가리키는 일종의 마크(mark)를 의미한다.
// 
// 
// C++에서 파일 포인터는 다음 2가지가 있으며, 열려진 파일(혹은 스트림)마다 별도의 파일 포인터가 유지된다.
// 
//		
// 
//		* get pointer- 파일 내의 일기 지점을 가리키는 포인터
//		* put pointer- 파일 내의 쓰기 지점을 가리키는 포인터
// 
// 
// ifstream이나 읽기 모드(ios::in)로 열려진 fstream은 get pointer 만을 가진다.
// get(),read(), getline(), >> 등의 읽기 연산은 get pointer가 가리키는 지점에서 읽고,
// 읽은 바이트 수 만큼 get pointer를 전진시킨다.
// 
// 반대로 ofstream이나 쓰기 모드(ios::out)로 열려진 fstream은 put pointer 만을 가진다. put(),
// write(), << 등 의 쓰기 연산은 put pointer 가 가리키는 위치에 데이터를 쓰고 쓴 바이트 수만큼
// put pointer를 전진시킨다.
// 
// 
// 
//			파일 모드와 파일 포인터
// 
// 
// '파일 포인터의 위치'는 '파일 모드'에 따라 다르게 설정된다. 읽기 모드(ios::in)로 파일을 열면 get pointer
// 는 파일의 맨 처음 위치를 가리키며, 쓰기 모드(ios::out)로 파일을 열면 put pointer가 파일의 맨 처음 위치를 가리킨다.
// 
// ios::ate 모드로 파일을 열면 put pointer를 파일의 맨 끝, 즉 EOF 위치를 가리키며 여기서부터 쓰기가 시작된다. ios::app
// 모드로 파일을 열면 put pointer는 파일의 처음 위치를 가리키지만, 파일 쓰기를 하면 자동으로 맨 끝으로 put pointer를 옮겨서
// 파일의 끝에 쓰기를 수행한다.
// 
// 
// 
// 
// 
// 
//			임의 접근 방법
// 
// 
// 임의의 접근 방법의 핵심은 '파일 포인터'의 위치를 '임의의 위치로 이동'시키는데 있다. 파일 포인터는 읽기나
// 쓰기 이후 항상 전진하지만, 다음 멤버 함수를 이용하면 언제든지 파일 포인터를 임의의 위치로 이동시킬 수 있다.
// 
// 
//		* streampos는 파일 포인터의 '절대적 위치' 값으로 실제 long 타입
// 
//		* streamoff는 파일 포인터의 '상대적 위치'값으로 실제 long 타입
// 
//	seekbase에 사용되는 상수는 다음과 같다.
// 
// 
//	seekbase	|					설명
// -------------------------------------------------------------------
//	ios::beg			파일의 처음 위치를 기준으로 파일 포인터를 움직인다.
// -------------------------------------------------------------------
//	ios::cur			현재 파일 포인터의 위치를 기준으로 파일 포인터를 움직인다.
// -------------------------------------------------------------------
//	ios::end			파일의 끝(EOF) 위치를 기준으로 파일 포인터를 움직인다.
// 
// 
//		istream& seekg(streampos pos);
//		: 정수 값으로 주어진 절대 위치 pos로 get pointer를 옮김
// 
//		istream& seekg(streamoff offset,ios::seekdir sookbase);
//		: seekbase를 기준으로 offset 만큼 떨어진 위치로 get pointer를 옮김
// 
//		ostream& seekp(streampos pos)
//		: 정수 값으로 주어진 절대 위치 pos로 put pointer를 옮김
// 
//		ostream& seekp(streamoff offset, ios::seekdir seekbase);
//		: seekbase를 기준으로 offset 만큼 떨어진 위치로 put pointer를 옮김
// 
//		streampos tellg()
//		: 입력 스트림의 현재 get pointer의 값 리턴
// 
//		streampos tellp()
//		: 출력 스트림의 put pointer의 값 리턴
// 
// 
// 
// 
// 파일 포인터는 '인덱스 0부터 시작'한다. seekg()와 tellg()는 입력 스트림과 사용하고,
// seekp()와 tellp()는 출력 스트림에서만 사용한다.
// 
// 
// 
// 
// 
// * 절대 위치로 파일 포인터 옮기기
// 
// 
// 다음은 seekg(5)를 이용하여 파일의 인덱스 5(0부터 시작) 위치로 파일 포인터를 옮기고
// 0x49 값을 읽는 사례이다.
// 
// fin.seekg(5);		// get pointer를 파일의 인덱스 5 위치로 옮긴다.
// int n=fin.tellg();	// n은 5가 된다.
// int c=fin.get();		// c=0x49
// 
// 
// 
// 
// 
// 
// * 상대 위치로 파일 포인터 옮기기
// 
// 매개 변수를 2개 가진 seekg(), seekp() 함수는 seekbase를 기준으로 offset만큼 상대
// 위치로 파일 포인터를 움직인다. 사용 예를 들면 다음과 같다.
// 
// fin.seekg(10,ios::beg);		// 파일 시작점을 기준으로 get pointer를 10바이트 전진시킨다.
// fin.seekg(-1, ios::cur);		// 현재 위치에서 get pointer를 한 바이트 후진시킨다.
// fin.seekg(0,ios::endl);		// 파일의 맨 끝 (EOF 위치)으로 get pointer를 움직인다.
//								// 여기서부터 읽을 데이터는 없다.  
// 
// 
// 
// * 파일의 맨 마지막 문자를 읽는 경우
// 
// fin.seekg(-1,ios::end);			// get pointer를 파일의 마지막 문자 위치로 보낸다.
// int c=fin.get();					// 파일의 마지막 문자 0x2B를 c에 읽어 온다.
//									// get() 실행 후 get pointer는 EOF를 가리킴
// 
// 
// 
// * 10바이트 간격으로 문자를 읽고자 하는 경우
// 
// int c;
// while((c=fin.get())!=EOF){		// get()에 의해 get pointer는 1바이트 전진 이동
//		fin.seekg(9,ios::cur);		// 나머지 9바이트를 건너뛰어 get pointer 전진 이동
//		}
// 
// 
// 
// 
// 
// 
// 
//	* 텍스트 파일을 거꾸로 화면에 출력하는 경우
// 
// fin.seekg(0,ios::end);	// get pointer를 파일의 EOF 위치로 이동
// 
// int filesize=fin.tellg();	// get Pointer 값이 바로 파일의 크기이다.
// 
// for(int i=0; i<filesize; i++){
//		fin.seekg(fileSize-1-i, ios::beg);			// 파일의 처음을 기준으로 get pointer 이동
//		int c=fin.get();
//		cout<<(char)c;
//		}
//
// 
// 
// 
//			파일 포인터를 이용하여 크기 알아내기
// 
// C++ 표준 입출력 라이브러리에서는 파일 크기를 아는 방법을 제공하지 않는다. 그렇지만 파일 포인터를
// 이용하여 파일 크기를 쉽게 알아 낼 수 있다. '파일 포인터를 파일의 맨 끝으로 이동'시킨 뒤 파일 포인터의
// 위치를 알면 그 값이 '파일 크기'이다
//

#include <iostream>
#include <fstream>
using namespace std;

long getFileSize(ifstream &fin) {
	fin.seekg(0, ios::end);
	long length = fin.tellg();// get pointer 리턴

	return length;	// length는 파일의 크기와 동일
}



int main() {
	const char* file = "c:\\windows\\system.ini";

	ifstream fin(file);
	if (!fin) {// 열기 실패 검사

		cout << file << " 열기 오류" << endl;
		return 0;

	}

	cout << file << "의 크기는" << getFileSize(fin);
	fin.close();

}
