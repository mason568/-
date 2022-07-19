#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	while (cin >> N) {
		//����
		vector<int> tall;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			tall.push_back(t);
		}
		//��ϸ����������+��ϸ�ݼ�������->��̬�滮
		vector<int> dp_h(N, 1), dp_t(N, 1);
		//����������dp����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (tall[i] > tall[j]) {
					dp_h[i] = max(dp_h[i],dp_h[j]+1);//�����1�Ǽӵĵ�i���ˣ���Ϊ����֮ǰ��i-1���ˣ�����j������
				}
			}
		}

		for (int i = N-1; i >= 0; i--) {
			for (int j = N - 1; j > i; j--) {
				if (tall[i] > tall[j]) {
					dp_t[i] = max(dp_t[i], dp_t[j] + 1);
				}
				
			}
		}
		//��͵õ��������������г��ȣ�������Ϊ���������һ�Σ�Ҫ�ڼ�ȥ1
		int maxNum = 0;
		for (int i = 0; i < N; i++) {
			if (dp_h[i] + dp_t[i] - 1 > maxNum) {
				maxNum = dp_h[i] + dp_t[i] - 1;
			}
		}
		cout << N - maxNum << endl;

	}

	return 0;
}