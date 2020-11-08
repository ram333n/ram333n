#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 0.000001;
const double STEP = EPS;
const double H = (EPS) / 2;
double Function(double x) {
    return sin(x) * cos(3 * x);
}

double DevOfFunc(double x, double(*function)(double)) {
    return ((Function(x + H) - Function(x - H)) / (2 * H));
}

bool isEqual(double a, double b, double eps) {
    return fabs(a - b) <= eps;
}

double findPeriod(double(*function)(double)) {
    double x = STEP;
    double period = -1;
    double fX = function(x);
    double fXdx = DevOfFunc(x, function);
    x += STEP;
    for (long long i = 0; i < 10000000000; i++, x += STEP) {
        if (isEqual(fX, function(x), EPS) && isEqual(fXdx, DevOfFunc(x, function), EPS) && isEqual(fX, function(2 * x), EPS) && isEqual(fXdx, DevOfFunc(2 * x , function), EPS)) {
            period = x - STEP;
            break;
        }
    }
    return period;
}
int main()
{
    double period = findPeriod(Function);
    if (period < 0) {
        cout << "Function isn't periodic" << endl;
    }
    else {
        cout << "Function is periodic, period :  " << period << endl;
    }
}