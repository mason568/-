#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;


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
