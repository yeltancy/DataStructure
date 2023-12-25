//第四题
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
bool DFS(int v, int parent, vector<bool>& visited, const vector<HNode>& vertices) {
    visited[v] = true;
    for (ArcNode* arc = vertices[v].firstarc; arc != nullptr; arc = arc->nextarc) {
        if (!visited[arc->adjvex]) {
            if (DFS(arc->adjvex, v, visited, vertices)) {
                return true;
            }
        }
        else if (arc->adjvex != parent) {
            return true;
        }
    }
    return false;
}

// 判断是否存在经过顶点v的回路
bool hasCycle(int v, const vector<HNode>& vertices) {
    vector<bool> visited(vertices.size(), false);
    return DFS(v, -1, visited, vertices);
}

int main() {
    vector<HNode> vertices = {
        {"V0", new ArcNode{1, 0, new ArcNode{2, 0, nullptr}}},
        {"V1", new ArcNode{0, 0, new ArcNode{2, 0, nullptr}}},
        {"V2", new ArcNode{0, 0, new ArcNode{1, 0, nullptr}}},
        {"V3", nullptr}
    };

    // 判断是否存在经过顶点V0的回路
    bool cycle = hasCycle(0, vertices);
    cout << "该图" << (cycle ? "存在" : "不存在") << " 经过v的回路" << endl;

    // 删除内存
    for (auto& vertex : vertices) {
        ArcNode* arc = vertex.firstarc;
        while (arc != nullptr) {
            ArcNode* nextArc = arc->nextarc;
            delete arc;
            arc = nextArc;
        }
    }

    return 0;
}
