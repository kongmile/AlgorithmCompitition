#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<iterator>
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x, x.begin())
using namespace std;

typedef set<int> Set;
map<Set, int> IDCache;
vector<Set> SetCache;

int ID(Set x) {
	if (IDCache.count(x)) {
		return IDCache[x];
	}
	else {
		SetCache.push_back(x);
		return IDCache[x] = SetCache.size() - 1;
	}
}

int main() {
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string op;
		cin >> op;
		if (op[0] == 'P') {
			s.push(ID(Set()));
		}
		else if (op[0] == 'D') {
			s.push(s.top());
		}
		else {
			Set x1 = SetCache[s.top()];
			s.pop();
			Set x2 = SetCache[s.top()];
			s.pop();
			Set x;
			if (op[0] == 'U') {
				set_union(ALL(x1), ALL(x2), INS(x));
			}
			if (op[0] == 'I') {
				set_intersection(ALL(x1), ALL(x2), INS(x));
			}
			if (op[0] == 'A') {
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << s.top() << ':' << SetCache[s.top()].size() << endl;
	}
	return 0;
}