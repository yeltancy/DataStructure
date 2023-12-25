//第五题
#include <vector>
#include <string>
#include<iostream>
#include <unordered_set>
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

//DFS
bool DFS(int v, int end, vector<bool>& visited, const vector<HNode>& vertices, vector<int>& path, const unordered_set<int>& mustPass, const unordered_set<int>& mustAvoid) {
    visited[v] = true;
    path.push_back(v);

    if (v == end) {
        unordered_set<int> passed(path.begin(), path.end());
        for (int node : mustPass) {
            if (passed.count(node) == 0) {
                path.pop_back();
                visited[v] = false;
                return false;
            }
        }
        return true;
    }

    for (ArcNode* arc = vertices[v].firstarc; arc != nullptr; arc = arc->nextarc) {
        if (!visited[arc->adjvex] && mustAvoid.count(arc->adjvex) == 0) {
            if (DFS(arc->adjvex, end, visited, vertices, path, mustPass, mustAvoid)) {
                return true;
            }
        }
    }

    path.pop_back();
    visited[v] = false;
    return false;
}

// 找出满足条件的路径
vector<int> findPath(int start, int end, const vector<HNode>& vertices, const unordered_set<int>& mustPass, const unordered_set<int>& mustAvoid) {
    vector<bool> visited(vertices.size(), false);
    vector<int> path;
    DFS(start, end, visited, vertices, path, mustPass, mustAvoid);
    return path;
}
