#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int count[4] = { 0 };
		for (auto ch : s) {
			if (isalpha(ch)) count[0]++;//ͳ����ĸ
			else if (ch == ' ') count[1]++;//ͳ�ƿո�
			else if (ch >= '0' && ch <= '9') count[2]++;//ͳ������
			else count[3]++;//ͳ�������ַ�
		}
		for (auto c : count) cout << c << endl;
	}
	return 0;
}