#include <iostream>
using namespace std;

double sumArr(int* arr, int n, int s) {
    int sum = arr[0];
    for (int i = 1; i < n; i++, s = s >> 1) {
        sum += arr[i] * (s && 1 ? -1 : 1);
    }
    return sum;
}

int balance(int* arr, int n) {
    long max = pow(2, n - 1);
    int signs = 0;
    int sum;
    do {
        sum = sumArr(arr, n, signs++);
    } while (sum != 0 && signs <= max);

    for (int i = 1; i < n; i++, signs = signs >> 1) {
        if (signs && 1) {
            arr[i] *= -1;
        }
    }
    return sum;
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) cout << "+"<< arr[i]  ;
        else cout << arr[i] ;
    }
}


int main()
{
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;
    int* array = new int[n];
    cout << "Enter the numbers" << endl;
    for (int i = 0; i < n; i++) {
        bool IsNegative = false;
        do {
            cin >> array[i];
            if (array[i] <= 0) {
                IsNegative = true;
                cout << "Incorrect input" << endl;
            }
        } while (IsNegative);
    }
    if (balance(array, n) == 0) printArray(array, n);
    else cout << "No solution" << endl;
}