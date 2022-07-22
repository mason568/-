#include<iostream>
#include<string>
#include"assert.h"
#include<algorithm>
using namespace std;

void cleanSpace(string& s) {
	//ȥ���ո� ˫ָ�� ˳�����������Ч�ַ���ǰ�� 
	//ȥ��ǰ��ո�
	int slow = 0, fast = 0;
	while (s.size() > 0 && fast < s.size() && s[fast] == ' ') fast++;
	//ȥ���м����ո� s
	for (; fast < s.size();fast++) {
		if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ') continue;
		else {
			s[slow++] = s[fast];
		}
	}

	//���slow��ǵĴ�������һ���ո�Ҳ����û�пո���äĿresize(slow-1)
	if (slow - 1 > 0 && s[slow - 1] == ' ') {
		s.resize(slow - 1);
	}
	else {
		s.resize(slow);
	}
}

void reverse(string& s,int start, int end) {
	//˫ָ��
	for (int i = start, j = end; i < j; i++, j--) {
		swap(s[i], s[j]);
	}
}

int main() {
	string s;
	while (getline(cin, s)) {
		//�����еķ���ĸ�����ַ���ɿո�
		for (int i = 0; i < s.size(); i++) {
			if (!isalnum(s[i])) s[i] = ' ';
		}
		//ȥ��ǰ��ո�Ͷ���ո�
		cleanSpace(s);
		//��������
		reverse(s,0,s.size()-1);
		
		//��ԭ�ַ����϶Ե�������
		
		for (int pos = 0; pos < s.size();) {
			int len = 0;
			while (pos + len<s.size() && s[pos + len] != ' ') len++;
			reverse(s, pos, pos + len-1);
			pos = pos + len + 1;
		}
		
		cout << s << endl;
	}

	return 0;
}