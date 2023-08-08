#include <iostream>
#include <string>
using namespace std;

class Book {		// å�� ǥ���ϴ� Ŭ����
	string title;
	string press;
	string author;
public:
	Book(string title = "", string press = "", string author = "") {
		this->title = title;
		this->press = press;
		this->author = author;

	}
	friend ostream& operator << (ostream& stream, Book b); // friend ����
};

// << ������ �Լ�
ostream& operator << (ostream& stream, Book b) {
	stream << b.title << "," << b.press << "," << b.author;
	return stream;
}

int main() {
	Book book("������ �����", "�ѱ����ǻ�", "����������"); // Book Ŭ���� ��ü ����
	cout << book;
}