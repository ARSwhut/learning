#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	/*int length = nums.size();
	if (length == 0) return 0;
	int i = 0, j = 1;
	while (j < length) {
		if (nums[i] == nums[j])
			j++;
		else {
			if ((i + 1) == j) {
				i++;
				j++;
			}
			else {
				nums[++i] = nums[j];
				j++;
			}
		}
	}
	return i + 1;*/
	int length = nums.size();
 	if (length <= 0) return 0;
	int count = 0;
	for (int i = 1; i < length; i++) {
		if (nums[i] != nums[count]) {
			count++;
			nums[count] = nums[i];
		}
	}
	return count + 1;
}

int main() {
	vector<int> vec = { 1,1,2,2,3,3,3,5};
	int a = removeDuplicates(vec);
	cout << a << endl;
	return 0;
}