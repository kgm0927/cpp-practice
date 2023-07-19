//
//
// int 배열과 double 변수를 바이너리 파일에 저장하고 다시 읽기
// 
// 변수나 배열, 혹은 버퍼의 내용을 저장하기 위해서는 바이너리 I/O를 반드시 사용해야 한다.
// 바이너리 I/O를 이용하므로 저장된 파일은 바이너리 파일이 된다.
// 
// 
// 
//
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	const char* file = "c:\\temp\\data.dat";

	ofstream fout;
	fout.open(file, ios::out | ios::binary);// 쓰기 모드로 파일 열기

	if (!fout) {// 열기 실패 검사
		cout << " 파일 열기 오류";
		return 0;
	}

	int n[] = { 0,1,2,3,4,5,6,7,8,9 };
	double d = 3.15;


	fout.write((char*)n, sizeof(n));		// int 배열 n을 한 번에 파일에 쓴다.
	fout.write((char*)(&d), sizeof(d));		// double 값 하나를 파일에 쓴다.
	fout.close(); 


	// 배열 n과 d 값을 임의의 값으로 변형시킨다.
	for (int i = 0; i < 10; i++)n[i] = 99;
	{
		d = 8.15;
	}

	// 배열 n과 d 값을 파일에서 읽어온다.

	ifstream fin(file, ios::in);

	if (!fin) {// 열기 실패 검사
		cout << "파일 열기 오류";
		return 0;

	}
	fin.read((char*)n, sizeof(n));
	fin.read((char*)(&d), sizeof(n));

	for (int i = 0; i < 10; i++)// 읽은 배열 n을 확인한다.
	{
		cout << n[i] << ' ';
	}
	cout << endl << d << endl;// 읽은 double 값을 확인한다.

	fin.close();


}