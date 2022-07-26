#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include<unordered_set>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		//����
		vector<int> weight;
		vector<int> nums;
		int tmp;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			weight.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			nums.push_back(tmp);
		}
		//cout << weight.size() << " " << nums.size() << endl;
		//����
		unordered_set<int> table;//���set����һ��ֵs����ô��ʾ�����е�������ѡ�����к�Ϊs�����ֻҪ���s�Ĵ�С
		table.insert(0);
		//����ÿһ������
		for (int i = 0; i < n; i++) {
			int num = nums[i];
			int w = weight[i];
			while (num--) {
				//���¼�������룬����table�е�ÿһ��Ԫ�أ�����Ͳ���table�У��ͰѺͼ���table
				unordered_set<int> tmp = table;
				for (auto s : tmp) {
					table.insert(s + w);
				}
			}
		}

		cout << table.size() << endl;
		
	}
	return 0;
}