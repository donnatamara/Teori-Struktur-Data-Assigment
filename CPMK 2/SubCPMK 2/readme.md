# <h1 align="center"> CPMK 2 – SubCPMK 2 </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma!

#### Jawaban
Algoritma sorting merupakan algoritma yang digunakan untuk meletakkan elemen-elemen data ke dalam urutan tertentu, berdasarkan satu atau beberapa kunci pada tiap elemennya. Sorting memiliki dua jenis pengurutan yaitu ascending pengurutan dari yang terkecil hingga ke terbesar dan descending pengurutan dari yang terbesar hingga yang terkecil.

a. Bubble sort merupakan cara pengurutan dengan cara membandingkan elemen-elemen yang berdekatan dalam array dan menukar posisinya jika elemen yang di sebelah kiri lebih besar daripada elemen di sebeleah kanan. 

Alur algortimanya yaitu ulangi seluruh elemen dalam array (kecuali elemen terakhir), kemudian bandingkan elemen ke-i dengan elemen ke-(i+1), jika elemen ke-i lebih besar, tukar posisisnya dengan elemen ke-(i+1), lalu ulangi langkah pertama dan kedua hingga tidak ada lagi pertukaran elemen.

Runtime:
- Best case: O(n), terjadi ketika array sudah terurut, sehingga tidak ada pertukaran elemen yang dilakukan.

- Worst case: O(n^2), terjadi ketika array terbalik, sehingga perlu melakukan banyak pertukaran elemen.

b. Selection Sort merupakan cara pengurutan dengan cara membandingkan elemen sekarang dengan elemen berikutnya hingga elemen terakhir. 

Alur algoritmanya adalah pertama temukan elemen terkecil dalam array, kedua tukar elemen terkecil dengan elemen pertama, terakhir ulangi langkah pertama dan kedua untuk elemen ke-2 hingga elemen terakhir.

Runtime:
- Best case: O(n), terjari ketika array sudah terurut, sehingga hanya perlu melakukan satu kali pertukaran elemen.
- Worst case: O(n^2), terjadi ketika elemen dalam array tidak terurut secara acak, sehingga perlu melakukan banyak pencarian elemen terkecil.

c. Merge sort



### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut

```
#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(arr[i], arr[minIndex]);
    }
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Array sebelum diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  selectionSort(arr, n);

  cout << "\nArray setelah diurutkan: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
```C++

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut!