#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> single = { "��", "Ҽ", "��", "��", "��",
                         "��", "½", "��", "��", "��" };

void sayPre(string& pre) {
    if (pre == "0") return;
    // �ж�С����ǰ���ǲ��ǿյ�
    for (int i = 0, j = pre.size() - 1; i < pre.size(); i++, j--) {
        // i����������Ǳ������ַ���, j������i�����м�����
        if (pre[i] != '0' and not(pre[i] == '1' and j % 4 == 1))
            cout << single[pre[i] - '0'];
        // ת������
        if (j != 0 and j % 8 == 0 and j >= 8)
            cout << "��";
        if (j != 0 and j % 4 == 0 and j % 8 != 0)
            pre[i + 1] == '0' ? cout << "����" : cout << "��";
        if (j != 0 and j % 4 == 3 and pre[i] != '0')
            pre[i + 1] == '0' and pre[i + 2] != '0' ? cout << "Ǫ��" : cout << "Ǫ";
        if (j != 0 and j % 4 == 2 and pre[i] != '0')
            pre[i + 1] == '0' and pre[i + 2] != '0' ? cout << "����" : cout << "��";
        if (j != 0 and j % 4 == 1 and pre[i] != '0')
            cout << "ʰ";
    }
    // �����if�ֱ��Ӧ�������������ǧ��ʮ
    cout << "Ԫ";
    // ����������Ԫ
}

void sayEnd(string& end) {
    if (end == "00")
        cout << "��\n";
    else if (end[0] == '0')
        cout << single[end[1] - '0'] << "��\n";
    else if (end[1] == '0')
        cout << single[end[0] - '0'] << "��\n";
    else
        cout << single[end[0] - '0'] << "��" << single[end[1] - '0'] << "��\n";
    // ��������, ��������С�������λ���������
}

signed main() {
    string s;
    while (cin >> s) {
        string pre = "", end = "";
        bool okk = false;
        for (auto& it : s) {
            if (it == '.') {
                okk = true;
                continue;
            }
            okk ? end += it : pre += it;
        }
        // ����������С����Ϊ�ָ�, ��С����ǰ��Ĵ洢����pre����,
        // С�������Ĵ洢����end����
        cout << "�����";
        sayPre(pre), sayEnd(end);
    }
    return 0;
}
