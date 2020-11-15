#include <iostream>


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
    cout << "Name of shop : " << p.NameOfShop << endl;
    cout << "Name of goods : " << p.NameOfGoods << endl;
    cout << "Price : " << p.price << endl;
}

void sort(PRICE* arr) {
    PRICE temp;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7 - i; j++) {
            if (arr[j].NameOfGoods > arr[j + 1].NameOfGoods) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char goodsInfo[20];
    cout << "Fill in the array" << endl;
    PRICE array[8];
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
    cout << "Enter the name of goods to get info" << endl;
    cin >> goodsInfo;
    bool IsGoods = false;
    for (int i = 0; i < 8; i++) {
        if (IsEqual(goodsInfo, array[i].NameOfGoods)) {
            PrintStruct(array[i]);
            IsGoods = true;
        }
    }
    if (!IsGoods) {
        cout << goodsInfo << " isn't at shop " << endl;
    }
}
