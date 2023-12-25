//������
#include<iostream>
using namespace std;

//��nextval����
void GetNextval(string t, int* nextval)
{
	int j = 0, k=-1;
	nextval[0] = -1;
	while (j < t.length())
	{
		if (k == -1 || t[j] == t[k]) {
			j++; k++;
			if (t[j] != t[k]) {
				nextval[j] = k;
			}
			else {
				nextval[j] = nextval[k];
			}
		}
		else k = nextval[k];
	}
}

//����KMP�㷨
int KMPval(string s, string t) {
	int n = s.length(), m = t.length();
	int* nextval = new int[m];
	GetNextval(t, nextval);
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		}
		else j = nextval[j];
	}
	//��KMP�㷨��ȷ��ص���ĩβλ��
	if (j >= m) return i - 1;
	else return -1;
}

//��ת�ַ���
string reverse(string s) {
	int start = 0, end = s.length() -1;
	while (start < end) {
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
	return s;
}
//����ĿҪ��
int lastKMP(string s, string t) {
	string s1 = reverse(s);
	string t1 = reverse(t);
	int f = KMPval(s1, t1);
	return s.length() - f - 1;
}
int main() {
	string s = "abcdabcd";
	string t = "abc";
	cout << lastKMP(s, t);
}
