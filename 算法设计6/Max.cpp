//第三题
#include<iostream>
#include<vector>
using namespace std;

int maxOfArray(const vector<int>& arr, int start, int end) {
        if (start == end) {
            return arr[start];
        }
        else {
            int mid = (start + end) / 2;
            int max1 = maxOfArray(arr, start, mid);
            int max2 = maxOfArray(arr, mid + 1, end);
            return max(max1, max2);
        }
}
int main() {
    vector<int> arr = { 3, 7, 2, 8, 5 };
    int result = maxOfArray(arr, 0, arr.size() - 1);
    cout << "数组中的最大元素值为: " << result << endl;
    return 0;
}