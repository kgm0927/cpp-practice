#include <iostream>
using namespace std;


bool average(int a[], int size, int& avg) {
	if (size <= 0)
		return false;
	
	int sum = 0;
	
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	avg = sum / size; // 참조 매개 변수 avg에 평균값 전달

	return true;
}

int main() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;

	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;// avg에는 평균이 넘어오고, average()는 true 리턴
	else cout << "매개변수 오류" << endl;

	if (average(x, -2, avg))cout << "평균은 " << avg << endl;// avg의 값은 의미 없고, average()는 false 리턴
	else cout << "매개 변수 오류" << endl;

}

// * 참조에 의한 호출의 장점
// '주소에 의한 호출'은 주소 전달을 위해 &를 사용하고, swap() 코드에서는 *를 반복적으로 사용함에따라 가독성이 떨어진다.
// 하지만 '참조에 의한 호출'은 간단히 변수를 넘겨주기만 하면 되고, 함수 내에서도 참조 매개 변수를 보통 변수처럼 사용하기 때문에
// 쉽고 보기 좋은 코드가 될 수 있다.
// 
// 
// * 참조에 의한 호출로 객체 전달
// 
// '값에 의한 호출'로 객체를 매개 변수에 전달하면 다음 두 가지 사항에 유의해야 한다.
// 
//  - 함수 내에서 매개 변수 객체를 변경하여도, 원본 객체를 변경시키지 않는다.
// - 매개 변수 객체의 생성자가 실행되지 않고 소멸자만 실행되는 비대칭 구조로 작동한다.
// 
// 그러나 참조에 의한 호추른 이 두 가지 사항에 완전히 다르게 작동한다.
// 
// - 참조 매개 변수로 이루어진 모든 연산은 원본 객체에 대한 연산이 된다.
// - 참조 매개 변수는 이름만 생성되므로, 생성자와 소멸자는 아예 실행되지 않는다.
//