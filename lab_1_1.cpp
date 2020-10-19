#include <iostream>
using namespace std;
//вважатимемо, що x,y,z-натуральні числа.Якщо ж розв'язувати задачу для цілих чисел, то можна дописати "+ or -" до числа
void PyphagorasNumbers() {
    int n;
    cout << "Enter the n" << endl;
    cin >> n;
    for (int x = 1; x < n; x++) {
        for (int y = 1; y < n; y++) {
            for (int z = 1; z <= n; z++) {
                int SumOfQuadratic = x * x + y * y;
                int ZQuadric = z * z;
                if (SumOfQuadratic == ZQuadric) cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
            }
        }
    }
}
int main()
{
    PyphagorasNumbers();
}
