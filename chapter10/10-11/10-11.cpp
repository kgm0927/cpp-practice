#include <iostream>
#include <vector>
using namespace std;

// iterator 사용
//
// iterator는 컨테이너 안에 있는 원소들을 하나씩 차례대로 접근하이 위한 원소에 대한
// 포인터이다.
// 
// iterator를 생성하려면 컨테이너 템플릿에 구체적인 타입을 지정하여, 원소의 타입이 드러나도록 한다.
// 밑의 코드는 vector<int>의 원소에 대한 iterator 변수 it를 생성하는 코드이다.
// 
// vector<int>::iterator it;
// 
// 
// 
// it 변수는 int 값을 원소로 가지는 벡터의 원소를 가리키는 포인터이다. 현재 it는
// 어떤 원소도 가리키도 있지 않다. v.begin()은 벡터 v의 첫 번째 원소의 주소를 리턴하므로,
// 다음 코드를 실행하면 it는 벡터 v에 있는 첫번째 원소를 가리킨다.
// 
// vector<int> v;
// it=v.begin(); // v의 첫 번째 원소에 대한 주소를 it에 저장한다.
// 
// 
// 
// 
// 다음과 같이 ++ 연산자를 이용하여 it가 다음 원소를 가리키게 한다. -- 연산자를 이용하여 후진시킬 수도 있다.
// 
// it++; // 벡터의 다음 원소를 가리킴.
// 
// 
// it는 포인터이므로 포인터 전수 연산이 가능하다. it++; 는 it=it+1; 과 동일하다. 또한
// 다음과 같이 it가 가리키는 원소의 값을 읽거나 쓸 수 있다.
// 
// int n = *it;		// it가 가리키는 원소의 값을 n에 읽어 온다.
// *it = n;			// it가 가리키는 원소에 5를 쓴다.
// 
// 
// 
// 
// 다음 코드를 실행하면 it가 벡터 v의 끝을 가리킨다.
// 
// it=v.end();
// 
// 
// 여기서, v.end()는 마지막 원소가 아니라, 마지막 원소 다음 위치에 대한 주소를
// 리턴한다는 점을 주목해야 한다.
// 
// 
//


int main() {
	vector<int> v;		// 정수 벡터의 생성
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;		// 벡터 v의 원소에 대한 포인터 it 선언

	for (it = v.begin();  it!=	v.end();it ++)
	{// iterator를 이용하여 모든 원소 탐색


		int n = *it;	// it가 가리키는 원소 값 리턴
		n = n * 2;		// 곱하기
		*it = n;		// it가 가리키는 원소에 값 쓰기
	}

	for (it  = v.begin();  it!=v.end() ; it++) // 벡터 v의 모든 원소 출력
	{
		cout << *it << ' ';
	}
	cout << endl;


}