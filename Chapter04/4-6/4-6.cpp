#include <iostream>
using namespace std;

// 배열의 동적 할당 및 반환
// 데이터타입 *포인터변수=new 데이터타입 [배열의 크기] (tip: 반드시 배열의 크기가 초기화되어야 한다.)
// 이를 통해 단순히 변수 뿐만이 아니라, 구조체, 클래스 등등의 타입을 할당할 수 있다.
int main() {
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n;// 정수의 개수 입력

	if (n <= 0)return 0;
	int* p = new int[n];// n 개의 정수 배열 동적 할당
	if (!p) {
		cout << "메모리를 찾을 수 없습니다.";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "번째 정수: "; // 프롬프트 출력
		cin >> p[i];// 키보드로부터 정수 입력
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += p[i];
	}
	cout << "평균 =" << sum / n << endl;
	delete[]p;// 배열 메모리 반환.
}