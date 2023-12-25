#include<iostream>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	//�������޲ι��캯��
	Date() {

	}
	//�������вι��캯��
	Date(int year, int month, int day){
		this->day = day;
		this->month = month;
		this->year = year;
	}
	//������չʾ����
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
	//��Ա���޲ι��캯��
	Person(){

	}
	//��Ա���вι��캯��
	Person(int id,bool sex,Date date,int IDnum) {
		this->id = id;
		this->sex = sex;
		this->date = date;
		this->IDnum = IDnum;
	}
	//��������
	~Person() {

	}
	//��������
	inline void set_IDnum(int IDnum) { 
		this->IDnum = IDnum; 
	}
	//�������캯��
	Person(const Person& p) {
		this->id = p.id;
		this->sex = p.sex;
		this->date = p.date;
		this->IDnum = p.IDnum;
	}
	//��Ա��չʾ����
	void displayPerson() {
		cout << "This is the person: " << endl;
		cout << "���" << id << endl;
		cout << "�Ա�" << sex << endl;
		cout << "�������ڣ�";
		date.displayDate();
		cout << "���֤��" << IDnum << endl;
	}
};

int main() {
	Date date(2004, 9, 22);
	Person zhangsan(1, true, date, 110);
	date.displayDate();
	zhangsan.displayPerson();
}
