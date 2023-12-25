//第七题
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

// 边结点类型
struct ArcNode {
    int adjvex;
    int weight;
    ArcNode* nextarc;
};

// 头结点类型
struct HNode {
    string info;
    ArcNode* firstarc;
};

// 有向图
struct Graph {
    vector<HNode> nodes;
};

bool hasCycle(Graph& G) {
    vector<int> inDegree(G.nodes.size(), 0);
    for (int i = 0; i < G.nodes.size(); ++i) {
        for (ArcNode* arc = G.nodes[i].firstarc; arc; arc = arc->nextarc) {
            ++inDegree[arc->adjvex];
        }
    }

    queue<int> q;
    for (int i = 0; i < G.nodes.size(); ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ++count;

        for (ArcNode* arc = G.nodes[v].firstarc; arc; arc = arc->nextarc) {
            if (--inDegree[arc->adjvex] == 0) {
                q.push(arc->adjvex);
            }
        }
    }

    return count != G.nodes.size();
}
