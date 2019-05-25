#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> mymap;
	vector<int> res;
	for (int i = 0; i < nums.size(); ++i) {
		int num = nums[i];
		if (mymap.find(num) != mymap.end()) {
			res = { mymap[num], i };
			return res;
		}
		mymap.insert(pair<int, int>(target - num, i));
	}
	return res;

}

int main() {
	vector<int> vec = { 2,7,11,15 };
	int target = 9;
	vector<int> res = twoSum(vec, target);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}