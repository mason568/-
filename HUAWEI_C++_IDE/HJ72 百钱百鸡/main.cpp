#include<iostream>

using namespace std;

int main() {
	int ok;
	while (cin >> ok) {
		//��ѧʽ�жϺ󣬼�������aһ����4�ı�������С�ڵ���20
		//��ĸ����b = 25 - (7*a)/4 > 0 
		//С������c = 100 +a -b
		//����aֻ��ȡ 0 4 8 12 ��16�Ͳ���ȡ�ˣ���Ϊ 25 - 28 = -3< 0
		for (int k = 0; k <= 3; k++) {
			int a = 4 * k;
			int b = 25 - (7 * a) / 4;
			int c = 100 - a - b;
			cout << a << " " << b << " " << c << endl;
		}

	}
	return 0;
}

//��Ȼ���������ñ����ƽ⣬O(n^3)���Ӷ� 
//for a [0,20]
	//for b [0,33]
		//for c [0,100]
			//if(a+b+c==100 && (5*a + 3*b + c/3 ==100))