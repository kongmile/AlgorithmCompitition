#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<functional> // greater<T>

using namespace std;

int main() {
	using LL = long long;
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> s;
	const int coeff[3] = { 2, 3, 5 };
	pq.push(1);
	s.insert(1);
	for (int i = 1; ; ++i) {
		LL x = pq.top();
		pq.pop();
		if (i == 1500) {
			cout << "The 1500th ugly number is " << x << '.' << endl;
			break;
		}
		for (auto n : coeff) {
			LL x2 = x * n;
			if (!s.count(x2)) {
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	return 0;
}