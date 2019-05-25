#include <iostream>
using namespace std;

int mySqrt(int x) {
	/*if (x <= 1) return x;
	int l = 0;
	int h = x;
	int r;
	while (l < h) {
		r = l + (h - l) / 2;
		if ((r + 1) > x / (r + 1) &&
			r <= x / r)
			break;
		if ((r - 1) < x / (r - 1) &&
			r > x / r) {
			r--;
			break;
		}
		if (r > x / r) {
			h = r - 1;
		}
		if (r < x / r) {
			l = r + 1;
		}
	}
	return r;*/
	if (x <= 1) return x;
	int low = 0;
	int high = x;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (mid <= x / mid && mid > 0)
			low = mid + 1;
		else {
			high = mid - 1;
		}
	}
	return low - 1;
	/*if (x <= 1) return x;
	int r = x;
	while (r > x / r) {
		r = r / 2 + x / (2 * r);
	}
	return r;*/
}
int main() {
	int res = mySqrt(0);
	cout << res << endl;
	return 0;
}