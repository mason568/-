#include<iostream>
#include<vector>
#include<sstream>
using namespace std;


//�ݹ�
vector<int> res;
void fun(int a, int b) {
	if (a == 1) {
		res.push_back(b);
		return;
	}

	if (b % a == 0) {
		res.push_back(b / a);
		return;
	}
	while (a > 1) {
		res.push_back(b / a + 1);
		fun(a - (b % a), b * (b / a + 1));
		return;
	}
	
}


int main() {
	string s;
	while (cin >> s) {
		stringstream ss(s);
		long int a, b;
		string sub;
		getline(ss, sub, '/');
		a = stoi(sub);
		getline(ss, sub, '/');
		b = stoi(sub);
		if (a > b) continue;
		//�ǲ���ҪԼ�ֵȵ��ٿ�
		//��vector<int>  ����¼��ĸ
		
		fun(a, b);


		string answer = "";
		for (auto num : res) {
			answer += "1/" + to_string(num);
			answer += '+';
		}
		answer.pop_back();
		cout << answer << endl;

	}


}

//��ѧ
#if 0
int main() {
	string s;
	while (cin >> s) {
		stringstream ss(s);
		long int a, b;
		string sub;
		getline(ss, sub, '/');
		a = stoi(sub);
		getline(ss, sub, '/');
		b = stoi(sub);
		if (a > b ) continue;
		//�ǲ���ҪԼ�ֵȵ��ٿ�
		//��vector<int>  ����¼��ĸ
		vector<int> res;

		while (a != 1) {
			if (a == 1 || b % a == 0) {
				res.push_back(b / a);
				break;
			}
			long int q = b / a, r = b % a;
			res.push_back(q + 1);
			b = b * (q + 1);
			a = a - r;
			if (a == 1) {
				res.push_back(b);
				break;
			}
		}
		
		

		string answer = "";
		for (auto num : res) {
			answer += "1/" + to_string(num);
			answer += '+';
		}
		answer.pop_back();
		cout << answer << endl;
		
	}


}

#endif
