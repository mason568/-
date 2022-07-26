#include<forward_list>
#include<iostream>

using namespace std;
#if 0
//ʹ��c++��׼�ⵥ������forward_list ��push_front,insert_after,begin(),end()remove()�Ƚӿ�
int main() {
	int N,head_val;

	cin>>N >> head_val;
	forward_list<int> flist;
	flist.push_front(head_val);
	//����ڵ㣬ע��ͷ�ڵ��Ѿ����룬֮��ֻ��Ҫ����N-1��ֵ�ͺ�
	for (int i = 1; i < N; i++) {
		int back, front;
		cin >> back >> front;
		auto it = find(flist.begin(), flist.end(),front); //#include<algorithm>
		flist.insert_after(it, back);
	}
	int delete_val;
	cin >> delete_val;
	flist.remove(delete_val);
	for (auto it = flist.begin(); it != flist.end(); it++) {
		cout << *it << " ";    //��ͷ��β��������ֵ
	}
	cout << endl;
	
	return 0;
}
#endif

//c++��ͳ����д��
struct node {
	int val;
	struct node* next = nullptr;
};

int main(){
	int n, val;
	while (cin >> n >> val) {
		//����ͷ�ڵ�
		node* Head = new node;
		Head->val = val;
		//����ڵ�
		for (int i = 1; i < n; i++) {
			int back, front;
			cin >> back >> front;
			//�ҵ�front,����back�ڵ�
			node* back_node = new node;
			back_node->val = back;
			node* p = Head;
			while (p->val != front)
				p = p->next;
			back_node->next = p->next;
			p->next = back_node;	
		}
		//ɾ��
		int remove_val;
		cin >> remove_val;
		node* tmp_head = new node;
		tmp_head->next = Head;
		node* cur = tmp_head;
		while (cur->next != nullptr) {
			if (cur->next->val == remove_val) {
				cur->next = cur->next->next;
				break;
			}
			cur = cur->next;
		}
		
		//���
		while (tmp_head->next != nullptr) {
			cout << tmp_head->next->val << " ";
			tmp_head = tmp_head->next;
		}
		cout << endl;
		delete Head,tmp_head;
	}

	return 0;
}