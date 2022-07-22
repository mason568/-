#include <iostream>
#include <string>
#include <algorithm>
#include"time.h"
using  namespace std;

void qucik_sort(string& s, int left, int right) {
	if (s == "") return;
	if (left >= right) return;
	srand((unsigned)time(NULL));
	int len = right - left;
	int kindex = left + rand() % (len + 1);
	swap(s[left],s[kindex]);

	int key = s[left];
	int i = left, j = right;
	while (i < j) {
		while (s[j] >= key && i < j) --j;
		if (i < j)s[i] = s[j];//��j����������ĵ�һ��С���ڱ�������ǰ�ӣ��ڱ������ǣ����Ǳ��ݵ�key��  ���ӵ����λ�þͿճ�����
		while (s[i] < key && i < j) ++i;
		if (i < j) s[j] = s[i];//��i���Ұ������ĵ�һ�����ڵ����ڱ��������ոտճ���λ�ü�������ʱ������λ��s[i]��ʵ����Ҫ��һ��Ԫ�ؽ����ģ�����б��ڱ�С�ĵ�Ȼ�ã�ʵ���Ҳ�����,�ѱ��ݵ��ڱ��Ž�����
	}

	s[i] = key;
	qucik_sort(s, left, i - 1);
	qucik_sort(s, j + 1, right);
}


int main() {
	string s;
	while (cin >> s) {
		qucik_sort(s,0,s.size()-1);



		cout << s << endl;
	}
}