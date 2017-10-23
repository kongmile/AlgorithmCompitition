#include<iostream>	// freopen
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


const int maxcol = 60;
const int maxn = 100 + 5;

string filenames[maxn];

int main() {
#ifdef DEBUG
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // DEBUG
	int n;
	while (cin >> n) {
		int M = 0;
		for (int i = 0; i < n; ++i) {
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());
		}
		for (int i = 0; i < maxcol; ++i) {
			cout << '-';
		}
		cout << endl;
		int col = (maxcol - M) / (M + 2) + 1;
		int row = (n - 1) / col + 1;
		sort(filenames, filenames + n);
		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < col; ++c) {
				int idx = row * c + r;
				if (idx < n) {
					cout << filenames[idx];
					int len = (row * (c + 1) + r) > n - 1 ? M : (M + 2);
					for (int i = filenames[idx].length(); i < len; ++i) {
						cout << ' ';
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}