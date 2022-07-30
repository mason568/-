#include<iostream>
#include<vector>
#include<stack>
#include"assert.h"

using namespace std;



void Caculation(stack<pair<int, int>>& mtx_st, int& sum,int &n,int &m) {
	pair<int, int> rhs = mtx_st.top();
	mtx_st.pop();
	pair<int, int> lhs = mtx_st.top();
	mtx_st.pop();
	n = lhs.first;
	m = rhs.second;
	sum += lhs.first * rhs.second * lhs.second;
	
}

bool candocaculate(stack<pair<int, int>>& st) {
	if (st.size() <= 1) return false;
	pair<int, int> rhs = st.top();
	st.pop();
	pair<int, int> lhs = st.top();
	st.pop();
	if (rhs.first != -1 && lhs.first != -1) {
		st.push(lhs);
		st.push(rhs);
		return true;
	}
	else {
		st.push(lhs);
		st.push(rhs);
		return false;
	}
	
}


int main() {
	int N;//N������
	while (cin >> N) {
		vector<pair<int, int>> matrixs;
		int n, m;//һ������n��m��
		string s;//����˳��
		for (int i = 0; i < N; i++) {
			cin >> n >> m;
			matrixs.push_back(make_pair(n, m));
		}
		//�������˳��
		cin >> s;
		stack<pair<int, int>> st;
		int cnt = 0;
		int sum = 0;
		pair<int, int> res = {-1,-1};
		for (auto ch : s) {
			if (ch == '(') {
				st.push(make_pair(-1,-1));
			}
			else if (ch == ')') {
				int tmp_n, tmp_m;
				//���ջ�����������󣬾Ͱ����ǵļ����������������ȥ��֮ǰ�ģ�-1��-1���ٰѽ���ӽ�ȥ
				while (candocaculate(st)) Caculation(st, sum, tmp_n, tmp_m);
				st.pop();
				st.push(make_pair(tmp_n, tmp_m));
				res = { tmp_n, tmp_m };
			}
			else if (isupper(ch) ) {
				st.push(matrixs[cnt++]);
			}		
		}

		cout << sum << endl;
	}


}