#include<iostream>
#include<string>
#include<vector>
using namespace std;



#if 1

string solution1(string s1, string s2) {//����s1�ĳ��ȸ���
	string res = "";
	if (s1.size() > s2.size()) {
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	//������ find���� [i,j]Ϊs1���Ӵ�
	if (s1.size() < 1) return res;
	//pair<int, int> pos(0,0);
	int maxLen = 0;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = i ; j < s1.size(); j++) {
			string sub = s1.substr(i, j - i+1);
			if (s2.find(sub) != string::npos) {
				if (j - i > maxLen) {
					maxLen = j - i;
					res = sub;
				} 
			}
		}
	}
	return res;
}

//��̬�滮
string solution2(string s1, string s2) {//����s1�ĳ��ȸ���
	string res = "";
	if (s1.size() > s2.size()) {
		swap(s1, s2);//swapҲ����ֱ�ӽ����ַ���
	}
	vector<vector<int> > dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
	int maxLen = 0, end = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for(int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
			//ά����ĳ���
			if (dp[i][j] > maxLen) {
				maxLen = dp[i][j];
			end = i - 1;
			}
		}
	}
	
	return s1.substr(end-maxLen+1,maxLen);
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		//cout << solution1(s1, s2) << endl;
		cout << solution2(s1, s2) << endl;
	}

	return 0;
}
#endif