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
