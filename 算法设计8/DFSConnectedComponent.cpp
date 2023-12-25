//������
#include<iostream>
#include<vector>
using namespace std;

//�߽������
struct ArcNode {
    int adjvex;
    int weight;
    ArcNode* nextarc;
};
//ͷ�������
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

//������ͨ������
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