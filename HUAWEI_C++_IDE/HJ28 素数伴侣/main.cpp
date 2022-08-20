
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPrime(int m) {
	if (m <= 1) return false;
	for (int i = 2; i < sqrt(m); i++) {
		if (m % i == 0) return false;
	}
	return true;
}

//����N������check�� ŷ����������ɸ
void buildPrimeTable(int N, bool* isprime_t, int *prime_t,int &count) {
	int cnt=0;
	isprime_t[0] = isprime_t[1] = false;
	for (int i = 2; i < N; i++) {
		if (isprime_t[i]) prime_t[cnt++] = i;//����������ͼ��뵽�������У�����С��������i����ǰ����˺��������
		for (int j = 0; j< N; j++) {
			if (i * prime_t[j] >= N) break;
			isprime_t[i * prime_t[j]] = false;//ÿһ�����������䵱ǰ��i�������Ϊ������
			if (i % prime_t[j] == 0) break;//��ؼ�ֻ���һ�Σ������ظ���j��һ�����ǲ��������ı���
		}
		
	}
	count = cnt;
}

void buildisPrimeTable(int N, bool* isprime_t) {
	int cnt = 0;
	int* prime_t = new int[N];
	isprime_t[0] = isprime_t[1] = false;
	for (int i = 2; i < N; i++) {
		if (isprime_t[i]) prime_t[cnt++] = i;//����������ͼ��뵽�������У�����С��������i����ǰ����˺��������
		for (int j = 0; j < N; j++) {
			if (i * prime_t[j] >= N) break;
			isprime_t[i * prime_t[j]] = false;//ÿһ�����������䵱ǰ��i�������Ϊ������
			if (i % prime_t[j] == 0) break;//��ؼ�ֻ���һ�Σ������ظ���j��һ�����ǲ��������ı���
		}
	}
	delete []prime_t;
}

bool odd_find_enev_matchbest(int odd, vector<int> &evens, vector<bool> &even_used, vector<int> &even_match, bool *isprime_t) {
	//����ÿһ��ż��������ƥ��
	for (int i = 0; i < evens.size(); i++) {
		if (!even_used[i] && isprime_t[odd + evens[i]]) {
			even_used[i] = true;//���ż����ʹ��
			//�����i��ż����δ��ԣ����߸�����Ե������б��ѡ��
			if (even_match[i] == 0 || odd_find_enev_matchbest(even_match[i], evens, even_used, even_match, isprime_t)) {
				even_match[i] = odd;
				return true;
			}
		}
	}
	return false;
}




int main() {
	const int len = 60000;
	bool isprime_t[len];
	memset(isprime_t, true, sizeof(isprime_t));
	buildisPrimeTable(len, isprime_t);
	int N,tmp;
 	while (cin >> N) {
		vector<int> nums(N);
		vector<int> odds;//������
		vector<int> evens;//ż����
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			nums[i] = tmp;
			if (tmp % 2 == 0) evens.push_back(tmp);
			else odds.push_back(tmp);
		}
		//����һ������һ��������һ��ż���ĺ͹���
		int count = 0;
		if (odds.size() == 0 || evens.size() == 0) {
			cout << count << endl;
			continue;
		}
		vector<int> even_match(evens.size(), 0);//��¼ÿһ��ż��[i]ƥ�������һ������even_match[i]
		for (int i = 0; i < odds.size(); i++) {//����ÿһ������
			vector<bool> even_used(evens.size(), false);//ż��û�б�ʹ������ֵΪ0
			//��ÿһ�����������ҵ����ŵ���֮��Ե�ż������ôƥ��+1
			if (odd_find_enev_matchbest(odds[i],evens,even_used,even_match,isprime_t)) {
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}