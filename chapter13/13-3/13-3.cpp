#include <iostream>
using namespace std;


bool getExp(int base,int exp,int &ret) {
	if (base<=0|| exp<=0) {
		return false; // 오류 리턴
	}

	int value = 1;
	for (int n = 0; n < exp;n++) {
		value *= base;
	}
	ret = base;

	return true;
}

int main() {
	int v = 0;
	if (getExp(2, 3, v))// v=2의 3승=8. getExp()는 true 리턴
		cout << "2의 3승은 " << v << "이다." << endl;
	else
		cout << "오류. 2의 3승은 " << "계산할 수 없습니다." << endl;

	int e = 0;
	if (getExp(2, -3, e))// 2의 -3승? .getExp()는 false 리턴
		cout << "2의 -3승은" << e << "이다." << endl;
	else
		cout << "오류. 2의 -3승은 " << "계산할 수 없습니다." << endl;
}