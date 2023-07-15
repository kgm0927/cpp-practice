#include <iostream>
#include <vector>
#include <algorithm>// for_each() �Լ��� ����ϱ� ����.
using namespace std;

//
// STL ���ø��� ���ٽ� Ȱ��
// 
// ���ٽ��� STL ���ø��� ����Ͽ� ���α׷��� �ۼ��� �� ���� �����ϴ�.
// 
// 
// 
// 
//



void print(int n) {
	cout << n << " ";
}

int main() {
	vector<int> v = { 1,2,3,4,5 };
	for_each(v.begin(),v.end(),print);
	// for_each()�� ���� v�� ù��° ���� (v.begin())���� ��(v.end())���� �˻��ϸ鼭,
	// �� ���ҿ� ���� 3��° �Ű� ������ print(int n) ȣ��. �Ű����� n�� �� ���Ұ� ����
}

//
// STL �Լ� for_each()�� ����Ͽ� ������ ��� ���Ҹ� ���
// 
// for_each()�� �����̳��� �� ���Ҹ� �˻��ϴ� STL �˰��� �Լ��̴�. for_each()�� �����̳ʿ�
// �� ���ҿ� ���� 3��° �Ű� ������ �־��� �Լ��� ȣ���Ѵ�.
//