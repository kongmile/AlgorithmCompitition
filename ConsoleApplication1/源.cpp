#include<iostream>

using namespace std;

/**
* 玩家标记
* 1：x
* 0: o
**/
int player = 1; 

int main() {
	int i = 0;
	int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	while (i < 4) { // 四次有效操作后结束游戏
		// 棋盘
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				int key = a[3 * r + c];
				if (key == 0)
					cout << 'x';
				else if (key == -1)
					cout << '0';
				else
					cout << key;
			}
			cout << endl;
		}
		// 玩家提示符
		if (player)
			cout << "x: ";
		else
			cout << "o: ";
		// 玩家操作
		int x;
		cin >> x;
		if (a[x - 1] > 0) {			// 操作合法
			a[x - 1] = player - 1;	// 棋盘记号
			player = !player;		// 切换玩家
			++i;					// 有效操作计数
		}
	}	
}