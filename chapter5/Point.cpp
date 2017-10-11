#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
struct Point {
public:
	Point(T x = 0, T y = 0) : x(x), y(y) { };
	T x, y;
};

template<typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B) {
	return Point<T>(A.x + B.x, A.y + B.y);
}

template<typename T>
ostream& operator << (ostream& os, const Point<T>& p) {
	cout << '(' << p.x << " , " << p.y << ')' << endl;
	return os;
}

template<typename T>
T sum(T *begin, T *end) {
	T ans = 0;
	for (T *p = begin; p != end; ++p) {
		ans = ans + *p;
	}
	return T;
}

int main() {
	Point<int> A(1, 1), B(3, 3);
	Point<double> C(3.4, 5.6), D(2.4, 4.5);
	cout << A + B << endl;
	cout << C + D << endl;
	vector<Point<int>> points{ Point<int>(1,1), Point<int>(3, 4) };
	cout << sum<Point<int>>(points.begin(), points.end()) << endl;
	return 0;
}