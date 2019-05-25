#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	/*int i = n + m;
	while (i--) {
		if (n == 0) {
			nums1[i] = nums1[m - 1];
			m--;
			continue;
		}
		if (m == 0) {
			nums1[i] = nums2[n - 1];
			n--;
			continue;
		}
		if (nums1[m - 1] >= nums2[n - 1]) {
			nums1[i] = nums1[m - 1];
			m--;
		} 
		else {
			nums1[i] = nums2[n - 1];
			n--;
		}
	}*/
	int index = m + n - 1;
	m--;
	n--;
	while (n >= 0) {
		if (m >= 0 && nums1[m] > nums2[n]) {
			nums1[index] = nums1[m];
			m--;
		}
		else {
			nums1[index] = nums2[n];
			n--;
		}
		index--;
	}
}
int main() {
	vector<int> s1 = { 0 };
	vector<int> s2 = { 1 };
	int m = 0;
	int n = 1;
	merge(s1, m, s2, n);
	for (auto item : s1) {
		cout << item << endl;
	}
	return 0;
}