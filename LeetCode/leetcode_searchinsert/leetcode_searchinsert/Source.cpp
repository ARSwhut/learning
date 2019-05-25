#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int l = 0;
	int h = nums.size() - 1;
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > target) {
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}
int main() {
	vector<int> t = { 1,3,5,6 };
	int target = 2;
	int res = searchInsert(t, target);
	cout << res << endl;
	return 0;
}
