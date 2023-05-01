#include <iostream>
using namespace std;

class Power {
	int kick;
	int punch;
	int score;
public:
	Power(int kick=0,int punch=0,int score=0) {
		this->kick = kick;
		this->punch = punch;
		this->score = score;
	}
	void show();
	Power& operator++();

};

void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch <<"score="<<score<< endl;
}

Power& Power::operator++() {
	kick++;
	punch++;
	for (int i = 0; i < 10; i++)
	{
		score++;
	}
	return *this;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a;

	a.show();
	b.show();
}