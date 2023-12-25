#include<iostream>
#include<vector>
using namespace std;
void spiralMatrix(int n) {
    if (n <= 0 || n > 10) {
        cout << "�����n������Χ��" << endl;
        return ;
    }
    vector<vector<int>> arr(n, vector<int>(n, 0));
    int num = 1;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (num <= n * n) {
        // �������
        for (int i = colStart; i <= colEnd; ++i) {
            arr[rowStart][i] = num++;
        }
        ++rowStart;

        // �������
        for (int i = rowStart; i <= rowEnd; ++i) {
            arr[i][colEnd] = num++;
        }
        --colEnd;

        // �������
        for (int i = colEnd; i >= colStart; --i) {
            arr[rowEnd][i] = num++;
        }
        --rowEnd;

        // �������
        for (int i = rowEnd; i >= rowStart; --i) {
            arr[i][colStart] = num++;
        }
        ++colStart;
    }

    // ��ӡ���ɵ���������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    spiralMatrix(n);
}