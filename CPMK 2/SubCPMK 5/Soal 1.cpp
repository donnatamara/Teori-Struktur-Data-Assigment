#include <iostream>

using namespace std;

// Definisi node untuk single linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk menghapus duplikasi dari linked list yang tidak terurut
void removeDuplicates(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;

    // Menambahkan data ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 10);
    append(head, 30);
    append(head, 20);
    append(head, 40);

    cout << "Linked list sebelum menghilangkan duplikasi: ";
    printList(head);

    removeDuplicates(head);

    cout << "Linked list setelah menghilangkan duplikasi: ";
    printList(head);

    return 0;
}
