#include<iostream>
#include<bitset>
using namespace std;

int hammingWeight(int num) {
//���� n & (n-1)  �Ѹ��ӶȽ�Ϊ O(M) O(1)  P.S. n & (n-1) �����������ж�n�ǲ���2���ݣ�M�Ǻ����� һ�����˵����O(log n)�㷨������ΪO(N)
	int res = 0;
	while (num > 0) {
		res += 1;
		num = num & (num - 1);
	}
	return res;
}


int main() {
	int num;
	while (cin >> num) {
		//cout << ((bitset<32>)num).count() << endl; //#include<bitset>
		//cout << hammingWeight(num)<<endl; //ʹ���Զ��庯�����㺺����
		
		//trivial�㷨
		int count = 0;
		while (num > 0) {
			count += num % 2;
			num = num >> 1;
		}
		cout << count << endl;
	}
	return 0;
}