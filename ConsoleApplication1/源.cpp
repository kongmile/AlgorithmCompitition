#include<iostream>

using namespace std;

/**
* ��ұ��
* 1��x
* 0: o
**/
int player = 1; 

int main() {
	int i = 0;
	int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	while (i < 4) { // �Ĵ���Ч�����������Ϸ
		// ����
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
		// �����ʾ��
		if (player)
			cout << "x: ";
		else
			cout << "o: ";
		// ��Ҳ���
		int x;
		cin >> x;
		if (a[x - 1] > 0) {			// �����Ϸ�
			a[x - 1] = player - 1;	// ���̼Ǻ�
			player = !player;		// �л����
			++i;					// ��Ч��������
		}
	}	
}