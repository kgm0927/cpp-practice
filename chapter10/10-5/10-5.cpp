#include <iostream>
using namespace std;

template <class T>
void print(T array[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << '\t';

	}
	cout << endl;
}

void print(char array[], int n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << (int)array[i] << '\t';
	}
	cout << endl;
}

int main() {
	int x[] = {1,2,3,4,5};
	double d[5] = { 1.1,1.2,1.3,1.4,1.5 };
	print(x, 5);
	print(d, 5);

	char c[5] = { 1,2,3,4,5 };
	print(c, 5);
}