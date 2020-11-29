#include <iostream>
#include <fstream>
#include <ctype.h>
#pragma warning(disable : 4996)
using namespace std;
struct disp_res {
    int x, y;
};

struct NOTEBOOK {
    char model[100]; //model
    int price; //price
    float d; //diagonal
    int f; //frequency
    disp_res display; //dispay    
};

void sort(NOTEBOOK* arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].price < arr[j + 1].price) {
                NOTEBOOK temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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
int read(NOTEBOOK*arr) {
    char* str = new char[1024];
    int i = 0;
    ifstream file("note.txt");
    while (!file.eof())
    {
        file.getline(str, 1024, '\n');
        char* parametr = strtok(str, " x"); //hot place
        int k(0);
        arr[i] = *(new NOTEBOOK);
        while (parametr != NULL) {
            switch (k) {
            case 0:
                strcpy(arr[i].model, parametr);
                break;
            case 1:
                arr[i].price = atoi(parametr);
                break;
            case 2:
                arr[i].d = atof(parametr);
                break;
            case 3:
                arr[i].f = atoi(parametr);
                break;
            case 4:
                arr[i].display.x = atoi(parametr);
                break;
            case 5:
                arr[i].display.y = atoi(parametr);
                break;
            }
            parametr = strtok(NULL, " x");
            k++;
        }
        i++;
    }
    file.close();
    delete [] str;
    return i;
}

void binary(NOTEBOOK* arr, int n){
    fstream binary;
    binary.open("binary.bin",ios::in | ios::app | ios::binary);
    short count;
    if (!binary.good()) {
        binary.open("binary.bin", ios::in | ios::out | ios::binary);
        count = n;
    }
    else {
       binary.seekg(0, binary.beg);
       binary.read((char*)&count,sizeof(short));
       count += n;
    }
    binary.seekg(0, binary.beg);
    binary.write((char*)&count, sizeof(short));
    binary.seekg(0, binary.end);
     for (int i = 0; i < n; i++)
     {
        binary.write((char*)&arr[i], sizeof(arr[i]));
     }
     binary.close();
}
int main()
{
    NOTEBOOK* array = new NOTEBOOK[100]{ NULL };
    int n = read(array);
    for (int i = 0; i < n; i++) {
        printStruct(array[i]);
    }
    NOTEBOOK filtered[100];
    int j(0);
    for (int i = 0; i < 100; i++) {
        if (array[i].f > 120) {
            filtered[j] = array[i];
            j++;
        }
        else continue;
    }
    sort(filtered,j+1);
    binary(filtered,j+1);
}