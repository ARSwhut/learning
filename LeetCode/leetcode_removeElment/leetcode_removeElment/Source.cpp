#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
	if (nums.empty()) return 0;
	int i = 0;
	int j = nums.size() - 1;
	while (i <= j) {
		if (nums[i] != val) {
			i++;
		}
		else if (nums[j] == val) {
			j--;
		}
		else {
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	return i;
}

int main() {
	vector<int> vec = { 0,1,2,3,4,4,5,5,5 };
	int val = 4;
	int count = removeElement(vec, val);
	cout << count << endl;
	return 0;
}