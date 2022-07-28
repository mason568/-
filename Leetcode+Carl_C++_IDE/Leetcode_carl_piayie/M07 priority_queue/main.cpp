#include <iostream>
#include <algorithm>
#include<time.h>
#include<vector>
#include<queue>
#include"assert.h"
using namespace std;

//��д�����>
//����1
class tmp1 //���������<
{
public:
	int x;
	tmp1(int a) { x = a; }
	bool operator<(const tmp1& a) const //Ĭ�������thisָ��
	{
		return x < a.x; //�󶥶�
	}
};

struct cmp2 {
	bool operator() (tmp1 lhs, tmp1 rhs) {
		return lhs.x > rhs.x;
	}

};


//��д�ȽϺ��� 
struct cmp {
	bool operator() (int lhs, int rhs) {
		return lhs > rhs;
	}

};



//С����
int main() {
	int n, k, t;
	while (cin >> n >> k) {
		vector<int> nums;
		priority_queue<int, vector<int>, cmp> min_queue;
		priority_queue<tmp1, vector<tmp1>, cmp2> tmp1_min_deque;
		for (int i = 0; i < n; i++) {
			cin >> t;
			nums.push_back(t);
			min_queue.push(t);
			tmp1_min_deque.push(t);
		}
		cout << "nums�е�ǰk��ֵ: ";
		int t = k;
		for (int i = 0; i < k; i++) {
			if (i < n) cout << nums[i] << " ";
		}
		cout << endl;
		cout << "min_queue�е�ǰk��ֵ: ";
		while (t-- && t <= min_queue.size()) {
			cout << min_queue.top() << " ";
			min_queue.pop();
		}
		cout << endl;
		cout << "tmp1_min_deque�е�ǰk��ֵ: ";
		t = k;
		while (t-- && t <= tmp1_min_deque.size()) {
			cout << tmp1_min_deque.top().x << " ";
			tmp1_min_deque.pop();
		}
		cout << endl;
	}
	//���ڻ������� Ĭ���Ǵ󶥶� STL����Ĭ���õ���vector 
	priority_queue<int> a;
	priority_queue<int,vector<int>,greater<int> > b; //С��������д

	//������У�С����
	priority_queue <int, vector<int>, greater<int> > q; //ע��> >�����м�Ŀո�û�еĻ����������ܻ���Ϊ�����������
	//������У��󶥶� Ĭ��
	priority_queue <int, vector<int>, less<int> > p;
	//���У�greater��less��stdʵ�ֵ������º���������ʹһ�����ʹ�ÿ���ȥ��һ����������ʵ�־�������ʵ��һ��operator()���������������ƺ�������Ϊ������һ���º�������

	//�Զ���ȽϺ�������������
	//��д�ȽϺ���
	priority_queue<int, vector<int>, cmp> min_queue;
	//����ıȽ�
	priority_queue<tmp1, vector<tmp1>, cmp2> tmp1_min_deque;
	return 0;

}

