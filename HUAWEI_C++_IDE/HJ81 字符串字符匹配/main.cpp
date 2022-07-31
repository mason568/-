#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<int> getNext(string s) {
	vector<int> next(s.size());
	int val = -1;//��ǰ����ǰ��׺���ȣ�-1������ʼ��Ϊ-1����Ϊһ���ַ�û��ǰ׺Ҳû�к�׺
	//��ؼ����val�����壬������forѭ����next[i]=val;֪����val��һ���м�״̬��������ǵ�ǰ����ǰ��׺����-1������ÿƥ��һ���ַ���Ҫ��������ֵ
	next[0] = val;
	for (int i = 1; i < s.size(); i++) {
		while (val >= 0 && s[i] != s[val + 1]) {
			val = next[val];//������֮ǰ�ַ���������ǰ��׺Ϊval-1�Ļ����ϣ����һ���ַ��ǲ���ǰ��׺����ȣ������Ϊ��ȵ�ǰ��׺����ô��Ҫ���˵���һ���ȵ�ǰ��һ�����ַ����ж��ǲ������һ���ַ���Ϊ�����������ǣ��������ˣ�Ҫô�ҵ���һ����һ�ص����ǰ��׺��Ҫôֱ���˲�����val=-1�˳�whileѭ����
		}
		//������֮ǰ�ַ���������ǰ��׺Ϊval-1�Ļ����ϣ����һ���ַ��ǲ���ǰ��׺����ȣ�����ǣ���ôval ����Ϊ val+1
		if (s[i] == s[val + 1]) {
			val++;
		}
		//����val
		next[i] = val;
	}
	return next;
}

int main() {
	string S, T;
	while (cin >> S >> T) {
		if (S.size() > T.size()) continue;
		vector<int> next = getNext(S);
		int j = -1;
		bool flag = false;
		for (int i = 0; i < T.size(); i++) {
			//��֮ǰ��˼·һ������ƥ��Ļ���Ҫ����һ��λ��
			while (j >= 0 && T[i] != S[j + 1]) {
				j = next[j];
			}
			if (T[i] == S[j + 1]) {
				j++;
			}
			if (j == (S.size() - 1)) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "true" << endl;
		else cout << "false" << endl;
	
		
	}

	return 0;
}