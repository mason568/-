#include<iostream>
using namespace std;
int main() {
	double high;
	
	while (cin >> high) {
		double dist = 0.0;
		//�����ε���ߵ�ʱ
		for (int i = 0; i < 5; i++) {
			dist += high * 1.5;
			high *= 0.5;
		}
		//��������ʱҪ��·�̼�СĿǰ�߶�Ϊ��ô��

		cout << dist-high << endl << high << endl;
	}
	
	return 0;
}