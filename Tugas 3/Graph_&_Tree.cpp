#include <iostream>

using namespace std;

const int max_simpul = 10;

void inputSimpul(char simpul_kota[][50], int n)
{
    cout << "Masukkan nama simpul" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul_kota[i];
    }
}

void inputBobot(int bobot[][max_simpul], char simpul_kota[][50], int n)
{
    cout << "Masukkan bobot antar simpul" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << simpul_kota[i] << "--> " << simpul_kota[j] << " = ";
            cin >> bobot[i][j];
        }
    }
}

void tampilkanMatriks(int bobot[][max_simpul], char simpul_kota[][50], int n)
{
    cout << "\n\t";
    for (int i = 0; i < n; i++)
    {
        cout << simpul_kota[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << simpul_kota[i] << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << bobot[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int a;
    cout << "Masukkan jumlah simpul : ";
    cin >> a;

    char simpul_kota[max_simpul][50];
    int bobot[max_simpul][max_simpul];

    inputSimpul(simpul_kota, a);
    inputBobot(bobot, simpul_kota, a);
    tampilkanMatriks(bobot, simpul_kota, a);

    return 0;
}
