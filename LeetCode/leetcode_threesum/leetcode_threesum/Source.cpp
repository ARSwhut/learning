#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> tmp;
	int next, last;
	sort(nums.begin(), nums.end());
	for (int first = 0; first < nums.size(); first++) {
		next = first + 1;
		last = nums.size() - 1;
		int target = -nums[first];
		while (next < last) {
			if (nums[next] + nums[last] == target) {
				tmp = { nums[first], nums[next], nums[last] };
				res.push_back(tmp);
				while (next < last && nums[next] == nums[next + 1]) next++;
				while (next < last && nums[last] == nums[last - 1]) last--;
				next++;
				last--;
			}
			else if (nums[next] + nums[last] > target) {
				last--;
			}
			else {
				next++;
			}
		}
		while ((first < nums.size() - 1) && nums[first] == nums[first + 1]) first++;
	}
	return res;
	/*sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for (int i = 0; i < nums.size(); ++i)
	{
		int target = -nums[i];
		int j = i + 1, k = nums.size() - 1;
		while (j < k)
		{
			if (nums[j] + nums[k] < target)
				++j;
			else if (nums[j] + nums[k] > target)
				--k;
			else
			{
				res.push_back(vector<int>{nums[i], nums[j], nums[k]});
				int mid = nums[j];
				int last = nums[k];
				while (j < k && nums[j] == mid)
					++j;
				while (j < k && nums[k] == last)
					--k;
			}
		}
		while (i + 1 < nums.size() && nums[i] == nums[i + 1])
			++i;
	}
	return res;*/

}

int main() {
	vector<int> vec = { -1,0,1,2,-1,-4,4 };
	vector<vector<int>> res = threeSum(vec);
	int row = res.size();
	int col = res[0].size();
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cout << res[i][j] << " ";
	cout << endl;
	return 0;


}