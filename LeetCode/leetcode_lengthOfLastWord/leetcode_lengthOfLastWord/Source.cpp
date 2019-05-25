#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
	/*if (s.size() == 0) return 0;
	int count = 0;
	int i = s.size();
	while (i--) {
		if (s[i] != ' ') {
			break;
		}
	}
	while (i >= 0) {
		if (s[i] == ' ')
			break;
		count++;
		i--;
	}
	return count;*/
	int length = 0;
	int index = s.size() - 1;
	while (index >= 0 && s[index] == ' ') index--;
	while (index >= 0 && s[index] != ' ') {
		index--;
		length++;
	}
	return length;
}

int main() {
	string str = "a   ";
	int res = lengthOfLastWord(str);
	cout << res << endl;
	return 0;
}