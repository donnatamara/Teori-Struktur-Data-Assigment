#include <iostream>
using namespace std;

// Definisi struct untuk node
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di akhir linked list
void append(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    
    last->next = newNode;
}

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddle(Node*& head) {
    if (head == nullptr) {
        return;
    }

    int length = getLength(head);
    int middleIndex = length / 2;

    if (middleIndex == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 1; i < middleIndex; i++) {
        current = current->next;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;
    
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    cout << "Linked List sebelum menghapus node tengah: ";
    printList(head);

    deleteMiddle(head);

    cout << "Linked List setelah menghapus node tengah: ";
    printList(head);

    return 0;
}
