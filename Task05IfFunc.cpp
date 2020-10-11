#include <iostream>
#include <cmath>
using namespace std;
int minOf(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
int maxOf(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int func1(int a) {
	cout << "Enter the number" << endl;
	cin >> a;
	if (a > 0) {
		return a + 1;
	}
	else {
		return a;
	}

}
int func6(int a,int b) {
	cout << "Enter the numbers" << endl;
	cin >> a >> b;
	if (a>b) {
		return a;
	}
	else {
		return b;
	}

}
void func8(int a, int b) {
	cout << "Enter the numbers" << endl;
	cin >> a >> b;
	if (a > b) {
		cout << a << " " << b;
	}
	else {
		cout << b << " " <<a;
	}

}
int func12(int a, int b,int c) {
	cout << "enter the numbers" << endl;
	cin >> a >> b>>c;
	return minOf(a, minOf(b, c));
}
void func10(int a, int b) {
	cout << "enter the numbers" << endl;
	cin >> a >> b;
	if (a != b) {
		a = a + b;
		b = a;
		cout << "a = b = " << a;
	}
	else {
		a = 0; b = 0;
		cout << "a = b = " << a;
	}
}
void func14(int a, int b, int c) {
	cout << "enter the numbers" << endl;
	cin >> a >> b >> c;
	cout << minOf(a, minOf(b, c));
	cout << maxOf(a, maxOf(b, c));
}
void func22(int x1, int y1) {
	cout << "enter the coords" << endl;
	cin >> x1 >> y1;
	if (x1 > 0 && y1 > 0) {
		cout << "first";
	}
	else if (x1 > 0 && y1 < 0) {
		cout << "fourth";
	}
	else if (x1 < 0 && y1 > 0) {
		cout << "second";
	}
	else {
		cout << "third";
	}
}
int func25(int x) {
	cout << "enter the x" << endl;
	cin >> x;
	if (x < -2 || x>2) {
		return 2 * x;
	}
	else {
		return -3 * x;
	}
}
void func28(int year) {
	cout << "enter the year" << endl;
	cin >> year;
	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
		cout << "365" << endl;
	}
	else {
		cout << "366" << endl;
	}
}
double func24(double x){
	if(x>0){
		return 2*sin(x);
	}
	else{
		return 6-x;

