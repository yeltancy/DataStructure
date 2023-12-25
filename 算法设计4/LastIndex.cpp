//µÚ¶şÌâ
#include<iostream>
using namespace std;
int lastIndexElement(int arr[],int n) {
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= arr[index] ) {
			index = i;
		}
	}
	return index;
}
int main() {
	int arr[] = { 7,5,8,4,8,7 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int index = lastIndexElement(arr,length);
	cout << index << endl;
    return 0;
}