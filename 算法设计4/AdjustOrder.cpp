//µÚÈıÌâ
#include<iostream>
#include <vector>
using namespace std;

void adjustOrder(vector<double> &doubleArray, vector<int> &intArray){
	int length = intArray.size();
	vector<double> copy(length);
	for (int i = 0; i < length; i++) {
		copy[i] = doubleArray[intArray[i]];
	}
	for (int i = 0; i < length; i++)
	{
		doubleArray[i] = copy[i];
	}
}int main() {
	vector<double> a = { 1,2,3,4,5 };
	vector<int> b = { 2,3,4,1,0 };
	int length = a.size();
	adjustOrder(a, b);
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << "  ";
	}
}

