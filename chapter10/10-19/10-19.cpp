#include <iostream>
#include <vector>
#include <algorithm>// for_each() 함수를 사용하기 위함.
using namespace std;

//
// STL 템플릿에 람다식 활용
// 
// 람다식은 STL 템플릿을 사용하여 프로그램을 작성할 때 더욱 유용하다.
// 
// 
// 
// 
//



void print(int n) {
	cout << n << " ";
}

int main() {
	vector<int> v = { 1,2,3,4,5 };
	for_each(v.begin(),v.end(),print);
	// for_each()는 벡터 v의 첫번째 원소 (v.begin())부터 끝(v.end())까지 검색하면서,
	// 각 원소에 대해 3번째 매개 변수인 print(int n) 호출. 매개변수 n에 각 원소값 전달
}

//
// STL 함수 for_each()를 사용하여 벡터의 모든 원소를 출력
// 
// for_each()는 컨테이너의 각 원소를 검색하는 STL 알고리즘 함수이다. for_each()는 컨테이너와
// 각 원소에 대해 3번째 매개 변수에 주어진 함수를 호출한다.
//