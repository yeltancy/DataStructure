//��һ��
#include <vector>
#include <iostream>
#include <string>
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

// �������
int calculateOutDegree(const HNode& vertex) {
    int outdegree = 0;
    ArcNode* arc = vertex.firstarc;
    while (arc != nullptr) {
        ++outdegree;
        arc = arc->nextarc;
    }
    return outdegree;
}

// ��ӡ����
void printOutdegree(const vector<HNode>& vertices) {
    for (const auto& vertex : vertices) {
        cout << "���� " << vertex.info << " �ĳ���Ϊ " << calculateOutDegree(vertex) << endl;
    }
}

int main() {
    // ����һ��ͼ
    vector<HNode> vertices = {
        {"V0", new ArcNode{1, 0, new ArcNode{2, 0, nullptr}}}, 
        {"V1", new ArcNode{2, 0, nullptr}}, 
        {"V2", nullptr}, 
        {"V3", new ArcNode{0, 0, new ArcNode{1, 0, nullptr}}} 
    };

    // ��ӡ����
    printOutdegree(vertices);

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
