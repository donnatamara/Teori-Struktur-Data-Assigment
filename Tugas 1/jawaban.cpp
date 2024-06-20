#include <iostream>
#include <algorithm> // Untuk menggunakan std::sort
using namespace std;

bool cekDuplikat(int arr[], int panjangArr) {
    sort(arr, arr + panjangArr); // Mengurutkan array
    for (int i = 0; i < panjangArr - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int arrA[] = {2, 1, 3, 1};
    int panjangArr = sizeof(arrA) / sizeof(arrA[0]);
    cout << cekDuplikat(arrA, panjangArr);

    return 0;
}