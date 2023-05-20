#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//
// STL 알고리즘 사용하기
// 
// STL 알고리즘은 전역 함수로서, STL 컨테이너 클래스의 멤버 함수가 아니며 템플릿으로 작성되어 있다.
// STL 알고리즘은 iterator와 함께 작성한다.
// 
// STL sort() 함수의 사용 예를 보자. sort() 함수는 두 개의 매개 변수를 가지고 있다. 첫 번째 매개 변수에 정렬을
// 시작할 원소에 대한 iterator 주소를, 두 번째 매개변수는 마지막 원소 다음의 interator 주소를 주어야 한다.
//


int main() {
	vector<int> v;	// 정수 벡터 생성

	cout << "5개의 정수를 입력하세요.>>";
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);// 키보드에서 읽은 정수 벡터에 삽입
	}

	// v.begin()에서 v.end() 사이의 값을 오름차순으로 정렬
	// sort() 함수의 실행 결과 벡터 v의 원소 순서가 변경됨

	sort(v.begin(), v.end());

		vector<int>::iterator it;// 벡터 내의 원소를 탐색하는 iterator 변수 선언

		for ( it = v.begin(); it < v.end(); it++)// 벡터 v의 모든 원소 출력
		{
			cout << *it << ' ';
		}
		cout << endl;

}