#include <iostream>
#include <string>
using namespace std;


class Power {
	int kick;
	int punch;
	string word;
public:
	Power(int kick = 0, int punch = 0,string word="") {
		this->kick = kick;
		this->punch = punch;
		this->word = word;
	}
	void show();
	Power& operator +=(Power op2);
};



void Power::show() {
	cout << "kick= " << kick << "punch= " << punch<< word<<endl;
}

Power& Power::operator+=(Power op2) {
	kick = kick + op2.kick;
	punch = punch + op2.punch;
	word += op2.word;
	return *this;
}
int main() {
	Power a(3, 5,"°¡"), b(4, 6,"°¡°­"), c;
	a.show();
	b.show();
	c = a+=b;
	a.show();
	c.show();
}
