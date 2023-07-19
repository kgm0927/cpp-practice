#include <iostream>
#include <cstring>
using namespace std;

//
//			한줄 읽기
// 
// 키보드나 파일로부터 읽는 프로그램을 작성하다보면, 한 줄 단위로 읽는 경우가
// 많다. 다음은 입력 스트림으로부터 한 줄을 읽어 배열에 저장하는 함수이다.
// 
// 
// 
// istream& get(char* s,int n,char delim='\n'): 입력 스트림으로부터 최대 n-1개의 문자를 읽어 배열 s에 젖아하고 마지막에 '\0' 문자 삽입.
//												입력 도중 delim에 지정된 구분 문자를 만나면 지금까지 읽은 문자를 배열 s에 저장하고 리턴
// 
// 
// 
// istream& getline(char* s,int n, char delim='\n'): get()과 동일. 하지만 delim에 지정된 구분 문자를 스트림에서 제거
//													
//												
// 
//
