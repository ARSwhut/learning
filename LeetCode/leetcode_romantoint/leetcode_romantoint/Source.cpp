#include <iostream>
using namespace std;

int romanToInt(string s) {
	int roman_int = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'I': roman_int += 1; break;
		case 'V': roman_int += 5; break;
		case 'X': roman_int += 10; break;
		case 'L': roman_int += 50; break;
		case 'C': roman_int += 100; break;
		case 'D': roman_int += 500; break;
		case 'M': roman_int += 1000; break;
		default:
			break;
		}
		if (i != 0) {
			if ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I')
				roman_int -= 1 * 2;
			if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X')
				roman_int -= 10 * 2;
			if ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C')
				roman_int -= 100 * 2;
		}
	}
	return roman_int;
	
}

int main() {
	string  str = "LVIII";
	int res = romanToInt(str);
	cout << res << endl;
	return 0;
}