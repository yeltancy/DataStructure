#include<iostream>
#include<list>
#include<fstream>
using namespace std;

class Arr
{
public:
	int* arr;
	Arr(int m)
	{
		arr = new int[m];
	}
};
int main()
{
	int m;
	fstream file("in.txt");
	file >> m;
	int i1 = m;

	file >> m;
	int j1 = m;
	int len1 = m;
	list<Arr>l1;
	for (int i = 0; i < i1; i++)
	{
		Arr a(j1);
		for (int j = 0; j < j1; j++)
		{
			file >> m;
			a.arr[j] = m;
		}
		l1.push_back(a);
	}
	file >> m;
	i1 = m;
	file >> m;
	j1 = m;
	int len2 = m;
	list<Arr>l2;
	for (int i = 0; i < i1; i++)
	{
		Arr a(j1);
		for (int j = 0; j < j1; j++)
		{
			file >> m;
			a.arr[j] = m;
		}
		l2.push_back(a);
	}
	file >> m;
	i1 = m;
	file >> m;
	j1 = m;
	freopen("abc.out", "w", stdout);
	for (list<Arr> ::iterator it1 = l1.begin(); it1 != l1.end(); it1++)
	{
		for (auto it2 = l2.begin(); it2 != l2.end(); it2++)
		{
			if (it1->arr[i1 - 1] == it2->arr[j1 - 1])
			{
				for (int i = 0; i < len1; i++)
				{
					cout << it1->arr[i] << " ";
					//printf("%d", it1->arr[i]," ");
				}
				for (int i = 0; i < len2; i++)
				{
					cout << it2->arr[i] << " ";
					//printf("%d", it2->arr[i]," ");
				}
				//printf("%d", "\n");
				cout << endl;
			}
		}
	}

}
