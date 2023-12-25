#include<iostream>
using namespace std;
//左移运算符重载

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
	cout << "a:" << p.a << "b:" << p.b;//链式编程思想，返回值必须是输出流接下来才可以继续输出，。
	//此处为函数重载，return后的cout继续用原函数，在不能使用拷贝函数的情况下，直接引用函数为宜
	return cout;
}
int main() {
	person p(10, 10);

	cout << p << endl;
	return 0;
}