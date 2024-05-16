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
    mhs1.IPK = 3.88;

    // Menampilkan data mahasiswa
    cout << "Nama: " << mhs1.nama << endl;
    cout << "Umur: " << mhs1.umur << endl;
    cout << "IPK: " << mhs1.IPK << endl;

    return 0;
}
