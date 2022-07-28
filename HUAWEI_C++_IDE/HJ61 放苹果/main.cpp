#include<iostream>
#include<vector>
using namespace std;


int put(int m, int n) {
	//�ݹ��������
	if (m == 0 || n == 1) return 1;
	if (m >= n) return put(m - n,n) + put(m, n - 1);
	if (m < n) return  put(m, n - 1);
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		cout << put( m, n) << endl;
	}
	return 0;
}

#if 0
int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++) {
			dp[i][1] = 1;//i��ƻ���ŵ�һ����ֻ��һ��
			for (int j = 1; j <= n; j++) {
				dp[0][j] = 1;// 0��ƻ����������Ҳֻ��һ��
				if (i >= j) dp[i][j] = dp[i - j][j] + dp[i][j - 1];
				else dp[i][j] = dp[i][j - 1];
 			}
		}
		cout << dp[m][n] << endl;
	
	}
	return 0;
}
#endif