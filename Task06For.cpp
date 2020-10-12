#include <iostream>
#include "Task06For.h"

using namespace std;

void Rectangle()
{
    int a, b;
    cout << "enter the length of base" << endl;
    cin >> a;
    cout << "enter the height";
    cin >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == 1 ||j == 1 || i == a || j == b) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void RightTriangle() {
    int a;
    cout << "enter the height(height=base" << endl;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++) {
            if (j == 1 || j == i || i == a) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void EquilateralTriangle() {
    int a;
    cout << "enter the base" << endl;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= a; j++) {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            if (k == 1 || k == 2 * i - 1 || i == a) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    int menu;
    cout << "Press 1 to draw a rectangle" << endl;
    cout << "Press 2 to draw a right triangle" << endl;
    cout << "Press 3 to draw a equilateral triangle" << endl;
    cout << "Drawing of rhombus isn't avaible" << endl;
    cin >> menu;
    switch (menu) {
    case 1:
        Rectangle(); break;
    case 2:
        RightTriangle(); break;
    case 3:
        EquilateralTriangle(); break;
    default:
        cout << "Enter the right action" << endl;
    }
}
