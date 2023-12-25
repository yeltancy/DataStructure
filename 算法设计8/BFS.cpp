//第二题
#include<iostream>
#include<queue>
using namespace std;

//时间复杂度为O(n2)
const int MAXV = 100;
const int INF = 0x3f3f3f3f;
class MatGraph {
public:
	//邻接矩阵
	int edges[MAXV][MAXV];
	int n, e;
	string vexs[MAXV];

	//BFS
	void BFS(int start) {
		queue<int> q;
		bool visited[MAXV] = { false };

		visited[start] = true;
		cout << vexs[start] << " ";
		q.push(start);

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int i = 0; i < n; i++)
			{
				if (edges[v][i] != INF && !visited[i]) {
					visited[i] = true;
					cout << vexs[i] << " ";
					q.push(i);
				}
			}
		}
	}
};