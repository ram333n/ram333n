#include <iostream>
using namespace std;
double max(double a, double b) {
	return ((a >= b) ? a : b);
}
double min(double a, double b) {
	return ((a <= b) ? a : b);
}
void crossing() {
	double x11, y11, x12, y12, x21, y21, x22, y22;
	cout << "Enter the coords the tops of 1st segment" << endl;
	cin >> x11 >> y11 >> x12 >> y12;
	cout << "x11 = " << x11 << ", y11 = " << y11 << endl;
	cout << "x12 = " << x12 << ", y12 = " << y12 << endl;
	cout << "Enter the coords the tops of 2st segment" << endl;
	cin >> x21 >> y21 >> x22 >> y22;
	cout << "x21 = " << x21 << ", y21 = " << y21 << endl;
	cout << "x22 = " << x22 << ", y22 = " << y22 << endl;
	//визначаємо, як розміщені відрізки(1 випадок - розміщені на паралельних прямих)
	if ((x11 == x12 && x21 == x22 && x11 != x21) 
		|| (((y12 - y11) / (x12 - x11)) == ((y22 - y21) / (x22 - x21))) && (((x12 * y11 - y12 * x11) / (x12 - x11)) != ((x22 * y21 - y22 * x21) / (x22 - x21)))) {
		cout << "There are no crossing (they are parallel)" << endl;
	}

	else if ((((y12 - y11) / (x12 - x11)) == ((y22 - y21) / (x22 - x21))) && (((x12 * y11 - y12 * x11) / (x12 - x11)) == ((x22 * y21 - y22 * x21) / (x22 - x21)))) {
		//випадок, коли відрізки на одній прямій і кінець 1-го співпадає з початком 2-го і навпаки
		if (((max(x11, x12) == min(x21, x22)))) {
			cout << "The coords of crossing:x=" << x21 << " y=" << y21;
		}
		else if (((min(x11, x12) == max(x21, x22)))) {
			cout << "The coords of crossing:x=" << x11 << " y=" << y11;
		}
		else {
			cout << "Segments are have many common moments of no crossing" << endl;
		}
	}
	//загальний випадок(відрізки не паралельні)
	else {
		double k1 = (y12 - y11) / (x12 - x11);
		double k2 = (y22 - y21) / (x22 - x21);
		double b1 = (x12 * y11 - y12 * x11) / (x12 - x11);
		double b2 = (x22 * y21 - y22 * x21) / (x22 - x21);
		double x, y;
		x = (b2 - b1) / (k1 - k2);
		y = k1 * x + b1;
		//випадки, коли один з кут.коефіцієнтів =0
		if (x11 == x12) {
			x = x11;
			y = k2 * x + b2;
			if (min(x21, x22) <= x && x <= max(x21, x22)) {
				cout << "The coords of crossing:x= " << x << "y=" << y << endl;
			}
			else {
				cout << "There are no crossing" << endl;
			}
		}
		else if (x21 == x22) {
			    x = x21;
				y = k1 * x + b1;
				if (min(x11, x12) <= x && x <= max(x11, x12)) {
					cout << "The coords of crossing:x= " << x << "y=" << y << endl;
				}
				else {
					cout << "There are no crossing" << endl;
				}
		}
		else if ((min(x11, min(x12, min(x21, x22))) <= x && x <= max(x11, max(x12, max(x21, x22))) && (min(y11, min(y12, min(y21, y22))) <= y&& y <= max(y11, max(y12, max(y21, y22)))))&&(min(x11,x12)<=x&&x<=max(x11,x12))&& (min(y11, y12) <= y&&y <= max(y11, y12))&& ((min(x21, x22) <= x && x <= max(x21, x22))) && ((min(y21, y22) <= y && y <= max(y21, y22)))) {
			cout << "The coords of crossing:x= " << x << "y=" << y << endl;
		}
		else {
			cout << "There are no crossing" << endl;

		}
	}
}

int main() {
	do {
		crossing();
	} while (true);
}