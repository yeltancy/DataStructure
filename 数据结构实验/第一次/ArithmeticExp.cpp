#include<iostream>
#include<stack>
#include <string>
using namespace std;

string trimAll(string str) {
    int index = 0;
    if (!str.empty()) {
        while ((index = str.find(' ', index)) != string::npos) {
            str.erase(index, 1);
        }
    }
    return str;
}
string trans(string str1) {
    string str = trimAll(str1);
    string postexp;
    stack<char> opor;
    char c;
    int strLength = str.length();
    for (int i = 0; i < strLength; i++) {
        c = str[i];
        if (c == '=') {
            break;
        }
        else if (c == '(') {
            opor.push(c);
        }
        else if (c == ')') {
            while (!opor.empty() && opor.top() != '(') {
                postexp += opor.top();
                opor.pop();
            }
            opor.pop();
        }
        else if (c == '+' || c == '-') {
            while (!opor.empty() && opor.top() != '(') {
                postexp += opor.top();
                opor.pop();
            }
            opor.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/')) {
                postexp += opor.top();
                opor.pop();
            }
            opor.push(c);
        }
        else {
            while (c >= '0' && c <= '9') {
                postexp += c;          
                c = str[++i];
            }
            i--;
            postexp += '#';
        }
    }
    while (!opor.empty()) {
        postexp += opor.top();
        opor.pop();
    }
    return postexp;
}

void arithmeticExp(string postexp) {
	stack<int> num;
	int i = 0, num1, num2, res;
	char c;
    int postexpLength = postexp.length();
	while (i < postexpLength) {
		c = postexp[i];
		switch (c) {
		case '+':
			num1 = num.top();
			num.pop();
			num2 = num.top();
			num.pop();
			res = num1 + num2;
			num.push(res);
			break;
		case '-':
			num1 = num.top();
			num.pop();
			num2 = num.top();
			num.pop();
			res = num2 - num1;
			num.push(res);
			break;
		case '*':
			num1 = num.top();
			num.pop();
			num2 = num.top();
			num.pop();
			res = num1 * num2;
			num.push(res);
			break;
		case '/':
			num1 = num.top();
			num.pop();
			num2 = num.top();
			num.pop();
			if (num1 == 0) {
				return ;
			}
			res = num2 / num1;
			num.push(res);
			break;
		default:
			int d =0;
			while (c >= '0' && c <= '9') {
				d = 10 * d + (c - '0');
                c = postexp[++i];
			}
			num.push(d);
			break;
		}
		i++;
	}
	res = num.top();
    cout << res;
}
int main() {
    string str;
    getline(cin, str);
    string postexp = trans(str);
    arithmeticExp(postexp);
}