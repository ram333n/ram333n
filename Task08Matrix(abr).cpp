#include <iostream>
#include <random>
using namespace std;
int max(int a, int b) {
    return (a >= b ? a : b);
}
int min(int a, int b) {
    return (a <= b ? a : b);
}
int maxOfArray(int n, int arr[]) {
    int maxElement = arr[0];
    for (int i = 0; i < n; i++) {
        maxElement = max(maxElement, arr[i]);
    }
    return maxElement;
}
int minOfArray(int n, int arr[]) {
    int minElement = arr[0];
    for (int i = 0; i < n; i++) {
        minElement = min(minElement, arr[i]);
    }
    return minElement;
}
void Matrix01() {
   int matrix[5][4];
   for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 4 ; j++) {
           matrix[i][j] = 10 * i;
       }
   }
     
}
void Matrix08() {
    int matrix[5][4];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = 10 * i;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << matrix[i][3];
    }
}
void Matrix07() {
    int matrix[5][4];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = 10 * i;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << matrix[2][i];
    }
}
void Matrix10() {
    int matrix[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = 10 * i;
        }
    }
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 5; i += 2) {
            cout << matrix[i][j] << endl;
        }
    }

}
void Matrix11() {
    int matrix[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 9 * i;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0 ) {
            for (int j = 0; j < 5; j++) {
                cout << matrix[i][j];
            }
        }
        else {
            for (int j = 4; j >=0; j--) {
                cout << matrix[i][j];
            }
        }
    }

}
void Matrix17() {
    int n, m, k, sum(0), sub(1);
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 5 + 4;
        }
    }
    cin >> k;
    for (int i = 0; i < m; i++) {
        sum += matrix[k][i];
        sub *= matrix[k][i];
    }
    cout << "sub = " << sub << endl;
    cout << "sum = " << sum;
}
void Matrix21() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 5 + 4;
        }
    }
    for (int i = 0; i < n; i += 2) {
        double avgSum(0);
        for (int j = 0; j < m; j++) {
            avgSum = matrix[i][j];
        }
        cout << i+1<<" : " << avgSum / m << endl;
    }
}
void Matrix24() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 5 + 4;
        }
    }
    for (int i = 0; i < n; i++) {
        int MaxValue = matrix[0][i];
        for (int j = 0; j < m; j++) {
            MaxValue = max(MaxValue, matrix[j][i]);
        }
        cout << i+1<<" : " << MaxValue << endl;
    }
}
void Matrix23() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 5 + 4;
        }
    }
    for (int i = 0; i < m; i++) {
        int MinValue = matrix[0][i];
        for (int j = 0; j < n; j++) {
            MinValue = max(MinValue, matrix[j][i]);
        }
        cout << i + 1 << " : " << MinValue << endl;
    }
}
void Matrix32() {
    int n, m;
    bool numOfStr = false;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        int positiveQuantity(0), negativeQuantity(0);
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 0) {
                positiveQuantity++;
            }
            else if (matrix[i][j] < 0) {
                negativeQuantity++;
            }
            if (positiveQuantity == negativeQuantity) {
                cout << i+1;
                numOfStr = true;
                break;
            }
        }
    }
    if (numOfStr) {
        cout << numOfStr << endl;
    }
}
void Matrix34() {
    int n, m;
    bool str = false;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        bool numOfNoPar = false;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 != 0) {
                numOfNoPar = true;
                continue;
            }
        }
        if (!numOfNoPar) {
            str = true;
            cout << i + 1 << endl;
            break;
        }
    }
    if (!str) {
        cout << "0" << endl;
    }
}
void Matrix35() {
    int n, m;
    bool col = false;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        bool numOfPar = false;
        for (int j = 0; j < n; j++) {
            if (matrix[j][i] % 2 == 0) {
                numOfPar = true;
                continue;
            }
        }
        if (!numOfPar) {
            col = true;
            cout << i + 1 << endl;
            break;
        }
    }
    if (!col) {
        cout << "0" << endl;
    }
}
void Matrix47() {
    int n, m, k1, k2;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    cin >> k1 >> k2;
    for (int i = 0; i < m; i++) {
        int temp;
        temp = matrix[k1][i];
        matrix[k1][i] = matrix[k2][i];
        matrix[k2][i] = temp;
    }
}
void Matrix48() {
    int n, m, k1, k2;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    cin >> k1 >> k2;
    for (int i = 0; i < n; i++) {
        int temp;
        temp = matrix[i][k1];
        matrix[i][k1] = matrix[i][k2];
        matrix[i][k2] = temp;
    }
}
void Matrix49() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  " << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        int IndexOfMax, IndexOfMin, temp;
        int maxElement = maxOfArray(m, matrix[i]);
        int minElement = minOfArray(m, matrix[i]);
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == maxElement) {
                IndexOfMax = j;
            }
            if (matrix[i][j] == minElement) {
                IndexOfMin = j;
            }
        }
        temp = matrix[i][IndexOfMax];
        matrix[i][IndexOfMax] = matrix[i][IndexOfMin];
        matrix[i][IndexOfMin] = temp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  " << endl;
        }
    }

}
void Matrix55() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int a = 0, b = n/2 ; a <= n / 2 && b<=n-1; a++, b++) {
        for (int c = 0; c < m; c++) {
            int tmp;
            tmp = matrix[a][c];
            matrix[a][c] = matrix[b][c];
            matrix[b][c] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void Matrix56() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int a = 0, b = m / 2; a <= m / 2 && b <= m - 1; a++, b++) {
        for (int c = 0; c < n; c++) {
            int tmp;
            tmp = matrix[c][a];
            matrix[c][a] = matrix[c][b];
            matrix[c][b] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void Matrix57() {
    int n, m;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int h1 = 0, h2 = n/2; h1<= n / 2 && h2<=n-1; h1++, h2++) {
        for (int k1 = 0, k2 = m / 2; k1 <= m / 2 && k2 <= m - 1; k1++, k2++) {
            int tmp;
            tmp = matrix[h1][k1];
            matrix[h1][k1] = matrix[h2][k2];
            matrix[h2][k2] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void Matrix61() {
    int n, m, k;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cin >> k;
    delete[] matrix[k];
    if (k != n-1) {
        for (int i = k; i < m - 1; i++) {
            matrix[i] = matrix[i + 1];
        }
    }
    else {
        for (int i = k; i < m - 1; i++) {
            matrix[i] = matrix[i - 1];
        }
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void Matrix62() {
    int n, m, k;
    cin >> n >> m;
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    //утечка памяти
    cin >> k;
    if (k != 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][k] = matrix[i][k - 1];
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            matrix[i][k] = matrix[i][k + 1];
        }
    }
}
//void Matrix63
//void Matrix 7(f)
void Matrix80() {
    int m, sum(0);
    cin >> m;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }
}
void Matrix81() {
    int m;
    double sum(0);
    cin >> m;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i =0, j = m - 1; j >= 0 && i<=m-1; i++,j--) {
        sum += matrix[i][j];
    }
    sum /= m;
}
void Matrix82() {
    int m;
    int sum(0);
    cin >> m;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int l = m - 1, h = 0; l >= 1; l--, h++) {
        for (int i = l, j = 0; j<=h; i++, j++) {
            sum += matrix[j][i];
        }
    }
    for (int h = 1, l = m - 2; h <= m - 1; h++, l--) {
        for (int i = h, j = 0; j <= l; i++, j++) {
            sum += matrix[i][j];
        }
    }
    cout << sum << endl;
}
void Matrix91() {
    int m;
    cin >> m;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int l = m - 1, h = 0; l >= 1; l--, h++) {
        for (int i = l, j = 0; j <= h; i++, j++) {
            matrix[j][i] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void Matrix92() {
    int m;
    cin >> m;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int a = 1,b = m - 2,h=0; h<m/2+1; a++, b--,h++) {
        for (int i = a; i <= b; i++) {
            matrix[h][i] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
void Matrix93() {
    int m;
    cin >> m;
    int** matrix = new int* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % (-100 + 200);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    for (int a = 1, b = m - 2, h = m-1; h > m / 2 ; a++, b--, h--) {
        for (int i = a; i <= b; i++) {
            matrix[i][h] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    while(true) Matrix61();
}
