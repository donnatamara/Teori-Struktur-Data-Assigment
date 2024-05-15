# <h1 align="center"> CPMK 2 – SubCPMK 6 </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

```C++
#include <iostream>
#define MAX 100

using namespace std;

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    // Menambahkan elemen ke dalam stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh, tidak dapat menambah elemen." << endl;
        } else {
            arr[++top] = value;
            cout << value << " ditambahkan ke dalam stack." << endl;
        }
    }

    // Menghapus elemen dari stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack kosong, tidak dapat menghapus elemen." << endl;
            return -1;
        } else {
            cout << arr[top] << " dihapus dari stack." << endl;
            return arr[top--];
        }
    }

    // Mengecek apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }

    // Mengecek apakah stack penuh
    bool isFull() {
        return top == MAX - 1;
    }

    // Melihat elemen teratas stack tanpa menghapusnya
    int peek() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    // Menampilkan semua elemen dalam stack
    void display() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
        } else {
            cout << "Elemen dalam stack: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Elemen teratas adalah " << stack.peek() << endl;

    stack.pop();
    stack.display();

    cout << "Apakah stack kosong? " << (stack.isEmpty() ? "Ya" : "Tidak") << endl;

    return 0;
}
```

### 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.

```C++
#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk mensortir stack
void sortStack(stack<int> &s)
{
    stack<int> tempStack;

    while (!s.empty())
    {
        // Ambil elemen teratas dari stack s
        int tmp = s.top();
        s.pop();

        // Pindahkan elemen dari tempStack ke s jika elemen di tempStack lebih besar dari elemen yang diambil
        while (!tempStack.empty() && tempStack.top() > tmp)
        {
            s.push(tempStack.top());
            tempStack.pop();
        }

        // Tempatkan elemen yang diambil ke tempStack
        tempStack.push(tmp);
    }

    // Pindahkan elemen kembali dari tempStack ke s
    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main()
{
    stack<int> s;

    // Menambahkan elemen ke stack
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    // Menampilkan stack sebelum disortir
    cout << "Stack sebelum disortir:" << endl;
    stack<int> temp = s;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Mensortir stack
    sortStack(s);

    // Menampilkan stack setelah disortir
    cout << "Stack setelah disortir:" << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
```
