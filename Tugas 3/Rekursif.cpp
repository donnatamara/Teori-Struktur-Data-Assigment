#include <iostream>
using namespace std;

int faktorial(int n)
{
    if (n <= 1)
    {
        return true;
    }
    else
    {
        return n * faktorial(n - 1);
    }
}

int main()
{
    int angka;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> angka;

    if (angka < 0)
    {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    }
    else
    {
        int hasil = faktorial(angka);
        cout << "Faktorial dari " << angka << " adalah: " << hasil << endl;
    }

    return 0;
}
