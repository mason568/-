#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;
#if 1
//��Ч�Ļ���
bool isPalindrome1(string s) {
    string sgood;
    for (char ch : s) {
        if (isalnum(ch)) { //ֻ����Ӣ����ĸ��Сд�����֣���������ascii�ַ�
            sgood += tolower(ch);
        }
    }
    string sgood_rev(sgood.rbegin(), sgood.rend()); 
    return sgood == sgood_rev;
}

bool isPalindrome2(string s) {
    int i = 0; int j = s.size() - 1;
    while (i <= j) {
        while (!isalnum(s[i])) i++;
        while (!isalnum(s[j])) j--;
        if (s[i] != s[j]) {
            return false;
        }
        else {
            i++;
            j--;
        }

    }
    return true;

}

int main() {
    string s = "asdf&&%*fbdsa";
    cout << isPalindrome1(s) << endl;
    cout << isPalindrome2(s) << endl;
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

#if 0
//�����������
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


//������Ӵ�


#if 0
string init(string& s) {
    string res = "";
    res += "$#";
    for (int i = 0; i < s.size(); i++) res += s[i], res += '#';
    res += '^';
    return res;
    // ������ڿ�ʼ�ͽ�������ͨ���, Ȼ�������м�ÿ���ָ�ĵط�����#
}

void manacher(vector<int>& p, string& s) {
    int mr = 0, mid;
    // mr������midΪ���ĵ�����ĵ��б߽�
    // midΪi��j�����ĵ�, i��midΪ�ԳƵ㷭�۵�j��λ��
    for (int i = 1; i < s.size(); i++) {
        if (i < mr)
            p[i] = min(p[mid * 2 - i], mr - i);
        // 2 * mid - iΪi����mid�ĶԳƵ�
        else
            p[i] = 1;
        // �����߽��ܹ��Ͳ��ǻ�����
        while (s[i - p[i]] == s[i + p[i]]) p[i]++;
        // ����Ҫ�жϱ߽�, ��Ϊ������ͨ���
        if (i + p[i] > mr) {
            mr = i + p[i];
            mid = i;
        }
        // ����ÿ��һ��i, ��Ҫ��mx�Ƚ�, ����ϣ��mx�����ܵ�Զ
    }
}

signed main() {
    string s;
    cin >> s;
    s = init(s);
    vector<int> p(s.size());
    manacher(p, s);
    // ��ʼ���ַ�������ȡ�������ǵ�ÿһ��λ�õ������
    int maxx = INT_MIN;
    for (auto& it : p) maxx = max(maxx, it);
    cout << maxx - 1 << "\n";
    return 0;
}

#endif