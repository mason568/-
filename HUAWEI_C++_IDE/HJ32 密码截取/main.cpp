#include<iostream>
#include<string>
#include<vector>
using namespace std;

int max_conc_plaindrome_dp(string s) {
	//dp[i][j]��ʾ[i,j]���ַ����ǲ���һ�������ַ���
	vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
	int n = s.size();
	int maxLen = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j) dp[j][i] = true; //�����������ӷ���
			else if (i - j == 1) dp[j][i] = (s[i] == s[j]);//ż���������ӷ���
			else dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);//ֻ���м�Ҳ�ǻ��Ĵ������������ַ���ȣ�������һ���µĻ��Ĵ� p.s.�м䴮��ֵ��һ���Ѿ�ȷ������
			if (dp[j][i] && i - j + 1 > maxLen) maxLen = i - j + 1;

		}
	}
	return maxLen;
}

int zxks_getmaxLen(string& s, int l, int r) {
	//��������ɢ�����̶�
	while (l >= 0 && r < s.size() && s[l] == s[r]) {
		l--;
		r++;
	}
	return r - l - 1;//��Ϊ�ϴ����֮��Ͱѳ��ȼ���2��������Ҫ����2
}

int max_conc_plaindrome_zxks(string s) {
	//������ɢ�����ĳ��ȷ���ż���
	if (s.size() == 0) return 0;
	if (s.size() == 1) return 1;
	int maxLen = 1;
	for (int i = 0; i < s.size(); i++) {
		int m1 = zxks_getmaxLen(s, i, i);
		maxLen = max(m1, maxLen);
	}
	for (int i = 0; i < s.size()-1; i++) {
		int m2 = zxks_getmaxLen(s, i, i + 1);
		maxLen = max(m2, maxLen);
	}

	return maxLen;
}
int main() {
	//��������������ַ��� - ��̬�滮 dp[i][j]��ʾ��[i,j]֮�������������ַ����ĳ���  ������Ҫ�����Ļ��ģ��������Ǽ�ϵ�
	string s;
	while (cin >> s) {
		//cout << max_conc_plaindrome_dp(s) << endl;
		cout << max_conc_plaindrome_zxks(s) << endl;
	}

	return 0;
}

