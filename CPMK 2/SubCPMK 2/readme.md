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

c. Merge sort merupakan

Alur algoritmanya:
1. Jika array memiliki lebih dari satu elemen, bagi array menjadi dua bagian yang sama besar, kemudian urutkan kedua bagian secara rekursif menggunakan merge sort, lalu gabungkan kedua bagian ynag sudah terurut.
2. Jika array hanya memiliki satu elemen atau tidak ada elemen, maka array sudah terurut.

Runtime:
- Best case, O(n log n), terjadi ketika array terbagi secara merata saat proses pembagian, sehingga penggabungan dapat dilakukan dengan efisien.
- Worst case: O(n log n), terjadi ketika array terbagi tidak merata saat proses pembagian, namun runtime tetap sama dengan best case karena algoritma ini memiliki sifat "divide and conquer" yang efisien.


Kesimpulannya, masing-masing algoritma sorting di atas memiliki kekurangan dan kelebihannya masing-masing. Bubble sort dan selection sort memiliki runtime yang sama dalam worst case, yaitu O(n^2), sehingga tidak efisien untuk mengurutkan array yang besar. Sedangkan Merge sort memiliki runtime yang lebih baik, yaitu O(n log n), dan lebih efisien untuk mengurutkan array yang besar. 


### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut

```C++
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
```

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram”

```C++
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2) {
  // Mengubah kedua string menjadi huruf kecil dan menghapus spasi
  transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
  s1.erase(remove(s1.begin(), s1.end(), ' '), s1.end());

  transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
  s2.erase(remove(s2.begin(), s2.end(), ' '), s2.end());

  // Mengurutkan kedua string
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  // Membandingkan string yang telah diurutkan
  if (s1 == s2) {
    return true; // Anagram
  } else {
    return false; // Tidak anagram
  }
}

int main() {
  // Deklarasi dan inisialisasi array of strings
  string str1[] = {"aku", "ini", "contoh"};
  string str2[] = {"aku", "ini", "contoh"};

  // Menentukan jumlah elemen array
  int n1 = sizeof(str1) / sizeof(str1[0]);
  int n2 = sizeof(str2) / sizeof(str2[0]);

  // Mengulangi setiap elemen array
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      // Memeriksa apakah dua string adalah anagram
      if (isAnagram(str1[i], str2[j])) {
        cout << str1[i] << " dan " << str2[j] << " adalah anagram" << endl;
      } else {
        cout << str1[i] << " dan " << str2[j] << " bukan anagram" << endl;
      }
    }
  }

  return 0;
}
```

### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut!

```C++
#include <iostream>

using namespace std;



void merge(int arr[], int l, int mid, int r) {
  int i = l, j = mid + 1, k = l;
  int tempArr[r - l + 1];

  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) {
      tempArr[k] = arr[i];
      i++;
    } else {
      tempArr[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    tempArr[k] = arr[i];
    k++;
    i++;
  }

  while (j <= r) {
    tempArr[k] = arr[j];
    k++;
    j++;
  }

  for (int i = l; i <= r; i++) {
    arr[i] = tempArr[i - l];
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

void mergeArrays(int A[], int nA, int B[], int nB) {
  // Memastikan A memiliki cukup ruang untuk menampung B
  if (nA + nB > sizeof(A) / sizeof(int)) {
    cout << "Ukuran array A tidak cukup untuk menampung array B" << endl;
    return;
  }

  // Salin elemen B ke akhir A
  for (int i = 0; i < nB; i++) {
    A[nA + i] = B[i];
  }

  // Gabungkan dan urutkan array A
  mergeSort(A, 0, nA + nB - 1);
}

int main() {
  int A[] = {2, 5, 8, 12, 16};
  int nA = sizeof(A) / sizeof(int);
  int B[] = {3, 6, 7, 11, 14};
  int nB = sizeof(B) / sizeof(int);

  mergeArrays(A, nA, B, nB);

  // Tampilkan array A yang sudah digabung dan diurutkan
  for (int i = 0; i < nA + nB; i++) {
    cout << A[i] << " ";
  }

  return 0;
}
```
