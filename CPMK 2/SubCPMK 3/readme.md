# <h1 align="center"> CPMK 2 – SubCPMK 3 </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

Algoritma Searching dapat disebut sebuah proses pencarian suatu data dalam array dengan cara mengecek satu demi satu pada setiap indeks bari atau setiap indeks kolomnya dengan menggunakan teknik perulangan untuk melakukan pencarian data.

a. Binary search, merupakan sebuah teknik pencarian pada array/list dengan elemen terurut dengan menghapus bagian data pada setiap langkah, dengan cara menentukan nilai tengah (median) dari data, lalu melakukan perbandingan untuk menentukan apakah nilai yang dicari berada pada sebelum atau sesudahnya, serta menentukan bagian lainnya dengan cara yang sama. Algortima ini hanya bekerja pada data yang sudah terurut.

Alur algoritmanya, pertama bagi data menjadi dua bagian, lalu bandingkan dengan elemen yang dicari dengan elemen di tengah, jika sama maka elemen ditemukan dan program akan berhenti, jika lebih kecil program akan mencari lagi di bagian kiri, jika lebih besar program akan mencari di bagian kanan, proses tersebut diulangi hingga elemen yang ditemukan dengan memeriksa seluruh data dalam suatu array/list.

Runtime:
- Best case, O(1), elemen ditemukan pada percobaan pertama (elemen tepat di tengah).
- Worst case, O(log n), elemen tidak ditemukan dan seluruh data terperiksa (elemen ada di ujung atau tidak ada sama sekali).

b. Linear search, merupakan algoritma untuk menemukan data tertentu dalam kumpulan data dengan cara memeriksa semua elemen data satu per satu. Namun, untuk kumpulan data besar, linear search menjadi kurang efisien dibandingkan dengan algoritma pencarian lainnya seperti binary search. Algoritma ini dapat bekerja pada data terurut maupun tidak terurut.

Alur algoritmanya, pertma periksa setiap elemen data satu per satu, bandingkan dengan elemen yang dicari, jika sama maka elemen ditemukan dan program berhenti, jika berbeda maka program akan melanjutkan ke elemen berikutnya, proses tersebut diulang hingga elemen yang dicari ditemukan atau seluruh data diperiksa.

Runtime:
- Best case, O(1), elemen ditemukan pada percobaan pertama (elemen ada di awal data).
- Worst case, O(n), elemen tidak ditemukan dan seluruh data terperiksa (elemen ada di ujung atau tidak ada sama sekali).

Kesimpulannya, binary search lebih efisien untuk data terurut karena runtimenya lebih cepat terutama pada worst case, sedangkan linear search lebih sederhana dan dapat digunakan pada data yang tidak terurut.


### 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut

```C++
#include <iostream>

using namespace std;

// Fungsi pencarian dengan algoritma Sequential Search
int sequentialSearch(int arr[], int n, int x) {
  // Menginisialisasi variabel untuk menampung indeks elemen yang ditemukan
  int index = -1;

  // Melakukan perulangan untuk setiap elemen dalam array
  for (int i = 0; i < n; i++) {
    // Memeriksa apakah elemen saat ini sama dengan nilai yang dicari
    if (arr[i] == x) {
      // Jika ditemukan, ubah variabel index dan hentikan perulangan
      index = i;
      break;
    }
  }

  // Mengembalikan indeks elemen yang ditemukan, atau -1 jika tidak ditemukan
  return index;
}

int main() {
  // Contoh penggunaan fungsi sequentialSearch
  int arr[] = {10, 22, 34, 45, 56};
  int n = sizeof(arr) / sizeof(arr[0]); // Menentukan jumlah elemen array
  int x = 34; // Nilai yang ingin dicari

  int index = sequentialSearch(arr, n, x);

  // Menampilkan hasil pencarian
  if (index != -1) {
    cout << "Nilai " << x << " ditemukan pada indeks ke-" << index << endl;
  } else {
    cout << "Nilai " << x << " tidak ditemukan dalam array" << endl;
  }

  return 0;
}
```

### 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut: Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 

```C++
#include <iostream>
#include <string>

using namespace std;

int binarySearch(string arr[], const string& target, int left, int right) {
    if (left > right) {
        return -1; // Target tidak ditemukan
    }

    int mid = left + (right - left) / 2;

    // Jika elemen tengah adalah string kosong, cari elemen non-kosong terdekat
    int midLeft = mid, midRight = mid;
    while (arr[midLeft] == "" && arr[midRight] == "") {
        if (midLeft > left) midLeft--;
        if (midRight < right) midRight++;
        if (midLeft == left && midRight == right) return -1; // Semua elemen kosong
    }

    if (arr[midLeft] != "") {
        mid = midLeft;
    } else {
        mid = midRight;
    }

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, right);
    } else {
        return binarySearch(arr, target, left, mid - 1);
    }
}

int search(string arr[], int size, const string& target) {
    if (size == 0 || target == "") {
        return -1; // Jika array kosong atau target adalah string kosong
    }
    return binarySearch(arr, target, 0, size - 1);
}

int main() {
    string arr[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    int size = sizeof(arr) / sizeof(arr[0]);
    string target = "ball";

    int index = search(arr, size, target);
    if (index != -1) {
        cout << "Kata '" << target << "' ditemukan pada indeks " << index << "." << endl;
    } else {
        cout << "Kata '" << target << "' tidak ditemukan dalam array." << endl;
    }

    return 0;
}
```
