#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<set>
#include<unordered_set>
#include"assert.h"
using namespace std;

int main() {
	string key, text;
	while (cin >> key >> text) {
		//������Կ��������
		char m[26];
		set<char> key_set;
		int i = 0;
		for (char k : key) {
			k = tolower(k);
			if (key_set.find(k) != key_set.end()) continue;
			else {
				key_set.insert(k);
				m[i++] = k;
			}
		}
		//����ӳ���
		for (int j=0; j < 26; j++) {
			if (key_set.find('a' + j) == key_set.end() && i<26) {
				m[i++] = 'a' + j;
			}
		}
		//����
		for (int j = 0; j < text.size(); j++) {
			assert(isalnum(text[j]));
			text[j] = m[tolower(text[j]) - 'a'];
		}
		//���
		cout << text << endl;
	}


	return 0;
}