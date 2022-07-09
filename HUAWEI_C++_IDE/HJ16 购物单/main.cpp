#include<iostream>
#include<bitset>
#include<vector>
using namespace std;



int main() {
	int N, m;
	while (cin>>N>>m) {
		//����
		int value, proority, isAttachments;
		vector<vector<int>> data(m + 1, vector<int>(6, 0));
		for (int i = 0; i < m; i++) {
			cin >> value >> proority >> isAttachments;
			if (isAttachments == 0) {
				data[i][0] = value;
				data[i][1] = proority;
			}
			//��Ϊ���ֻ��������
			else if (data[isAttachments][2] == 0) {
				data[isAttachments][2] = value;
				data[isAttachments][3] = value;
			}
			else {
				data[isAttachments][4] = value;
				data[isAttachments][5] = value;
			}
		}
		//dp[i][j]����ʾǰi����Ʒ����������Ϊj���������װ������ֵ n
		//01�������� ��ά���� dp[i][j]��
		vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				//i=1,j=1ʱ���ǳ�ʼ��
				int valuePrime = data[i][0];
				int valueAttach1 = data[i][2];
				int valueAttach2 = data[i][4];
				int prorityPrime = data[i][1];
				int prorityAttach1 = data[i][3];
				int prorityAttach2 = data[i][5];

				//����ÿһ�����������5����� 1��������(��ǰһ�����) 2���������򸽼� 3�������򸽼�1 4�������򸽼�2 5��������������������
				dp[i][j] = j >= valuePrime ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime, dp[i - 1][j]) : dp[i - 1][j];
				dp[i][j] = j >= (valuePrime+valueAttach1) ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1, dp[i][j]) : dp[i][j];
				dp[i][j] = j >= (valuePrime + valueAttach2) ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime + valueAttach2 * prorityAttach2, dp[i][j]) : dp[i][j];
				dp[i][j] = j >= (valuePrime + valueAttach1 + valueAttach2) ? max(dp[i - 1][j - valuePrime] + valuePrime * prorityPrime + valueAttach1 * prorityAttach1 + valueAttach2 * prorityAttach2, dp[i][j]) : dp[i][j];


			}
		}

		cout << dp[m][N] << endl;
		
		//cout << N << " " << m << endl;
	}
	return 0;
}