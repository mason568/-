#include<iostream>
#include<string>
#include<map>
#include<deque>
#include<vector>
#include<sstream>
using namespace std;

string getFile(string path) {
	istringstream iss(path);
	string sub;
	while (getline(iss, sub, '\\')) continue;
	int size = sub.size();
	if (size > 16) {
		sub = sub.substr(size - 16, size);
	}
	return sub;
}


void recordFalt(vector<pair<pair<string, int>, int> >& record_data,string file_name,int line_num) {
	vector<pair<pair<string, int>, int> >::iterator it;
	for (it = record_data.begin(); it < record_data.end(); it++) {
		if (it->first.first == file_name && it->first.second == line_num) {
			it->second += 1;
			return ;
		}
	}
	record_data.push_back(make_pair(make_pair(file_name,line_num),1));
	return;
}
#if 0
int main() {
	string path_name;
	int line_num;
	//unordered_map<string, pair<int, int>> map;
	vector<pair<pair<string, int>, int> > record_data;//������¼���ִ���Ľض����ݣ��кţ����ֵĴ���
	//vector<pair<string, int>> res;//��¼����ض��ļ���+�к�
	while (cin >> path_name >> line_num) {
		string file_name = getFile(path_name);
		recordFalt(record_data, file_name, line_num);
	}
	vector<pair<pair<string, int>, int> >::iterator it1;
	if (record_data.size() < 8) {
		
		for (it1 = record_data.begin(); it1 != record_data.end(); it1++) {

			cout << it1->first.first << " " << it1->first.second << " " << it1->second << endl;
		}
	}
	else {

		for (it1 = record_data.begin()+(record_data.size()-8); it1 != record_data.end(); it1++) {

			cout << it1->first.first << " " << it1->first.second << " " << it1->second << endl;
		}
	}
	return 0;
}

#endif

#if 1
//��˫�˶���deque+map����
int main() {
	//�������������ַ���,��file_name+line_num
	string name_line;
	//ʹ��hashӳ�����洢���ֵĴ���
	map<string, int> m;
	//ʹ�ö���ά�����µ�8������
	deque<string> res;
	while (getline(cin, name_line)) {
		//��ȡ�ض��ļ���+�к�
		name_line = name_line.substr(name_line.find_last_of('\\') + 1);
		int pos = name_line.find_last_of(" ");
		if (pos > 16) {
			name_line = name_line.substr(pos - 16);
		}

		//��¼������ֵĴ���
		if (m.find(name_line) == m.end()) {
			res.push_back(name_line);
		}
		++m[name_line];

		//ά��8���ڰ�����
		if (res.size() > 8) {
			res.pop_front();
		}
	}

	for (auto it : res) {
		cout << it << " " << m[it] << endl;
	}


	return 0;
}

#endif