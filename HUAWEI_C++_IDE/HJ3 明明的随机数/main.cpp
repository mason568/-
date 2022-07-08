#include<iostream>
#include<map>
#include<set>
using namespace std;

#if 0
//map ����hash��ȥ��
int main() {
	int N;
	cin >> N;
	map<int, int> order_map;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (order_map.find(num) == order_map.end()) {
			order_map[num] = 1;
		}
	}

	for (auto it : order_map) {
		cout << it.first << endl;
	}
	return 0;
}
#endif

// set���������Զ�ʵ��ȥ�غ�����
int main() {
	int N;
	cin >> N;
	set<int> order_set;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		order_set.insert(num);
	}
	
	for (auto it : order_set) {
		cout << it << endl;
	}
	return 0;
}