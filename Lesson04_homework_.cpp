#include <iostream>
using namespace std;

void func4() {
    int num;
    cin >> num;
    switch (num) {
    case 1:
        cout << "winter";
        break;
    case 2:
        cout << "winter";
        break;
    case 3:
        cout << "spring";
        break;
    case 5:
        cout << "spring";
        break;
    case 6:
        cout << "summer";
        break;
    case 7:
        cout << "summer";
        break;
    case 8:
        cout << "summer";
        break;
    case 9:
        cout << "autumn";
        break;
    case 10:
        cout << "autumn";
        break;
    case 11:
        cout << "autumn";
        break;
    case 12:
        cout << "winter";
        break;
    default:
        cout << "enter the right number";
    }
}
void func1() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a <= b && b <= c && c <= d) || (a <= b && b <= d && d <= c) || (a <= c && c <= b && b <= d) || (a <= c && c <= d && d <= b) || (a <= d && d <= c && c <= b) || (a <= b && b <= d && d <= c)) {
        cout << a;
    }
    else if ((b <= a && a <= c && c <= d) || (b <= a && a <= d && d <= c) || (b <= c && c <= a && a <= d) || (b <= c && c <= d && d <= a) || (b <= d && d <= c && c <= a) || (b <= d && d <= a && a <= c)) {
        cout << b;
    }
    else if ((c <= a && a <= b && b <= d) || (c <= a && a <= d && d <= b) || (c <= b && b <= a && a <= d) || (c <= b && b <= d && d <= a) || (c <= d && d <= c && c <= a) || (c <= d && d <= a && a <= c)) {
        cout << c;
    }
    else {
        cout << d;
    }
}
int minnum(int n1, int n2) {
    if (n1 > n2) {
        return n2;
    }
    else if (n1 < n2) {
        return n1;
    }
}
int maxnum(int n1, int n2) {
    if (n1 > n2)
    {
        return n1;
    }
    else if (n1 < n2)
    {
        return n2;
    }
}
void func3() {
    int k(10), f(22), s(0), q(1);
    cout << "Min: " << minnum(k, minnum(f, minnum(s, q)));
    cout << "Max: " << maxnum(k, maxnum(f, maxnum(s, q)));
}
void func2(int a,int b, int c,int  d) {
    int max = maxnum(a, maxnum(b, maxnum(c, d)));
    if (max == a || max == b || max == c || max == d) {
        cout << 1;
    }
    else if ((max == a && max == b) || (max == a && max == c) || (max == a && max == d) || (max == b && max == c) || (max == b && max == d) || (max == c && max == d)) {
        cout << 2;
    }
    else if ((max == a && max == b && max == c) || (max == a && max == b && max == d) || (max == a && max == c && max == d) || (max == b && max == c && max == d)) {
        cout << 3;
    }
    else{
        cout << 4;
    }

}



