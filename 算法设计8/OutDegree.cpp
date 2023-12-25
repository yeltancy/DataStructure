//第一题
#include <vector>
#include <iostream>
#include <string>
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

// 计算出度
int calculateOutDegree(const HNode& vertex) {
    int outdegree = 0;
    ArcNode* arc = vertex.firstarc;
    while (arc != nullptr) {
        ++outdegree;
        arc = arc->nextarc;
    }
    return outdegree;
}

// 打印出度
void printOutdegree(const vector<HNode>& vertices) {
    for (const auto& vertex : vertices) {
        cout << "顶点 " << vertex.info << " 的出度为 " << calculateOutDegree(vertex) << endl;
    }
}

int main() {
    // 创建一个图
    vector<HNode> vertices = {
        {"V0", new ArcNode{1, 0, new ArcNode{2, 0, nullptr}}}, 
        {"V1", new ArcNode{2, 0, nullptr}}, 
        {"V2", nullptr}, 
        {"V3", new ArcNode{0, 0, new ArcNode{1, 0, nullptr}}} 
    };

    // 打印出度
    printOutdegree(vertices);

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
