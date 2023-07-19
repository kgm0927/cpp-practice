#include <iostream>
using namespace std;




//
// 포맷 함수 활용- 너비 설정, 빈칸 채우기, 유효 숫자 자리수 설정
// 
// ostream 클래스의 멤버 함수 width(), fill(), precision()은 각각 출력되는 필드의, 너비,
// 유효 숫자 개수, 빈칸을 채우는 문자 등을 지정하는 데 사용된다. 이 함수로 지정된 포맷은
// << 연산자를 이용하여 출력될 때만 적용된다.
// 
// 
// 
// 
// 
// 
// * 필드의 최소 너비 설정, width()
// 
// width() 함수는 하나의 필드가 차지하는 화면의 최소 너비를 지정한다.
// 
// int width(int minWidth): 출력되는 필드의 최소 너비를 minWidth로 설정하고 이전에 설정된
//							너비 값 리턴
// 
// 
// 
// 
// cout.width(30); // 다음에 출력되는 "Hello"를 10칸으로 지정
// cout<< "Hello"<<endl;
// cout.width(5);	// 다음에 출력되는 정수 12를 5칸으로 지정
// cout<< 12<<endl;
// 
//						
// 
// 다만, width()의 효과는 호출 직후 하나의 필드에만 적용되므로 주의하여야 한다.
// 
// 
// cout<< '%';
// cout.width(10);
// cout<< "Korea/"<<"Seoul/"<<"City"<<endl;
// 
// A): % Korea/Seoul/City
// 
// 
// cout.width(10)에 의해 지정된 너비 10은 오직 "Korea/" 문자열에만 적용되었다.
//
// 
// 
// 
// 
// 
// * 필드의 빈 공간 채우기, fill()
// 
// 필드의 실제 크기가 width()에 의해 정의된 너비보다 작을 때, 남은 칸은 빈칸으로 채워진다.
// fill() 함수를 사용하면 빈칸을 채울 문자를 지정할 수 있다.
// 
// char fill(char cFill): 필드의 빈칸을 cFill 문자로 채우도록 하고 이전 문자값 리턴 
// 
// 
// 
// 빈칸을 '^' 문자로 채우는 예는 다음과 같다.
// 
// cout.fill('^');
// cout.width(10);
// cout<< "Hello"< endl;
// 
// A): ^^^^^Hello
// 
// 
// 최소 너비를 10으로 지정하고 "Hello" 문자열을 출력하면 5개의 문자가 출력되므로 빈칸에 5개의 '^'가 삽입된다.
// 디폴트가 오른쪽 정렬이기에 빈칸은 필드 앞쪽에 생긴다.
// 
// 
// 
// 
// * 유효 숫자 자리수 지정, presicion()
// 
// 출력 스트림은 숫자를 출력할 때 유효 숫자 자리수를 디폴트 6으로 정하고 있다. 개발자는
// 다음과 같은 precision() 멤버 함수를 호출하여 유효 숫자의 자리수를 변경할 수 있다.
// 
// int precision(int np): 출력되는 수의 유효 숫자 자리수를 np개로 설정. 정수 부분과 소수점 이하의 수의 자리를 모두
//						  포함하고 소수점(.)은 제외
// 
// 
// cout.precision(5);
// cout<< 11./3.;
// 
// A): 3.6667
// 
// 
// 제일 마지막 소수점은 반올림한다.
// 
// 
// 
// 

void showWidth() {
	cout.width(10);		// 다음에 출력되는 "Hello"를 10칸으로 지정
	cout << "Hello" << endl;
	cout.width(5);		// 다음에 출력되는 정수 12를 5 칸으로 지정
	cout << 12 << endl;


	cout << '%';
	cout.width(10);	// 다음에 출력되는 "Korea/"만 10 칸으로 지정


	cout << "Korea/" << "Seoul/" << "City" << endl;
}

int main() {
	showWidth(); // width() 사용 사례
	cout << endl;

	cout.fill('^'); // fill()을 적용한 후 width()의 사례를 보여준다.
	showWidth();
	cout << endl;

	cout.precision(5);	// precision() 사용 예
	cout << 11. / 3. << endl;
}