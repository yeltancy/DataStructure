#include<iostream>
using namespace std;
//�������������

class person {
	friend ostream& operator<<(ostream& cout, person& p);
public:
	person(int a, int b) {
		this->a = a;
		this->b = b;
	}


	person& operator--() {
		a--;
		b--;
		return *this;
	}
	person operator--(int) {
		person temp = *this;
		a--;
		b--;
		return temp;
	}
private:
	int a;
	int b;

};
ostream& operator<<(ostream& cout, person& p) {
	cout << "a:" << p.a << "b:" << p.b;//��ʽ���˼�룬����ֵ������������������ſ��Լ����������
	//�˴�Ϊ�������أ�return���cout������ԭ�������ڲ���ʹ�ÿ�������������£�ֱ�����ú���Ϊ��
	return cout;
}
int main() {
	person p(10, 10);

	cout << p << endl;
	return 0;
}