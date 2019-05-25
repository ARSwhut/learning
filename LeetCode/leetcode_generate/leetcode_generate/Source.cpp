#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	if (numRows == 0) return res;
	vector<int> pre;
	vector<int> v = {1};
	res.push_back(v);
	while (numRows > 1) {
		pre = v;
		v.push_back(1);
		for (int i = 1; i < pre.size(); i++) {
			v[i] = pre[i - 1] + pre[i];
		}
		res.push_back(v);
		numRows--;
	}
	return res;
}

vector<int> getRow(int numRows) {
	//if (numRows == 0) return vector<int>();
	vector<int> res(numRows + 1, 1);
	for (int i = 1; i < numRows; i++) {
		for (int j = i; j > 0; j--) {
			res[j] += res[j - 1];
		}
	}
	return res;
}

int main() {
	vector<vector<int>> res;
	res = generate(5);
	for (auto item : res) {
		for(auto c : item)
			cout << c << " ";
		cout << endl;
	}
	cout << "----------------------" << endl;
	vector<int> test;
	test = getRow(0);
	for (auto item : test)
		cout << item << endl;
	return 0;
}