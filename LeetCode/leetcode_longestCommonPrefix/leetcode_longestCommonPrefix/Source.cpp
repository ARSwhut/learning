#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestString(vector<string>& strs) {
	if (strs.empty())
		return "";
	int count = 0;
	string firstString = strs[0];
	while (true) {
		for (auto str : strs) {
			if (str.size() == count || str[count] != firstString[count])
				return firstString.substr(0, count);
		}
		count++;
	}
	
}

int main() {
	vector<string> strs = { "flowers", "flow", "flight" };
	string str = longestString(strs);
	cout << str << endl;
	return 0;
}