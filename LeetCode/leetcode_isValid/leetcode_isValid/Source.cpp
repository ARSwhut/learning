#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(' || c == '{' || c == '[')
			stk.push(c);
		else if (stk.empty() && (c == '}' || c == ']' || c == ')'))
			return false;
		else if (c == ')') {
			if (stk.top() == '(')
				stk.pop();
			else
				return false;
		}
		else if (c == '}') {
			if (stk.top() == '{')
				stk.pop();
			else
				return false;
		}
		else if (c == ']') {
			if (stk.top() == '[')
				stk.pop();
			else
				return false;
		}
	}
	return stk.empty();
}

int main() {
	string str = "()[]()";
	bool flag = isValid(str);
	cout << flag << endl;
	return 0;
}