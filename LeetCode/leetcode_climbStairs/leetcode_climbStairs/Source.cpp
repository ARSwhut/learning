#include <iostream>
using namespace std;
int climbStairs(int n) {
	if(n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	int f1 = 1;
	int f2 = 2;
	int res;
	for (int i = 3; i <= n; i++) {
		res = f1 + f2;
		f1 = f2;
		f2 = res;
	}
	return res;
}

int main() {
	int res = climbStairs(4);
	cout << res << endl;
	return 0;
}

