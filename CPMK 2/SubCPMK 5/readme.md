# <h1 align="center"> CPMK 2 – SubCPMK 5 </h1>

<p align="center">Donna Nur Tamara</p>

## Soal

### 1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular) 

```C++
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
```

### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

```C++
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
```

### 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

```C++
#include <iostream>
using namespace std;

// Definisi struktur node dari linked list
struct Node
{
    char data;
    Node *next;
    Node(char x) : data(x), next(nullptr) {}
};

// Fungsi untuk menambahkan node baru di akhir linked list
void append(Node **head_ref, char new_data)
{
    Node *new_node = new Node(new_data);
    Node *last = *head_ref;
    if (*head_ref == nullptr)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr)
    {
        last = last->next;
    }
    last->next = new_node;
}

// Fungsi untuk membalikkan linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Fungsi untuk memeriksa apakah linked list adalah palindrom
bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    // Temukan tengah linked list
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Balikkan separuh kedua dari linked list
    Node *second_half = reverse(slow);
    Node *first_half = head;

    // Bandingkan kedua setengah linked list
    while (second_half != nullptr)
    {
        if (first_half->data != second_half->data)
        {
            return false;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return true;
}

int main()
{
    Node *head = nullptr;
    string s;
    cout << "Masukkan string untuk membuat linked list: ";
    cin >> s;
    for (char c : s)
    {
        append(&head, c);
    }

    if (isPalindrome(head))
    {
        cout << "Linked list adalah palindrom.\n";
    }
    else
    {
        cout << "Linked list bukan palindrom.\n";
    }

    return 0;
}
```
