#include<iostream>
#include<string>
#include<vector>
using namespace std;


//�ַ����е�ĳһ���ִ�ȫ�滻Ϊ��һ����
string& replace_all(string& src, const string& old_value, const string& new_value) {
	// ÿ�����¶�λ��ʼλ�ã���ֹ�����滻����ַ����γ��µ�old_value
	for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
		if ((pos = src.find(old_value, pos)) != string::npos) {
			src.replace(pos, old_value.length(), new_value);
		}
		else break;
	}
	return src;

}

#if 0
//string substr ( size_t pos = 0, size_t n = npos ) const; ��ȡ���ַ���
int main() {
	string s;

	while (getline(cin, s)) {
		int pos = 0;
		vector<string> res;
		//��������
		while (pos + 8 < s.size()) {
			string sub = s.substr(pos,8);
			res.push_back(sub);
			pos += 8;
		}

		//����ʣ�²��������ַ���
		//int l = s.size() - pos;
		string sub = s.substr(pos, s.size());
		string sub_end(8-sub.size(), '0');
		sub += sub_end;
//		sub = editstr(sub);
		res.push_back(sub);

		for (auto strs : res) {
			cout << strs << endl;
		}
	}
	
	
	
	
	return 0;
}

#endif

#if 0
//����һ��cout֮���մ
//ʹ�����������׼���Դ��Ĺ��ܡ�ʹ��cout����ĳ�Ա����width()ָ��������ʹ�ó�Ա����fill()ָ������ַ���ʹ�������ݷ�leftָ������롣
//ע�⣬��ʹstrʣ����ַ������Ȳ���8��str.substr(0, 8)Ҳ��������ȡʣ����ַ������ᱨ��
int main()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		for (int i = 0; i < len; i += 8)
		{
		
			cout.width(8);
			cout.fill('0');
			cout << left << str.substr(i, 8) << endl;

			
		}
	}
	return 0;
}
#endif

#if 1
int main()
{
	string str;
	string str1;
	int num;
	char ch;
	ch=cin.get();
	cout << ch << endl;

	

	return 0;
}
#endif