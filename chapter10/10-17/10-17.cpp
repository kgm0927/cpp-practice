#include <iostream>
using namespace std;

int main() {
	double pi = 3.14;
	auto calc = [pi](int r)->double{return pi * r * r; };
	cout << "¸éÀûÀº" << calc(3);
}