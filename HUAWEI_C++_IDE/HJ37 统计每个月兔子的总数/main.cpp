#include<iostream>
using namespace std;

#if 1
int main() {
	int n;
	while (cin >> n) {
		int A = 1, B = 0, C = 0;//��ʼ��һ���µ�����Ϊ1 B=C=0�ֱ��������¡������¼����ϵ�����
		//�ӵڶ����¿�ʼ��
		for (int i = 1; i < n; i++) {
			//int tmp = C;
			C = C + B;
			B = A;
			A = C;
			//����ÿ���� ��5�Ļ���ѭ����ѭ��4��
		}

		cout << (A + B + C) << endl;
	}
	return 0;
}
#endif
