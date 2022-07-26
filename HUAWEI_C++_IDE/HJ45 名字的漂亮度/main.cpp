#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"assert.h"
using namespace std;

bool comp(pair<char, int>& lhs, pair<char, int> &rhs) {
	return lhs.second > rhs.second;
}

int main() {
	
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			int res = 0;
			//̰�ļ���һ���ַ�����Ư����
			//��ͳ�Ƴ��ִ�������¼��map��ȥ  //��ʲômap,��������� Ȼ�����Զ���ıȽϺ������¶�������������
			map<char, int> m;
			for (auto ch : s) {
				m[tolower(ch)]++;
			}
			//sortֻ��֧�����飬vector������ map���У������Ȱ�ӳ��ŵ�vector��
			vector<pair<char, int>> vec;
			for (auto it = m.begin(); it != m.end(); it++) {
				vec.push_back(make_pair(it->first, it->second));
			}
			sort(vec.begin(), vec.end(), comp);
			assert(vec.size() <= 26);
			int val = 26;
			for (auto it : vec) {
				res += it.second * (val--);
			}
			cout << res << endl;

		}
	}
	return 0;
}