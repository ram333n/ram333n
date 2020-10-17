#include <iostream>
using namespace std;
int maxNum(int a, int b) {
    if (a > b) {
        return a;
    }
    else if (b > a) {
        return b;
    }
    else return a;
}
int minNum(int a, int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}
void minmax1() {
    int n,num, minnum, maxnum;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (i == 1) {
            minnum = num;
            maxnum = num;
        }
        minnum = minNum(minnum, num);
        maxnum = maxNum(maxnum, num);
    }
    cout << minnum << ", " << maxnum << endl;
}
void minmax11() {
    int n, num, minnum, maxnum, index;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (i == 1) {
            minnum = num;
            maxnum = num;
        }
        minnum = minNum(minnum, num);
        maxnum = maxNum(maxnum, num);
        if (num == maxnum||num==minnum) {
            index = i;
        }
    }
    cout << index << endl;
}
void minmax24() {
    int n, num,temp,sum1,sum2, maxsum;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        if (i == 1) {
            sum1 = num;
        }       
            else if (i == 2) {
            sum1 += num;
            temp = num;
        }
        else {
            sum2 = temp + num;
            maxsum = maxNum(sum1, sum2);
            sum1 = sum2;
            temp = num;
        }
    }
    cout <<maxsum<< endl;
}
void array1() {
    int array[10];
    for (int i = 0; i < 10 ; i++) {
        array[i] = 2 * i + 1;
    }
    for (auto n : array) {
        cout << n << endl;
    }
}
void array11() {
    int k;
    int array[10] = { 1,2,4,8,1,24,56,3,14,5 };
    cin >> k;
    for (int i = k; i < 10; i +=k) {
        cout << array[i] << endl;
    }
}
int main()
{
    
}
