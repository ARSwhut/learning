#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
	if (haystack == needle) return 0;
	for (int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i++) {
		int j = 0;
		while (j < (int)needle.size()) {
			if (haystack[i + j] != needle[j])
				break;
			j++;
		}
		if (j == (int)needle.size())
			return i;
	}
	return -1;
}

int main() {
	string str1 = "mississippi";
	string str2 = "pi";
	int a = strStr(str1, str2);
	cout << a << endl;
	return 0;
}