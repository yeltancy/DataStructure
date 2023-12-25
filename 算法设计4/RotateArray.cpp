//第四题
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
bool rotateArray(vector<vector<T>> &arr) {
	int rowLength = arr.size();
	int colLength = arr[0].size();
	if (rowLength != colLength) {
		return false;
	}
	for (int i = 0; i < rowLength; i++) {
		for (int j = i + 1; j < colLength; j++) {
			T temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	return true;
}
int main() {
	vector<vector<int>> arr = { {1,2,3},{4,5,6},{7,8,9} }; 
	int rowLength = arr.size();
	int colLength = arr[0].size();
	cout << "初始矩阵" << endl;
	for (int i = 0; i < rowLength; i++)
	{
		for (int j = 0; j < colLength; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
	bool flag = rotateArray(arr);
	if (flag) {
		cout << "翻转成功" << endl;
		for (int i = 0; i < rowLength; i++)
		{
			for (int j = 0; j < colLength; j++) {
				cout << arr[i][j] << "  ";
			}
			cout << endl;
		}
	}
	else {
		cout << "翻转出错" << endl;
	}
	return 0;
}
//#include <iostream>
//#include <vector>
//
//bool transposeInPlace(std::vector<std::vector<int>>& a) {
//    int m = a.size();
//    int n = a[0].size();
//
//    if (m != n) {
//        return false;
//    }
//
//    for (int i = 0; i < m; i++) {
//        for (int j = i + 1; j < n; j++) {
//            // 交换a[i][j]和a[j][i]
//            int temp = a[i][j];
//            a[i][j] = a[j][i];
//            a[j][i] = temp;
//        }
//    }
//
//    return true;
//}
//
//int main() {
//    int m = 3;
//    int n = 3;
//    std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//
//    std::cout << "Original Array:" << std::endl;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            std::cout << a[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    bool success = transposeInPlace(a);
//
//    if (success) {
//        std::cout << "Transposed Array:" << std::endl;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                std::cout << a[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//    } else {
//        std::cout << "Transpose not possible because m is not equal to n." << std::endl;
//    }
//
//    return 0;
//}
