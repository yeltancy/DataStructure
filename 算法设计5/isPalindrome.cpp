//µÚÈıÌâ
#include<iostream>
using namespace std;

bool isPalindrome(string& s) {
	bool res = true;
	if (s.empty() || s == "") return false;
	if (s.length() == 1) return true;
	int start = 0;
	int end = s.length() - 1;
	while (start < end) {
		if (s[start] != s[end]) {
			res = false;
			break;
		}
		else {
			start++;
			end--;
		}
	}
	return res;
}

int main() {
	string s = "avba";
	cout<<isPalindrome(s);
}