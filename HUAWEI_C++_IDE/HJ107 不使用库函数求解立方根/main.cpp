#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

double solution(double b) {
	double a = 0.0;
	if (b == 0 || b == 1 || b == -1) return b;
	//ȷ����ʼ��������
	double left = b > 0 ? min(b, 1.0) : min(b, -1.0);
	double right = b > 0 ? max(b, 1.0) : max(b, -1.0);
	//����һλС��,0.1;��ô���ǵľ��ȱ���߾ͺ� abs(b_t-b)<0.01�ͷ���

	while (abs(left - right) > 0.01) {
		a = (left + right) / 2;
		if (a * a * a > b) {
			right = a;
		}
		else if (a * a * a == b) {
			break;
		}
		else {
			left = a;
		}
	}
	return a;
}

int main() {
	double b;
	while (cin >> b) {
		cout << fixed << setprecision(1) << solution(b) << endl;
	}

}