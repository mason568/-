#include<iostream>
using namespace std;


int exgcd(int a, int b, int& x, int& y)//��չŷ������㷨
{
    if (b == 0)
    {
        x = 1; y = 0;
        return a;  //����ݹ�߽翪ʼ����һ�㷵��
    }
    int r = exgcd(b, a % b, x, y);
    int temp = y;    //��x y�����һ���
    y = x - (a / b) * y;
    x = temp;
    return r;     //�õ�a b���������
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int s=0, t=0,g=0;
        g = exgcd(a, b, s, t);
        cout << g << " " << s << " " << t << endl;
    }
}
