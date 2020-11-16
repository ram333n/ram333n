#include <iostream>
#include <cstring>
using namespace std;
struct PRICE {
    char NameOfGoods[20];
    char NameOfShop[20];
    float price;
};

bool IsEqual(char* c1, char* c2) {
    for (int i = 0; i < 20; i++) {
        if (c1[i] != c2[i]) {
            return false;
        }
    }
    return true;
}

void PrintStruct(struct PRICE p) {
    cout << "/////////////////////////////////////" << endl;
    cout << "Name of shop : " << p.NameOfShop << endl;
    cout << "Name of goods : " << p.NameOfGoods << endl;
    cout << "Price : " << p.price << endl;
    cout << "/////////////////////////////////////" << endl;
}

void sort(PRICE* arr)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6 - i; j++)
        {
            if (strcmp(arr[j].NameOfGoods, arr[j + 1].NameOfGoods) > 0) {
                PRICE temp;
                temp = arr[j];
                arr[j + 1] = arr[j];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    cout << "Fill in the array" << endl;
    PRICE array[8];
    bool LoopSwitcher = true;
    for (int i = 0; i < 8; i++) {
        bool good = true;
        cout << "Enter the name of shop" << endl;
        cin >> array[i].NameOfShop;
        cout << "Enter the name of goods" << endl;
        cin >> array[i].NameOfGoods;
        cout << "Enter the price" << endl;
        do
        {
            cin >> array[i].price;
            if (!(good = cin.good()))
                cout << "Incorrect input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (!good);
        PrintStruct(array[i]);
    }
    sort(array);
    cout << "Enter the name of goods to get info(press 'y'), or exit(press 'e')" << endl;
    while (LoopSwitcher) {
        char switcher;
        bool IsGoods = false;
        cin >> switcher;
        switch (switcher) {
        case 'y':
            char goodsInfo[20];
            cout << "Enter the name of goods to get info" << endl;
            cin >> goodsInfo;
            for (int i = 0; i < 8; i++) {
                if (IsEqual(goodsInfo, array[i].NameOfGoods)) {
                    PrintStruct(array[i]);
                    IsGoods = true;
                }
            }
            if (!IsGoods) {
                cout << goodsInfo << " isn't at shops " << endl;
            }
            break;
        case 'e':
            LoopSwitcher = false;
            break;
        default:
            cout << "Enter the right action" << endl;
        }
    }
}