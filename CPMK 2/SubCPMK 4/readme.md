# <h1 align="center"> CPMK 2 – SubCPMK 4 </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct!
Struct dalam bahasa C++ adalah struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda yang tersedia dalam C++. Tipe data yang baru, dapat dibentuk di luar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan kebutuhan program atau aplikasi yang dirancang. Struct digunakan untuk mengelompokkan data terkait ke dalam satu unit yang lebih besar. Dalam C++, struct mirip dengan class, namun dengan perbedaan utama bahwa semua anggotanya secara default bersifat public, sehingga memungkinkan akses langsung ke anggota struct tersebut. Variabel-variabel yang ada di dalam struct disebut sebagai anggota struct (atau member).

Karakteristik struct:
- Mendefinisikan tipe data baru yang dapat digunakan untuk menyimpan data yang terkait.
- Anggota struct dapat berupa tipe data apa pun, termasuk struct lain.
- Struct dapat diakses menggunakan operator dot(.)
- Struct dapat digunakan untuk membuat instance (objek) yang menyimpan data spesifik.
- Struct dapat menjadi anggota data dari struct lain.

Contoh program:
```C++
#include <iostream>
using namespace std;

// Mendefinisikan struct Mahasiswa
struct Mahasiswa {
    string nama;
    int umur;
    float IPK;
};

int main() {
    // Deklarasi variabel tipe struct Mahasiswa
    Mahasiswa mhs1;

    // Mengisi nilai ke dalam anggota struct
    mhs1.nama = "Andi";
    mhs1.umur = 20;
    mhs1.IPK = 3.75;

    // Menampilkan data mahasiswa
    cout << "Nama: " << mhs1.nama << endl;
    cout << "Umur: " << mhs1.umur << endl;
    cout << "IPK: " << mhs1.IPK << endl;

    return 0;
}
```
