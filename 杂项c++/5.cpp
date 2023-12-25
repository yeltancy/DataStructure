#include<iostream>
using namespace std;

class animal {
public:
	animal() {
		cout << "animal����";
	}
	virtual ~animal() {
		cout<< "animal����";
	}
	virtual void speak() = 0;
};

class cat :public animal {
public:
	cat(string name) {
		cout << "cat����";
		myname = new string(name);
	}
	virtual void speak() {
		cout << *myname << "cat speak";
	}
	~cat() {
		if (this->myname != NULL) {
			cout << "cat��������";
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