#include<iostream>
#include<iomanip>
using namespace std;

void solve() {
    int n;
    while (cin >> n) {
        int cnt = 0, sum = 0, num = 0;
        // cnt Ϊ����������sumΪ�����ĺͣ�numΪ�����ĸ���
        int tmp;
        // ���ٴ�СΪ n ������
        for (int i = 0; i < n; i++) {
            // �������ͳ��
            cin >> tmp;
            if (tmp < 0) ++cnt;
            else if (tmp > 0) sum += tmp, ++num;
        }
        if (num) cout << cnt << " " << fixed << setprecision(1) << sum * 1.0 / num << endl;
        else cout << cnt << " " << fixed << setprecision(1) << "0.0" << endl;
        // ����һλС��
    }
}

signed main() {
    solve();
    return 0;
}
