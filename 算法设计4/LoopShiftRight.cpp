//µÚÒ»Ìâ
#include <iostream>
using namespace std;

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotateArray(int arr[], int n, int m) {
    m = m % n;
    if (m == 0) return;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, m - 1);
    reverse(arr, m, n - 1);
}
int main() {
    int n = 5;
    int m = 2;
    int arr[] = { 1, 2, 3, 4, 5 };
    rotateArray(arr, n, m);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}