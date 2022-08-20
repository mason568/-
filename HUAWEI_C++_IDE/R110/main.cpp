#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<set>
using namespace std;


//�����ֽⶨ�� һ������1�����������ֽ���ʽ��Ψһ�ġ�
int main() {
	int N;
	int opt,cnt;
	string name;
	map<string, set<string>> name_stocks;
	map<string, set<string>> stock_links;
	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			cin >> opt;
			if (opt == 1) {
				cin >>name>> cnt;
				string stock;
				for (int j = 0; j < cnt; j++) {
					//�����Ʊ
					cin >> stock;
					name_stocks[name].insert(stock);
				}
				//link��ϵ

				for (auto stock : name_stocks[name]) {
					set<string> tmp = name_stocks[name];
					tmp.erase(stock);
					for(auto s: tmp)
					stock_links[stock].insert(s);
				}
			}
			else if (opt == 2) {
				//��ѯ
				cin >> name;
				if (name_stocks.find(name) == name_stocks.end()) {
					cout << "error" << endl;
				}
				else {
					set<string> tmp;
					for (auto stock : name_stocks[name]) {
						for (auto link : stock_links[stock]) {
							tmp.insert(link);
						}
					}
					cout << tmp.size() - name_stocks[name].size() << endl;
				}
			}
		}
	}
	
}


/*
5 
1 Alice 2 
Zoom KKK
2 Bob 
2 Alice 
1 Bob 2
Zoom Microsoft
2 Bob


*/