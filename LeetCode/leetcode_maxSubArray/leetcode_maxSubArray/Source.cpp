#include <iostream>
#include <vector>
#define max(a,b) (a > b) ? a : b
using namespace std;
int maxSubArray(vector<int>& nums) {
	int res = -INT_MAX;
	int tmp = 0;
	for (int i = 0; i < nums.size(); i++) {
		tmp = max(nums[i], tmp + nums[i]);
		res = max(res, tmp);
	}
	return res;
}

int main() {
	vector<int> vec = { -2134556676};
	int res = maxSubArray(vec);
	cout << res << endl;
}