#include<iostream>
#include<cstdlib> // rand()
#include<ctime> // time()
#include<vector>
#include<algorithm>
#include<cassert> // assert()
using namespace std;

void fill_random_int(vector<int> &v, int cnt) {
	for (int i = 0; i < cnt; ++i) {
		//v.push_back(rand());
		v.push_back(rand() / RAND_MAX * 1000);
	}
}

void test_sort(vector<int> &v) {
	sort(v.begin(), v.end());
	for (decltype(v.size()) i = 0; i < v.size() - 1; ++i) {
		assert(v[i] <= v[i + 1]);
	}
}

int main() {
	srand(time(NULL)); // 随机数种子,只需调用一次
	vector<int> v;
	fill_random_int(v, 10);
	test_sort(v);
	return 0;
}