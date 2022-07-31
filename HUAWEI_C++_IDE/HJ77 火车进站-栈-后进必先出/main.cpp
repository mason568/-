#include<iostream>
#include<stack>
#include<deque>
#include"assert.h"
#include<vector>
#include<algorithm>
using namespace std;


#if 0
//ѧϰ���˵Ļ���


int n;
vector<int> trains;//���
stack<int> st;//��վ
vector<vector<int>> paths;

void dfs(int cnt, vector<int>& ans) {
    if (cnt == n && st.empty()) {
        paths.push_back(ans);
        return;
    }
    //��վ
    if (cnt < n) {
        st.push(trains[cnt]);
        dfs(cnt + 1, ans);
        //����վ������
        st.pop();
    }
    //��վ
    if (!st.empty()) {
        //�ȳ�վһ��
        int tmp = st.top();
        ans.push_back(tmp);
        st.pop();
        dfs(cnt, ans);
        //����վ������
        st.push(tmp);
        ans.pop_back();
    }
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
        trains.push_back(x);
	}

	vector<int> ans;
	dfs(0, ans);

	sort(paths.begin(), paths.end());

	for (int i = 0; i < paths.size(); i++) {
		for (int j = 0; j < paths[i].size(); j++) {
			cout << paths[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}



#endif

#if  1

vector<vector<int>> paths;
void dfs(deque<int> trains, stack<int> st, vector<int>& ans) {
    if (trains.empty() && st.empty()) {
        paths.push_back(ans);
        return;
    }
    //��վ
    if (!trains.empty()) {
        int tmp = trains.front();
        st.push(tmp);
        trains.pop_front();
        dfs(trains, st, ans);
        //����վ������
        trains.push_front(tmp);
        st.pop();
    }
    //��վ
    if (!st.empty()) {
        //�ȳ�վһ��
        int tmp = st.top();
        ans.push_back(tmp);
        st.pop();
        dfs(trains, st, ans);
        //����վ������
        st.push(tmp);
        ans.pop_back();
    }
}

int main() {
    int n;
    while (cin >> n) {
        deque<int> trains;//���
        stack<int> st;//��վ
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            trains.push_back(x);
        }
         vector<int> ans;
         dfs(trains, st, ans);
         sort(paths.begin(), paths.end());

         for (int i = 0; i < paths.size(); i++) {
             for (int j = 0; j < paths[i].size(); j++) {
                 cout << paths[i][j] << " ";
             }
             cout << endl;
         }

    }
    return 0;
}
#endif