#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

struct BigInteger {
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	std::vector<int> s;
	BigInteger(long long num = 0) {
		*this = num;
	}

	BigInteger operator = (long long num) {
		s.clear();
		do {
			s.push_back(num % BASE);
			num /= BASE;
		} while (num > 0);
		return *this;
	}

	BigInteger operator = (std::string &str) {
		s.clear();
		int len = (str.size() - 1) / WIDTH + 1;	// -1 保证既在整除时不会多一个
		for (int i = 0; i < len; ++i) {
			int x;
			decltype(str.size()) end = str.size() - WIDTH * i;
			decltype(str.size()) start = std::max(0, (int)str.size() - WIDTH * (i + 1));	// 注意有无符号数混算
			sscanf_s(str.substr(start, end - start).c_str(), "%d", &x);	// 从c字符串输入
			s.push_back(x);
		}
		return *this;
	}

	BigInteger operator + (const BigInteger &b) {
		BigInteger c;
		c.s.clear();
		for (int i = 0, g = 0; ; ++i) {
			if (g == 0 && i >= s.size() && i >= b.s.size()) break;
			int x = g;
			if (i < s.size()) x += s[i];
			if (i < b.s.size()) x += b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		return c;
	}

	BigInteger operator * (const BigInteger &b) {
		BigInteger c;
		BigInteger d;
		BigInteger e;
		for (int i = 0; i < b.s.size(); ++i) {
			d.s.clear();
			e.s.clear();
			for (int m = 0; m < i; ++m) {
				d.s.push_back(0);
				e.s.push_back(0);
			}
			e.s.push_back(0);
			for (int j = 0; j < s.size(); ++j) {
				long long g = (long long)b.s[i] * s[j];
				d.s.push_back(g % BASE);
				/*if((j < b.s.size() - 1 && )|| g / BASE > 0)*/
				e.s.push_back(g / BASE);
			}
			while (!e.s.back() && e.s.size() > 1) {
				e.s.pop_back();
			}
			c = c + d + e;
		}
		return c;
	}

	bool operator < (const BigInteger &b) const {
		if (s.size() != b.s.size())
			return s.size() < b.s.size();
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] != b.s[i]) {
				return s[i] < b.s[i];
			}
		}
		return false;	// 遗忘：全部相等要返回
	}

	bool operator > (const BigInteger &b) const {
		return b < *this;
	}

	bool operator >= (const BigInteger &b) const {
		return !(*this < b);
	}

	bool operator <= (const BigInteger &b) const {
		return !(b < *this);
	}

	bool operator != (const BigInteger &b) const {
		return *this < b || b < *this;
	}

	bool operator == (const BigInteger &b) const {
		return !(*this < b) && !(b < *this);
	}
};

std::ostream& operator << (std::ostream& os, const BigInteger &x) {
	std::cout << x.s.back(); // vector back
	for (int i = x.s.size() - 2; i >= 0; --i) {
		printf("%08d", x.s[i]);
	}
	std::cout << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, BigInteger &x) {
	std::string s;
	if (!(is >> s))	return is;
	x = s;
	return is;
}