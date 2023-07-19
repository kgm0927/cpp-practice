#include <iostream>
using namespace std;


//
// 
// 11.6 사용자 조작자 만들기
// 
//	
// 
//  	조작자의 실행 과정
// 
// 사용자는 새로운 조작자를 만들 수 있다. 그 전에 조작자가 어떻게 작동되는지 알아본다. 조작자는 <<,>>와 함께 실행이되는데,
// 밑의 예시는 다음 문장의 endl 조작자가 호출되고 실행되는 과정을 설명한다.
// 
// cout<< endl;
// 
// 
// 
// 
// 
// 
// 
// 
// 컴파일러는 << 연산자가 처리하는 방식과 동일하게 앞의 문장을 다음과 같이 변형한다.
// 
// cout. <<(endl);
// 
// 
// 
// 
// 
// 
// 
// 이 코드는 다음 << 연산자 함수를 호출하며, 'endl() 함수의 주소'가 매개 변수 _f에 전달된다. endl은 <ostream> 클래스에 작성된
// endl() 함수의 이름이므로 함수의 주소이다.
// 
// ostream& ostream:: operator << (ostream& (* _f)(ostream&)){
//		(*_f)(*this);
//		return *this;
// }
// 
// 
// 
// 
// 
// 앞의 코드에서 (*_f)(*this);의 의미를 세분화하면 다음과 같다.
// 
//			(*_f)		--> endl() 함수 호출문
//			(*this)		-->	cout() 객체
//			(*_f)(*this)--> endl(cout); 함수 호출
// 
// 
// 
// 
// 결국 << 연산자 함수는 'endl(cout)'을 '호출'한다. endl() 함수는 <ostream> 헤더 파일에 구현되어 있는데,
// 이렇게 단순화 해 보았다.
// 
// ostream& endl(ostream& outs){
// 
//		outs.put('\n');
//		outs.flush();
//		return outs;
// }
// 
// 
// 
// 
//		새로운 조작자 만들기
// 
// '매개 변수 없는 조작자'는 다음과 같이 모두 동일한 '원형'을 가진다.
// 
//		istream& manipulatorFunction(istream& ins)
//			입력 스트림에 사용되는 조작자 원형
// 
//		ostream& manipulatorFunction(ostream& outs)
//			출력 스트림에 사용하는 조작자 원형
// 
// 
// 
// 
// 조작자들은 모두 <<나 >> 연산자에 의해 동일한 형식으로 호출되기 때문에, 다른 형식으로 조작자 함수를
// 만들 수 없다.
// 
//  
// 
//

ostream& fivestar(ostream& outs) {
	return outs << "*****";

}

ostream& rightarrow(ostream& outs) {
	return outs << "---->";

}




ostream& beep(ostream& outs) {
	return outs << '\a';

}

int main() {
	cout << "벨이 울립니다." << beep << endl;
	cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}