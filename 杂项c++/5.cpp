#include<iostream>
using namespace std;

class animal {
public:
	animal() {
		cout << "animal构造";
	}
	virtual ~animal() {
		cout<< "animal析构";
	}
	virtual void speak() = 0;
};

class cat :public animal {
public:
	cat(string name) {
		cout << "cat构造";
		myname = new string(name);
	}
	virtual void speak() {
		cout << *myname << "cat speak";
	}
	~cat() {
		if (this->myname != NULL) {
			cout << "cat析构函数";
			delete myname;
			myname = NULL;
		}
	}
	string* myname;
};
void test() {
	animal* animal = new cat("tom");
	animal->speak();
	delete animal;
	animal = NULL;
}
int main() {
	test();
	return 0;
}