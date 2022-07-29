#include<iostream>
#include<vector>
#include"assert.h"
#include<sstream>
using namespace std;

double nums[4];
bool flag = false;
bool used[4] = { 0 };
void dfs(int step,double sum) {
	//�ݹ��������
	//ÿ������Ҫ��ѡȡ����
	if (step == 4) {
		if (sum == 24) {
			flag = true;
			return;
		}
	}
	else {
		step++;
		//�����ĸ�����
		for (int j = 0; j < 4; j++) {
			if (used[j] == false) {
				used[j] = true;
				dfs(step, sum + nums[j]);
				dfs(step, sum - nums[j]);
				dfs(step, sum * nums[j]);
				dfs(step, sum / nums[j]);
				//����
				used[j] = false;
			}

		}
		
	}

	//���ص�return  ÿ�����������˵��ǵò���24
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> nums[i];
	}
	dfs(0,0);
	if (flag == true) cout << "true" << endl;
	else cout << "false" << endl;


	return 0;
}