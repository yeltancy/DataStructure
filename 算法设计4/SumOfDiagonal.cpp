//第五题
#include<iostream>
#include<vector>
using namespace std;

bool sumOfDiagonal(vector<vector<int>>& arr) {
	int rowLength = arr.size();
	int colLength = arr[0].size();
	int left_right = 0, right_left = 0;
	if (rowLength != colLength) {
		return false;
	}
	for (int i = 0; i < rowLength; i++) {
		for (int j = 0; j < colLength; j++) {
			if (i == j) {
				left_right += arr[i][j];
			}
			if (i + j == rowLength - 1) {
				right_left += arr[i][j];
			}
		}
	}
	int sum = left_right + right_left;
	cout << "left_right:  " << left_right << endl;
	cout << "right_left:  " << right_left << endl;
	cout << "sum = left_right + right_left = " << sum << endl;
	return true;
}
int main() {
	vector<vector<int>> arr = { {1,2,3},{4,5,6},{7,8,9} };
	int rowLength = arr.size();
	int colLength = arr[0].size();
	cout << "初始矩阵:" << endl;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < colLength; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	bool flag = sumOfDiagonal(arr);
}