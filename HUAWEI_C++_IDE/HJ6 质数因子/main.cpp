#include<iostream>
#include<vector>
using namespace std;


//�����ֽⶨ�� һ������1�����������ֽ���ʽ��Ψһ�ġ�
int main() {

	int N;
	//vector<int> res;
	while (cin >> N) {
		if (N == 1) {
			cout << N << " " << N << endl;
		}
		
		for (int i = 2; i <= N / i; i++) {
			//M*�ܹ�����i
			if (N % i == 0) {
				int cnt = 0;
				while (N % i == 0) {
					cnt++;
					//s.push_back(i);
					N /= i;
					//if (cnt) cout << i << " " << cnt << endl;
					if (cnt) cout << i << " ";
				}
			}
		}
		//if (N > 1) cout << N << " " << 1<< endl;
		if (N > 1) cout << N << endl;
	
	}

	return 0;
}
