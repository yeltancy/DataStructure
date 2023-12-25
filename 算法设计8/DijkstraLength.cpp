//µÚ°ËÌâ
#include<iostream>
#include <vector>
using namespace std;

const int MAXV = 100;
const int INF = 0x3f3f3f3f;
class MatGraph {
public:
    //ÁÚ½Ó¾ØÕó
    int edges[MAXV][MAXV];
    int n, e;
    string vexs[MAXV];
};

int dijkstra(MatGraph& G, int s, int t) {
    vector<int> dist(G.n, INF);
    vector<bool> visited(G.n, false);

    dist[s] = 0;
    for (int i = 0; i < G.n; ++i) {
        int u = -1, MIN = INF;
        for (int j = 0; j < G.n; ++j) {
            if (!visited[j] && dist[j] < MIN) {
                u = j;
                MIN = dist[j];
            }
        }

        if (u == -1) return -1;
        visited[u] = true;
        for (int v = 0; v < G.n; ++v) {
            if (!visited[v] && G.edges[u][v] != INF && dist[u] + G.edges[u][v] < dist[v]) {
                dist[v] = dist[u] + G.edges[u][v];
            }
        }
    }

    return dist[t];
}
