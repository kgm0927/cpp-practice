#include <iostream>
#include <cstring>
using namespace std;

class Person {  // Person Ŭ���� ����
    char* name;
    int id;
public:
    Person(int id, const char* name); // ������
    Person(const Person& person); // ���� ������
    ~Person(); // �Ҹ���
    void changeName(const char* name);
    void show() { cout << id << ', ' << name << endl; }
};

Person::Person(int id, const char* name) {// ������
    this->id = id;
    int len = strlen(name); // name�� ������ ����
    this->name = new char[len + 1]; // name�� ���ڿ� ���� �Ҵ�
    strcpy(this->name, name); // name�� ���ڿ� ����
}

Person::Person(const Person& person) {// ���� ������
    this->id = person.id; // id �� ����
    int len = strlen(person.name); // name�� ���� ����
    this->name = new char[len + 1]; // name�� ���� ���� �Ҵ�
    strcpy(this->name, person.name);// name�� ���ڿ� ����
    cout << "���� ������ ����. ���� ��ü�� �̸�" << this->name << endl;
}

Person::~Person() { // �Ҹ���
    if (name) // aksdlf name�� ����  �Ҵ�� �迭�� ������
        delete[] name; // ���� �Ҵ� �޸� �Ҹ�
}

void Person::changeName(const char* name) { // �̸� ����
    if (strlen(name) > strlen(this->name))
        return; // ���� name �� �Ҵ�� �޸𸮺��� �� �̸����� �ٲ� �� ����.
    strcpy(this->name, name);
}

int main() {
    Person father(1, "Kitae");      // father ��ü ����
    Person daugther(father);        // daughter ��ü ���� ����. ���� ������ ȣ��

    cout << "dauther ��ü ���� ���� ----" << endl;

    father.show();      // father ��ü ���
    daugther.show();    // daughter ��ü ���

    daugther.changeName("Grace");       // daughter�� �̸��� "Grace"�� ����
    cout << "daughter �̸��� Grace �� ������ �� ----" << endl;
    father.show();                      // father ��ü ���
    daugther.show();                    // daughter ��ü ���

    return 0;                           // ��ü �Ҹ�

}
