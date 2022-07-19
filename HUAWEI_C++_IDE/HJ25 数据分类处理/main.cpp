#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;

void check_r_belongto_I(int r, vector<int>& I, map<int, int>& key_val) {
	// ����I��ÿһ��Ԫ�� ����Ƿ������r����� ���ֲ����жϣ�ת�ַ��� ��Ϊ�����жϣ�ȡ�಻����r=3 however 6%3=0 
	string r_s = to_string(r);
	for (int i = 0; i < I.size(); i++) {
		string i_s = to_string(I[i]);
		if (i_s.find(r_s)!=string::npos) {
			key_val.emplace(i, I[i]);
		}
	}
}

int main() {
	//����
	int I_size, R_size, tmp;
	vector<int> I;
	set<int> R;
	cin >> I_size;
	
	vector<int> res;//�������
	for (int i = 0; i < I_size; i++) {
		cin >> tmp;
		I.push_back(tmp);
	}
	cin >> R_size;
	for (int i = 0; i < R_size; i++) {
		cin >> tmp;
		R.insert(tmp);
	}

	//����$r \in R$�����I�а���r��Ԫ�� д�ɺ���
	set<int>::iterator r;
	for (r = R.begin(); r != R.end(); r++) {
		map<int, int> key_val;
		check_r_belongto_I(*r, I, key_val);
		//�ѷ��صĶ������뵽���������
		if (key_val.size() > 0) {
			// �����R[i]
			res.push_back(*r);
			//���������������I�ĸ���
			res.push_back(key_val.size());
			//�������key_val��Ԫ��
			for (auto k_v : key_val) {
				res.push_back(k_v.first);
				res.push_back(k_v.second);
			}
		}
	}

	int count = res.size();//������������Ԫ�صĸ���
	res.insert(res.begin(), count);
	for (auto i : res) {
		cout << i << " ";
	}
	cout << endl;
	

	return 0;
}