	#include<iostream>
	#include<set>
	#include<string>
	#include<algorithm>
	using namespace std;


	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			set<char> _set;
			int count = 0, left = 0, right = 0;
			while (right < (int)s.size()) {
				if (_set.find(s[right]) == _set.end()) {
					_set.insert(s[right++]);
					count = max(count, (int)_set.size());
				}
				else {
					_set.erase(s[left++]);                 //这里需要理解
				}
			}
			return count;


		}
	};

	int main() {
		Solution solution;
		string s = "dvdf";
		cout<<solution.lengthOfLongestSubstring(s)<<endl;

		system("pause");
		return 0;

	}