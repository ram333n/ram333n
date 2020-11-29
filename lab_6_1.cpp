#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

bool IsPalindrom(char* string) {
    for (int i = 0; i < (strlen(string)-1)/2; i++) {
        if (string[i] != string[strlen(string) - i - 1]) {
            return false;
        }
    }
    return true;
}


void Searching() {
    int n;
    cout << "Enter the length" << endl;
    cin >> n;
    ifstream source;
    ofstream filter;
    char buff[200];
    source.open("Source.txt", ios::out);
    filter.open("Filter.txt", ios::out);
    while (!source.eof()) {
        source.getline(buff, 200);
        char* word = strtok(buff, " .,-");
        while ((word != NULL)) {
            if (IsPalindrom(word) && (strlen(word) >= n)) cout << "Palindrom '" << word << "' has been removed" << endl;
            else filter << word << " ";
            word = strtok(NULL, " .,-");
        }
    }
    source.close();
    filter.close();
    source.open("Source.txt", ios::trunc);
    source.close();
    ifstream filter2;
    ofstream source2;
    source2.open("Source.txt", ios::out);
    filter2.open("Filter.txt", ios::out);
    do {
        filter2.getline(buff, 200);
        cout << buff;
        source2 << buff ;
    } while (!filter2.eof());
    source2.close();
    filter2.close();
}
int main()
{
    Searching();
}
