#include <iostream>
#include <cmath>
using namespace std;

void func1() {
	int n;
	cout << "Enter the number" << endl;
	cin >> n;
	switch (n) {
	case1: cout << "Monday" << endl; break;
	case2: cout << "Tuesday" << endl; break;
	case3: cout << "Wednesday" << endl; break;
	case4: cout << "Thursday" << endl; break;
	case5: cout << "Friday" << endl; break;
	case6: cout << "Saturday" << endl; break;
	case7: cout << "Sunday" << endl; break;
	}
}	
void func4() {
	int n;
	cout << "Enter the number" << endl;
	cin >> n;
	switch (n) {
	case1: 
	case3: 
	case7: 
	case8: 
	case10: 
	case12: cout << "31" << endl; break;
	case4:
	case6:
	case9:
	case11:cout << "30" << endl; break;
	case2:cout << "28" << endl; break;
	default:cout << "enter the right number";
	}

}
void func5() {
	double a, b;
	int n;
	cout << "enter the numbers" << endl;
	cin >> a >> b;
	cout << "enter the action" << endl;
	cin >> n;
	switch (n)
	{
	case 1: cout << a + b; break;
	case 2: cout << a - b; break;
	case 3: cout << a * b; break;
	case 4: cout << a / b; break;
	default: cout << "enter the right action";
	
	}
	
}
void func12() {
	double elementOfCircle;
	int n;
	cout << "enter the element" << endl;
	cin >> n;
	cout << "enter the value of element of circle" << endl;
	cout << "1.Radius" << endl;
	cout << "2.Diametr" << endl;
	cout << "3.Length of circle" << endl;
	cout << "4.Area of circle" << endl;

	cin >> elementOfCircle;

	switch (n)
	{
	case 1: cout << "D = " << 2 * elementOfCircle<<", L = "<<6.28*elementOfCircle<<", S = "<<3.14*elementOfCircle*elementOfCircle; break;
	case 2: cout << "R = " << elementOfCircle / 2 << ", L = " << 3.14 * elementOfCircle << ", S = " << 3 , 14 * elementOfCircle * elementOfCircle / 4; break;
	case 3: cout << "R = " << elementOfCircle / 6.28 << ", D = " << elementOfCircle / 3.14 << ", S= "<< elementOfCircle * elementOfCircle / (4 * 3.14); break;
	case 4: cout << "R = " << sqrt(elementOfCircle / 3.14) << ", D = " << 2 * sqrt(elementOfCircle / 3.14) << ", L = " << 2 * sqrt(3.14 * elementOfCircle); break; break;
	default: cout << "enter the right element"; break;
	}
}
void func20() {
	int day, month;
	cin >> day >> month;
	switch (month) {
	case 1:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19: cout << "Kozerog"; break;
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30: cout << "Vodoley"; break;
		}; break;

	case 2:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18: cout << "Vodoley"; break;
		case 19:
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29: cout << "Ryby"; break;
		} break;
	case 3:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20: cout << "Ryby"; break;
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Oven"; break;
		}; break;
	case 4:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19: cout << "Oven"; break;
		case 20:
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30: cout << "Teletc"; break;
		}; break;
	case 5:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:cout << "Teletc"; break;
		case 21:
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Bliznetcy"; break;
		}break;
	case 6:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21: cout << "Bliznetcy"; break;
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Rak"; break;
		}break;
	case 7:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22: cout << "Rak"; break;
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Lev"; break;
		}break;
	case 8:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22: cout << "Lev"; break;
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Deva"; break;
		}break;
	case 9:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22: cout << "Deva"; break;
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30: cout << "Vesy"; break;
		}break;
	case 10:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22: cout << "Vesy"; break;
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Scorpion"; break;
		}break;
	case 11:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
		case 22:cout << "Scorpion"; break;
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:cout << "Streletc"; break;
		}break;
	case 12:
		switch (day) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21: cout << "Streletc"; break;
		case 22:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31: cout << "Kozerog"; break;
		}break;
	}
}
void func19() {
	int year;
	cin >> year;
	if ((year >= 1984 && year < 1984 + 12) || (year >= 1984 + 60 && year <= 1984 + 72)) {
		switch (year % 12) {
		case 4:
			cout << "god zelenoy krysy"; break;
		case 5:
			cout << "god zelenoy korovy"; break;
		case 6:
			cout << "god zelenogo tigra"; break;
		case 7:
			cout << "god zelenogp zaica"; break;
		case 8:
			cout << "god zelenogo drakona"; break;
		case 9:
			cout << "god zelenoy zmei"; break;
		case 10:
			cout << "god zelenoy loshadi"; break;
		case 11:
			cout << "god zelenoy ovcy"; break;
		case 0:
			cout << "god zelenoy obezjany"; break;
		case 1:
			cout << "god zelenoy kyritcy"; break;
		case 2:
			cout << "god zelenoy sobaki"; break;
		case 3:
			cout << "god zelenoy svini"; break;
		}
	}
	if ((year >= 1996 && year < 1996 + 12) || (year >= 1996 + 60 && year <= 1996 + 72)) {
		switch (year % 12) {
		case 4:
			cout << "god krasnoy krysy"; break;
		case 5:
			cout << "god krasnoy korovy"; break;
		case 6:
			cout << "god krasnogo tigra"; break;
		case 7:
			cout << "god krasnogo zaica"; break;
		case 8:
			cout << "god krasnogo drakona"; break;
		case 9:
			cout << "god krasnoy zmei"; break;
		case 10:
			cout << "god krasnoy loshadi"; break;
		case 11:
			cout << "god krasnoy ovcy"; break;
		case 0:
			cout << "god krasnoy obezjany"; break;
		case 1:
			cout << "god krasnoy kyritcy"; break;
		case 2:
			cout << "god krasnoy sobaki"; break;
		case 3:
			cout << "god krasnoy svini"; break;
		}

	}
	if ((year >= 2008 && year < 2008 + 12) || (year >= 2008 + 60 && year <= 2008 + 72)) {
		switch (year % 12) {
		case 4:
			cout << "god zholtoy krysy"; break;
		case 5:
			cout << "god zholtoy korovy"; break;
		case 6:
			cout << "god zholtogo tigra"; break;
		case 7:
			cout << "god zholtogo zaica"; break;
		case 8:
			cout << "god zholtogo drakona"; break;
		case 9:
			cout << "god zholtoy zmei"; break;
		case 10:
			cout << "god zholtoy loshadi"; break;
		case 11:
			cout << "god zholtoy ovcy"; break;
		case 0:
			cout << "god zholtoy obezjany"; break;
		case 1:
			cout << "god zholtoy kyritcy"; break;
		case 2:
			cout << "god zholtoy sobaki"; break;
		case 3:
			cout << "god zholtoy svini"; break;
		}

	}
	if ((year >= 2020 && year < 2020 + 12) || (year >= 2020 + 60 && year <= 2020 + 72)) {
		switch (year % 12) {
		case 4:
			cout << "god beloy krysy"; break;
		case 5:
			cout << "god beloy korovy"; break;
		case 6:
			cout << "god belogo tigra"; break;
		case 7:
			cout << "god belogo zaica"; break;
		case 8:
			cout << "god belogo drakona"; break;
		case 9:
			cout << "god  beloy zmei"; break;
		case 10:
			cout << "god  beloy loshadi"; break;
		case 11:
			cout << "god  beloy ovcy"; break;
		case 0:
			cout << "god  beloy obezjany"; break;
		case 1:
			cout << "god  beloy kyritcy"; break;
		case 2:
			cout << "god  beloy sobaki"; break;
		case 3:
			cout << "god  beloy svini"; break;
		}

	}
	if ((year >= 2032 && year < 2032 + 12) || (year >= 2032 + 60 && year <= 2032 + 72)) {
		switch (year % 12) {
		case 4:
			cout << "god chornoy krysy"; break;
		case 5:
			cout << "god chornoy korovy"; break;
		case 6:
			cout << "god chornogo tigra"; break;
		case 7:
			cout << "god chornogo zaica"; break;
		case 8:
			cout << "god chornogo drakona"; break;
		case 9:
			cout << "god  chornoy zmei"; break;
		case 10:
			cout << "god  chornoy loshadi"; break;
		case 11:
			cout << "god  chornoy ovcy"; break;
		case 0:
			cout << "god  chornoy obezjany"; break;
		case 1:
			cout << "god  chornoy kyritcy"; break;
		case 2:
			cout << "god  chornoy sobaki"; break;
		case 3:
			cout << "god  chornoy svini"; break;
		}

	}
}