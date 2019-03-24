#include<iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)return false;
		int count=0;
		int x2 = x;
		while (x2 != 0) {
			int pop=x2 % 10 ;
			x2 /= 10;
			if (count > INT_MAX / 10 || count == INT_MAX / 10 && pop > 7)return false;
			count = count * 10 + pop;
		}
		if (count == x) return true;
		else return false;
	}
};

int main() {
	Solution solution;
	int x;
	cout << "set a number,check it:" << endl;
	cin >> x;
	if (solution.isPalindrome(x)) {
		cout << "true"<<endl;
	}
	else cout << "false" << endl;
	system("pause");
	return 0;
}