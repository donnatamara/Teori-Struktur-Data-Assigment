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
