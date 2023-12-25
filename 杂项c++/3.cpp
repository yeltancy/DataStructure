#include<iostream>
using namespace std;
class person {
public:
	person(int age) {
		mage = new int(age);
	}
	~person() {
		if (mage != NULL) {
			delete mage;
			mage = NULL;
		}
	}
	person& operator=(person& p) {
		if (mage != NULL) {
			delete mage;
			mage = NULL;
		}
		mage = new int(*p.mage);
		return *this;
	}
	int* mage;
};
int main(){
	person p1(18);
	cout << *p1.mage;
	person p2(20);
	p2 = p1;
	cout << *p2.mage;
	return 0;
}