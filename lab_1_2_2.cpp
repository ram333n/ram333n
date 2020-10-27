#include <iostream>
#include <cmath>
#include <stdlib.h>//для функції rand()
#include <conio.h>
using namespace std;
//зміна напрямку після зіткнення 2х точок
void onIntersect(int i,int* x, int* y, int* dx, int* dy, 
    int* direction, int* _x, double* k) {
    double rad = atan(fabs(k[i]));
    //дивимось, відносно якої осі потрібно поміняти напрямок
    if (rad < -sqrt(3) || rad > sqrt(3)) {
        k[i] = -k[i];
    }
    else {
        //вектор напрямку
        direction[i] = -direction[i];
    }

    dx[i] = x[i];
    dy[i] = y[i];
    _x[i] = 0;
}
//віддзеркалення відн Ox
void onXIntersect(int i, int* x, int* y, int* dx, int* dy, int* direction, int* _x){
        //вектор напрямку
        direction[i] = -direction[i];
        dx[i] = x[i];
        dy[i] = y[i];
        _x[i] = 0;
}
void onYIntersect(int i, int* x, int* y, int* dx, int* dy, double* k, int* _x) {
    k[i] = -k[i];
    dx[i] = x[i];
    dy[i] = y[i];
    _x[i] = 0;
}
int main()
{
    int n, w(200), h(200), STEP(1);
    cin >> n;
    //поточні координати точки та описи руху
    int* x = new int[n];
    int* y = new int[n];
    //зміщення(для того, що описати рух після зіткнення)
    int* dx = new int[n];
    int* dy = new int[n];
    //напрямок
    int* direction = new int[n];
    //координати точки в даний момент без зміщення
    int* _x = new int[n] {0};
    //кутовий коефіцієнт прямої, по якій іде рух
    double* k = new double[n];
    //зміння для того, щоб визначити, чи пропустити взаємодію
    bool* cancelIntersect = new bool[n] {false};
    //рухаємо всі точки
    for (int i = 0; i < n; i++)
    {
        x[i] = dx[i] = rand() % w;
        y[i] = dy[i] = rand() % h;
        k[i] = ((double)(rand()) / RAND_MAX  * (rand() % 2 == 1 ? -1 : 1));
        direction[i] = rand() % 2 == 1 ? -1 : 1;
    }
    //рухаємо всі точки
    while (true) {
        cout << "_________________________________" << endl;
        for (int i = 0; i < n; i++) {
            int anotherDot;
            _x[i] += direction[i] * STEP;
            y[i] = (int)(direction[i] * k[i] * _x[i]) + dy[i];
            x[i] = dx[i] + _x[i];

            if (cancelIntersect[i] == false) {
                bool intersect = false;
                for (int j = 0; j < n; j++) {
                    //якщо точки частково перетинаються, то 2-га точка ігнорує перевірку на перетин і змінює свій напрям одразу
                    if (j != i &&
                        x[i] >= x[j] - STEP &&
                        x[i] <= x[j] + STEP &&
                        y[i] >= y[j] - STEP &&
                        y[i] <= y[j] + STEP
                        ) {
                        anotherDot = j;
                        cancelIntersect[j] = true;;
                        onIntersect(j, x, y, dx, dy, direction, _x, k);
                        intersect = true;
                        break;
                    }
                }

                if (x[i] <= 0 || x[i] >= w) {
                    while (x[i] <= 0) x[i]++;
                    while (x[i] >= w) x[i]--;
                    onXIntersect(i, x, y, dx, dy, direction, _x);
                }
                else if (y[i] <= 0 || y[i] >= h) {
                    while (y[i] <= 0) y++;
                    while (y[i] >= h) y--;
                    onYIntersect(i, x, y, dx, dy, k, _x);
                }
                else if (intersect) {
                    onIntersect(i, x, y, dx, dy, direction, _x, k);
                    cout << "dot " << i << "(" << x[i] << "; " << y[i] << ")" << " intersected with dot " << anotherDot << " : (" << x[anotherDot] << ";" << y[anotherDot] << ")" << endl;
                }
            }
            cancelIntersect[i] = false;
            cout << "dot " << i << " : (" << x[i] << ";" << y[i] << ")" << endl;
        }
        //enter 
        _getch();
    }
}

