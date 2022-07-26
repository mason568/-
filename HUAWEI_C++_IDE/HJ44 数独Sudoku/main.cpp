#include<iostream>

using namespace std;

int nums[9][9];
bool flag = false;

bool check(int n) {
    int h = n / 9;//��ǰ�к�
    int l = n % 9;//��ǰ�к�

    //ͬһ���в������ظ�����
    for (int i = 0; i < 9; ++i) {//ͬһ���в������ظ�
        if (i != l && nums[h][i] == nums[h][l]) {
            return false;
        }
    }

    //ͬһ���в������ظ�
    for (int i = 0; i < 9; ++i) {//ͬһ���в������ظ�
        if (i != h && nums[i][l] == nums[h][l]) {
            return false;
        }
    }

    //���ھŹ��������ظ�
    for (int i = h / 3 * 3; i < h / 3 * 3 + 3; i++) {
        for (int j = l / 3 * 3; j < l / 3 * 3 + 3; j++) {
            if ((i != h || j != l) && nums[i][j] == nums[h][l]) {
                return false;
            }
        }
    }
    return true;
}

//9*9=81�� �ݹ��0-81 ����Ϊ λ��
void dfs(int n) {
    //�ݹ��������
    if (n == 81) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << nums[i][j] << ' ';
            }
            cout << nums[i][8] << endl;
        }
        flag = true;
        return;
    }

    int h = n / 9;//��ǰ�к�
    int l = n % 9;//��ǰ�к�
    if (nums[h][l] == 0) { //��Ҫ���һ����ȷ���������λ��
        //ö��1-9
        for (int i = 1; i <= 9; i++) {
            nums[h][l] = i;
            //��������
            if (check(n)) {//��ǰλ���Ƿ���������
                dfs(n + 1);//�������ͼ����ݹ���һ��λ��

                //����ɹ��ڻ���֮ǰreturn
                if (flag) return; //��֦
            }
        }
        //����������㣬�ǿ϶���ǰ���趨��ֵ�����ˣ���Ҫ���� �ָ�����ֵΪ0
        nums[h][l] = 0;
    
    }
    else {
        dfs(n + 1);
    }



}


int main() {
	
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> nums[i][j];//����9x9����
        }
    }
    dfs(0);//�����Ͻǿ�ʼ�ݹ�

    return 0;


}