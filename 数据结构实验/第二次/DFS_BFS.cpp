#include<iostream>
#include<sstream>
#include<vector>
#include <algorithm>
#include <string>
#include<queue>
using namespace std;

//�߽������
struct ArcNode {
    int adjvex;
    ArcNode* nextarc;
};
//ͷ�������
struct HNode {
    int info;
    ArcNode* firstarc;
};

//������
vector<int> inputRead() {
    vector<int> nums;
    string str, numStr;
    while (getline(cin, str)) {
        istringstream ss(str);
        while (ss >> numStr) {
            int num = atoi(numStr.c_str());
            nums.push_back(num);
        }
    }
    //for (int i = 0; i < nums.size(); i++)
    //{
    //    cout << nums[i] << " ";
    //}
    //cout << endl;
    return nums;
    
}

//�����ڽӱ�
vector<HNode> createAdjGraph(const vector<int>& nums) {
    int p = 0;
    int n = nums[p];
    int e = nums[++p];
    // ����ͷ�������
    vector<HNode> adjGraph(n);
    for (int i = 0; i < n; i++) {
        adjGraph[i].info = i;
        adjGraph[i].firstarc = NULL;
    }
    //�����ڽӱ�
    for (int i = 0; i < e; i++) {
        int u = nums[++p];
        int v = nums[++p];
        ArcNode* node1 = new ArcNode();
        node1->adjvex = v;
        node1->nextarc = NULL;
        //ʹ�ڽӱ��нڵ㰴�����������
        //���ڽӱ�Ϊ�գ����ߵ�һ���ڵ�ı�Ŵ���v��ֱ����ͷ�巨
        //�����ҵ���һ����Ŵ���v�Ľڵ㣬������ͷ�巨
        
        if (adjGraph[u].firstarc == NULL || adjGraph[u].firstarc->adjvex > v) {
            node1->nextarc = adjGraph[u].firstarc;
            adjGraph[u].firstarc = node1;
        }
        else{
            ArcNode* current = adjGraph[u].firstarc;
            while (current->nextarc != NULL && current->nextarc->adjvex < v) {
                current = current->nextarc;
            }
            node1->nextarc = current->nextarc;
            current->nextarc = node1;
        }
        //����ͼ���µ�
        int temp = u;
        u = v;
        v = temp;
        ArcNode* node2 = new ArcNode();
        node2->adjvex = v;
        node2->nextarc = NULL;
        if (adjGraph[u].firstarc == NULL || adjGraph[u].firstarc->adjvex > v) {
            node2->nextarc = adjGraph[u].firstarc;
            adjGraph[u].firstarc = node2;
        }
        else{
            ArcNode* current = adjGraph[u].firstarc;
            while (current->nextarc != NULL && current->nextarc->adjvex < v) {
                current = current->nextarc;
            }
            node2->nextarc = current->nextarc;
            current->nextarc = node2;
        }
    }
    return adjGraph;
}

////��ӡ�ڽӱ�
//void printAdjGraph( vector<HNode>& adjGraph) {
//    for (HNode& node : adjGraph) {
//        cout << "���� " << node.info << ":";
//        for (ArcNode* arc = node.firstarc; arc != NULL; arc = arc->nextarc) {
//            cout << " -> " << arc->adjvex;
//        }
//        cout << endl;
//    }
//}

//DFS
void DFS(const vector<HNode>& adjGraph, vector<bool>& visited, int begin) {
    cout << begin << " ";
    visited[begin] = true;
    ArcNode* arc = adjGraph[begin].firstarc;
    while (arc != NULL) {
        int adjNode = arc->adjvex;
        if (!visited[adjNode]) {
            DFS(adjGraph, visited, adjNode);
        }
        arc = arc->nextarc;
    }
}

//ɾ��һ���ڵ�
void deleteNode(int v, vector<HNode>& adjGraph) {
    int n = adjGraph.size();
    // ɾ����ر�
    while (adjGraph[v].firstarc != NULL) {
        ArcNode* temp = adjGraph[v].firstarc;
        adjGraph[v].firstarc = temp->nextarc;
        delete temp;
    }
    // ��������������ڽӱ�
    for (int i = 0; i < n; ++i) {
        if (i != v) {
            ArcNode* prev = NULL;
            ArcNode* curr = adjGraph[i].firstarc;
            while (curr != NULL) {
                if (curr->adjvex == v) {
                    if (prev == NULL) {
                        adjGraph[i].firstarc = curr->nextarc;
                    }
                    else {
                        prev->nextarc = curr->nextarc;
                    }
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->nextarc;
            }
        }
    }
}

//BFS
void BFS(const vector<HNode>& adjGraph, vector<bool>& visited, int begin) {
    queue<int> q;
    cout << begin << " ";
    visited[begin] = true;
    q.push(begin);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ArcNode* arc = adjGraph[u].firstarc;
        while (arc != NULL) {
            if (!visited[arc->adjvex]) {
                cout << arc->adjvex << " ";
                visited[arc->adjvex] = true;
                q.push(arc->adjvex);
            }
            arc = arc->nextarc;
        }
    }
}
int main() {
    //vector<int> nums = { 5, 7, 0, 1, 0, 2, 1, 4, 2, 4, 2, 3, 3, 4, 4, 0 ,3};
    //vector<HNode> adjGraph = createAdjGraph(nums);
    //printAdjGraph(adjGraph);
    //vector<bool> visited1(adjGraph.size(), false);
    //vector<bool> visited2(adjGraph.size(), false);
    //DFS(adjGraph, visited1,0);
    //cout << endl;
    //int v = nums[nums.size() - 1];
    //cout << "---------------------" << endl;
    //deleteNode(v, adjGraph);
    //printAdjGraph(adjGraph);
    //BFS(adjGraph, visited2, 0);
    //cout << endl;
    vector<int> nums = inputRead();
    vector<HNode> adjGraph = createAdjGraph(nums);
    vector<bool> visited1(adjGraph.size(), false);
    vector<bool> visited2(adjGraph.size(), false);
    DFS(adjGraph, visited1,0);
    cout << endl;
    int v = nums[nums.size() - 1];
    deleteNode(v, adjGraph);
    BFS(adjGraph, visited2, 0);
    cout << endl;
}