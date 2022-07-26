#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> paths;
void dfs(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<pair<int, int>>& res) {
	res.push_back(make_pair(i, j));//����·��
	matrix[i][j] = 1;//�߹��˾Ͳ���������
	//�ݹ���ֹ����
	if (i == n - 1 && j == m - 1) {
		paths = res;
		return;
	}
	//�ĸ����� ��[i-1][j]��[i+1][j]��[i][j-1]��[i][j+1]
	if (i - 1 >= 0 && matrix[i - 1][j] == 0)
		dfs(matrix, i - 1, j, n, m, res);
	if (i + 1 < n && matrix[i + 1][j] == 0)
		dfs(matrix, i + 1, j, n, m, res);
	if (j - 1 >= 0 && matrix[i][j-1] == 0)
		dfs(matrix, i, j-1, n, m, res);
	if (j+1 < m && matrix[i][j+1] == 0)
		dfs(matrix, i , j+1, n, m, res);
	//����
	res.pop_back();
	matrix[i][j] = 0;
}


int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> matrix(n, vector<int>(m,0));
		vector<pair<int, int>> res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> matrix[i][j];
			}
		}
		dfs(matrix, 0, 0, n, m, res);
		for (auto i : paths) {
			cout << "(" << i.first << "," << i.second << ")" << endl;
		}
	
	}
}