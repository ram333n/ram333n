#include <iostream>
using namespace std;
void Matrix1() {
    int matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] > 0) {
                cout << matrix[i][j] << endl;
            }
        }
    }
    
    
}
void Matrix2() {
    int rows, cols, numOfRows(0);
    cin >> rows >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    for (int i = 0; i < rows; i++) {
        int zeroElement(0);
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0) {
                zeroElement++;
            }
        }
        if (zeroElement != 0) {
            numOfRows++;
        }
    }
    cout << numOfRows << endl;
    

   
}

int main()
{
    Matrix2();
}
