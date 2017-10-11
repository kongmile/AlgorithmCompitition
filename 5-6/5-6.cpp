#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;

const int maxn = 1000;

int main() {
	map<int, int> team;
	int n;
	cout << "num of teams:";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cout << "how many people of team " << i << ' ';
		cin >> m;
		for (int j = 0; j < m; ++j) {
			int id;
			cin >> id;
			team[id] = i;
		}
	}
	queue<int> q, q2[maxn];
	for (;;) {
		string op;
		cin >> op;
		if (op[0] == 'S') {
			break;
		}
		if (op[0] == 'E') {
			int x;
			cin >> x;
			int t = team[x];
			if (q2[t].empty()) {
				q.push(t);
			}
			q2[t].push(x);
		}
		if (op[0] == 'D') {
			int t = q.front();
			cout << q2[t].front() << endl;
			q2[t].pop();
			if (q2[t].empty()) {
				q.pop();
			}
		}
	}
	return 0;
}