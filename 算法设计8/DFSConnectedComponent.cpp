//第三题
#include<iostream>
#include<vector>
using namespace std;

//边结点类型
struct ArcNode {
    int adjvex;
    int weight;
    ArcNode* nextarc;
};
//头结点类型
struct HNode {
    string info;
    ArcNode* firstarc;
};

//DFS
void DFS(int v, vector<bool>& visited, const vector<HNode>& vertices) {
    visited[v] = true;
    for (ArcNode* arc = vertices[v].firstarc; arc != NULL; arc=arc->nextarc)
    {
        if (!visited[arc->adjvex]) {
            DFS(arc->adjvex, visited, vertices);
        }
    }
}

//计算连通分量数
int calculateConnectedComponents(vector<HNode>& vertices) {
    int count = 0;
    vector<bool> visited(vertices.size(), false);
    for (int v = 0; v < vertices.size(); ++v) {
        if (!visited[v]) {
            DFS(v, visited, vertices);
            ++count;
        }
    }
    return count;
}