#include <iostream>
#include <cmath>
using namespace std;
const double H = 0.000001;
double Function(double x) {
    return pow(x, 10) + pow(x, 9) + pow(x, 3) - x - 1;
} 
double DevOfFunc(double x, double(*func)(double)) {
    return ((Function(x + H) - Function(x - H)) / (2 * H));
}
double SecondDevOfFunc(double x, double(*func12)(double)) {
    return ((Function(x + H) + Function(x - H) - 2 * Function(x)) / (H * H));
}

int main()
{
    double a, b, x0,  eps;
    cout << "Enter the a,b,eps (a<b)" << endl;
    cin >> a >> b >> eps;
    if (a >= b) cout << "incorrect input, try again";
    else {
        if (DevOfFunc(a, Function) * (SecondDevOfFunc(a, Function) > 0)) x0 = a;
        else x0 = b;
        do {
            x0 = x0 - (Function(x0) / DevOfFunc(x0, Function));
        } while (Function(x0) >= eps);
        cout << "The root  : " << x0;
    }
}