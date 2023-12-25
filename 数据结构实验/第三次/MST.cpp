#include<iostream>
#include<sstream>
#include<vector>
#include <algorithm>
#include <climits> 
using namespace std;

//�߽������
struct ArcNode {
    int adjvex;
    int weight;
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
    return nums;
}
//�����ڽӾ���
void createAdjMatrix(vector<int>& nums, vector<vector<int>>& adjMatrix, vector<vector<int>>& ID) {
    //��ʼ������
    for (int i = 0; i < nums[1]; i++) {
        int d = nums[2 + 4 * i];//id
        int u = nums[3 + 4 * i];//����ʼ��
        int v = nums[4 + 4 * i];//�߽�����
        int w = nums[5 + 4 * i];//Ȩֵ
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
        ID[u][v] = d;
        ID[v][u] = d;
    }
    for (int i = 0; i < nums[0]; i++) {
        adjMatrix[i][i] = 0;
   }
}

void Prim(const vector<vector<int>>& AdjMatrix, const vector<int>& nums, const vector<vector<int>>& ID, int v) {
    vector<int> lowcost(nums[0]);
    vector<int> closest(nums[0]);
    vector<int> idUsed(nums[0] - 1);//nums[0]-1����
    int sum = 0;
    //��ʼ��lowcost��closest����
    for (int i = 0; i < nums[0]; i++)
    {
        lowcost[i] = AdjMatrix[v][i];
        closest[i] = v;
    }
    //ѭ�����붥��,nums[0]������ֻ��Ҫѭ��nums[0]-1���ҵ�nums[0]����
    for (int i = 0; i < nums[0] - 1; i++)
    {
        int min = INT_MAX;
        int k = -1;
        for (int j = 0; j < nums[0]; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
        }
        lowcost[k] = 0;//�����Ѽ���
        sum += min;//��Ȩֵ
        idUsed[i] = ID[closest[k]][k];//�õ��ıߵ�id
        for (int j = 0; j < nums[0]; j++)
        {
            if (lowcost[j] != 0 && AdjMatrix[k][j] < lowcost[j]) {
                lowcost[j] = AdjMatrix[k][j];
                closest[j] = k;
            }
        }
    }
    cout << sum << endl;
    sort(idUsed.begin(), idUsed.end());
    for (int id : idUsed) {
        cout << id << " ";
    }
}
int main() {
    vector<int> nums = inputRead();
    vector<vector<int>> adjMatrix(nums[0], vector<int>(nums[0], INT_MAX));
    vector<vector<int>> ID(nums[0], vector<int>(nums[0], 0));
    createAdjMatrix(nums, adjMatrix,ID);
    Prim(adjMatrix, nums,ID, 0);
}