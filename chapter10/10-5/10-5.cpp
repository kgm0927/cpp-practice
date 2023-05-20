#include <iostream>
using namespace std;

// 중복 함수가 템플릿 함수보다 우선
// 
//  템플릿 함수와 이름이 동일한 함수가 중복되어 있을 때, 컴파일러는 중복된 함수를
// 템플릿 함수보다 우선하여 바인딩한다.
//

template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << '\t';

	}
	cout << endl;
}

void print(char array[], int n) {	// 템플릿 함수와 동일한 이름의 함수 중복
	for (size_t i = 0; i < n; i++)
	{
		cout <<(int)array[i] << '\t';	// array[i]를 int 타입으로 변환하여 정수 출력
	}
	cout << endl;
}

int main() {
	int x[] = {1,2,3,4,5};
	double d[5] = { 1.1,1.2,1.3,1.4,1.5 };
	print(x, 5);	// 템플릿으로부터 구체화한 함수 
	print(d, 5);	// 텝플릿으로부터 구체화한 함수

	char c[5] = { 1,2,3,4,5 };
	print(c, 5);
}

// 템플릿 함수에 디폴트 매개 변수 사용
// 
// 템플릿에서 함수 선언에 디폴트 매개 변수를 사용할 수 있다. 앞의 mcopy() 템플릿이 디폴트
// 매개 변수를 가지도록 수정하면 다음과 같다.
// 
// template<class T1,class T2>
// void mcopy(T1 src[], T2 dest[], int n=5){
// 
//		for(int i=0; i<n;i++)
//			dest[i]=(T2)src[i];
// 
// }
//