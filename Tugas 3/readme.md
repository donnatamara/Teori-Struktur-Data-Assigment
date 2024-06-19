# <h1 align="center"> Tugas 3 Struktur Data </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Berikan penjelasan dan contoh program (beserta penjelasan alur program) dari masing-masing materi struktur data berikut:
a.	Priority Queue
b.	Hash Table
c.	Rekursif
d.	Graph & Tree

## Jawaban:
### Priority Queue
Priority Queue adalah seuah struktur data yang didalamnya memiliki satu set pasangan key-value, yang mana key sebagai prioritasnya [1]. Ada beberapa cara untuk mengimplementasikan priority queue diantaranya yaitu linked list, array, heap, atau binary search tree. Priority queue sering digunakan dalam sistem real-time, yang mana urutan proses elemen dilakukan dapat memiliki konsekuensi yang signifikan.

Priority queue hanya terdapat dua operasi yaitu insert yang berguna untuk menambahkan item dengan prioritas terkait ke dalam sebuah antrean, dan DeleteMin yang digunakan untuk menghapus item prioritas tertinggi pada antrean [2]. Pada priority queue menentukan prioritas dengan menggunakan operator kurang dari elemen. Fungsi untuk menyisipkan serta menghapus pada priority queue berjalan dalam waktu logaritmik [3].

```C++
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_HEAP_SIZE = 50;
int H[MAX_HEAP_SIZE];
int heapSize = -1;

int parent(int i)
{
    return (i - 1) / 2;
}

int leftChild(int i)
{
    return ((2 * i) + 1);
}

int rightChild(int i)
{
    return ((2 * i) + 2);
}

void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i)
{
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex])
    {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex])
    {
        maxIndex = r;
    }
    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p)
{
    if (heapSize + 1 >= MAX_HEAP_SIZE)
    {
        cout << "Heap overflow, cannot insert more elements\n";
        return;
    }
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax()
{
    if (heapSize == -1)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;
    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

int getMax()
{
    if (heapSize == -1)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    return H[0];
}

void remove(int i)
{
    if (heapSize == -1)
    {
        cout << "Heap is empty\n";
        return;
    }
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main()
{
    int n;
    cout << "Enter the number of elements in the heap: ";
    cin >> n;

    if (n > MAX_HEAP_SIZE)
    {
        cout << "Number of elements exceeds maximum heap size (" << MAX_HEAP_SIZE << ")\n";
        return 1;
    }

    cout << "Enter the elements of the heap: ";
    for (int i = 0; i < n; ++i)
    {
        int element;
        cin >> element;
        insert(element);
    }

    cout << "Priority Queue: ";
    for (int i = 0; i <= heapSize; ++i)
    {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority: " << extractMax() << "\n";

    cout << "Priority queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i)
    {
        cout << H[i] << " ";
    }
    cout << "\n";

    // Ubah prioritas elemen ke-2 (index 1) menjadi 49
    if (n > 2)
    {
        changePriority(2, 49);
        cout << "Priority queue after priority change: ";
        for (int i = 0; i <= heapSize; ++i)
        {
            cout << H[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "Not enough elements to change priority\n";
    }

    // Hapus elemen ke-3 (index 2)
    if (n > 3)
    {
        remove(3);
        cout << "Priority queue after removing the element: ";
        for (int i = 0; i <= heapSize; ++i)
        {
            cout << H[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "Not enough elements to remove\n";
    }

    return 0;
}
```
#### Interpretasi
Kode di atas adalah kode program yang menggunakan sebuah max Heap atau priority queue.

Pertama, program akan membaca jumlah elemen dan memeriksa apakah jumlah ini melebihi kapasitas maksimum heap. Elemen-elemen dimasukkan ke dalam heap menggunakan fungsi `insert`, dan kemudian program akan menampilan semua elemen dalam heap. Elemen dengan prioritas tertinggi dikeluarkan menggunakan fungsi `extractMax`, dan hasilnya ditampilkan bersama dengan heap yang diperbarui. Program juga mengubah prioritas elemen tertentu menggunakan fungsi `changePriority` dan menghapus elemen tertentu menggunakan fungsi `remove`, dengan hasil setiap operasi ditampilkan. Fungsi-fungsi utama termasuk `insert` untuk menambahkan elemen, `extractMax` untuk mengeluarkan elemen maksimum, `changePriority` digunakan untuk mengubah prioritas elemen, dan `remove` digunakan untuk menghapus elemen, memastikan max heap selalu terjaga melalui operasi `shiftup` dan `shiftDown`.

### Hash Table 
Hash Table adalah sebuah struktur data yang dapat digunakan untuk mengambil dan menyimpan data menggunakan sebuah key yang unik [4]. Hash table merupakan fungsi yang merepresentasikan setiap nilai dengan sebuah key unik, lalu menggunakan kunci yang sama untuk memeriksa lokasi kuncinya untuk mengambil nilai yang sesuai, tergantung penggunaannya [5].

Hash table memiliki beberapa operasi yaitu:
- Insertion, digunakan untuk memasukkan sebuah data baru ke dalam tabel hash.
- Deletion, digunakan untuk menghapus data pada hash table.
- Searching 
 
```C++
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashNode
{
public:
    int key;
    int value;
    HashNode *next;

    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

class HashTable
{
private:
    HashNode **table;

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
    {
        table = new HashNode *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value)
    {
        int hash = hashFunction(key);
        HashNode *prev = nullptr;
        HashNode *entry = table[hash];

        while (entry != nullptr && entry->key != key)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr)
        {
            entry = new HashNode(key, value);
            if (prev == nullptr)
            {
                table[hash] = entry;
            }
            else
            {
                prev->next = entry;
            }
        }
        else
        {
            entry->value = value;
        }
    }

    int search(int key)
    {
        int hash = hashFunction(key);
        HashNode *entry = table[hash];

        while (entry != nullptr)
        {
            if (entry->key == key)
            {
                return entry->value;
            }
            entry = entry->next;
        }
        return -1; // Mengembalikan -1 jika kunci tidak ditemukan
    }

    void remove(int key)
    {
        int hash = hashFunction(key);
        HashNode *entry = table[hash];
        HashNode *prev = nullptr;

        while (entry != nullptr && entry->key != key)
        {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr)
        {
            cout << "Key not found!" << endl;
            return;
        }

        if (prev == nullptr)
        {
            table[hash] = entry->next;
        }
        else
        {
            prev->next = entry->next;
        }
        delete entry;
        cout << "Key removed!" << endl;
    }

    ~HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode *entry = table[i];
            while (entry != nullptr)
            {
                HashNode *prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }
};

int main()
{
    HashTable ht;

    // Menggunakan pointer ke metode anggota
    auto insert = [&ht](int key, int value)
    { ht.insert(key, value); };
    auto search = [&ht](int key)
    { return ht.search(key); };
    auto remove = [&ht](int key)
    { ht.remove(key); };

    insert(1, 50);
    insert(2, 60);
    insert(77, 50);

    cout << "Value for key 1: " << search(1) << endl;
    cout << "Value for key 2: " << search(2) << endl;
    cout << "Value for key 77: " << search(77) << endl;

    remove(2);

    cout << "Value for key 2: " << search(1) << endl;

    return 0;
}
```
#### Interpretasi
Kode di atas adalah kode program yang menggunakan algoritma tabel hash dengan penanganan tabrakan menggunakan chaining (linked list). 

Pertama, program akan membuat kelas `HashNode` yang digunakan untuk merepresentasikan node dengan atribut `key`, `value`, dan , `next`. Kelas `HashTable` berisi array pointer `table` yang diinisialisasi dengan ukuran tetap 10. Fungsi `insert` digunakan untuk menambahkan pasangan key-value ke dalam table hash, menggunakan fungsi hash (`key % TABLE_SIZE`) untuk menentukan indeks pada elemennya, dan menangani tabrakan dengan linked list. Fungsi `serach` digunakan untuk mencari nilai berdasarkan key dengan memeriksa linked list di indeks yang sesuai. Fungsi `remove` digunakan untuk menghapus node dengan key tertentu dari linked list. Dalam fungsi `main`, beberapa key dan value ditambahkan, dicari, dan dihapus untuk memperlihatkan penggunaan tabel hash. Kemudian, destruktor membersihkan memori dengan menghapus semua node dari linked list di setiap indeks tabel hash. Program akan mengembalikan nilai 0 yang mana program telah berjalan dengan sukses.



### Rekursif
Rekursif adalah sebuah fungsi yang dapat memanggil dirinya sendiri secara langsung atau tidak langsung [6]. 
```C++
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
```
#### Interpretasi
Kode di atas adalah kode program untuk menghitung faktorial dari sebuah bilangan bulat positif menggunakan fungsi rekursif.

Program dimulai dari pemanggilan fungsi `main`, di mana variabel `angka` dideklarasikan untuk menyimpan inputan dari pengguna. Pengguna diminta memasukkan bilang bulat positif. Jika `angka` bernilai negatif, program akan menampilkan pesan error dan program berhenti berjalan. Jika `angka` yang dimasukkan benar, maka program akan memanggil fungsi rekursif `faktorial` untuk menghitung faktorial dari `angka`. Fungsi `faktorial` memiliki basis rekursi yang mengembalikan `1` jika `n <= 1, memanggil dirinya sendiri hingga mecapai basis rekursi. Setelah menghitung faktorial, hasil disimpan dalam variabel `hasil` dan ditampilkan kepada pengguna. Program kemudian akan mengembalikan nilai 0 jika program telah selesai dijalankan. 



### Graph & Tree 
Graph and Tree adalah

```C++
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
```
#### Interpretasi
Kode di atas adalah kode program yang dapat memasukkan dan menampilkan matriks bobot antar simpul kota dari inputan pengguna. Program ini memiliki tiga fungsi utama yaitu `inputSimpul`, `inputBobot`,`tampilkanMatriks`, serta fungsi `main`.

Pertama, program akan mendeklarasikan konstanta `max_simpul` untuk menentukan jumlah maksimum simpul (10). Program memiliki tiga fungsi utama yaitu `inputSimpul`, `inputBobot`, dan `tampilkanMatriks`. Fungsi `inputSimpul` meminta pengguna untuk memasukkan nama simpul dan menyimpannya dalam sebuah array dua dimensi `simpul_kota`. Fungsi `inputBobot` meminta pengguna untuk memasukkan bobot antar simpul dan menyimpannya dalam array dua dimensi `bobot`. Fungsi `tampilkanMatriks` menampilkan matriks bobot dalam format utama tabel dengan nama simpul sebagai header baris dan kolom. Pada fungsi `main` meminta pengguna untuk memasukkan jumlah simpul, mendeklarasikan array untuk menyimpan nama simpul dan bobot, lalu memanggil fungsi `inputSimpul`, `inputBobot`, dan `tampilkanMatriks` secara berurutan untuk mengisi dan menampilkan data yang dimasukkan pengguna, kemudian program selesai dijalnkan setelah menampilkan matriks bobot dan mengembalikan nilai 0 yang mana program telah sukses berjalan. 



## Referensi
[1] Goponenko, A., & Carroll, S. "A C++ implementation of a lock-free priority queue based on Multi-Dimensional Linked List". Link: https://www.researchgate.net/publication/337020321_A_C_Implementation_of_a_Lock-Free_Priority_Queue_Based_on_Multi-Dimensional_Linked_List. 2019.

[2] Carroll, S., & Goponenko, A. "A C++ implementation of a threadsafe priority queue based on multi-dimensional linked lists and MRLock". 2019.

[3] B. Andrist, V. Sehr, and B. Garney, "C++ High performance: Master the art of optimizing the functioning of your C++ code". Packt Publishing Ltd, 2020.

[4] V. Tran, L. Wang, H. Chen, and Q. Xiao, “MCHT: A maximal clique and hash table-based maximal prevalent co-location pattern mining algorithm,” Expert Systems With Applications, vol. 175, p. 114830, Aug. 2021, doi: 10.1016/j.eswa.2021.114830.

[5] J. Carey, S. Doshi, and P. Rajan, C++ Data structures and algorithm design principles: Leverage the power of modern C++ to build robust and scalable applications. Packt Publishing Ltd, 2019.

[6] S. H. S. Kom. MT and I. W. J. S. Kom. MCs, Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi, 2020.
