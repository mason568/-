#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�ݹ�
#if 0
bool match(const char* s, const char* p) {
	if (*s == '\0' && *p == '\0') return true;//��ȫƥ��
	if ((*p == '\0' || *s == '\0')) return false;//��ƥ��
	if (*p == '?') {
		//��ƥ��
		if (!isalnum(*s)) return false;
		return match(s + 1, p + 1);
	}
	else if (*p == '*') {
		//���*����һ��
		while (*p == '*') p++;
		p--;
		return match(s, p + 1) || match(s + 1, p + 1) || match(s + 1, p);//��һ��ƥ��
	}
	else if (tolower(*s) == tolower(*p)) {
		return match(s + 1, p + 1);//��һ��ƥ��
	}
	//������������������� �� 'a'������ '.'
	return false;//��ƥ��
}

int main() {
	string p, s;
	while (cin >> p >> s) {
		bool res = match(s.c_str(), p.c_str());
		if (res) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}

#endif 


//dp
#if 1

bool ismatch(string s, string p) {
	int len_s = s.size(); //�ִ�
	int len_p = p.size(); //ͨ�����
	vector<vector<bool>> dp(len_p + 1, vector<bool>(len_s + 1, false));
	dp[0][0] = 1;


	for (int i = 1; i <= len_p; i++) {
		char ch_p = p[i - 1];
		//���sΪ�գ�pֻ����ȫ'*'���п���ƥ�䣨��ȫ*ƥ��0���ַ���
		dp[i][0] = dp[i - 1][0] && (ch_p == '*');
		for (int j = 1; j <= len_s; j++) {
			char ch_s = s[j - 1];
			if (ch_p == '*' && isalnum(ch_s)) {
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; //*ƥ��0��||���
			}
			else if (tolower(ch_s) == tolower(ch_p)) {  //���������ַ���ֻ������ '.'== '.'
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (ch_p == '?') {
				//ֻ��ƥ���ַ��������֣�һ��
				if (isalnum(ch_s)) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = false;
			}
			else if (ch_p == '*') {// ���*����ֻ��һ��*�����ã��������*����ƥ��0��
				dp[i][j] = dp[i - 1][j];
			}

		}
	}


	return dp[len_p][len_s];
}
int main() {
	string p, s;
	while (cin >> p >> s) {
		bool res = ismatch(s, p);
		if (res) cout << "true" << endl;
		else cout << "false" << endl;
	}
	return 0;
}

#endif