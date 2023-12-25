#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// 矩阵类
class Matrix {
public:
    int rows;
    int cols;
    vector<vector<int>> data;

    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c)) {}

    void readData(ifstream& file) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file >> data[i][j];
            }
        }
    }

    void printData(ofstream& file) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file << data[i][j] << " ";
            }
        }
        file << endl;
    }
};

// 等值联接运算
Matrix joinOperation(const Matrix& R, const Matrix& S, int a1, int a2) {
    Matrix C(R.rows*S.cols, R.cols + S.cols - 1);
    int numRow = 0;
    for (int i = 0; i < R.rows; i++) {
        for (int j = 0; j < S.rows; j++) {
            if (R.data[i][a1] == S.data[j][a2]) {
                for (int x = 0; x < R.cols; x++)
                {
                    C.data[numRow][x] = R.data[i][x];
                }
                for (int y = 0; y < S.cols; y++)
                {
                    C.data[numRow][y+R.cols] = R.data[j][y];
                }
                numRow++;
            }
        }
    }

    return C;
}

int main() {
    ifstream inputFile("in.txt");
    ofstream outputFile("abc.out");

    int m1, n1;
    inputFile >> m1 >> n1;

    Matrix R(m1, n1);
    R.readData(inputFile);

    int m2, n2;
    inputFile >> m2 >> n2;

    Matrix S(m2, n2);
    S.readData(inputFile);

    int a1, a2;
    inputFile >> a1 >> a2;

    Matrix C = joinOperation(R, S, a1, a2);

    C.printData(outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}
