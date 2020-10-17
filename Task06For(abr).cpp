#include <iostream>
#include <cmath>
using namespace std;

double fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}
void task04For() {
    int price;
    cin >> price;
    for (int i = 2; i <= 10; i++) {
        cout << i * price << endl;
    }
}
void task11For() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        sum += (n + i) * (n + i);
    }
    cout << sum << endl;
}
void task22For() {
    double x;
    int n;
    double sum = 1;
    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i) / fact(i);
    }
    cout << sum << endl;
}
void task39For() {
    int a, b;
    cin >> a >> b;
    for (int num = a; num <= b; num++) {
        int times = num;
        for (int i = 0; i < times; i++) {
            cout << num << endl;
        }
    }
}
bool task4While() {
    int n;
    cin >> n;
    while (n > 1) {
        if (n % 3 != 0) {   
            return false;
            break;
        }
        else {
            n /= 3;
        }
    }
    return true;
}
void task10While() {
    int n, k = 0;
    cin >> n;
    while (pow(3, k) < n) {
        k++;
        if (pow(3, k) > n) {
            cout << k-- << endl;
            break;
        }
    }
}
bool task22While() {
    int n, k = 2;
    cin >> n;
    while (k < n) {
        if (n % k == 0) {
            return false;
            break;
        }
        k++;
    }
    return true;
    
}
void task01Series() {
    double n;
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        sum += n;
    }
    cout << sum << endl;
}
bool task10Series() {
    int number, n;
    bool posnum = false;
    cin >> n >> number;
    for (int i = 0; i < n; i++) {
        cin >> n;
        if (number < 0) {
            posnum=true;
        }
    }
    return posnum;
    
}
bool task22Series() {
    int number, n;
    bool g = true;
    int delta;
    cin >> n >> number;
    for (int i = 1; i < n; i++) {
        cin >> number;
        if (i == 1) {
            delta = number;
        }
        else {
            if (number - delta < 0) {
                g = false;
            }
            else {
                delta = number;
            }

        }
    }
    return g;
}
void task30Series() {
    int k, n, nums;
    int quantityOfTwo = 0;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums;
        }
        if (nums == 2) {
            quantityOfTwo++;
        }

    }
    cout << "quantityOfTwo = " << quantityOfTwo << endl;
}
int main()
{
    task30Series();
}
