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
