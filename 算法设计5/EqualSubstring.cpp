//µÚËÄÌâ
#include<iostream>
#include<string>
using namespace std;

string equalSubstring(string& s) {
	if (s.empty() || s == ""|| s.length() == 1) return "";
	string res = "";
	int begin = 0;
	int end = 0;
	while (end < s.length()) {
		end++;
		if (s[end] != s[end - 1]) {
			if (end - begin > res.length()) {
				res = s.substr(begin, end - begin);
			}
			begin = end;
		}
	}
	return res;
}
int main() {
	string s = "abbbqaaaa";
	cout<<equalSubstring(s);
}