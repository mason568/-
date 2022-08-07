#include<iostream>
#include<vector>
#include"assert.h"
#include<sstream>
#include<string>
#include<unordered_map>
using namespace std;



int nums[4];
bool flag = false;
bool used[4] = { 0 };
vector<string> res;
unordered_map<string, int> m;
void dfs(int step, double sum) {
	//�ݹ��������
	//ÿ������Ҫ��ѡȡ����
	if (step == 4) {
		if (flag == true) {
			return; //ֻ��һ����  ����һ��ȥ�����������н�
		}

		if (sum == 24) {
			flag = true;
			
			for (int i = 0; i < res.size();i++) {
				cout << res[i];
			}
			cout << endl;
			//exit(0);
			return;
		}
	}
	else if (step == 0) {
		step++;
		//�����ĸ�����
		for (int j = 0; j < 4; j++) {
			if (used[j] == false) {
				used[j] = true;
				string tmp = "";
				for (auto it : m) {
					if (it.second == nums[j]) {
						tmp = it.first;
					}
				}
				res.push_back(tmp);
				dfs(step,nums[j]);
				res.pop_back();

				//����
				used[j] = false;
			}

		}
	}
	else {
		step++;
		//�����ĸ�����
		for (int j = 0; j < 4; j++) {
			if (used[j] == false) {
				used[j] = true;
				string tmp = "";
;				for (auto it : m) {
					if (it.second == nums[j]) {
						tmp = it.first;
					}
				}
				res.push_back("+");

				res.push_back(tmp);
				dfs(step, sum + nums[j]);
				res.pop_back();
				res.pop_back();


				res.push_back("-");
				res.push_back(tmp);
				dfs(step, sum - nums[j]);
				res.pop_back();
				res.pop_back();

				res.push_back("*");
				res.push_back(tmp);
				dfs(step, sum * nums[j]);
				res.pop_back();
				res.pop_back();

				res.push_back("/");
				res.push_back(tmp);
				dfs(step, sum / nums[j]);
				res.pop_back();
				res.pop_back();
				//����
				used[j] = false;
			}

		}

	}

	//���ص�return  ÿ�����������˵��ǵò���24
}

int main() {
	
	m["2"] = 2;
	m["3"] = 3;
	m["4"] = 4;
	m["5"] = 5;
	m["6"] = 6;
	m["7"] = 7;
	m["8"] = 8;
	m["9"] = 9;
	m["10"] = 10;
	m["J"] = 11;
	m["Q"] = 12;
	m["K"] = 13;
	m["A"] = 1;

	

	string sub;
	for (int i = 0; i < 4; i++) {
		cin >> sub;
		if (sub == "joker" || sub == "JOKER") {
		
			cout << "ERROR" << endl;
			return 0;
		}
		nums[i] = m[sub];
	}
	dfs(0, 0);
	if (flag == false) cout << "ERROR" << endl;
	return 0;
}