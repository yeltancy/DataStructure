#include<iostream>
using namespace std;
class animal {
public:
	virtual void speak() {
		cout << "speak";
	};
};
class cat :public animal {
public:
	void speak() {
		cout << "cat speak" << endl;
	}
};
void dospeak(animal& animal) {
	animal.speak();
}
void test1() {
	cat cat1;
	dospeak(cat1);
}
int main() {
	test1();
	return 0;
}