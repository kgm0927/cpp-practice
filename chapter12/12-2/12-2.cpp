// 
// 
//			>> 연산자를 이용한 텍스트 파일 읽기
// 
// 파일을 읽는 과정도 파일에 쓰는 과정과 유사하다. 우선 다음과 같이 ifstream 클래스를 이용하여 파일 입력 스트림 객체를
// 생성한다.
// 
// 
// ifstream fin; // 파일 입력 스트림 객체 fin 생성
// 
// 
// 그리고 open() 함수를 이용하여 파일을 읽고, 열기의 성공 여부를 검사한다.
// 
// fin.open("c:\\temp\\student.txt");
// if(!fin){
//		cout<<" 파일을 열 수 없다.";
//		return 0;
// }
// 
// 
// 그리고 읽기를 마치고자 하면 다음과 같이 파일을 닫는다.
// 
// 
// fin.close();
// 
// 
// 잠깐! : 파일의 경로명
// 
// 반드시 백슬래시('\')가 두번 쓰여져야 한다.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin;

	fin.open("c:\\temp\\student.txt");
	if (!fin) {// 파일 열기 실패
		cout << "파일을 열 수 없다.";
		return 0;
	}

	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();// 파일 읽기를 마치고 파일을 닫는다.

}