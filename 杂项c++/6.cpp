#include<iostream>
#include<list>
#include<string>
using namespace std;

class person {
	public:
	person(string name, int age, int tall) {
		this->name = name;
		this->age = age;
		this->tall = tall;
	}
	string name;
	int age;
	int tall;
};

bool compare(person& p1, person& p2) {
	if (p1.age == p2.age) {
		return p1.tall > p2.tall;
	}
	else {
		return p1.age < p2.age;
	}
}
void test01() {
	list<person>p;
	person p1("a", 11, 150);
	person p2("b", 17, 180);
	person p3("c", 16, 170);
	person p4("d", 17, 160);
	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	p.push_back(p4);
	p.sort(compare);
	for (list<person>::const_iterator it = p.begin(); it != p.end(); it++) {
		cout << (*it).name << " " << (*it).age << " " << (*it).tall << endl;
	}
}
int main() {
	test01();
	return 0;
}