#include<iostream>
#include<string>
#include <map>
using namespace std;

// map 컨테이너의 활용
//
// 
// map(이하 맵이라고 부름)은 '키'와 '값'의 쌍을 원소로 저장하고 '키'를 이용하여 값을
// 검색하는 제네릭 컨테이너이다. map을 이용하기 위해서는 다음과 같이 <map> 헤더 파일과 using 지시어가
// 필요하다.
// 
// #include <map>
// using namespace std;
// 
// * map 컨테이너 생성 및 원소 삽입
// 
// 
// 
// 다음과 같이 map 컨테이너를 생성한다.
// 
// map<string, string> dic;
// 
// 
// 
// map의 insert() 멤버 함수나 [] 연산자를 사용하여 다음과 같이 원소를 저장한다.
// 
// dic.insert(make_pair("love","사랑"));
// dic["love"]="사랑";
// 
// 
// 
// * '키'로 검색하여 '값' 알아내기
// 
// [] 연산자를 이용하면 '키'로 검색하여 '값'을 알아낼 수 있다.
// 
// string kor=dic["love"];
// 
// 
// [] 연산자는 찾을 수 없는 경우 빈 문자열을 ("")을 리턴한다. 다음과 같이
// at()을 이용하여 검색을 할 수 있지만, at()은 찾을 수 없는 경우 예외를 발생시키므로 예외 처리
// 코드를 작성해야 하는 부담이 있다.
// 
// string kor=dic.at("love");
// 
// 맵에 '키'의 데이터가 있는 지 검사하기 위해서는 전형적으로 다음 코드를 이용한다.
// 
// if(dic.find(eng) == dic.end()) // eng의 '키'를 찾을 수 없다면 조건문은 true
// 
// 
// 
// <표 10-5> map의 멤버 함수와 연산자 함수
// 
// 멤버와 연산자 함수							설명
// 
// insert(pair<> &element):				맵에 '키'와 '값'으로 구성된 pair 객체 element 삽입
// at(key_type & key):					맵에서 '키' 값에 해당하는 '값' 리턴
// begin():								맵의 첫 번째 원소에 대한 참조 리턴
// end():								맵이 끝(마지막 원소 다음)을 가리키는 참조 리턴
// empty():								맵이 비어 있으면 true 리턴
// find(key_type& key):					맵에서 '키' 값에 해당하는 원소를 가리키는 iterator 리턴
// erase(interator it):					맵에서 it가 가리키는 원소 삭제
// size():								맵에 들어 있는 원소의 개수 리턴
// operator[key_typ& key]():			맵에서 '키' 값에 해당하는 원소를 찾아 '값' 리턴
// operator=()							맵 차환(복사)
// 
//



int main() {
	map<string, string> dic;			// 맵 컨테이너 생성. 키는 영어 단어, 값은 한글 단어


	// 단어 3개를 map에 저장
	dic.insert(make_pair("love","사랑"));	// ("love","사랑") 저장
	dic.insert(make_pair("apple","사과"));	// ("apple","사과") 저장
	dic["cherry"] = "체리";					// ("cherry","체리") 저장

	cout << "저장된 단어 개수" << dic.size() << endl;

	string eng;

	while (true) {
		cout << "찾고 싶은 단어";
		getline(cin, eng);

		if (eng == "exit")
			break;

		if (dic.find(eng) == dic.end())
			cout << "없음" << endl;	// 사용자로부터 키 입력
		else
			cout << dic[eng] << endl;// "exit"이 입력되면 종료

	}
	cout << "종료합니다 ..." << endl;
}