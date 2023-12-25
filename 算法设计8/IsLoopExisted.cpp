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

// �ж��Ƿ���ھ�������v�Ļ�·
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

    // �ж��Ƿ���ھ�������V0�Ļ�·
    bool cycle = hasCycle(0, vertices);
    cout << "��ͼ" << (cycle ? "����" : "������") << " ����v�Ļ�·" << endl;

    // ɾ���ڴ�
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
