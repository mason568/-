#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//��ĸ��λ�� hash�� ����ֻ��Сд��ĸ
bool is_bro(string a, string b) {
	if (a == b) return false;
	if (a.size() != b.size()) return false;
	int count[26] = { 0 };
	for (int i = 0; i < a.size(); i++) {
		count[a[i] - 'a']++;
		count[b[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) {
		if (count[i] != 0) return false;
	}
	return true;

}

void find_bro(string x, vector<string>& dict, vector<string>& bros) {
	for (auto s : dict) {
		if (is_bro(s,x)) {
			bros.push_back(s);
		}
	}
	sort(bros.begin(),bros.end());
}

int main() {
	int N;
	while (cin >> N) {
		//����
		vector<string> dict;
		string tmp,x;
		int k;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			dict.push_back(tmp);
		}
		cin >> x >> k;
		//�ֵܵ��ʾ��ǵ��ʴ���˳���Ĵʣ��ұز���ͬ
		//�ҵ�����x���ֵܵ���,�����ų��ֵ���
		vector<string> bros;
		find_bro(x, dict, bros);
		cout << bros.size() << endl;
		if (bros.size() >= k) {
			cout << bros[k - 1] << endl;
		}
	}


	return 0;
}