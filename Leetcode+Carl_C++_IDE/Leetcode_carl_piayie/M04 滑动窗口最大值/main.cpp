#include<iostream>
#include<deque>
#include<sstream>
#include<vector>
using namespace std;
vector<int> get_maxVal_in_wind(vector<int>& nums, int k) {
	vector<int> res;
	//ά��һ�������Ķ��� �����з��Ż�����ǰ���ļ���Ԫ�أ�����ȡ������һ�����봰�ڵ�ֵ
	deque<int> monoQueue;
	int n = nums.size();
	for (int i = -k+1; i < n - k+1; i++) { //O(n)���Ӷ�
		int j = i + k - 1;//����������ȡ����������
		//����Ԫ��nums[i-1]�� i>0 
		if (i > 0 && nums[i-1] == monoQueue.front()) monoQueue.pop_front();
		//ά������
		while (!monoQueue.empty()&& nums[j] >= monoQueue.back()) {
			monoQueue.pop_back();
		}
		//�봰Ԫ��nums[j]
		monoQueue.push_back(nums[j]);
		
		if (i >= 0) {
			res.push_back(monoQueue.front());
		}
	}
	return res;
}


int main() {
	//����
	string s;
	while (getline(cin,s)) {
		vector<int> nums;
		string num;
		stringstream ss(s);
		while (getline(ss, num, ' ')) {
			nums.push_back(stoi(num));
		}

		int k = nums[nums.size()-1];
		nums.pop_back();
		
		//����
		vector<int> res = get_maxVal_in_wind(nums, k);
		for (auto i : res) {
			cout << i << endl;
		}
		
	}
	return 0;
}