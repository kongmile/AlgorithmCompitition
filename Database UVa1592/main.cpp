#include"SplitString.h"
#include<iostream>
#include<vector>
#include<string>
#include<ctime>;
using namespace std;

const int maxn = 10000;
const int maxm = 10;
string table[maxn][maxm];

int main() {
#ifdef DEBUG
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	time_t start = time(NULL);
	int n, m;
	while (cin >> n >> m) {
		string row;
		getline(cin, row);
		for (int i = 0; i < n; ++i) {
			getline(cin, row);
			vector<string> v = splitString(row, ",");
			int j = 0;
			for (auto s : v) {
				table[i][j] = s;
				++j;
			}
		}
		//for (int r = 0; r < n; ++r) {
		//	for (int c = 0; c < m; ++c) {
		//		cout << table[r][c] << endl;
		//	}
		//}
		vector<int> v;
		for (int r1 = 0; r1 < n; ++r1) {
			for (int r2 = r1 + 1; r2 < n; ++r2) {
				v.clear();
				for (int c = 0; c < m; ++c) {
					//cout << table[r1][c] << endl;
					//cout << table[r2][c] << endl;
					//cout << (table[r1][c] == table[r2][c]) << endl;
					if (table[r1][c] == table[r2][c]) {
						v.push_back(c);
						if (v.size() == 2) {
							cout << "NO" << endl;
							cout << r1 + 1 << ' ' << r2 + 1<< endl;
							cout << v[0] + 1 << ' ' << v[1] + 1<< endl;
							goto quit;
						}
					}
				}
			}
		}
		cout << "YES" << endl;
	quit:;
	}
	time_t end = time(NULL);
	cout << "time: " << end - start << " s" << endl;
	return 0;
}