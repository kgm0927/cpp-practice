//
//
// 
// 
// '예외 값'으로 int, double 등의 기본 타입을 사용할 때보다 '클래스'를 사용하는
// catch(){} 블록에 '더 많은 정보를 전달'할 수 있다. 지금부터 '예외 값'으로 사용할
// 클래스를 작성해보자.
//
#include <iostream>
#include <string>
using namespace std;


class MyException {
	int lineNo;
	string func, msg;
public:
	MyException(int n, string f, string m) {
		lineNo = n;
		func = f;
		msg = m;
	}

	void print() {
		cout << func << ":" << lineNo << ", " << msg << endl;
	}
};


class DivideByZeroException : public MyException {
public:
	DivideByZeroException(int lineNo,string func,string msg): MyException(lineNo,func,msg){}
};

class InvalidInputException : public MyException {

public:
	InvalidInputException(int lineNo,string func,string msg): MyException(lineNo,func,msg){}
};

int main() {
	int x, y;
	try {
		cout << "나눗셈을 합니다. 두 개의 양의 정수를 입력하세요>>";
		cin >> x >> y;

		if (x < 0 || y < 0) {		//라인번호 //함수 // 예외 메세지
			throw InvalidInputException(33, "main()", "음수 입력 예외 발생");
		}


		if (y == 0)
			throw DivideByZeroException(35,"main()","0으로 나누는 예외 발생");
		cout << (double)x / (double)y;

	}
	catch (DivideByZeroException &e) {
		e.print();
	}
	catch (InvalidInputException &e) {
		e.print();
	}
}