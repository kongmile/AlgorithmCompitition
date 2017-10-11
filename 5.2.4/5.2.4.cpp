#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

string repr(const string s) {
	string ans;
	for (auto ch : s) {
		ans.push_back(tolower(ch));
	}
	sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	string word;
	vector<string> words;
	map<string, int> cnt;
	while (cin >> word) {
		if (word == "#")
			break;
		words.push_back(word);
		string r = repr(word);
		if (!cnt.count(r)) {
			cnt[r] = 0;
		}
		else {
			++cnt[r];
		}
	}
	vector<string> ans;
	for (auto word : words) {
		if (cnt[repr(word)] == 0) {
			ans.push_back(word);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto word : ans) {
		cout << word << endl;
	}
	return 0;
}