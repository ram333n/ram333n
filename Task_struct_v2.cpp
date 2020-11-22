#include <iostream>
#include <cstring>
using namespace std;
struct PRICE {
    char NameOfStuff[20];
    char NameOfShop[20];
    float price;
};

bool IsStructEqual(PRICE p1, PRICE p2) {
    if ((strcmp(p1.NameOfStuff , p2.NameOfStuff)==0) && (strcmp(p1.NameOfShop, p2.NameOfShop) == 0) && (p1.price == p2.price)) {
        return true;
    }
    return false;
}

void PrintStruct(struct PRICE p) {
    cout << "/////////////////////////////////////" << endl;
    cout << "Name of shop : " << p.NameOfShop << endl;
    cout << "Name of stuff : " << p.NameOfStuff << endl;
    cout << "Price : " << p.price << endl;
    cout << "/////////////////////////////////////" << endl;
}

void sort(PRICE* arr)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6 - i; j++)
        {
            if (strcmp(arr[j].NameOfStuff, arr[j + 1].NameOfStuff) > 0) {
                PRICE temp;
                temp = arr[j];
                arr[j + 1] = arr[j];
                arr[j + 1] = temp;
            }
        }
    }
}

void fillIn(PRICE* arr) {
    cout << "Fill in the array" << endl;
    for (int i = 0; i < 8; i++) {
        while (true) {
            bool IsCopy = false;
            bool good = true;
            cout << "Enter the name of shop" << endl;
            cin >> arr[i].NameOfShop;
            cout << "Enter the name of stuff" << endl;
            cin >> arr[i].NameOfStuff;
            cout << "Enter the price" << endl;
            do
            {
                cin >> arr[i].price;
                if (!(good = cin.good())||!(good=(arr[i].price>0)))
                    cout << "Incorrect input" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (!good);
            for (int j = i-1; j >= i-1; j--) {
                if (IsStructEqual(arr[i], arr[j])) {
                    cout << "This is a copy of note, try again" << endl;
                    IsCopy = true;
                    break;
                }
            }
            if (!IsCopy) {
                break;
            }
        }
        PrintStruct(arr[i]);
    }
    sort(arr);
}

void Read(PRICE* arr) {
    char stuff[20];
    cout << "Enter the name of stuff" << endl;
    cin >> stuff;
    bool IsInArray = false;
    for (int i = 0; i < 8; i++) {
        if (strcmp(stuff, arr[i].NameOfStuff) == 0) {
            PrintStruct(arr[i]);
            IsInArray = true;
        }
    }
    if (!IsInArray) {
        cout << "Stuff isn't available at the shops" << endl;
    }
}
void Update(PRICE* arr) {
    PRICE oldInfo;
    PRICE newInfo;
    bool good = true;
    bool IsInArray = false;
    cout << "Enter the information about stuff" << endl;
    cin >> oldInfo.NameOfShop >> oldInfo.NameOfStuff >> oldInfo.price;
    cout << "Enter the new information about stuff" << endl;
    cin >> newInfo.NameOfShop >> newInfo.NameOfStuff;
    do
    {
        cin >> newInfo.price;
        if (!(good = cin.good()) || !(good = (newInfo.price > 0)))
            cout << "Incorrect input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!good);
    for (int i = 0; i < 8; i++) {
        if (IsStructEqual(arr[i], oldInfo)) {
            IsInArray = true;
                arr[i] = newInfo;
                sort(arr);
                break;
        }
    }
    if (!IsInArray) {
        cout << "Enter the right info" << endl;
    }
}
void Dump(PRICE* arr) {
    for (int i = 0; i < 8; i++) {
        PrintStruct(arr[i]);
    }
}

int main()
{
    PRICE array[8];
    fillIn(array);

    cout << "1:Read" << endl;
    cout << "2:Update" << endl;
    cout << "3:Dump" << endl;
    cout << "4:Exit" << endl;
    int Switcher;
    bool loop = true;
    while (loop) {
        cin >> Switcher;
        switch (Switcher)
        {
        case 1:
            Read(array);
            break;

        case 2:
            Update(array);
            break;
        case 3:
            Dump(array);
            break;
        case 4:
            loop = false;
            break;
        default:
            cout << "Enter the right action" << endl;
        }
    }

}