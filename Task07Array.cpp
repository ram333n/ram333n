#include <iostream>
using namespace std;

int max(int a, int b) {
	if (a>= b) {
		return a;
	}
	else {
		return b;
	}
}
void Array18() {
	int arr[10] = { 1,4,7,89,4,1,64,2,51,6 };
	for (int i = 0; i < 10; i++) {
		if (arr[i] < arr[9]) {
			cout << arr[i];
			break;
		}
		else {
			cout << 0;
		}
	}	
}
void Array20() {
	int n, k, l;
	int sum(0);
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k >> l;
	for (int i = k; k <= l; k++) {
		sum += arr[k];
	}
	
}
void Array21() {
	int n, k, l;
	int sum(0);	
	cin >> n;
	int* arr = new int[n];
	cin >> k >> l;
	int q = l - k + 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = k; k <= l; k++) {
		sum += arr[k];
	}
	cout << sum / q << endl;

}
void Array51() {
	int n, temp;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "a" << endl;
		cin >> a[i];
		cout << "b" << endl;
		cin >> b[i];
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	for (int i = 0; i < n; i++) {
		cout << " 1st: " << a[i] << " 2nd: " << b[i];
	}
}
void Array60() {
	int n, k;
	cin >> n;
	int* arr = new int[n];
	int* barr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int* barr = new int[n];
	for (int k = 0; k < n; k++) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}
		barr[k] = sum;
	}
	delete[]arr;

}
void Array71() {
	int n, t;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}
void Array83() {
	int n, t;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	t = arr[n - 1];
	for (int i = 0; i < n - 1; i++) {
		arr[i + 1] = arr[i];
	}
	arr[0] = t;
}
void Array90() {
	int n, k;
	cin >> n;
	int* arr = new int[n];
	int* filter = new int[n-1];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;
	for (int i = 0; i < n-1; i++) {
		if (i >= k) {
			filter[i] = arr[i + 1];
			continue;
		}
		filter[i] = arr[i];
	}
	for (int i = 0; i < n-1; i++) {
		cout << filter[i] << endl;
	}
	delete[] arr;
}
void Array109() {
	int n, j = 0;
	cin >> n;
	int* arr = new int[n];
	int* barr = new int[2*n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0 ; i < n; i++,j++) {
		barr[j] = arr[i];
		if (arr[i] < 0) {
			barr[++j] = 0;
		}
	}
	delete[]arr;
	arr = new int[j];
	for (int i = 0; i < j; i++) {
		cout << barr[i] << endl;
		arr[i] = barr[i];
	}
	delete[]arr;
	delete[]barr;
}
void Array110() {
	int n, j = 0;
	cin >> n;
	int* arr = new int[n];
	int* barr = new int[2 * n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++, j++) {
		barr[j] = arr[i];
		if (arr[i] %2==0) {
			barr[++j] = arr[i];
		}
	}
	delete[]arr;
	arr = new int[j];
	for (int i = 0; i < j; i++) {
		cout << barr[i] << endl;
		arr[i] = barr[i];
	}
	delete[]arr;
	delete[]barr;
}

int main()
{
	
}

