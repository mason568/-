#include<iostream>
#include<string>
#include<stack>
using namespace std;
#if 1
//˫ջ��  �����
void caxulate(stack<int>& st_num, stack<char>& st_op) {
	if (st_num.size() < 2 || st_op.empty()) return;
	int rhs = st_num.top();
	st_num.pop();
	int lhs = st_num.top();
	st_num.pop();
	char op = st_op.top();
	st_op.pop();
	if (op == '+') st_num.push(lhs + rhs);
	else if (op == '-') st_num.push(lhs - rhs);
	else if (op == '*') st_num.push(lhs * rhs);
	else if (op == '/' && rhs != 0) st_num.push(lhs / rhs);
}


bool priority(char m, char n) { //�Ƚ���������ȼ�

	if (m == '(') 
		return false;
	else if ((m == '+' || m == '-') && (n == '*' || n == '/')) //�Ӽ���С�ڳ˳���
		return false;
	return true; //n �����ȼ���
}


int caculateVal(string s) {
	stack<int> st_num;//�洢������
	stack<char> st_op;//�洢��������������
	st_op.push('(');
	s += ')';
	bool flag = false;//ֻ���ټ���һ������������ܼ������ + - * /
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			st_op.push('(');
		}
		else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
			while (st_op.top() != '(') caxulate(st_num, st_op);
			st_op.pop();
		}
		else if (flag) {
			//���ǰһ�������������ţ���ô����Ҫ������ֱ�Ӽ��ϵ�ǰ������-*/+
			//���ǰһ���������������ţ���ǰҪ����Ĳ������ֱ�ǰһ�����������ȼ��ߣ���ǰ��s[i]Ϊ*��/��ǰһ��������Ϊ-��+����ôǰ��Ĳ�����-��+Ҳ�ñ�����ֱ�Ӽ��ϵ�ǰ������
			//����Ļ���Ҫô���ֲ��������ȼ���ͬ��Ҫôǰ��Ĳ��������ȼ����¼ӵĲ��������ȼ��ߣ���Ҫ���㣬����֮���ټ��ϵ�ǰ�Ĳ�����
			while(priority(st_op.top(),s[i])) caxulate(st_num, st_op);
			st_op.push(s[i]);
			//�¼���һ���������󣬱����һ����������flag����Ϊfalse
			flag = false;
		}
		else {
			st_num.push(stoi(s.substr(i)));
			int len = to_string(stoi(s.substr(i))).size();
			i += len - 1;
			flag = true;
		}
	}


	return st_num.top();
}

int main() {
	string s;
	while (cin >> s) {
		cout << caculateVal(s) << endl;
	}
	return 0;
}
#endif

//�ݹ鷨
#if 0
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compute(string& s, int left, int right) {
	char op = '+'; //Ĭ�ϼӿ�ʼ
	int num = 0;
	vector<int> st;
	for (int i = left; i <= right; i++) {
		if (isdigit(s[i])) //����
			num = num * 10 + s[i] - '0'; //����ò��������ܺ�
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') { //����������
			int layer = 0; //ͳ�������Ų���
			int j = i;
			while (j <= right) { //�������ұ�
				if (s[j] == '{' || s[j] == '[' || s[j] == '(')
					layer++; //���������ţ������ۼ�
				else if (s[j] == '}' || s[j] == ']' || s[j] == ')') {
					layer--; //���������Ų����ݼ�
					if (layer == 0) //ֱ������Ϊ0
						break;
				}
				j++;
			}
			num = compute(s, i + 1, j - 1); //�ݹ���������еĲ���
			i = j + 1;
		}
		if (!isdigit(s[i]) || i == right) { //������������߽�β
			switch (op) { //�����������ʼ����
			case '+': st.push_back(num); break; //�Ӽ������뵽ĩβ
			case '-': st.push_back(-num); break;
			case '*': st.back() *= num; break; //�˳�����ĩβ����
			case '/': st.back() /= num; break;
			}
			op = s[i]; //�޸�Ϊ��һ�ε������  ����֮�ذ�����
			num = 0;
		}
	}
	int res = 0;
	for (int x : st) //�ۼӺ�
		res += x;
	return res;
}
int main() {
	string s;
	while (cin >> s) {
		cout << compute(s, 0, s.length() - 1) << endl;
	}
	return 0;
}


#endif