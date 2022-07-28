#include<iostream>
#include<vector>
#include<queue>
#include"assert.h"
using namespace std;

//ֱ��ģ��
#if 0
int main() {
	int n;
	string ops;
	while (cin >> n >> ops) {
		vector<int> dialog(n);
		for (int i = 0; i < n; i++) dialog[i] = i + 1;
		int it = 0;
		int len = n > 4 ? 4 : n;
		vector<int> screen(len);
		for (int j = 0; j < len; j++) screen[j] = j+1;
		if (len >= 4) {
			for (int i = 0; i < ops.size(); i++) {
				char op = ops[i];
				assert(op == 'U' || op == 'D');
				if (op == 'U') {
					if (it == 0 && screen[0] == 1) {
						it = len - 1;
						for (int j = 0; j < 4; j++) screen[j] += n - len;
					}
					else if (it == 0 && screen[0] > 1) {
						it = 0;
						for (int j = 0; j < 4; j++) screen[j] -= 1;
					}
					else {
						it--;
					}
				}
				else {
					if (it == 3 && screen[3] == n) {
						it = 0;
						for (int j = 0; j < 4; j++) screen[j] -= n - 4;
					}
					else if (it == 3 && screen[0] < n) {
						it = 3;
						for (int j = 0; j < 4; j++) screen[j] += 1;
					}
					else {
						it++;
					}

				}
			}
		}
		else {
			for (int i = 0; i < ops.size(); i++) {
				char op = ops[i];
				assert(op == 'U' || op == 'D');
				if (op == 'U') {
					if (it == 0 ) {
						it = len - 1;
					}
					else {
						it--;
					}
				}
				else {
					if (it == len-1 ) {
						it = 0;
					}
					else {
						it++;
					}

				}
			}
		}
		for (auto _ : screen) cout << _ << " ";
		cout << endl << screen[it] << endl;
	}

}
#endif
//��������

#if 1
int main() {
	int n;
	string commands;
	while (cin >> n >> commands) {
		int num = 1;//ѡ�еĸ���
		int win_b = 1;//ҳ�����ʼ
		int win_e = min(4, n);//ҳ���ĩλ�� 2
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == 'U') {//�����ƶ�һ��
				num = (num - 1 - 1 + n) % n + 1;
			}
			else if (commands[i] == 'D') {//�����ƶ�һ��
				num = num % n + 1;
			}
			if (num < win_b) {//�����ǰ�����ڴ���ǰ���򽫴�����ǰ�ƶ�
				win_b = num;
				win_e = win_b + 3;
			}
			else if (num > win_e) {//�����ǰ�����ڴ��ں��򽫴��������ƶ�
				win_e = num;
				win_b = win_e - 3;
			}
		}
		for (int i = win_b; i <= win_e; i++) {//�����ǰҳ��
			cout << i << ' ';
		}
		cout << endl;
		cout << num << endl;//���ѡ�еĸ���
	}
	return 0;
}



#endif 