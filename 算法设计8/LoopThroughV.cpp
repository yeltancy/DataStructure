//第六题
#include <vector>
#include <string>
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

// 无向图
struct Graph {
    vector<HNode> nodes;
};

void findCycles(Graph& G, int start, int v, vector<int>& visited, vector<int>& path) {
    visited[start] = 1;
    path.push_back(start);

    for (ArcNode* w = G.nodes[start].firstarc; w; w = w->nextarc) {
        if (!visited[w->adjvex]) {
            findCycles(G, w->adjvex, v, visited, path);
        }
        else if (w->adjvex == path[0] && path[0] == start) {
            bool label = false;
            for (int i = 0; i < path.size(); i++)
            {
                if (path[i] = v) {
                    label = true;
                }
            }
            if (label) {
                for (int i = 0; i < path.size(); ++i) {
                    cout << path[i] << ' ';
                }
                cout << endl;
            }
        }
    }

    visited[start] = 0;
    path.pop_back();
}

void findAllCycles(Graph& G, int v) {
    vector<int> visited(G.nodes.size(), 0);
    vector<int> path;
    for (int i = 0; i < G.nodes.size(); ++i) {
        findCycles(G, i, v, visited, path);
    }
}
