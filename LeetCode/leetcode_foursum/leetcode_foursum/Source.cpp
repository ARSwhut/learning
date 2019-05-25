#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> res;
	if (nums.size() < 4) return res;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		int newtarget = target - nums[i];
		for (int j = i + 1; j < nums.size(); j++) {
			int k = j + 1, l = nums.size() - 1;
			int newtarget2 = newtarget - nums[j];
			while (k < l) {
				if (nums[k] + nums[l] > newtarget2) l--;
				else if (nums[k] + nums[l] < newtarget2)  k++;
				else {
					res.push_back({ nums[i], nums[j], nums[k], nums[l] });
					while (k < l && nums[k] == nums[k + 1]) k++;
					while (k < l && nums[l] == nums[l - 1]) l--;
					k++;
					l--;
				}
			}
			while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
		}
		while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
	}
	return res;
}

int main() {
	vector<int> vec = { 1, 0, -1, 0, -2, 2 };
	int target = 0;
	vector<vector<int>> res = fourSum(vec, target);
	int row = res.size();
	int col = res[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}