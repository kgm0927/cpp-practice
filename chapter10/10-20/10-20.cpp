#include <iostream>
#include <vector>
#include <algorithm>// for_each() 알고리즘 함수를 사용하기 위함
using namespace std;

int main() {
	vector<int > v = { 1,2,3,4,5 };

	//for_each()는 벡터 v의 첫번째 원소부터 끝까지 검색하면서,
	// 각 원소에 대해 3번째 매개 변수인 람다식 호출, 매개 변수 n에 각 원소 값 전달
	for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
}


//
// C++ 에서 람다식의 의미
// 
// 특별히 람다가 유용한 경우는 다음과 같다.
// 
// * 한번만 호출하고 재사용되지 않기 때문에 함수에 이름을 붙일 필요가 없는 경우
// * STL 알고리즘 함수의 매개 변수에 연산 코드를 넘기는 경우, 연산 코드를 익명의 람다식으로 작성
//
//