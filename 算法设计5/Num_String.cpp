//�ڶ���
#include<iostream>
using namespace std;

//ʱ�临�Ӷ�ΪO{n},�ռ临�Ӷ�ΪO{1}
string num_string(string& s) {
	if (s.empty() || s == "") return NULL;
	if (s.length() == 1) return s;
	int start = 0;
	int end = s.length() - 1;
	while (start < end) {
		while (s[start] >= '0' && s[start] <= '9') {
			start++;
		}
		while (s[end] >= 'a' && s[end] <= 'z') {
			end--;
		}
		if (start < end) {
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		}
		
	}
	return s;
}
int main() {
	string s = "13ab45fi8gj";
	num_string(s);
	cout << s << endl;
}