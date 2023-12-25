#include<iostream>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	//日期类无参构造函数
	Date() {

	}
	//日期类有参构造函数
	Date(int year, int month, int day){
		this->day = day;
		this->month = month;
		this->year = year;
	}
	//日期类展示函数
	void displayDate(){
		cout << "This is date:" << year << "-" << month << "-" << day << endl;
	}
};

class Person {
private:
	int id;
	bool sex;
	Date date;
	int IDnum;
public:
	//人员类无参构造函数
	Person(){

	}
	//人员类有参构造函数
	Person(int id,bool sex,Date date,int IDnum) {
		this->id = id;
		this->sex = sex;
		this->date = date;
		this->IDnum = IDnum;
	}
	//析构函数
	~Person() {

	}
	//内联函数
	inline void set_IDnum(int IDnum) { 
		this->IDnum = IDnum; 
	}
	//拷贝构造函数
	Person(const Person& p) {
		this->id = p.id;
		this->sex = p.sex;
		this->date = p.date;
		this->IDnum = p.IDnum;
	}
	//人员类展示函数
	void displayPerson() {
		cout << "This is the person: " << endl;
		cout << "编号" << id << endl;
		cout << "性别：" << sex << endl;
		cout << "出生日期：";
		date.displayDate();
		cout << "身份证号" << IDnum << endl;
	}
};

int main() {
	Date date(2004, 9, 22);
	Person zhangsan(1, true, date, 110);
	date.displayDate();
	zhangsan.displayPerson();
}
