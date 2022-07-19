#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
//��Ч�Ļ���
bool isPalindrome(string s) {
    string sgood;
    for (char ch : s) {
        if (isalnum(ch)) {
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend());
    return sgood == sgood_rev;
}

int main() {
    string s = "asdffdsa";
    cout << isPalindrome(s) << endl;
	return 0;
}
#endif

#if 0
//�ַ�������Ч�Ļ����Ӵ����� ����Ϊ�Ѿ���������ַ���
//����ÿһ�������ǻ������ĵ�λ�ã�Ȼ��������ɢ��ֱ�������ַ�����Ⱦ�ֹͣ��ɢ
int countSubstrings(string s) {
    int n = s.size(), ans = 0;
    //��żλ��һ���Դ���
    /*
    for (int i = 0; i < 2 * n - 1; ++i) {
        int l = i / 2, r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    */
    //��żλ�ô���
    //�Ӵ������� ����Ϊs[i]
    //�Ӵ�ż������ ����Ϊs[i],s[i+1]
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    for (int i = 0; i < n; i++) {
        int l = i, r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
            ++ans;
        }
    }
    return ans;
}

int main() {
    cout << countSubstrings("asajfdsfigghhjhhgg") << endl;
}
#endif

#if 1
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        char c1 = s[i];
        for (int j = i + 1; j < n; j++) {
            char c2 = s[j];
            if (c1 == c2) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    cout << longestPalindromeSubseq("asajfdsfigghhjhhgg") << endl;
    return 0;
}

#endif
