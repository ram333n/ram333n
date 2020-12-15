#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;


struct NOTEBOOK {
    char model[100]; //model
    int price; //price
    float d; //diagonal
    int f; //frequency
    struct disp_res {
        int x, y;
    }display; //dispay    
};

void sort(NOTEBOOK* arr, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].price < arr[j + 1].price) {
                NOTEBOOK temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printStruct(NOTEBOOK& p) {
    cout << p.model << endl;
    cout << p.price << endl;
    cout << p.d << endl;
    cout << p.f << endl;
    cout << p.display.x << "x" << p.display.y << endl;
    cout << endl;
}

void read(NOTEBOOK*arr) {
    char* str = new char[100];
    int i = 0;
    ifstream file("note.txt");
    while (!file.eof())
    {
        file.getline(str, 1024, '\n');
        strncpy_s(arr[i].model, str, 19);
        arr[i].model[19] = '\0';
        arr[i].price = atoi(&str[20]);
        arr[i].f = atof(&str[43]);
        arr[i].d = atof(&str[51]);
        arr[i].display.x = atoi(&str[58]);
        arr[i].display.y = atoi(&str[63]);
        i++;
    }
    file.close();
    delete [] str;
}

int quantityOfNotes() {
    int q(0);
    ifstream file("note.txt");
    char* str = new char[100];
    while (!file.eof()) {
        file.getline(str, 1024, '\n');
        q++;
    }
    delete[]str;
    file.close();
    return q;
}

void binary(NOTEBOOK* arr, int n){
    ofstream binary;
    binary.open("binary.dat",ios::out| ios::app | ios::binary);
    short count=n;
    binary.seekp(0, binary.beg);
    binary.write((char*)&count, sizeof(short));
    binary.seekp(0, binary.end);
    for (int i = 0; i < n; i++)
    {
       binary.write((char*)&arr[i], sizeof(arr[i]));
    }
    binary.close();
}

int main()
{
    int q = quantityOfNotes();
    NOTEBOOK* array = new NOTEBOOK[q]{ NULL };
    read(array);
    NOTEBOOK* filtered = new NOTEBOOK[q]{ NULL };
    int j(0);
    for (int i = 0; i < q; i++) {
        if (array[i].f > 120) {
            filtered[j] = array[i];
            j++;
        }
        else continue;
    }
    sort(filtered,j);
    for (int i = 0; i < j; i++) {
        printStruct(filtered[i]);
    }
    binary(filtered,j);
    delete[] array;
    delete[] filtered;
}