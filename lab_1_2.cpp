#include <iostream>
using namespace std;
const int LEN = 128;
//визначаємо останній індекс
//a[i]==0 
int getLastIdx(char* a) {
	for (int i = 0; i < LEN; i++) {
		if (a[i] == 0) return i-1;
	}
	return LEN;
}
//параметри за вказівником(масиви)
void sum(char* a, char* b, char* sum) {

	int aIdx = getLastIdx(a);
	int bIdx = getLastIdx(b);
	//визначаємо індекс суми
	int sumIdx = (aIdx > bIdx ? aIdx : bIdx) + 1;
	int c = 0;
	//код '0' = 48; '1'=49,... , 96 = 2 відступи, віднімаємо 96 для того, щоб отримати числове значення суми розрядів у int . c- перенесення 
	while (aIdx > -1 && bIdx > -1) {
		int s = (a[aIdx] + b[bIdx] - 96 + c);
		sum[sumIdx] = (s % 10) + 48;
		c = s / 10;
		aIdx--, bIdx--, sumIdx--;
	}
	//якщо є перенесення, то нічого не відбувається(залишається в int).Інакше,c в char
	if(c)sum[sumIdx] = sumIdx  ? c : c + 48;
	//перенесення залишкових цифр
	char* rest; 
	int restIdx;
	if (aIdx > bIdx) {
		rest = a;
		restIdx = aIdx;
	} else {
		rest = b;
		restIdx = bIdx;
	}
	while (restIdx > -1) {
		sum[sumIdx--] += rest[restIdx--];
	}
	//фіксимо баг 
	if (sum[0]==0) {
		for (int i = 0; i < LEN ; sum[i] = sum[i + 1], i++);
	}
}
int main() {

	char a[LEN] = {0};
	char b[LEN] = {0};
	char c[LEN + 1] = {0};
	cout << "enter the numbers" << endl;
	cin >> a;
	cin >> b;

	sum(a, b, c);

	cout << c << endl;
	
}