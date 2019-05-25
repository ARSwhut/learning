#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
	int index = digits.size() - 1;
	int carry = 1;
	while (carry == 1 && index >= 0) {
		if (digits[index] == 9) {
			digits[index] = 0;
			index--;
		}
		else {
			digits[index]++;
			carry = 0;
		}
	}
	if (digits[0] == 0) {
		digits.push_back(0);
		digits[0] = 1;
	}
	return digits;
}

int main() {
	vector<int> vec = { 9,9,9 };
 	vector<int> res = plusOne(vec);
	for (auto item : res) {
		cout << item << endl;
	}
	return 0;
}